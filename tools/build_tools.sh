#!/bin/bash
#A simple script that builds/runs the project/tests via cmake
#NOTE: script must be run from the base directory of the project

COMMAND=$1

case $COMMAND in
    build)
        echo -e "Building project..."
        cmake -S . -B build
        cmake --build build
        ;;
    run)
        echo -e "Running project...\n"
        ./build/project_exec
        ;;
    test)
        echo -e "Testing project...\n"
        ./build/project_tests
        ;;
    *)
        echo "Unknown command '$1'!"
        ;;
esac

