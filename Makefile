# Flags
CC = gcc
WARNINGS = -Wall -Wextra -Werror
# Supports multiple dirs
INCDIRS = include
OPT = -O0
DEBUG = -g
ASAN =
# ASAN = -fsanitize=address 
CFLAGS = $(WARNINGS) $(foreach i, $(INCDIRS), -I$(i) )$(OPT) $(DEBUG) $(ASAN) 
LDFLAGS = 


# Directories
SRC_DIR = src
BUILD_DIR = lib

# Files
BIN = $(BUILD_DIR)/liblogger.so
SRC = $(SRC_DIR)/logger.c


.PHONY = all clean rebuild
all: $(BIN)

# Linking the .o files
$(BIN): $(SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC) -shared -fPIC -o $@ $(LDFLAGS)

# Directories
$(BUILD_DIR) :
	mkdir -p $@
clean: 
	rm -rf $(BUILD_DIR)
rebuild: clean all
