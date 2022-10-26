FROM ubuntu:latest

# Unless specified something else as arguments, user is 'devel:build', (uid:gid is 10000:10000).
ARG UID=10000

ARG GID=10000

# Base packages for toolchaining
# ******************************
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    pkg-config \
    libssl-dev \
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
# *************************
RUN apt-get install -y \
    qtcreator \
    meld \
    doxygen \
    gedit
    
# Dev third-party packages : Boost
# ********************************
RUN apt-get install -y \
    libboost-all-dev \
    libboost-doc

# Dev third-party packages : Cppzmq / Libzmq
# ******************************************
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
# **********************************
RUN cd /tmp && \
    rm -rf libnmea && \
    git clone https://github.com/jacketizer/libnmea && \
    cd libnmea && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j4 install
    
# Dev third-party packages : Spdlog
# *********************************
RUN apt-get install -y \
    libspdlog-dev
    
# Dev third-party packages : JSON for Modern C++
# **********************************************
RUN cd /tmp && \
    rm -rf json && \
    git clone https://github.com/nlohmann/json.git && \
    cd json && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j4 install

# Dev third-party packages : Libcpr
# *********************************
RUN cd /tmp && \
    rm -rf cpr && \
    git clone https://github.com/libcpr/cpr.git && \
    cd cpr && \
    mkdir build && \
    cd build && \
    cmake .. -DCPR_USE_SYSTEM_CURL=OFF && \
    cmake --build . && \
    sudo cmake --install .

# Dev third-party packages : SDBus C++
# ************************************
RUN apt-get install -y \
    sdbus-c++
    
# Dev third-party packages : LibBLE++
# ***********************************
RUN apt-get install -y \
    bluez \
    libbluetooth-dev

RUN cd /tmp && \
    rm -rf libblepp && \
    git clone https://github.com/edrosten/libblepp.git && \
    cd libblepp && \
    mkdir build && \
    cd build && \
    cmake -DWITH_EXAMPLES=ON .. && \
    make -j4 install

# Dev third-party packages : Tinyb
# ********************************
RUN apt-get install -y \
    bluez \
    libbluetooth-dev \
    libglib2.0-dev

RUN cd /tmp && \
    rm -rf tinyb && \
    git clone https://github.com/intel-iot-devkit/tinyb.git && \
    cd tinyb && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j4 install

# Dev third-party packages : Websocket++
# **************************************
RUN cd /tmp && \
    rm -rf websocketpp && \
    git clone https://github.com/zaphoyd/websocketpp.git && \
    cd websocketpp && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j4 install

# Dev third-party packages : CppLinuxSerial
# *****************************************
RUN cd /tmp && \
    rm -rf CppLinuxSerial && \
    git clone https://github.com/gbmhunter/CppLinuxSerial.git && \
    cd CppLinuxSerial && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j4 install

# Dev third-party packages : OpenCV
# *********************************
RUN apt-get install -y \
    libopencv-dev

# Dev third-party packages : POCO
# *******************************
RUN apt-get install -y \
    libpoco-dev

# Dev third-party packages : Protobuf
# ***********************************
RUN apt-get install -y \
    protobuf-compiler protobuf-compiler-grpc

# Dev third-party packages : Cap'n'Proto
# **************************************
RUN apt-get install -y \
    capnproto
    
# Dev third-party packages : Flatbuffers
# **************************************
RUN apt-get install -y \
    flatbuffers-compiler

USER devel

WORKDIR /mnt

# Usage :
# * to rebuild image :
# docker build -t XXXX --build-arg UID=$UID --build-arg GID=`id -g` .
# (launch from the folder holding this Dockerfile)
# * to respawn container :
# (from anywhere)
# docker run -it --privileged -v "$PWD":/mnt -v /tmp:/tmp -e DISPLAY=$DISPLAY --network host --rm XXXX

