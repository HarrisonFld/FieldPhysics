#!/bin/python3
import os
import sys
import shutil

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
BUILD_DIR = SCRIPT_DIR + "/build"

if not os.path.isdir(BUILD_DIR):
    print("Creating directory: " + BUILD_DIR)
    os.mkdir(BUILD_DIR)

call_args = ""

# Handle args
for i in range(len(sys.argv)):
    match sys.argv[i]:
        
        case "--clean-first" | "-cf":
            print("Cleaning build directory: " + BUILD_DIR)
            shutil.rmtree(BUILD_DIR)
            continue

        case "--call-args" | "-a":
            i += 1
            try:
                call_args = sys.argv[i]
            except:
                sys.exit("Expected args after --call-args/-a")
            continue


# Build and run project with cmake
os.system("cmake -S " + SCRIPT_DIR + " -B " + BUILD_DIR)
os.system("cmake --build " + BUILD_DIR)
print(BUILD_DIR + "/RaylibProj " + call_args)
os.system(BUILD_DIR + "/RaylibProj " + call_args) # Run executable