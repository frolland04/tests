#!/bin/bash

set -eu

DIR_ROOT=`dirname $(readlink -f $0)`

echo "**************************"
echo "      NLOHMANN JSON       "
echo "**************************"

echo $DIR_ROOT
cd $DIR_ROOT
pwd
sudo rm -rf json
git clone https://github.com/nlohmann/json.git
cd json
mkdir build
cd build
cmake ..
sudo make -j4 install

echo "**************************"
echo "        FINISHED.         "
echo "**************************"

