#!/bin/python3

import getopt
import os
import sys
from datetime import datetime
from time import sleep
import csv
import json
from enum import Enum


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


def process_ddb_export_json_dict(json_path, json_dict, out_fields, out_rows):
    """
    Unmarshall JSON payload

    @:param json_path path in the JSON tree to generate CSV field names (using dot instead of /)
    @:param json_dict result dict from json.loads() called with the payload
    @:param out_fields current list of field names for output file
    @:param out_rows current list of output rows
    """

    assert isinstance(json_path, str)
    assert isinstance(json_dict, dict)
    assert isinstance(out_fields, list)
    assert isinstance(out_rows, list)

    global nb_input_fields_json_dict, nb_input_fields_json_value
    nb_input_fields_json_dict += 1

    for fi in json_dict.keys():
        print(f"property='{fi}'")
        value = json_dict[fi]
        if len(json_path) == 0:
            field = fi
        else:
            field = json_path + "." + fi

        if isinstance(value, dict):
            print("(dict)")
            process_ddb_export_json_dict(field, value, out_fields, out_rows)

        elif isinstance(value, list):
            print("(list)")
            process_ddb_export_json_list(field, value, out_fields, out_rows)

        else:
            print("(value)")
            nb_input_fields_json_value += 1
            print(f"populate new field '{field}' with value '{value}'")

            # Set the value into each transient row (?)
            if len(out_rows) == 0:
                out_rows.append({})
            for r in out_rows:
                r[field] = value

            # Keep the new column name if newly created
            if field not in out_fields:
                out_fields.append(field)


def process_ddb_export_json_list(json_path, json_list, out_fields, out_rows):
    """
    Unmarshall JSON payload

    @:param json_path path in the JSON tree to generate CSV field names (using dot instead of /)
    @:param json_list result list from json.loads() called with the payload
    @:param out_fields current list of field names for output file
    @:param out_rows current list of output rows
    """
    assert isinstance(json_path, str)
    assert isinstance(json_list, list)
    assert isinstance(out_fields, list)
    assert isinstance(out_rows, list)

    global nb_input_fields_json_list, nb_input_fields_json_value
    nb_input_fields_json_list += 1

    print(json.dumps(json_list, indent=3))

    for fi in enumerate(json_list):
        list_index = fi[0]
        list_value = fi[1]
        nb_input_fields_json_value += 1

        print(">>>>>>>>>", list_index, list_value)
        print(f"populate row where '{json_path}' has value '{list_value}'")

        destination_row = None
        if list_index >= len(out_rows):
            # Create new row
            print("Create a new row")
            destination_row = out_rows[-1].copy()
            out_rows.append(destination_row)

        else:
            # Populate exiting
            print("Populate an exiting row")
            destination_row = out_rows[-1]

        destination_row[json_path] = list_value

        # Is it a new transposed field ? Keep it as output field
        if json_path not in out_fields:
            out_fields.append(json_path)


if __name__ == "__main__":
    ts = datetime.now()
    banner()

    input_file, output_file = get_io_files(sys.argv[1:])

    # Some runtime statistics
    nb_input_fields_json_value = 0
    nb_input_fields_json_dict = 0
    nb_input_fields_json_list = 0
    nb_output_rows = 0
    nb_output_fields = 0

    with open(output_file, "w") as output_csv_file:
        # On creation, 'fieldnames' of 'DictWriter' are NOT set. Postponed upon the first time we need to write into.
        csv_writer = csv.DictWriter(
            output_csv_file, fieldnames=None, delimiter=",", quoting=csv.QUOTE_NONE
        )
        has_header = False
        output_fields = []
        output_rows = []

        with open(input_file, "r") as input_json_file:
            # (1) Load and parse the input file
            res = json.load(input_json_file)

            # (2) Dict items at first level are flattened into newly generated fields / newly generated rows
            # by recursive decoding
            if isinstance(res, dict):
                print(
                    f"*** First-level JSON structure is Object, has {len(res.keys())} properties ***",
                )
                process_ddb_export_json_dict("", res, output_fields, output_rows)
            else:
                raise Exception("JSON", "Unsupported JSON content")

            # (3) Finishing : writing to output file
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

    print("nb_input_fields_json_value:", nb_input_fields_json_value)
    print("nb_input_fields_json_dict:", nb_input_fields_json_dict)
    print("nb_input_fields_json_list:", nb_input_fields_json_list)
    print("nb_output_rows:", nb_output_rows)
    print("nb_output_fields:", nb_output_fields)

    ending(ts)
    print("Bye Bye !")
