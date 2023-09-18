#!/bin/sh

# Copyright (c) 2019-2023 BUGSENG srl
# See LICENSE.txt for details.

set -e

# Make sure that $GCC expands to GCC/x86_64 version 9, 10 or 11.
export GCC=gcc-9

"${GCC}" -w main.c -o a.out
max=56623103
seq 0 100 "${max}" | parallel --bar --jobs 12 --halt soon,fail=1 ./test_one.sh
rm -f a.out
