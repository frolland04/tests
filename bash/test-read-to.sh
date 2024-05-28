#!/bin/bash

set -aeux -o pipefail

read -t 20 -n 1 -p "It might take a long time, do you agree ? (Y/N)" || true
echo "${REPLY}"
if [ "${REPLY}" == "" ] ; then
    # defaulted to 'No'
    REPLY="N"
fi

if [ "${REPLY}" == "Y" ] || [ "${REPLY}" == "y" ] ; then
    echo ""
    echo "Please wait a long time."
    sleep 5
else
    echo "Skipping"
    sleep 1
fi

echo "Finished."
