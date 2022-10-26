#!/bin/bash

set -eu

DIR_ROOT=`dirname $(readlink -f $0)`

echo "**************************"
echo "         LIBBLEPP         "
echo "**************************"

sudo apt-get install bluez libbluetooth-dev

echo $DIR_ROOT
cd $DIR_ROOT
pwd
sudo rm -rf libblepp
git clone https://github.com/edrosten/libblepp.git
cd libblepp
mkdir build
cd build
cmake -DWITH_EXAMPLES=ON ..
sudo make -j4 install

echo "**************************"
echo "        FINISHED.         "
echo "**************************"
