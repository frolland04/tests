#!/bin/bash

set -aeu -o pipefail

function get_python_stable_from_branch()
{
    local branch
    readonly branch=$1

    for version in $(echo ${PYTHON_VERSIONS})
    do
        if [ "${branch}" == "$(echo ${version} | cut -d . -f '1-2' )" ] ; then
            echo "${version}"
            return
        fi
    done
    echo "null"
}

# ----------------------------------------------------------------------------------------

# Important variables
readonly DEFAULT_PYTHON_VERSION="3.10"

readonly PYTHON_VERSIONS=$(cat << EOF
3.7.17
3.8.19
3.9.19
3.10.14
3.11.9
3.12.4
EOF
)

PV_STABLE=$(get_python_stable_from_branch '3.7')
echo "PV_STABLE: 3.7 -> ${PV_STABLE}"
PV_STABLE=$(get_python_stable_from_branch '3.8')
echo "PV_STABLE: 3.8 -> ${PV_STABLE}"
PV_STABLE=$(get_python_stable_from_branch '3.9')
echo "PV_STABLE: 3.9 -> ${PV_STABLE}"
PV_STABLE=$(get_python_stable_from_branch '3.10')
echo "PV_STABLE: 3.10 -> ${PV_STABLE}"
PV_STABLE=$(get_python_stable_from_branch '3.11')
echo "PV_STABLE: 3.11 -> ${PV_STABLE}"
PV_STABLE=$(get_python_stable_from_branch '3.12')
echo "PV_STABLE: 3.12 -> ${PV_STABLE}"
PV_STABLE=$(get_python_stable_from_branch '3.13')
echo "PV_STABLE: 3.13 -> ${PV_STABLE}"
PV_STABLE=$(get_python_stable_from_branch '4.2')
echo "PV_STABLE: 4.2 -> ${PV_STABLE}"

