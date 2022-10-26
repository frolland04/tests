#!/bin/bash

GID=`id -g`
IMAGE_NAME=dev

echo "Building Docker image $IMAGE_NAME ..."

DIR_ROOT=`dirname $(readlink -f $0)`

cd $DIR_ROOT
docker build -t $IMAGE_NAME --build-arg UID=$UID --build-arg GID=$GID .

echo "FINISHED."
cd -

