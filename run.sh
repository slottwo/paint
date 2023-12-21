#!/bin/bash

for lib in lib/*.c; do
    if [ -f "$lib" ]; then
        gcc -c "$lib" -o "${lib%.c}.o"
    fi
done

if [ ! -d "bin" ]; then
    mkdir "bin";
fi

file=$(basename "$1")

gcc $1 -o bin/${file%.c}.exe -lm -lGL -lglut -lGLU

rm lib/*.o

if [ $# -gt 1 ]; then
    ./bin/${file%.c}.exe "${@:2}"
else
    ./bin/${file%.c}.exe
fi
