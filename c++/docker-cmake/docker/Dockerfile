FROM ubuntu:latest

# Unless specified something else as arguments, user is 'devel:build', (uid:gid is 10000:10000).
ARG UID=10000

ARG GID=10000

# Base packages for toolchaining
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    pkg-config \
    git \
    python3 \
    wget \
    apt-utils \
    sudo \
    dialog \
    pv \
    nano \
    vim

# Keep docker build non interactive
RUN DEBIAN_FRONTEND=noninteractive TZ=Europe/Paris apt-get -y install tzdata

# 'devel' passwd is 'devel'
RUN groupadd -g $GID build && useradd -p UZu.giVcrobhI -G sudo,build -u $UID devel

RUN mkdir -p /home/devel && cd /home/devel && chown -R devel:build . && chmod g+w .

# Dev toolchaining packages
RUN apt-get install -y \
    qtcreator \
    meld \
    doxygen \
    gedit
    
# Dev third-party packages : Boost
RUN apt-get install -y \
    libboost-all-dev \
    libboost-doc

# Dev third-party packages : Cppzmq / Libzmq
RUN cd /tmp && \
    rm -rf libzmq && \
    git clone https://github.com/zeromq/libzmq && \
    cd libzmq && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j4 install
    
RUN cd /tmp && \
    rm -rf cppzmq && \
    git clone https://github.com/zeromq/cppzmq && \
    cd cppzmq && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j4 install

# Dev third-party packages : Libnmea
RUN cd /tmp && \
    rm -rf libnmea && \
    git clone https://github.com/jacketizer/libnmea && \
    cd libnmea && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j4 install
    
# Dev third-party packages : Spdlog
RUN apt-get install -y \
    libspdlog-dev
    
USER devel

WORKDIR /mnt

# Usage :
# * to rebuild image :
# docker build -t XXXX --build-arg UID=$UID --build-arg GID=`id -g` .
# (launch from the folder holding this Dockerfile)
# * to respawn container :
# (from anywhere)
# docker run -it --privileged -v "$PWD":/mnt -v /tmp:/tmp -e DISPLAY=$DISPLAY --network host --rm XXXX

