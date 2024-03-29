#!/bin/bash

P_UID=`id -u`
P_GID=`id -g`

IMAGE_NAME="dev-qt5"
echo "Building Docker image $IMAGE_NAME ..."

DIR_ROOT=`dirname $(readlink -f $0)`
cd $DIR_ROOT

# Use '--no-cache' if needed.
docker build --no-cache --tag $IMAGE_NAME --build-arg UID=$P_UID --build-arg GID=$P_GID .

echo "FINISHED."
cd -

