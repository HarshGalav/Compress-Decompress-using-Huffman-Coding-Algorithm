# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source files and object files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/huffman.c $(SRC_DIR)/minheap.c $(SRC_DIR)/file_handler.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Output executable
EXEC = huffman_compression

# Targets
all: $(EXEC)

# Ensure the build directory exists
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Link object files to create the executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(BUILD_DIR)/$(EXEC)

# Compile .c files to .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/$(EXEC)

# Run the program (useful for testing)
run: $(EXEC)
	./$(BUILD_DIR)/$(EXEC)

# For debugging purposes, add debug flag
debug: CFLAGS += -DDEBUG
debug: $(EXEC)

.PHONY: all clean run debug
