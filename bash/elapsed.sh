#!/usr/bin/env bash

TIMEFORMAT='It took %0R seconds.'
time {
echo "Starting.."
sleep 5
echo "Let's continue.."
sleep 7
echo "Finished."
}
