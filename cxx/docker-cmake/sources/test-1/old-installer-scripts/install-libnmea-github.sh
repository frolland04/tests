#!/bin/bash

set -eu

DIR_ROOT=`dirname $(readlink -f $0)`

echo "**************************"
echo "         LIBNMEA          "
echo "**************************"

echo $DIR_ROOT
cd $DIR_ROOT
pwd
sudo rm -rf libnmea
git clone https://github.com/jacketizer/libnmea
cd libnmea
mkdir build
cd build
cmake ..
sudo make -j4 install
make test

echo "**************************"
echo "        FINISHED.         "
echo "**************************"

