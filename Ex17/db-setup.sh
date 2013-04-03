#!/bin/bash
set -e
rm -f test.dat
./ex17 test.dat c
./ex17 test.dat s 1 john john@doe.com
./ex17 test.dat s 2 jane jane@doe.com
./ex17 test.dat s 3 jill jill@doe.com

