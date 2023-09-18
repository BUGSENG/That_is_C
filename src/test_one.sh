#!/bin/sh

# Copyright (c) 2019-2023 BUGSENG srl
# See LICENSE.txt for details.

set -e

# Make sure that $GCC expands to GCC/x86_64 version 9, 10 or 11.
GCC=gcc-9

usage() {
    echo "Usage: $0 N" >&2
    exit 2
}

[ $# -eq 1 ] || usage

value=$1
options=$(./a.out "${value}")
"$GCC" -g -w $options main.c -o "${value}".out
result=$(./"${value}".out)
if [ "${result}" -ne "${value}" ]
then
    exit 1
fi
rm "${value}".out
exit 0
