#!/bin/bash

# Compile the C++ source file
g++ Station1.cpp -o Station1

# Run the program and capture its output
output=$(./Station1)

# Check if it prints "Hello, World!"
if [[ $output == *"Hello, World!"* ]]; then
    echo "Station1 prints Hello, World!"
else
    echo "Station1 does not print Hello, World!"
    echo "Output: $output"
fi