#!/bin/bash

[[ -d basho.leveldb ]] || git clone https://github.com/basho/leveldb basho.leveldb
cd basho.leveldb
git checkout 2.1.3
make

cd ..
mkdir -p bin
