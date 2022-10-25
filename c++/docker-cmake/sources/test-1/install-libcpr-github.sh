#!/bin/bash

set -eu

DIR_ROOT=`dirname $(readlink -f $0)`

echo "**************************"
echo "         LIBCPR           "
echo "**************************"

sudo apt-get install libssl-dev

echo $DIR_ROOT
cd $DIR_ROOT
pwd
sudo rm -rf cpr
git clone https://github.com/libcpr/cpr.git
cd cpr
mkdir build
cd build
cmake .. -DCPR_USE_SYSTEM_CURL=OFF
cmake --build .
sudo cmake --install .

echo "**************************"
echo "        FINISHED.         "
echo "**************************"

