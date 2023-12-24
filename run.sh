#!/bin/bash

if [ ! -d "bin" ]; then
    mkdir -p "bin"
fi

if [ ! -d "obj" ]; then
    mkdir -p "obj"
fi

# Compile custom libs

find src/ -type f -name '*.c' | while read -r file; do
    output_file="obj/$(basename "${file%.c}.o")"
    gcc -c "$file" -o "$output_file" -lm -lGL -lglut -lGLU
done

# Link everyone

gcc obj/*.o -o "bin/${1%.c}" -lm -lGL -lglut -lGLU

# Remove object files (?)

# rm bin/*.o 
# find . -type f -name "*.o" -delete

# Run

if [ $# -gt 1 ]; then
    "./bin/${1%.c}" "${@:2}"
else
    "./bin/${1%.c}"
fi
