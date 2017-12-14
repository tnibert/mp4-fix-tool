#!/bin/bash
g++ `pkg-config --cflags --libs opencv` mp4walk.cpp -o mp4walk
