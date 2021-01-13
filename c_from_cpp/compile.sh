#!/bin/bash

gcc -c sample.c
gcc -shared -o libsample.so sample.o
g++ -Wall -c main.cpp
g++ -o main main.o -L./ -l sample

