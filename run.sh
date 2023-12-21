#!/bin/bash

gcc $1 -o out -lm -lGL -lglut -lGLU

if [ $# -gt 1 ]; then
    ./out "${@:2}"
fi

rm out
