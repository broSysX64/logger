#!/bin/bash

rm -R build
mkdir build
cd build
cmake ..
make
make test
