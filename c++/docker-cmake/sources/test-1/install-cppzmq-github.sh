#!/bin/bash

set -eu

DIR_ROOT=`dirname $(readlink -f $0)`

echo "**************************"
echo "         LIBZMQ           "
echo "**************************"

echo $DIR_ROOT
cd $DIR_ROOT
pwd
sudo rm -rf libzmq
git clone https://github.com/zeromq/libzmq
cd libzmq
mkdir build
cd build
cmake ..
sudo make -j4 install

echo "**************************"
echo "         CPPZMQ           "
echo "**************************"

# After this the C++ lib can be installed. The cppzmq was chosen because
# it’s the most lightweight, the most used and the best mantained C++ lib.

echo $DIR_ROOT
cd $DIR_ROOT
pwd
sudo rm -rf cppzmq
git clone https://github.com/zeromq/cppzmq
cd cppzmq
mkdir build
cd build
cmake ..
sudo make -j4 install

echo "**************************"
echo "        FINISHED.         "
echo "**************************"

