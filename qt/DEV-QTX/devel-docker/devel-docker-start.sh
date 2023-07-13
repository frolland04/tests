#!/bin/bash

set -aeu -o pipefail 

IMAGE_NAME="dev-qtx"

echo "Starting Docker container from '$IMAGE_NAME' ..."
echo "************************************************"
echo ""

THIS=`readlink -f $0`
START_DIR=`dirname $THIS`
SAVED_DIR=$PWD
cd $START_DIR

# Host folders
DBUS_SESSION_DIR_H=`echo $DBUS_SESSION_BUS_ADDRESS | cut -d "=" -f 2`
ROOT_DIR_H=$SAVED_DIR
DOCKER_DIR_H=$START_DIR
DEVEL_DIR_H=$DOCKER_DIR_H/devel

# Container folders
ROOT_DIR_D=/mnt/host
DOCKER_DIR_D=/mnt/`basename $START_DIR`
DEVEL_DIR_D=/home/devel

echo "$ROOT_DIR_H => $ROOT_DIR_D"
echo

docker run --interactive --tty --privileged \
    -v $ROOT_DIR_H:$ROOT_DIR_D \
    -v $DOCKER_DIR_H:$DOCKER_DIR_D \
    -v $DEVEL_DIR_H:$DEVEL_DIR_D \
    -v /tmp:/tmp \
    -v /dev:/dev \
    -v $DBUS_SESSION_DIR_H:$DBUS_SESSION_DIR_H \
    --env DISPLAY=:0 \
    --env DBUS_SESSION_BUS_ADDRESS="$DBUS_SESSION_BUS_ADDRESS" \
    --network host  \
    --rm            \
    $IMAGE_NAME     \
    $DOCKER_DIR_D/devel-docker-app.sh

echo "FINISHED."

