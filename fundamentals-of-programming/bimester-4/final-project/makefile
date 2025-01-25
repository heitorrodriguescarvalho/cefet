# Variables
SRC_DIR := src
BUILD_DIR := build
OUTPUT_DIR := output
TARGET := $(OUTPUT_DIR)/main

# Find all source files
SRCS := $(shell find $(SRC_DIR) -name '*.c')
# Convert source files to object files in the build directory
OBJS := $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%, $(SRCS:.c=.o))

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -I$(SRC_DIR) -lm

# Default rule
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	@mkdir -p $(OUTPUT_DIR)
	$(CC) $(OBJS) -o $@ $(CFLAGS)
	@echo "Build complete: $(TARGET)"

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

# Clean build and output directories
clean:
	@rm -rf $(BUILD_DIR) $(OUTPUT_DIR)
	@echo "Cleaned up build and output directories."

# Debug rule to show variables
debug:
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"
