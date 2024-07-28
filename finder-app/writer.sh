#!/bin/bash

if [ "$#" -ne 2 ]
then
    echo "Incorrect arguments. Please enter the aruments [FILESDIR], [WRITESTR]"
    exit 1
fi 

directoryName=$(dirname $1)

if [ ! -d "$directoryName" ]
then 
    mkdir -p $directoryName
fi

(echo "$2") > "$1"

