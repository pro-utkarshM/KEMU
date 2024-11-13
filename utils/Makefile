# Compiler and Flags
CC = gcc
CFLAGS = -O3 -Wall -std=c2x -I$(SRC_DIR) -fPIC
LDFLAGS = -fPIC -shared -ldl -D_GNU_SOURCE
LIBDIR = /lib/x86_64-linux-gnu/
INCDIR = /usr/include

# Project Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = $(LIBDIR)

# Files
UTILS_SRC = $(SRC_DIR)/KEMU_utils.c
UTILS_OBJ = $(OBJ_DIR)/KEMU_utils.o
LIBRARY = $(BIN_DIR)/libkemu_utils.so

# Targets
all: clean $(LIBRARY)

$(LIBRARY): $(UTILS_OBJ)
	@mkdir -p $(BIN_DIR)  # Ensure bin directory exists
	@echo "Linking shared library..."
	$(CC) $(UTILS_OBJ) -o $(LIBRARY) $(LDFLAGS)
	@echo "Library built: $(LIBRARY)"

$(UTILS_OBJ): $(UTILS_SRC)
	@mkdir -p $(OBJ_DIR)  # Ensure obj directory exists
	@echo "Compiling KEMU_utils..."
	$(CC) $(CFLAGS) -c $(UTILS_SRC) -o $(UTILS_OBJ)

install: $(LIBRARY)
	@echo "Installing shared library and header..."
	cp $(LIBRARY) $(LIB_DIR)
	cp $(SRC_DIR)/KEMU_utils.h $(INCDIR)
	ldconfig
	@echo "Installation complete."

clean:
	@echo "Cleaning up..."
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*.so

.PHONY: all clean install
