#!/bin/bash
cc -c contours.cpp
cc -c mp4walk.cpp
g++ `pkg-config --cflags --libs opencv` contours.o mp4walk.o -o mp4walk
