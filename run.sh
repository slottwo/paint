#!/bin/bash

if [ ! -d "bin" ]; then
    mkdir -p "bin"
fi

if [ ! -d "obj" ]; then
    mkdir -p "obj"
fi

# Compile C files

find src/ -type f -name '*.c' | while read -r file; do
    gcc -c "$file" -o "obj/$(basename "${file%.c}.o")" -lm -lGL -lglut -lGLU
done

# Link objects

gcc obj/*.o -o "bin/paint.exe" -lm -lGL -lglut -lGLU

# Remove object files (?)

# rm bin/*.o 
# find . -type f -name "*.o" -delete

# Run

if [ $# -gt 1 ]; then
    "./bin/paint.exe" "${@:1}"
else
    "./bin/paint.exe"
fi
