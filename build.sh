#!/bin/bash

# This whole script is kind of a pain to manage and defeats the purpose of cmake being multiplatform
# TODO: find a better way to do this

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd)
BUILD_DIR="build/" # specify build directory
BUILD_DIR=$SCRIPT_DIR/$BUILD_DIR # global build directory

if [[ ! -d $BUILD_DIR ]]; then
    mkdir -v $BUILD_DIR
fi

# Generate, Build, and Run the project
cmake -S $SCRIPT_DIR -B $BUILD_DIR
cmake --build $BUILD_DIR
${BUILD_DIR}src/RaylibProj