#!/bin/sh

# Copyright (c) 2019-2023 BUGSENG srl
# See LICENSE.txt for details.

set -e

# Make sure that $GCC expands to GCC/x86_64 at least version 8.
GCC=gcc-8

"$GCC" -w main.c -o a.out
max=767
success=yes
for value in $(seq 0 $max)
do
    #echo $value
    options=$(./a.out $value)
    #echo $options
    "$GCC" -w $options main.c -o $value.out
    result=$(./$value.out)
    #echo $result
    if [ "$result" -ne "$value" ]
    then
        success=no
        break
    fi
done
if [ "$success" = "yes" ]
then
    echo "tests 0..$max succeeded"
else
    echo "test $value failed"
fi
