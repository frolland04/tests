#
# -----------------
# |    dev-qtx    |
# -----------------
#

FROM ubuntu:22.04

# Unless specified something else as arguments, final user is 'devel:build'
# (defaulted to 10000:10000).
ARG UID=10000
ARG GID=10000

# Specific account ID for Qt licensing (login and passwd)
ARG QT_ACCOUNT_LOGIN
ARG QT_ACCOUNT_PASSWD

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
    clang-format       \
    htop               \
    linux-tools-common \
    sysvbanner         \
    tree               \
    wget               \
    curl               \
    libcurl4           \
    libcurl4-openssl-dev \ 
    jq                 \
    p7zip-full         \
    libarchive-dev     \
    libarchive-tools   \
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
    openssl            \
    libssl-dev         \
    sqlite3            \
    libsqlite3-dev     \
    rrdtool            \
    librrd-dev         \
    nghttp2            \
    libnghttp2-dev     \
    can-utils          \
    libdbus-1-dev      \
    ccrypt             \
    dos2unix           \
    psmisc             \
    libgtest-dev       \
    gpg                \
    libgcrypt20-dev    \
    netcat             \
    fuse

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
RUN groupadd -g $GID build && useradd -p UZu.giVcrobhI -G sudo,build,adm -u $UID -s /bin/bash devel

RUN mkdir -p /home/devel && cd /home/devel && chown -R devel:build . && chmod g+w .

# Specific system packages
# ************************
RUN apt-get install -y \
    systemd \
    libsystemd-dev \
    dbus \
    libdbus-1-dev 

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
    wireshark          \
    audacity           \
    alsa-utils         \
    pulseaudio         \
    sox
    
RUN groupadd wireshark && usermod -a -G wireshark devel

# Qt packages from official installer
# ***********************************
ENV QT_ROOT_INSTALL_DIR=/opt/Qt
ENV QT_INSTALLER_FILE=qt-unified-linux-x64.run

COPY ./devel/${QT_INSTALLER_FILE} /tmp/${QT_INSTALLER_FILE}
RUN /tmp/${QT_INSTALLER_FILE} \
    install \
    qt.tools.maintenance \
    qt.qt5.5152 \
    qt.qt6.642 \
    qt.tools.cmake \
    qt.tools.ninja \
    qt.tools.ifw \
    qt.tools.qt3dstudio \
    qt.tools.qtcreator \
    qt.tools.qtcreator_gui \
    qt.tools.qtdesignstudio \
    --root $QT_ROOT_INSTALL_DIR \
    --auto-answer telemetry-question=No,AssociateCommonFiletypes=Yes \
    --default-answer \
    --accept-licenses \
    --accept-obligations \
    --email ${QT_ACCOUNT_LOGIN} \
    --pw ${QT_ACCOUNT_PASSWD}\
    --confirm-command
RUN rm /tmp/$QT_INSTALLER_FILE

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

# Conan builder tool
# ******************
RUN pip3 install --upgrade conan==1.59.0

# GStreamer dev packages
# **********************
RUN apt install -y \
    pkg-config \
    libgstreamer1.0-dev \
    libgstreamer-plugins-base1.0-dev \
    libgstreamer-plugins-bad1.0-dev \
    gstreamer1.0-plugins-base \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-ugly \
    gstreamer1.0-libav \
    gstreamer1.0-tools \
    gstreamer1.0-x \
    gstreamer1.0-alsa \
    gstreamer1.0-gl \
    gstreamer1.0-gtk3 \
    gstreamer1.0-qt5 \
    gstreamer1.0-pulseaudio \
    libasound2-dev \
    portaudio19-dev \
    libfaad-dev \
    libopus0 \
    ffmpeg

# Google chrome
# *************
RUN cd /tmp && wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb && \
    apt-get install -y libu2f-udev && \
    dpkg -i google-chrome-stable_current_amd64.deb && rm /tmp/google-chrome-stable_current_amd64.deb

# Specific dev packages
# *********************
RUN apt install -y      \
    libspdlog-dev       \
    nlohmann-json3-dev

# Polishing end-user environnement
# ********************************
ENV DEBIAN_FRONTEND=dialog
RUN apt-get clean

USER devel
RUN mkdir -p /home/devel/.local/bin
ENV PATH="/home/devel/.local/bin:${PATH}"
RUN conan profile new default --detect --force && \
    conan profile update settings.compiler.libcxx=libstdc++11 default

USER root
RUN ln -sf /usr/bin/python3 /usr/bin/python
RUN chmod a+w /opt
WORKDIR /mnt

# Usage :
# * to rebuild this image :
# docker build -t dev-qtx --build-arg UID=`id -u` --build-arg GID=`id -g` .
# (launch from the folder holding this Dockerfile)
#
# * to respawn a fresh container :
# (from anywhere)
# docker run -it --privileged -v "$PWD":/mnt -v /tmp:/tmp -e DISPLAY=$DISPLAY --network host --rm dev-qtx
