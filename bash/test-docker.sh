#/bin/bash

function error_output()
{
    cat <<< "$@" 1>&2;
}

# Checking Docker runtime is OK
DOCKER_COMMAND_NAME=docker
DOCKER_GROUP_NAME=docker

if ! command -v "${DOCKER_COMMAND_NAME}" &> /dev/null ; then
    error_output "ERROR: command '${DOCKER_COMMAND_NAME}' could not be found!"
    error_output "Please install Docker runtime."
    error_output "Aborting."
    exit 2
fi

if [ ! $(getent group ${DOCKER_GROUP_NAME}) ] ; then
    error_output "ERROR: a '${DOCKER_GROUP_NAME}' user group is missing on your system!"
    error_output "Aborting."
    exit 2
fi

if [ "$(id | grep '('${DOCKER_GROUP_NAME}')')" == "" ] ; then
    error_output "ERROR: User account does not belong to '${DOCKER_GROUP_NAME}' system group!"
    error_output "Aborting."
    exit 2
fi
