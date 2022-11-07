#!/bin/bash

set -e

INPUT=$1
echo INPUT $INPUT
OUTPUT=converted-`basename $INPUT`
echo OUTPUT $OUTPUT

./convert-csv.py -i $INPUT -o $OUTPUT

