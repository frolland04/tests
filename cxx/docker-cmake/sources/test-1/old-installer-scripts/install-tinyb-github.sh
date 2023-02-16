#!/bin/bash

set -eu

DIR_ROOT=`dirname $(readlink -f $0)`

echo "**************************"
echo "          TINYB           "
echo "**************************"

sudo apt-get install bluez libbluetooth-dev
sudo apt-get install libglib2.0-dev

echo $DIR_ROOT
cd $DIR_ROOT
pwd
sudo rm -rf tinyb
git clone https://github.com/intel-iot-devkit/tinyb.git
cd tinyb
mkdir build
cd build
cmake ..
sudo make -j4 install

echo "**************************"
echo "        FINISHED.         "
echo "**************************"
