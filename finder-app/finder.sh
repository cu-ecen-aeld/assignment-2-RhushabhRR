#!/bin/bash

if [ "$#" -ne 2 ]
then
    echo "Incorrect arguments. Please enter the aruments [FILESDIR], [SEARCHSTR]"
    exit 1
fi 

filesdir="$1"
searchstr="$2"

if [ -d "$filesdir" ]
then
    # number of files indirectoy
    fileCount=$(find "$filesdir" -type f -name '*' | wc -l)
    searchCount=$(grep -r "$searchstr*" "$filesdir"| wc -l)
    echo "The number of files are "$fileCount" and the number of matching lines are "$searchCount""
else
    echo "Specified directory $filesdir does not exist"
    exit 1
fi
