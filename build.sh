#!/bin/bash
set -e
make clean
make
echo "Build complete:"
ls *.8x*
