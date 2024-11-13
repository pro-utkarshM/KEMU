#!/bin/bash

# Define directories and files
SRC_DIR="src"
OBJ_DIR="obj"
BIN_DIR="bin"
LIB_NAME="libkemu_utils.so"
HEADER_FILE="KEMU_utils.h"

# Compiler flags
CFLAGS="-O3 -Wall -std=c2x -fPIC"
LDFLAGS="-fPIC -shared -ldl -D_GNU_SOURCE"

# Check if the required directories exist
if [ ! -d "$SRC_DIR" ]; then
    echo "Source directory $SRC_DIR does not exist!"
    exit 1
fi

if [ ! -d "$OBJ_DIR" ]; then
    echo "Object directory $OBJ_DIR does not exist! Creating it..."
    mkdir -p "$OBJ_DIR"
fi

if [ ! -d "$BIN_DIR" ]; then
    echo "Binary directory $BIN_DIR does not exist! Creating it..."
    mkdir -p "$BIN_DIR"
fi

# Clean up old build files
echo "Cleaning up old build files..."
rm -f "$OBJ_DIR"/*.o "$BIN_DIR"/*.so

# Compile the source code
echo "Compiling KEMU_utils..."
gcc $CFLAGS -I$SRC_DIR -c $SRC_DIR/KEMU_utils.c -o $OBJ_DIR/KEMU_utils.o

# Link the object files to create the shared library
echo "Linking the shared library..."
gcc $OBJ_DIR/KEMU_utils.o -o $BIN_DIR/$LIB_NAME $LDFLAGS

# Check if the library was created successfully
if [ ! -f "$BIN_DIR/$LIB_NAME" ]; then
    echo "Error: Failed to create $LIB_NAME"
    exit 1
fi

echo "Library $LIB_NAME built successfully!"

# Install the library and header (optional)
read -p "Do you want to install the library (y/n)? " choice
if [[ "$choice" == "y" || "$choice" == "Y" ]]; then
    echo "Installing shared library and header..."
    sudo cp "$BIN_DIR/$LIB_NAME" /lib/x86_64-linux-gnu/
    sudo cp "$SRC_DIR/$HEADER_FILE" /usr/include/
    sudo ldconfig
    echo "Installation complete."
else
    echo "Skipping installation."
fi

echo "Build script completed."
