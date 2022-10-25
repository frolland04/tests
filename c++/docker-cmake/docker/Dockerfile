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

# Dev tooling packages
RUN apt-get install -y \
    qtcreator \
    meld \
    doxygen \
    gedit
    
# Dev third-party packages
RUN apt-get install -y \
    libboost-all-dev \
    libboost-doc

USER devel

WORKDIR /mnt

# Usage :
# * to rebuild image :
# docker build -t XXXX --build-arg UID=$UID --build-arg GID=`id -g` .
# (launch from the folder holding this Dockerfile)
# * to respawn container :
# (from anywhere)
# docker run -it --privileged -v "$PWD":/mnt -v /tmp:/tmp -e DISPLAY=$DISPLAY --network host --rm XXXX

