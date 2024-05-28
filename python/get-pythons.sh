#!/bin/bash

for PV in 3.12.0 3.11.6 3.10.13 3.9.18 3.8.18 3.7.16 ; do
    cd /usr/src
    rm -rf Python-${PV}.tgz Python-${PV}
    wget https://www.python.org/ftp/python/${PV}/Python-${PV}.tgz && \
    tar -xzf Python-${PV}.tgz && \
    cd Python-${PV} && \
    ./configure --prefix /usr/local --enable-optimizations --with-lto && \
    make -j "$(nproc)" && make altinstall
done



