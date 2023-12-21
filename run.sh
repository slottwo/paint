#!/bin/bash

for lib in lib/*.c; do
    if [ -f "$lib" ]; then
        gcc -c "$lib" -o "${lib%.c}.o"
    fi
done

if [ ! -d "bin"]; then
    mkdir "bin";
fi

gcc $1 -o bin/${1%.c}.exe -lm -lGL -lglut -lGLU

if [ $# -gt 1 ]; then
    ./bin/${1%.c}.exe "${@:2}"
fi
