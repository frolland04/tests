#!/bin/bash

set -aeux -o pipefail

# --- Helper functions --------------------------------------------------------------------
# -----------------------------------------------------------------------------------------

function usage() {
    echo ""
    echo "Python runtime distribution builder from sources."
    echo ""
    echo "Usage:"
    echo "$(basename $0) [-h|--help] [OPTIONS] <VERSION>"
    echo ""
    echo "Fetch Python sources for a given release, extract them, build and install it as an"
    echo "alternative binary distribution, located in '/usr/local'."
    echo ""
    echo "PARAMETERS:"
    echo "<VERSION>          Tells the Python version you want to get, in the form of X.Y.Z,"
    echo "                   like 3.7.18, 3.10.13 or 3.12.0"
    echo ""
    echo "OPTIONS:"
    echo "-b,--build-only    Extract and build sources, but does not install and clean build tree."
    echo "-i,--install-path  Install path prefix, default is /usr/local."
    echo "-h,--help          Print this help message and exit."
    echo ""
}

function error_output()
{
    cat <<< "$@" 1>&2;
}

# ----------------------------------------------------------------------------------------

# Program options
OPTION_NO_INSTALL=false
OPTION_INSTALL_PATH=""
OPTION_VERSION=""

# Parse input parameters
while (( "$#" )); do
    case "$1" in
        -h|--help)
            usage 1>&2
            exit
            ;;
        -b|--build-only)
            OPTION_NO_INSTALL=true
            shift
            ;;
        -i|--install-path)
            if [[ "$#" -eq 1 ]] || [[ -z "$2" ]] ; then
                error_output "ERROR: -i|--install-path requires an argument."
                error_output "Aborting."
                exit 1
            fi
            OPTION_INSTALL_PATH="$2"
            shift 2
            ;;
        *)
            if [[ ! "$1" =~ ^[0-9].[0-9]([0-9]){0,1}.[0-9]([0-9]){0,1}$ ]] ; then
                error_output "ERROR : please provide the desired Python version, in the form of X.Y.Z, like 3.7.18, 3.10.13 or 3.12.0"
                error_output "Aborting."
                exit 1
            else
                OPTION_VERSION=$1
            fi
            shift
            ;;
    esac
done

# Check parameters
if [[ "${OPTION_VERSION}" == "" ]] ; then
    error_output "ERROR : providing a Python version string is required."
    error_output "Aborting."
    exit 1
else
    PV="${OPTION_VERSION}"
fi

if [[ "${OPTION_INSTALL_PATH}" == "" ]] ; then
    OPTION_INSTALL_PATH="/usr/local"
fi

if [[ ! -d "${OPTION_INSTALL_PATH}" ]] && [[ ${OPTION_NO_INSTALL} == false ]] ; then
    mkdir -p "${OPTION_INSTALL_PATH}"
fi

for cmd in wget gcc g++ make pkg-config gdb lcov ; do
    if ! command -v "${cmd}" &> /dev/null ; then
        error_output "ERROR: '${cmd}' is not installed."
        error_output "Aborting."
        exit 1
    fi
done

echo "*** Download and build Python-${PV}. ***"
echo "*******************************************"

CONFIGURE_PARAMETERS="--with-lto --enable-shared --disable-test-modules "
if [[ "${PV}" != 3.7* ]] ; then
    # Drop performance optimization on Python 3.7.x (too long to build!)
    CONFIGURE_PARAMETERS+=" --enable-optimizations "
fi

cd /usr/src && \
rm -rf Python-${PV}.tgz Python-${PV} && \
wget https://www.python.org/ftp/python/${PV}/Python-${PV}.tgz && \
tar -xzf Python-${PV}.tgz && \
cd Python-${PV} && \
./configure --prefix ${OPTION_INSTALL_PATH} ${CONFIGURE_PARAMETERS} && \
make -j "$(nproc)" && \
if [[ ${OPTION_NO_INSTALL} == false ]] ; then
    echo "*** Installing Python-${PV}. ***"
    echo "***********************************"
    make altinstall && ldconfig ${OPTION_INSTALL_PATH}/lib
    cd /usr/src && rm -rf Python-${PV}.tgz Python-${PV}
else
    echo "Python-${PV} build tree available at /usr/src/Python-${PV}"
fi

echo "FINISHED."

