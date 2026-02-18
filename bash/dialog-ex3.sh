#!/bin/bash

BACKGROUND="An Example of --mixedgauge usage"
: ${DIALOG=dialog}
for i in 5 10 20 30 40 50 60 70 80 90 100
do
    ${DIALOG} --backtitle "${BACKGROUND}" \
        --title "Mixed gauge demonstration" "$@" \
        --mixedgauge "This is a prompt message,\nand this is the second line." \
            30 80 28 \
            "Process 1"	"0" \
            "Process 2"	"1" \
            "Process 3"	"2" \
            "Process 4"	"3" \
            ""	        " " \
            "Process 5"	"5" \
            "Process 6"	"6" \
            "Process 7"	"7" \
            "Process 8"	"4" \
            "Process 9"	"-$i"
    sleep 1
done

#  0: success
#  1: failed
#  2: passed
#  3: completed
#  4: checked
#  5: done
#  6: skipped
#  7: in progress
# -X: 0-100, progress of process