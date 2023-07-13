#!/bin/bash

if [ $# -ne 2 ] ; then 
     echo "Usage: $0 <Qt Account Login> <Qt Account Password>"
     echo ""
     exit -1
fi

P_UID=`id -u`
P_GID=`id -g`

IMAGE_NAME="dev-qtx"
echo "Building Docker image $IMAGE_NAME ..."

DIR_ROOT=`dirname $(readlink -f $0)`
cd $DIR_ROOT

# Use '--no-cache' if needed.
docker build --no-cache --tag $IMAGE_NAME --build-arg UID=$P_UID --build-arg GID=$P_GID --build-arg QT_ACCOUNT_LOGIN=$1 --build-arg QT_ACCOUNT_PASSWD=$2 .

echo "FINISHED."
cd -

