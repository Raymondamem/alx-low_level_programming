#!/bin/bash
for file in [0-9]*-.c; do
    mv "$file" "_${file#*-}"
done
