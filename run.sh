#!/bin/bash

if [ ! -d "bin" ]; then
    mkdir -p "bin"
fi

# Compile custom libs

find lib/ -type f -name '*.c' | while read -r file; do
    output_file="bin/$(basename "${file%.c}.o")"
    gcc -c "$file" -o "$output_file" -lm -lGL -lglut -lGLU
done

# Compile main file

file=$(basename "$1")

if [ ! -d "bin/${1%$file}" ]; then
    mkdir -p "bin/${1%$file}"
fi

gcc -c $1 -o "bin/${file%.c}.o" -lm -lGL -lglut -lGLU

# Link everyone

gcc bin/*.o -o "bin/${1%.c}" -lm -lGL -lglut -lGLU

# Remove object files

rm bin/*.o # find . -type f -name "*.o" -delete

# Run

if [ $# -gt 1 ]; then
    "./bin/${1%.c}" "${@:2}"
else
    "./bin/${1%.c}"
fi
