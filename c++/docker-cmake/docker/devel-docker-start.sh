#!/bin/bash

IMAGE_NAME=dev

echo "Starting Docker container from '$IMAGE_NAME' ..."
echo "****************************************"
echo ""

cd `dirname $0`

docker run -it --privileged \
    -v $PWD/devel-home:/home/devel \
    -v $PWD/..:/mnt \
    -v /tmp:/tmp    \
    -e DISPLAY=:0   \
    --network host  \
    --rm            \
    $IMAGE_NAME     \
    /mnt/docker/devel-docker-app.sh

echo "FINISHED."

