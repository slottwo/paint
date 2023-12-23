#!/bin/bash

if [ ! -d "bin" ]; then
    mkdir -p "bin"
fi

find lib/ -type f -name '*.c' | while read -r file; do
    output_file="bin/$(basename "${file%.c}.o")"
    gcc -c "$file" -o "$output_file" -lm -lGL -lglut -lGLU
done

file=$(basename "$1")

if [ ! -d "bin/${1%$file}" ]; then
    mkdir -p "bin/${1%$file}"
fi

gcc -c $1 -o "bin/${file%.c}.o" -lm -lGL -lglut -lGLU

gcc lib/*.o bin/*.o -o "bin/${1%.c}" -lm -lGL -lglut -lGLU

rm bin/*.o
# find . -type f -name "*.o" -delete

if [ $# -gt 1 ]; then
    "./bin/${1%.c}" "${@:2}"
else
    "./bin/${1%.c}"
fi
