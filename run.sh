#!/bin/bash

for lib in lib/*.c; do
    if [ -f "$lib" ]; then
        gcc -c "$lib" -o "${lib%.c}.o" -lm -lGL -lglut -lGLU
    fi
done


file=$(basename "$1")

if [ ! -d "bin/${1%$file}" ]; then
    mkdir -p "bin/${1%$file}"
fi

gcc $1 -c -lm -lGL -lglut -lGLU

gcc lib/*.o *.o -o "bin/${1%.c}" -lm -lGL -lglut -lGLU

rm lib/*.o
rm *.o

if [ $# -gt 1 ]; then
    "./bin/${1%.c}" "${@:2}"
else
    "./bin/${1%.c}"
fi
