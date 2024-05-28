#!/usr/bin/env bash

set -ae -o pipefail

function banana() {
    echo "banana to stdout"
    echo "still on stdout"
    echo >&2 "banana to stderr"
    echo >&2 "still on stderr"
    echo "banana to stdout again"
    return 42;
}

function exec_helper() {
    local -n o=$2
    local -n e=$3
    local -n s=$4
    eval "$({ ee=$({ oo=$($1); ss=$?; } 2>&1; declare -p oo ss >&2); declare -p ee; } 2>&1)"
    o=${oo}
    e=${ee}
    s=${ss}
}

echo "Hello !"

# WITHOUT REDIRECTION TO A TEMPORARY FILE
# ***************************************
#
# . <({ berr=$({ bout=$(banana); bret=$?; } 2>&1; declare -p bout bret >&2); declare -p berr; } 2>&1)
# or
# eval "$({ berr=$({ bout=$(banana); bret=$?; } 2>&1; declare -p bout bret >&2); declare -p berr; } 2>&1)"
#
# echo "stdout: '${bout}'"
# echo "stderr: '${berr}'"
# echo "return: '${bret}'"

# WITH REDIRECTION TO A TEMPORARY FILE
# ************************************
#
# TMP=$(mktemp)
# bout=$(banana 2> "${TMP}")
# berr=$(cat "${TMP}")
# rm "${TMP}"
# 
# echo "stdout: '${bout}'"
# echo "stderr: '${berr}'"

exec_helper "$(banana)" bout berr bret
echo "stdout: '${bout}'"
echo "stderr: '${berr}'"
echo "return: '${bret}'"

echo "Finished."

