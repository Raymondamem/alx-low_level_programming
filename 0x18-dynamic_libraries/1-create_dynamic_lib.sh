#!/bin/bash
# Create an object file from each .c file in the current dir
for fil in *.c; do
    gcc -c -fPIC "$fil"
done
# Create a static library from all the obj
gcc -shared *.o -o liball.so
