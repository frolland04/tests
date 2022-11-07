#!/bin/python3

import getopt
import os
import sys
from datetime import datetime
from time import sleep
import csv
import json
from enum import Enum


# *--------*-------------------------------------------*-------
"""
"""


def banner():
    print(f"STARTING {datetime.today()}")
    print(f"Running from {os.curdir}")
    print(f"Program is {sys.argv[0]}")


def ending(sts):
    print(f"ENDING {datetime.today()}")
    print(f"Ran {(datetime.now() - sts).total_seconds()} seconds")


def get_io_files(argv):
    input_file = None
    output_file = None

    try:
        opts, args = getopt.getopt(argv, "hi:o:", ["input=", "output="])
    except getopt.GetoptError:
        print_usage()
        sys.exit(2)

    for opt, arg in opts:
        if opt == "-h":
            print_usage()
            sys.exit()
        elif opt in ("-i", "--input"):
            input_file = arg
        elif opt in ("-o", "--output"):
            output_file = arg

    if not input_file or not output_file:
        print("ERROR: You MUST provide both input and output file names! Aborting.")
        print_usage()
        sys.exit(3)

    print(f"Input file is {input_file}")
    print(f"Output file is {output_file}")

    try:
        with open(input_file, "r"):
            pass
    except IOError:
        print(f"ERROR: Unable to open {input_file} for reading! Aborting.")

    try:
        with open(output_file, "w"):
            pass
    except IOError:
        print(f"ERROR: Unable to open {output_file} for writing! Aborting.")

    return input_file, output_file


def print_usage():
    print(f"Usage:\n{os.path.basename(sys.argv[0])} -i <inputfile> -o <outputfile>")


def process_ddb_export_json_dict(
    in_field, json_dict_a, in_fields, out_fields, out_rows
):
    """
        Unmarshall JSON payload, following the AWS DynamoDB 'grammar' :
        {
    (A)     "string": {
    (B)(C)      "S": "string",
    (B)(C)      "N": "string",
    (B)(C)      "B": b"bytes",
    (B)(D)      "SS": [
                    "string",
                ],
    (B)(D)      "NS": [
                    "string",
                ],
    (B)(D)      "BS": [
                    b"bytes",
                ],
    (B)(A)      "M": {
                    "string": {"... recursive ..."}
                },
    (B)(E)      "L": [
                    {"... recursive ..."},
                ],
    (B)(C)      "NULL": True|False,
    (B)(C)      "BOOL": True|False
            }
        }

        @:param in_field CSV field name (from input file) that is containing JSON payload
        @:param json_dict_a result dict from json.loads() called with the payload
        @:param in_fields list of field names from input file
        @:param out_fields current list of field names for output file
        @:param out_rows current list of output rows (generated for the current input row)
    """
    assert isinstance(in_field, str)
    assert isinstance(json_dict_a, dict)
    assert isinstance(in_fields, list)
    assert isinstance(out_fields, list)
    assert isinstance(out_rows, list)

    global nb_output_fields_generated, nb_output_flattened_as_rows, nb_output_flattened_as_fields, nb_input_fields_json_dict_S, nb_input_fields_json_dict_N, nb_input_fields_json_dict_B, nb_input_fields_json_dict_SS, nb_input_fields_json_dict_NS, nb_input_fields_json_dict_BS, nb_input_fields_json_dict_NU, nb_input_fields_json_dict_BO, nb_input_fields_json_dict_L, nb_input_fields_json_dict_M

    print(json.dumps(json_dict_a, indent=3))

    # (A) beginning of the grammar, context is dict_a : dict_a.property = 'string' : dict_b
    for fi in json_dict_a.keys():
        print(f"property='{fi}'")
        json_dict_b = json_dict_a[fi]
        assert isinstance(json_dict_b, dict)
        assert len(json_dict_b) == 1
        prop = list(json_dict_b.keys())[0]

        # (B) determine which type of property in dict_b
        if prop == "S":
            print("[S]")
            nb_input_fields_json_dict_S += 1
        elif prop == "N":
            print("[N]")
            nb_input_fields_json_dict_N += 1
        elif prop == "B":
            print("[B]")
            nb_input_fields_json_dict_B += 1
        elif prop == "SS":
            print("[SS]")
            nb_input_fields_json_dict_SS += 1
        elif prop == "NS":
            print("[NS]")
            nb_input_fields_json_dict_NS += 1
        elif prop == "BS":
            print("[BS]")
            nb_input_fields_json_dict_BS += 1
        elif prop == "L":
            print("[L]")
            nb_input_fields_json_dict_L += 1
        elif prop == "M":
            print("[M]")
            nb_input_fields_json_dict_M += 1

        # (B) dict_b.prop = S | N | B | SS | NS | BS | M | L | NULL | BOOL
        # (B) determine which DynamoDB type is present in the second-level property
        basic_prop = ("S", "N", "B", "NULL", "BOOL")
        other_prop = ("SS", "NS", "BS")

        # (C) basic set of types
        if prop in basic_prop:
            print("(BASIC)")

            # This is a new column in the output CSV
            generate_field = in_field + "." + fi
            generate_value = json_dict_b[prop]
            print(
                f"populate new field '{generate_field}' with value '{generate_value}'"
            )
            nb_output_flattened_as_fields += 1

            # Set the value into each transient row
            for r in out_rows:
                r[generate_field] = generate_value

            # Keep the new column name if newly created
            if generate_field not in out_fields:
                out_fields.append(generate_field)
                if generate_field not in in_fields:
                    nb_output_fields_generated += 1

        # (D) second set of types (not implemented)
        elif prop in other_prop:
            print("(OTHER)")
            raise Exception("JSON", "Not implemented yet.")

        # (B)->(A) context is (A) again, we recurse
        elif prop == "M":
            print("(recurse)")
            field_prefix = in_field + "." + fi
            process_ddb_export_json_dict(
                field_prefix, json_dict_b["M"], in_fields, out_fields, out_rows
            )

        # (B)->(E), we recurse
        elif prop == "L":
            print("(recurse)")
            field_prefix = in_field + "." + fi
            process_ddb_export_json_list(
                field_prefix, json_dict_b["L"], in_fields, out_fields, out_rows
            )

        else:
            raise Exception(
                "JSON", "Unsupported field type when unmarshalling JSON object"
            )


def process_ddb_export_json_list(in_field, json_list, in_fields, out_fields, out_rows):
    """
        Unmarshall JSON payload, following the AWS DynamoDB 'grammar' :
        {
    (A)     "string": {
    (B)(C)      "S": "string",
    (B)(C)      "N": "string",
    (B)(C)      "B": b"bytes",
    (B)(D)      "SS": [
                    "string",
                ],
    (B)(D)      "NS": [
                    "string",
                ],
    (B)(D)      "BS": [
                    b"bytes",
                ],
    (B)(A)      "M": {
                    "string": {"... recursive ..."}
                },
    (B)(E)      "L": [
                    {"... recursive ..."},
                ],
    (B)(C)      "NULL": True|False,
    (B)(C)      "BOOL": True|False
            }
        }

        @:param in_field CSV field name (from input file) that is containing JSON payload
        @:param json_list result list from json.loads() called with the payload
        @:param in_fields current list of field names from input file
        @:param out_fields current list of field names for output file
        @:param out_rows current list of output rows (generated for the current input row)
    """
    assert isinstance(in_field, str)
    assert isinstance(json_list, list)
    assert isinstance(in_fields, list)
    assert isinstance(out_fields, list)
    assert isinstance(out_rows, list)

    global nb_output_fields_generated, nb_output_flattened_as_rows, nb_output_flattened_as_fields, nb_input_fields_json_dict_S, nb_input_fields_json_dict_N, nb_input_fields_json_dict_B, nb_input_fields_json_dict_SS, nb_input_fields_json_dict_NS, nb_input_fields_json_dict_BS, nb_input_fields_json_dict_NU, nb_input_fields_json_dict_BO, nb_input_fields_json_dict_L, nb_input_fields_json_dict_M, nb_output_rows_generated

    print(json.dumps(json_list, indent=3))

    # We deal with the (E) context of the grammar
    for fi in enumerate(json_list):
        list_index = fi[0]
        list_value = fi[1]
        print(">>>>>>>>>", list_index, list_value)
        assert isinstance(list_value, dict)
        assert len(list_value) == 1
        prop = list(list_value.keys())[0]

        # TODO this part should be merged into 'process_ddb_export_json_dict()'
        #  Only a small piece code specific to the (E) context
        if prop == "S":
            print("[S]")
            nb_input_fields_json_dict_S += 1
        elif prop == "N":
            print("[N]")
            nb_input_fields_json_dict_N += 1
        elif prop == "B":
            print("[B]")
            nb_input_fields_json_dict_B += 1
        elif prop == "SS":
            print("[SS]")
            nb_input_fields_json_dict_SS += 1
        elif prop == "NS":
            print("[NS]")
            nb_input_fields_json_dict_NS += 1
        elif prop == "BS":
            print("[BS]")
            nb_input_fields_json_dict_BS += 1
        elif prop == "L":
            print("[L]")
            nb_input_fields_json_dict_L += 1
        elif prop == "M":
            print("[M]")
            nb_input_fields_json_dict_M += 1

        basic_prop = ("S", "N", "B", "NULL", "BOOL")
        other_prop = ("SS", "NS", "BS")

        if prop in basic_prop:
            print("(BASIC)")
            generate_value = list_value[prop]

            # This part is specific to unmarshall lists & building CSV rows
            print(f"populate row where '{in_field}' has value '{generate_value}'")
            nb_output_flattened_as_rows += 1

            destination_row = None
            if list_index >= len(out_rows):
                # Create new row
                print("Create a new row")
                destination_row = out_rows[-1].copy()
                out_rows.append(destination_row)
                nb_output_rows_generated += 1

            else:
                # Populate exiting
                print("Populate an exiting row")
                destination_row = out_rows[-1]

            destination_row[in_field] = generate_value

            # Is it a new transposed field ? Keep it as output field
            if in_field not in out_fields:
                out_fields.append(in_field)
                if in_field not in in_fields:
                    nb_output_fields_generated += 1

        elif prop in other_prop:
            print("(OTHER)")
            raise Exception("JSON", "Not implemented yet.")

        elif prop == "M":
            print("(recurse)")
            process_ddb_export_json_dict(
                in_field, list_value["M"], in_fields, out_fields, out_rows
            )

        else:
            raise Exception(
                "JSON", "Unsupported field type when unmarshalling JSON array"
            )


if __name__ == "__main__":
    ts = datetime.now()
    banner()

    input_file, output_file = get_io_files(sys.argv[1:])

    # Some runtime statistics
    nb_input_rows = 0
    nb_input_fields = 0
    nb_total_input_fields = 0
    nb_input_fields_json = 0
    nb_input_fields_json_dict = 0
    nb_input_fields_json_list = 0
    nb_input_fields_json_dict_S = 0
    nb_input_fields_json_dict_N = 0
    nb_input_fields_json_dict_B = 0
    nb_input_fields_json_dict_SS = 0
    nb_input_fields_json_dict_NS = 0
    nb_input_fields_json_dict_BS = 0
    nb_input_fields_json_dict_NU = 0
    nb_input_fields_json_dict_BO = 0
    nb_input_fields_json_dict_M = 0
    nb_input_fields_json_dict_L = 0
    nb_output_rows_generated = 0
    nb_output_fields_generated = 0
    # ^^^ current number of newly created fields for output file (not existing in input file)
    nb_output_flattened_as_rows = 0
    # ^^^ current number of JSON properties processed and flattened as new rows
    nb_output_flattened_as_fields = 0
    # ^^^ current number of JSON properties processed and flattened as new fields
    nb_output_rows = 0
    nb_output_fields = 0
    nb_total_output_fields = 0

    with open(output_file, "w") as output_csv_file:
        # On creation, 'fieldnames' of 'DictWriter' are NOT set. Postponed upon the first time we need to write into.
        csv_writer = csv.DictWriter(
            output_csv_file, fieldnames=None, delimiter=",", quoting=csv.QUOTE_NONE
        )
        has_header = False
        output_fields = []
        output_rows = []

        with open(input_file, "r") as input_csv_file:
            csv_reader = csv.DictReader(input_csv_file, delimiter=",", quotechar='"')
            print("header:", csv_reader.fieldnames)
            input_fields = csv_reader.fieldnames
            nb_input_fields = len(input_fields)

            # Iterate on all input rows
            # *************************
            for indexed_row in enumerate(csv_reader):
                nb_input_rows += 1
                print(f"current line is {indexed_row}")
                index = indexed_row[0]
                row = indexed_row[1]  # index is here just for fun :-)
                current_output_rows = [{}]  # we start with one empty row as output

                # At each input row, get each field (item_key/item_value)
                for item_key in row:
                    nb_total_input_fields += 1
                    item_value = row[item_key]
                    # print(index, item_key, item_value)

                    # (1) Specific processing if current field is JSON payload
                    # ********************************************************
                    if "{" in item_value:
                        res = json.loads(item_value)
                        print(f"(1) JSON in field '{item_key}' with payload '{res}'")
                        nb_input_fields_json += 1

                        # Dict items at first level are flattened into newly generated fields / newly generated rows
                        # by recursive decoding
                        if isinstance(res, dict):
                            print(
                                f"*** First-level JSON structure is Object, has {len(res.keys())} properties ***",
                            )
                            nb_input_fields_json_dict += 1

                            # INPUT :
                            # - CSV field name (from input file) that is containing JSON payload
                            # - result dict from json.loads() called with the payload
                            # - current list of field names for output file
                            # - current list of output rows (generated for the current input row)

                            # OUTPUT :
                            # - (updated) current list of field names for output file
                            # - (updated) current list of output rows (generated for the current input row)

                            process_ddb_export_json_dict(
                                item_key,
                                res,
                                input_fields,
                                output_fields,
                                current_output_rows,
                            )

                        # List items at first level are flattened into newly generated rows
                        # Apparently no need to decode recursively ... (to be confirmed)
                        elif isinstance(res, list):
                            print(
                                "*** First-level JSON structure is Array ***", len(res)
                            )
                            nb_input_fields_json_list += 1

                            process_ddb_export_json_list(
                                item_key,
                                res,
                                input_fields,
                                output_fields,
                                current_output_rows,
                            )
                        else:
                            raise Exception("JSON", "Unsupported JSON content")
                    else:
                        # (2) This is not a field carrying JSON text, simply transpose to output
                        # **********************************************************************
                        print(
                            f"(2) standard field '{item_key}' with value '{item_value}'"
                        )

                        # Set value for this field, in output, for all rows
                        for rowdict in current_output_rows:
                            rowdict[item_key] = item_value

                        # Is it a new transposed field ? Keep it as output field
                        if item_key not in output_fields:
                            output_fields.append(item_key)

                # (3) Put final rows in the global output buffer
                # **********************************************
                print("(3) Done with current input row.")
                print("current_output_rows", current_output_rows)
                output_rows += current_output_rows
                for current_row in current_output_rows:
                    nb_total_output_fields += len(current_row)

            # (4) Finishing : writing to output file
            # **************************************
            print("******** (4) Finishing, writing output file ********")
            print("output fields", output_fields)
            nb_output_fields = len(output_fields)
            nb_output_rows = len(output_rows)

            # (a) Write header in output file
            if not has_header:
                csv_writer.fieldnames = output_fields
                csv_writer.writeheader()
                has_header = True

            # (b) Write rows
            csv_writer.writerows(output_rows)

    # sleep(1)

    print("nb_input_rows:", nb_input_rows)
    print("nb_input_fields:", nb_input_fields)
    print("nb_total_input_fields:", nb_total_input_fields)
    print("nb_input_fields_json:", nb_input_fields_json)
    print("nb_input_fields_json_dict:", nb_input_fields_json_dict)
    print("nb_input_fields_json_list:", nb_input_fields_json_list)
    print("nb_input_fields_json_dict_S:", nb_input_fields_json_dict_S)
    print("nb_input_fields_json_dict_N:", nb_input_fields_json_dict_N)
    print("nb_input_fields_json_dict_B:", nb_input_fields_json_dict_B)
    print("nb_input_fields_json_dict_SS:", nb_input_fields_json_dict_SS)
    print("nb_input_fields_json_dict_NS:", nb_input_fields_json_dict_NS)
    print("nb_input_fields_json_dict_BS:", nb_input_fields_json_dict_BS)
    print("nb_input_fields_json_dict_NU:", nb_input_fields_json_dict_NU)
    print("nb_input_fields_json_dict_BO:", nb_input_fields_json_dict_BO)
    print("nb_input_fields_json_dict_M:", nb_input_fields_json_dict_M)
    print("nb_input_fields_json_dict_L:", nb_input_fields_json_dict_L)
    print("nb_output_flattened_as_rows:", nb_output_flattened_as_rows)
    print("nb_output_flattened_as_fields:", nb_output_flattened_as_fields)
    print("nb_output_rows:", nb_output_rows)
    print("nb_output_fields:", nb_output_fields)
    print("nb_output_rows_generated:", nb_output_rows_generated)
    print("nb_output_fields_generated:", nb_output_fields_generated)
    print("nb_total_output_fields:", nb_total_output_fields)

    ending(ts)
    print("Bye Bye !")
