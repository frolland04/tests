#!/bin/bash

set -aeu -o pipefail

# --- Helper functions --------------------------------------------------------------------
# -----------------------------------------------------------------------------------------

function error_output()
{
    cat <<< "$@" 1>&2;
}

# ----------------------------------------------------------------------------------------

readonly PYTHON_VERSIONS=$(cat << EOF
3.7.17
3.8.19
3.9.19
3.10.14
3.11.9
3.12.4
EOF
)

readonly VARIANTS=$(cat << EOF
Debian_11
Debian_12
Ubuntu_20.04
Ubuntu_22.04
Ubuntu_24.04
EOF
)

function build_python()
{
    local host_os=$1
    local python_stable=$2

    echo "Build on ${host_os}, Python ${python_stable}"
    sleep 2
}

# for OS_VARIANT in ${VARIANTS} ; do
#     for PV in ${PYTHON_VERSIONS} ; do
#         build_python ${OS_VARIANT} ${PV}
#     done
# done

# System-wide commands
for cmd in 'parallel' ; do
    if ! command -v "${cmd}" &> /dev/null ; then
        error_output "ERROR: '${cmd}' is not installed !"
        error_output "Exiting."
        exit 2
    fi
done

parallel --shuf --delay 10 build_python {2} {1} ::: ${PYTHON_VERSIONS} ::: ${VARIANTS}
