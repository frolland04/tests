#!/bin/bash

GID=`id -g`
IMAGE_NAME=dev

echo "Building Docker image $IMAGE_NAME ..."

docker build -t $IMAGE_NAME --build-arg UID=$UID --build-arg GID=$GID .

echo "FINISHED."
