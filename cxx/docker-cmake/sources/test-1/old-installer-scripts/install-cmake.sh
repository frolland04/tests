#!/usr/bin/env bash

DISTRIB_PREFIX="${1:-/usr}"
CMAKE_VERSION="3.27.3"
ARCHIVE_NAME="cmake-${CMAKE_VERSION}.tar.gz"

rm -rf ${ARCHIVE_NAME} cmake-${CMAKE_VERSION}

wget "https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/${ARCHIVE_NAME}" && \
tar zxvf ${ARCHIVE_NAME} && \
cd cmake-${CMAKE_VERSION} && \
mkdir build && \
cd build/ && \
cmake -G Ninja -B . -S .. -DCMAKE_INSTALL_PREFIX=${DISTRIB_PREFIX} && \
cmake --build . && \
cmake --install . && \
cd ../.. && \
rm -rf ${ARCHIVE_NAME} cmake-${CMAKE_VERSION}
