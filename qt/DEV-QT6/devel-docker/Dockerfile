#
# -----------------
# |    dev-qt6    |
# -----------------
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
RUN apt-get update && apt-get install -y \
    apt-utils
    
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
    can-utils

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
RUN groupadd -g $GID build && useradd -p UZu.giVcrobhI -G sudo,build -u $UID devel

RUN mkdir -p /home/devel && cd /home/devel && chown -R devel:build . && chmod g+w .

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
    d-feet
    
# Main IDE and associated tools
# *****************************
RUN apt-get install -y \
    qtcreator                        \
    gammaray                         \
    gammaray-plugin-positioning      \
    gammaray-plugin-bluetooth        \
    gammaray-plugin-quickinspector   \ 
    gammaray-plugin-waylandinspector
    
# Qt6 deps packages
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

# Qt6 dev and tooling packages
# ****************************
RUN apt-get install -y \
    assistant-qt6                               \
    designer-qt6                                \
    libqcoro6core0                              \
    libqcoro6dbus0                              \
    libqcoro6network0                           \
    libqt6bodymovin6-dev                        \
    libqt6charts6-dev                           \
    libqt6chartsqml6                            \
    libqt6core5compat6-dev                      \
    libqt6datavisualization6-dev                \
    libqt6hunspellinputmethod6                  \
    libqt6keychain1                             \
    libqt6networkauth6-dev                      \
    libqt6opengl6-dev                           \
    libqt6qml6                                  \
    libqt6quicktimeline6-dev                    \
    libqt6remoteobjectsqml6                     \
    libqt6scxmlqml6                             \
    libqt6sensors6-dev                          \
    libqt6serialbus6-bin                        \
    libqt6serialbus6-dev                        \
    libqt6serialport6-dev                       \
    libqt6shadertools6-dev                      \
    libqt6sql6-ibase                            \
    libqt6sql6-mysql                            \
    libqt6sql6-odbc                             \
    libqt6sql6-psql                             \
    libqt6sql6-sqlite                           \
    libqt6statemachineqml6                      \
    libqt6svg6-dev                              \
    libqt6virtualkeyboard6-dev                  \
    libqt6webchannel6-dev                       \
    libqt6webenginecore6-bin                    \
    libqt6webenginequickdelegatesqml6           \
    libqt6websockets6-dev                       \
    linguist-qt6                                \
    qcoro-qt6-dev                               \
    qml-qt6                                     \
    qml6-module-qt-labs-animation               \
    qml6-module-qt-labs-folderlistmodel         \
    qml6-module-qt-labs-lottieqt                \
    qml6-module-qt-labs-platform                \
    qml6-module-qt-labs-qmlmodels               \
    qml6-module-qt-labs-settings                \
    qml6-module-qt-labs-sharedimage             \
    qml6-module-qt-labs-wavefrontmesh           \
    qml6-module-qt3d-animation                  \
    qml6-module-qt3d-core                       \
    qml6-module-qt3d-extras                     \
    qml6-module-qt3d-input                      \
    qml6-module-qt3d-logic                      \
    qml6-module-qt3d-render                     \
    qml6-module-qt5compat-graphicaleffects      \
    qml6-module-qtcharts                        \
    qml6-module-qtcore                          \
    qml6-module-qtdatavisualization             \
    qml6-module-qtmultimedia                    \
    qml6-module-qtpositioning                   \
    qml6-module-qtqml                           \
    qml6-module-qtqml-models                    \
    qml6-module-qtqml-statemachine              \
    qml6-module-qtqml-workerscript              \
    qml6-module-qtqml-xmllistmodel              \
    qml6-module-qtquick                         \
    qml6-module-qtquick-controls                \
    qml6-module-qtquick-dialogs                 \
    qml6-module-qtquick-layouts                 \
    qml6-module-qtquick-localstorage            \
    qml6-module-qtquick-nativestyle             \
    qml6-module-qtquick-particles               \
    qml6-module-qtquick-pdf                     \
    qml6-module-qtquick-scene2d                 \
    qml6-module-qtquick-scene3d                 \
    qml6-module-qtquick-shapes                  \
    qml6-module-qtquick-templates               \
    qml6-module-qtquick-timeline                \
    qml6-module-qtquick-tooling                 \
    qml6-module-qtquick-virtualkeyboard         \
    qml6-module-qtquick-window                  \
    qml6-module-qtremoteobjects                 \
    qml6-module-qtscxml                         \
    qml6-module-qtsensors                       \
    qml6-module-qttest                          \
    qml6-module-qtwayland-client-texturesharing \
    qml6-module-qtwayland-compositor            \
    qml6-module-qtwebchannel                    \
    qml6-module-qtwebengine                     \
    qml6-module-qtwebengine-controlsdelegates   \
    qml6-module-qtwebsockets                    \
    qml6-module-qtwebview                       \
    qml6-module-quick3d                         \
    qml6-module-quick3d-assetutils              \
    qml6-module-quick3d-effects                 \
    qml6-module-quick3d-helpers                 \
    qml6-module-quick3d-particles3d             \
    qmlscene-qt6                                \
    qt6-3d-assimpsceneimport-plugin             \
    qt6-3d-defaultgeometryloader-plugin         \
    qt6-3d-dev                                  \
    qt6-3d-gltfsceneio-plugin                   \
    qt6-3d-scene2d-plugin                       \
    qt6-base-dev                                \
    qt6-base-dev-tools                          \
    qt6-base-private-dev                        \
    qt6-connectivity-dev                        \
    qt6-declarative-dev                         \
    qt6-declarative-dev-tools                   \
    qt6-declarative-private-dev                 \
    qt6-documentation-tools                     \
    qt6-image-formats-plugin-pdf                \
    qt6-image-formats-plugins                   \
    qt6-l10n-tools                              \
    qt6-multimedia-dev                          \
    qt6-pdf-dev                                 \
    qt6-positioning-dev                         \
    qt6-quick3d-assetimporters-plugin           \
    qt6-quick3d-dev                             \
    qt6-quick3d-dev-tools                       \
    qt6-remoteobjects-dev                       \
    qt6-scxml-dev                               \
    qt6-tools-dev                               \
    qt6-tools-dev-tools                         \
    qt6-tools-private-dev                       \
    qt6-translations-l10n                       \
    qt6-virtualkeyboard-plugin                  \
    qt6-wayland-dev                             \
    qt6-wayland-dev-tools                       \
    qt6-webengine-dev                           \
    qt6-webengine-dev-tools                     \
    qt6-webengine-private-dev                   \
    qt6-webview-dev                             \
    qt6-xdgdesktopportal-platformtheme          \
    qtkeychain-qt6-dev

# Polishing end-user environnement
# ********************************
ENV DEBIAN_FRONTEND=dialog
RUN apt-get clean

WORKDIR /mnt

# Usage :
# * to rebuild this image :
# docker build -t dev-qt6 --build-arg UID=`id -u` --build-arg GID=`id -g` .
# (launch from the folder holding this Dockerfile)
#
# * to respawn a fresh container :
# (from anywhere)
# docker run -it --privileged -v "$PWD":/mnt -v /tmp:/tmp -e DISPLAY=$DISPLAY --network host --rm dev-qt6

