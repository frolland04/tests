#!/bin/bash

export LD_LIBRARY_PATH=/usr/local/lib
rm -rf build
mkdir -p build && cd build && cmake .. && make && ./hello_world
