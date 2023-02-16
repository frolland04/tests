#
# --------------------
# |      dev-cpp     |
# --------------------
#

FROM ubuntu:latest

# Unless specified something else as arguments, final user is 'devel:build'
# (defaulted to 10000:10000).
ARG UID=10000
ARG GID=10000

# Keep docker build fully automated
# *********************************
ENV DEBIAN_FRONTEND=noninteractive 

# Package manager setup
# *********************
RUN apt-get update --fix-missing && apt-get install -f && apt-get install -y \
    apt-utils \
    apt-transport-https
    
# Base packages for toolchaining & debug from shell
# *************************************************
RUN apt-get install -y \
    build-essential    \
    cmake              \
    ninja-build        \
    pkg-config         \
    git                \
    git-lfs            \
    python3            \
    python3-venv       \
    bison              \
    flex               \
    sudo               \
    dialog             \
    pv                 \
    nano               \
    vim                \
    doxygen            \
    gdb                \
    cppcheck           \
    valgrind           \
    heaptrack          \
    clazy              \
    clang-tidy         \
    htop               \
    linux-tools-common \
    sysvbanner         \
    tree               \
    wget               \
    curl               \
    jq                 \
    p7zip-full         \
    unzip              \
    cpio               \
    xz-utils           \
    rsync              \
    diffstat           \
    chrpath            \
    socat              \
    locales            \
    debianutils        \
    debtree            \
    graphviz           \
    findutils          \
    file               \
    time               \
    fontconfig         \
    strace             \
    ltrace             \
    lsof               \
    patchelf           \
    iputils-ping       \
    iproute2           \
    net-tools          \
    traceroute         \
    iperf              \
    libssl-dev         \
    sqlite3            \
    libsqlite3-dev     \
    rrdtool            \
    librrd-dev         \
    can-utils          \
    libdbus-1-dev      \
    ccrypt             \
    dos2unix           \
    psmisc             \
    gpg

# Set the locale & timezone
# *************************
ENV LC="fr_FR.UTF-8"

RUN sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# fr_FR.UTF-8 UTF-8/fr_FR.UTF-8 UTF-8/' /etc/locale.gen && \
    echo 'LANG="fr_FR.UTF-8"' > /etc/default/locale && \
    dpkg-reconfigure locales && \
    update-locale LANG=$LC
    
ENV TZ="Europe/Paris"

RUN ln -fs /usr/share/zoneinfo/$TZ /etc/localtime && \
    apt-get -y install tzdata && \
    dpkg-reconfigure tzdata
    
ENV LANG=$LC
ENV LANGUAGE=$LC
ENV LC_ALL=$LC

# Accounts
# ********
# 'devel' passwd is 'devel'
RUN groupadd -g $GID build && useradd -p UZu.giVcrobhI -G sudo,build,adm -u $UID devel

RUN mkdir -p /home/devel && cd /home/devel && chown -R devel:build . && chmod g+w .

# Specific system packages
# ************************
RUN apt-get install -y \
    systemd \
    dbus

# Dev tool packages
# *****************
RUN apt-get install -y \
    meld               \
    gedit              \
    kate               \
    terminator         \
    terminology        \
    cool-retro-term    \
    konsole            \
    gitk               \
    git-gui            \
    git-cola           \
    kcachegrind        \
    hotspot            \
    d-feet             \
    wireshark
    
RUN groupadd wireshark && usermod -a -G wireshark devel
    
# Main IDE and associated tools
# *****************************
RUN apt-get install -y \
    qtcreator                        \
    gammaray                         \
    gammaray-plugin-positioning      \
    gammaray-plugin-bluetooth        \
    gammaray-plugin-quickinspector   \ 
    gammaray-plugin-waylandinspector
    
# Visual Studio Code
# ******************
RUN wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg && \
    install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg && \
    sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list' && \
    rm -f packages.microsoft.gpg && apt-get update && apt-get install -y code

# Specific Python 3 packages and tools
# ************************************
RUN apt-get install -y \    
    python3-pip        \
    python3-pipdeptree \
    python3-apt        \
    python3-gi         \
    python3-dev        \
    libglib2.0-dev     \
    python3-gst-1.0

USER devel
RUN mkdir -p /home/devel/.local/bin
ENV PATH="${PATH}:/home/devel/.local/bin"

RUN pip3 install --upgrade \
    pip \
    setuptools \
    meson
    
RUN pip3 install --upgrade \
    black  \
    pylint \
    mypy
     
RUN pip3 install --upgrade \
    serial \
    mysql.connector \
    dbus-python

USER root
    
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
    
# Dev third-party packages : LMDB
# **************************************
RUN apt-get install -y \
    liblmdb-dev \
    liblmdb++-dev \
    lmdb-utils \
    python3-lmdb \
    python3-zlmdb
    
# Dev third-party packages : Mosquitto MQTT
# *****************************************
RUN apt-get install -y \
    mosquitto \
    libmosquitto-dev

# Dev third-party packages : Paho MQTT
# ************************************
RUN apt-get install -y \
    libpaho-mqtt-dev \    
    libpaho-mqttpp-dev \
    python3-paho-mqtt \
    paho.mqtt.c-examples

# Polishing end-user environnement
# ********************************
ENV DEBIAN_FRONTEND=dialog
RUN apt-get clean
RUN chmod 777 /opt

WORKDIR /mnt

# Usage :
# * to rebuild this image :
# docker build -t dev-cpp --build-arg UID=`id -u` --build-arg GID=`id -g` .
# (launch from the folder holding this Dockerfile)
#
# * to respawn a fresh container :
# (from anywhere)
# docker run -it --privileged -v "$PWD":/mnt -v /tmp:/tmp -e DISPLAY=$DISPLAY --network host --rm dev-cpp

