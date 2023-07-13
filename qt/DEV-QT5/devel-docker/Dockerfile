#
# -----------------
# |    dev-qt5    |
# -----------------
#

FROM ubuntu:22.04

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
    
# Main IDE and associated tools
# *****************************
RUN apt-get install -y \
    qtcreator                        \
    gammaray                         \
    gammaray-plugin-positioning      \
    gammaray-plugin-bluetooth        \
    gammaray-plugin-quickinspector   \ 
    gammaray-plugin-waylandinspector
    
# Qt5 deps packages
# *****************
RUN apt-get install -y \
    libxrender1             \
    libxcb-render0          \
    libxcb-render-util0     \
    libxcb-shape0           \
    libxcb-randr0           \
    libxcb-xfixes0          \
    libxcb-xkb1             \
    libxcb-sync1            \
    libxcb-shm0             \
    libxcb-icccm4           \
    libxcb-keysyms1         \
    libxcb-image0           \
    libxcb-util1            \
    libxcb-cursor0          \
    libxkbcommon0           \
    libxkbcommon-x11-0      \
    libfontconfig1          \
    libfreetype6            \
    libxext6                \
    libx11-6                \
    libxcb1                 \
    libx11-xcb1             \
    libsm6                  \
    libice6                 \
    libglib2.0-0            \
    libfontconfig1-dev      \
    libfreetype6-dev        \
    libx11-dev              \
    libx11-xcb-dev          \
    libxext-dev             \
    libxfixes-dev           \
    libxi-dev               \
    libxrender-dev          \
    libxcb1-dev             \
    libxcb-cursor-dev       \
    libxcb-glx0-dev         \
    libxcb-keysyms1-dev     \
    libxcb-image0-dev       \
    libxcb-shm0-dev         \
    libxcb-icccm4-dev       \
    libxcb-sync-dev         \
    libxcb-xfixes0-dev      \
    libxcb-shape0-dev       \
    libxcb-randr0-dev       \
    libxcb-render-util0-dev \
    libxcb-util-dev         \
    libxcb-xinerama0-dev    \
    libxcb-xkb-dev          \
    libxkbcommon-dev        \
    libxkbcommon-x11-dev    \
    libatspi2.0-dev         \
    libgl1-mesa-dev

# Qt5 dev and tooling packages
# ****************************
RUN apt-get install -y \
    gstreamer1.0-qt5                           \
    libdbusextended-qt5-1                      \
    libdbusextended-qt5-dev                    \
    libdbusmenu-qt5-dev                        \
    libphonon4qt5-4                            \
    libphonon4qt5-data                         \
    libphonon4qt5-dev                          \
    libpyside2-dev                             \
    libqca-qt5-2                               \
    libqca-qt5-2-dev                           \
    libqca-qt5-2-plugins                       \
    libqcoro5core0                             \
    libqcoro5dbus0                             \
    libqcoro5network0                          \
    libqt53danimation5                         \
    libqt53dcore5                              \
    libqt53dextras5                            \
    libqt53dinput5                             \
    libqt53dlogic5                             \
    libqt53dquick5                             \
    libqt53dquickanimation5                    \
    libqt53dquickextras5                       \
    libqt53dquickinput5                        \
    libqt53dquickrender5                       \
    libqt53dquickscene2d5                      \
    libqt53drender5                            \
    libqt5bluetooth5                           \
    libqt5bluetooth5-bin                       \
    libqt5charts5                              \
    libqt5charts5-dev                          \
    libqt5datavisualization5                   \
    libqt5datavisualization5-dev               \
    libqt5feedback5                            \
    libqt5gamepad5                             \
    libqt5gamepad5-dev                         \
    libqt5hunspellinputmethod5                 \
    libqt5keychain1                            \
    libqt5location5                            \
    libqt5location5-plugin-mapboxgl            \
    libqt5location5-plugins                    \
    libqt5multimedia5                          \
    libqt5multimedia5-plugins                  \
    libqt5multimediagsttools5                  \
    libqt5multimediaquick5                     \
    libqt5multimediawidgets5                   \
    libqt5networkauth5                         \
    libqt5networkauth5-dev                     \
    libqt5nfc5                                 \
    libqt5opengl5                              \
    libqt5opengl5-dev                          \
    libqt5pdf5                                 \
    libqt5pdfwidgets5                          \
    libqt5positioning5-plugins                 \
    libqt5positioningquick5                    \
    libqt5publishsubscribe5                    \
    libqt5quickparticles5                      \
    libqt5quickshapes5                         \
    libqt5remoteobjects5                       \
    libqt5remoteobjects5-bin                   \
    libqt5remoteobjects5-dev                   \
    libqt5script5                              \
    libqt5scripttools5                         \
    libqt5scxml5                               \
    libqt5scxml5-bin                           \
    libqt5scxml5-dev                           \
    libqt5scxml5-private-dev                   \
    libqt5sensors5-dev                         \
    libqt5serialbus5                           \
    libqt5serialbus5-bin                       \
    libqt5serialbus5-dev                       \
    libqt5serialbus5-plugins                   \
    libqt5serialport5-dev                      \
    libqt5serviceframework5                    \
    libqt5sql5-ibase                           \
    libqt5sql5-mysql                           \
    libqt5sql5-odbc                            \
    libqt5sql5-psql                            \
    libqt5sql5-tds                             \
    libqt5svg5-dev                             \
    libqt5systeminfo5                          \
    libqt5texttospeech5-dev                    \
    libqt5virtualkeyboard5                     \
    libqt5virtualkeyboard5-dev                 \
    libqt5waylandclient5-dev                   \
    libqt5waylandcompositor5-dev               \
    libqt5webchannel5-dev                      \
    libqt5webengine-data                       \
    libqt5webengine5                           \
    libqt5webenginecore5                       \
    libqt5webenginewidgets5                    \
    libqt5webkit5-dev                          \
    libqt5websockets5                          \
    libqt5websockets5-dev                      \
    libqt5webview5                             \
    libqt5webview5-dev                         \
    libqt5x11extras5-dev                       \
    libqt5xmlpatterns5-dev                     \
    libqwt-qt5-6                               \
    libqwt-qt5-dev                             \
    libqwtplot3d-qt5-0                         \
    pyqt5-dev                                  \
    pyqt5-dev-tools                            \
    pyqt5-examples                             \
    pyqt5chart-dev                             \
    python3-attr                               \
    python3-automat                            \
    python3-bcrypt                             \
    python3-cffi-backend                       \
    python3-click                              \
    python3-colorama                           \
    python3-constantly                         \
    python3-cryptography                       \
    python3-dbus.mainloop.pyqt5                \
    python3-hamcrest                           \
    python3-hyperlink                          \
    python3-idna                               \
    python3-incremental                        \
    python3-mock                               \
    python3-numpy                              \
    python3-openssl                            \
    python3-packaging                          \
    python3-pbr                                \
    python3-pyasn1                             \
    python3-pyasn1-modules                     \
    python3-pyparsing                          \
    python3-pyqt5                              \
    python3-pyqt5.qtbluetooth                  \
    python3-pyqt5.qtchart                      \
    python3-pyqt5.qtmultimedia                 \
    python3-pyqt5.qtnfc                        \
    python3-pyqt5.qtopengl                     \
    python3-pyqt5.qtpositioning                \
    python3-pyqt5.qtquick                      \
    python3-pyqt5.qtremoteobjects              \
    python3-pyqt5.qtsensors                    \
    python3-pyqt5.qtserialport                 \
    python3-pyqt5.qtsql                        \
    python3-pyqt5.qtsvg                        \
    python3-pyqt5.qttexttospeech               \
    python3-pyqt5.qtwebchannel                 \
    python3-pyqt5.qtwebengine                  \
    python3-pyqt5.qtwebkit                     \
    python3-pyqt5.qtwebsockets                 \
    python3-pyqt5.qtx11extras                  \
    python3-pyqt5.qtxmlpatterns                \
    python3-pyqt5.qwt                          \
    python3-pyqt5.sip                          \
    python3-pyside2.qt3danimation              \
    python3-pyside2.qt3dcore                   \
    python3-pyside2.qt3dextras                 \
    python3-pyside2.qt3dinput                  \
    python3-pyside2.qt3dlogic                  \
    python3-pyside2.qt3drender                 \
    python3-pyside2.qtcharts                   \
    python3-pyside2.qtconcurrent               \
    python3-pyside2.qtcore                     \
    python3-pyside2.qtdatavisualization        \
    python3-pyside2.qtgui                      \
    python3-pyside2.qthelp                     \
    python3-pyside2.qtlocation                 \
    python3-pyside2.qtmultimedia               \
    python3-pyside2.qtmultimediawidgets        \
    python3-pyside2.qtnetwork                  \
    python3-pyside2.qtopengl                   \
    python3-pyside2.qtopenglfunctions          \
    python3-pyside2.qtpositioning              \
    python3-pyside2.qtprintsupport             \
    python3-pyside2.qtqml                      \
    python3-pyside2.qtquick                    \
    python3-pyside2.qtquickcontrols2           \
    python3-pyside2.qtquickwidgets             \
    python3-pyside2.qtremoteobjects            \
    python3-pyside2.qtscript                   \
    python3-pyside2.qtscripttools              \
    python3-pyside2.qtscxml                    \
    python3-pyside2.qtsensors                  \
    python3-pyside2.qtserialport               \
    python3-pyside2.qtsql                      \
    python3-pyside2.qtsvg                      \
    python3-pyside2.qttest                     \
    python3-pyside2.qttexttospeech             \
    python3-pyside2.qtuitools                  \
    python3-pyside2.qtwebchannel               \
    python3-pyside2.qtwebengine                \
    python3-pyside2.qtwebenginecore            \
    python3-pyside2.qtwebenginewidgets         \
    python3-pyside2.qtwebsockets               \
    python3-pyside2.qtwidgets                  \
    python3-pyside2.qtx11extras                \
    python3-pyside2.qtxml                      \
    python3-pyside2.qtxmlpatterns              \
    python3-qt5reactor                         \
    python3-qtpy                               \
    python3-qwt3d-qt5                          \
    qca-qt5-2-utils                            \
    qcoro-doc                                  \
    qcoro-qt5-dev                              \
    qdbus-qt5                                  \
    qml                                        \
    qml-module-qt-labs-animation               \
    qml-module-qt-labs-calendar                \
    qml-module-qt-labs-location                \
    qml-module-qt-labs-qmlmodels               \
    qml-module-qt-labs-sharedimage             \
    qml-module-qt-labs-wavefrontmesh           \
    qml-module-qt-websockets                   \
    qml-module-qt3d                            \
    qml-module-qtaudioengine                   \
    qml-module-qtbluetooth                     \
    qml-module-qtcharts                        \
    qml-module-qtcontacts                      \
    qml-module-qtdatavisualization             \
    qml-module-qtfeedback                      \
    qml-module-qtgamepad                       \
    qml-module-qtgstreamer                     \
    qml-module-qtlocation                      \
    qml-module-qtmultimedia                    \
    qml-module-qtnfc                           \
    qml-module-qtorganizer                     \
    qml-module-qtpositioning                   \
    qml-module-qtpublishsubscribe              \
    qml-module-qtqml-statemachine              \
    qml-module-qtqml-workerscript2             \
    qml-module-qtquick-controls                \
    qml-module-qtquick-controls2               \
    qml-module-qtquick-dialogs                 \
    qml-module-qtquick-extras                  \
    qml-module-qtquick-layouts                 \
    qml-module-qtquick-localstorage            \
    qml-module-qtquick-particles2              \
    qml-module-qtquick-pdf                     \
    qml-module-qtquick-privatewidgets          \
    qml-module-qtquick-scene2d                 \
    qml-module-qtquick-scene3d                 \
    qml-module-qtquick-shapes                  \
    qml-module-qtquick-templates2              \
    qml-module-qtquick-virtualkeyboard         \
    qml-module-qtquick-window2                 \
    qml-module-qtquick-xmllistmodel            \
    qml-module-qtquick2                        \
    qml-module-qtremoteobjects                 \
    qml-module-qtscxml                         \
    qml-module-qtsensors                       \
    qml-module-qtserviceframework              \
    qml-module-qtsysteminfo                    \
    qml-module-qttest                          \
    qml-module-qtwayland-client-texturesharing \
    qml-module-qtwayland-compositor            \
    qml-module-qtwebchannel                    \
    qml-module-qtwebengine                     \
    qml-module-qtwebkit                        \
    qml-module-qtwebsockets                    \
    qml-module-qtwebview                       \
    qt3d-assimpsceneimport-plugin              \
    qt3d-defaultgeometryloader-plugin          \
    qt3d-gltfsceneio-plugin                    \
    qt3d-scene2d-plugin                        \
    qt3d5-dev                                  \
    qt3d5-dev-tools                            \
    qt3d5-doc-html                             \
    qt3d5-examples                             \
    qt5-doc-html                               \
    qt5-image-formats-plugin-pdf               \
    qt5-image-formats-plugins                  \
    qt5-qmake                                  \
    qt5-qmake-bin                              \
    qt5-quick-demos                            \
    qt5-style-plugin-cleanlooks                \
    qt5-style-plugin-motif                     \
    qt5-style-plugin-plastique                 \
    qt5-style-plugins                          \
    qt5ct                                      \
    qt5keychain-dev                            \
    qt5serialport-examples                     \
    qtbase5-dev                                \
    qtbase5-doc-dev                            \
    qtbase5-doc-html                           \
    qtbase5-examples                           \
    qtbase5-private-dev                        \
    qtcharts5-doc-html                         \
    qtcharts5-examples                         \
    qtconnectivity5-dev                        \
    qtconnectivity5-doc-html                   \
    qtconnectivity5-examples                   \
    qtdatavisualization5-doc-html              \
    qtdatavisualization5-examples              \
    qtdeclarative5-dev                         \
    qtdeclarative5-doc-dev                     \
    qtdeclarative5-doc-html                    \
    qtdeclarative5-examples                    \
    qtdeclarative5-private-dev                 \
    qtfeedback5-dev                            \
    qtfeedback5-examples                       \
    qtgamepad5-doc-html                        \
    qtgamepad5-examples                        \
    qtgraphicaleffects5-doc-html               \
    qtkeychain-qt5-dev                         \
    qtlocation5-dev                            \
    qtlocation5-doc-dev                        \
    qtlocation5-doc-html                       \
    qtlocation5-examples                       \
    qtmultimedia5-dev                          \
    qtmultimedia5-doc-html                     \
    qtmultimedia5-examples                     \
    qtnetworkauth5-doc-html                    \
    qtnetworkauth5-examples                    \
    qtpdf5-dev                                 \
    qtpdf5-doc                                 \
    qtpdf5-doc-html                            \
    qtpdf5-examples                            \
    qtpim5-dev                                 \
    qtpim5-doc                                 \
    qtpim5-doc-html                            \
    qtpim5-examples                            \
    qtpositioning5-dev                         \
    qtquickcontrols2-5-dev                     \
    qtquickcontrols2-5-doc-html                \
    qtquickcontrols2-5-examples                \
    qtquickcontrols2-5-private-dev             \
    qtquickcontrols5-doc-html                  \
    qtquickcontrols5-examples                  \
    qtremoteobjects5-doc                       \
    qtremoteobjects5-doc-html                  \
    qtremoteobjects5-examples                  \
    qtscript5-dev                              \
    qtscript5-doc-html                         \
    qtscript5-examples                         \
    qtscxml5-doc-html                          \
    qtscxml5-examples                          \
    qtsensors5-doc-html                        \
    qtsensors5-examples                        \
    qtserialbus5-doc-html                      \
    qtserialbus5-examples                      \
    qtserialport5-doc-html                     \
    qtspeech5-doc                              \
    qtspeech5-doc-html                         \
    qtspeech5-examples                         \
    qtspeech5-flite-plugin                     \
    qtsvg5-doc-html                            \
    qtsvg5-examples                            \
    qtsystems5-dev                             \
    qtsystems5-examples                        \
    qtsystems5-private-dev                     \
    qtsystems5-tools                           \
    qttools5-dev                               \
    qttools5-doc-html                          \
    qttools5-examples                          \
    qttools5-private-dev                       \
    qtvirtualkeyboard-plugin                   \
    qtvirtualkeyboard5-doc-html                \
    qtvirtualkeyboard5-examples                \
    qtwayland5-dev-tools                       \
    qtwayland5-doc-html                        \
    qtwayland5-examples                        \
    qtwayland5-private-dev                     \
    qtwebchannel5-doc-html                     \
    qtwebchannel5-examples                     \
    qtwebengine5-dev                           \
    qtwebengine5-dev-tools                     \
    qtwebengine5-doc-html                      \
    qtwebengine5-examples                      \
    qtwebengine5-private-dev                   \
    qtwebsockets5-doc-html                     \
    qtwebsockets5-examples                     \
    qtwebview5-doc-html                        \
    qtwebview5-examples                        \
    qtx11extras5-doc-html                      \
    qtxmlpatterns5-doc-html                    \
    qtxmlpatterns5-examples

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
# docker build -t dev-qt5 --build-arg UID=`id -u` --build-arg GID=`id -g` .
# (launch from the folder holding this Dockerfile)
#
# * to respawn a fresh container :
# (from anywhere)
# docker run -it --privileged -v "$PWD":/mnt -v /tmp:/tmp -e DISPLAY=$DISPLAY --network host --rm dev-qt5

