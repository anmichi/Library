#!/bin/bash
# 使い方: ./run.sh x.cpp

g++-14 -std=gnu++23 -O2 -Wall -Wextra -fsanitize=address,undefined  -I ../ac-library -D LOCAL "$1" || exit 1
./a.out