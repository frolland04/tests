#!/bin/bash

set -eu

DIR_ROOT=`dirname $(readlink -f $0)`

echo "**************************"
echo "      CPPLINUXSERIAL      "
echo "**************************"

echo $DIR_ROOT
cd $DIR_ROOT
pwd
sudo rm -rf CppLinuxSerial
git clone https://github.com/gbmhunter/CppLinuxSerial.git
cd CppLinuxSerial
mkdir build
cd build
cmake ..
sudo make -j4 install

echo "**************************"
echo "        FINISHED.         "
echo "**************************"
