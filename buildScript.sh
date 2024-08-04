#!/bin/bash
BUILD_DIR="build"
if [ ! -d "$BUILD_DIR" ]; then
    mkdir $BUILD_DIR
    echo "Directory $BUILD_DIR created."
fi

cd $BUILD_DIR
python ../launchUI.py

read -p "Do you want to delete the contents of the $BUILD_DIR directory? (y/n): " choice

if [ "$choice" = "y" ]; then
    cd ../
    rm -rf "$BUILD_DIR"/*
fi