#!/bin/bash

set -eu

DIR_ROOT=`dirname $(readlink -f $0)`

echo "**************************"
echo "       WEBSOCKETPP        "
echo "**************************"

echo $DIR_ROOT
cd $DIR_ROOT
pwd
sudo rm -rf websocketpp
git clone https://github.com/zaphoyd/websocketpp.git
cd websocketpp
mkdir build
cd build
cmake ..
sudo make -j4 install

echo "**************************"
echo "        FINISHED.         "
echo "**************************"
