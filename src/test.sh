#!/bin/sh

# Copyright (c) 2019-2023 BUGSENG srl
# See LICENSE.txt for details.

set -e

# Make sure that ${GCC} expands to GCC/x86_64 version 9, 10 or 11.
GCC=gcc-9

"${GCC}" -w main.c -o a.out
max=56623103
success=yes
for value in $(seq 0 1000 ${max})
do
    echo "${value}"
    options=$(./a.out "${value}")
    echo "${options}"
    "${GCC}" -g -w ${options} main.c -o ${value}.out
    result=$(./"${value}".out)
    echo "${result}"
    if [ "${result}" -ne "${value}" ]
    then
        success=no
        break
    fi
done
if [ "${success}" = "yes" ]
then
    echo "tests 0..${max} succeeded"
else
    echo "test ${value} failed"
fi
