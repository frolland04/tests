#!/bin/bash

BACKGROUND="An Example of 2x --gauge usage"
: ${DIALOG=dialog}
for i in 5 10 20 30 40 50 60 70 80 90 100
do
    ${DIALOG} \
        --backtitle "${BACKGROUND}" \
                     --begin  0 2 --title "Gauge 1 demo" \
                                  --mixedgauge "This is a prompt message,\nand this is the second line." 10 35 $i \
        --and-widget --begin 12 2 --title "Gauge 2 demo" \
                                  --mixedgauge "This is a prompt message,\nand this is the second line." 10 35 18 \
        --and-widget --begin 24 2 --title "Gauge 3 demo" \
                                  --mixedgauge "This is a prompt message,\nand this is the second line." 10 35 28

    sleep 1
done