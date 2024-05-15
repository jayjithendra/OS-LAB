#!/bin/bash
read passed
if [ -d $passed ]; then
	echo "$passed is a directory"
elif [ -f $passed ]; then
	echo "$passed is a file"
else
	echo "$passed is not valid"
	exit 1
fi

