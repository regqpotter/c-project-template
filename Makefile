# Makefile for the C project template.
# Builds debug, release, and test binaries and runs formatting,
# static analysis, unit tests, and documentation generation.


# Simple configuration
CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic

TARGET = template.exe
TEST_TARGET = test_template.exe

DEBUG_DIR = build/debug
RELEASE_DIR = build/release
TEST_DIR = build/test

DEBUG_LOG = $(DEBUG_DIR)/template.log
RELEASE_LOG = $(RELEASE_DIR)/template.log
TEST_LOG = $(TEST_DIR)/template.log

DEBUG_FLAGS = -g -O0 -DBUILD_DEBUG -DLOG_TO_CONSOLE -DLOG_TO_FILE -DLOG_FILE_PATH=\"$(DEBUG_LOG)\"
TEST_FLAGS = -g -O0 -DBUILD_TEST -DLOG_TO_CONSOLE -DLOG_TO_FILE -DLOG_FILE_PATH=\"$(TEST_LOG)\"
RELEASE_FLAGS = -O2 -DBUILD_RELEASE -DLOG_TO_CONSOLE
INCLUDES = -Iinclude

# Computed values
SOURCES := main.c $(wildcard src/*.c)
TEST_SOURCES := $(wildcard tests/*.c)
TEST_COMMON_SOURCES := $(filter-out main.c,$(SOURCES))
HEADERS := $(wildcard include/*.h)


.PHONY: all debug release test test_execution tidy format format-check clean docs

all: format-check tidy debug release test docs

format:
	clang-format -i $(SOURCES) $(TEST_SOURCES) $(HEADERS)

format-check:
	clang-format --dry-run --Werror $(SOURCES) $(TEST_SOURCES) $(HEADERS)

tidy:
	clang-tidy $(SOURCES) $(TEST_SOURCES) -- -std=c17 $(INCLUDES) $(DEBUG_FLAGS)

debug: $(DEBUG_DIR)/$(TARGET)

release: $(RELEASE_DIR)/$(TARGET)

test: $(TEST_DIR)/$(TEST_TARGET) test_execution

test_execution: $(TEST_DIR)/$(TEST_TARGET)
	./$(TEST_DIR)/$(TEST_TARGET)

$(DEBUG_DIR)/$(TARGET): $(SOURCES) $(HEADERS)
	mkdir -p $(DEBUG_DIR)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(INCLUDES) $(SOURCES) -o $@

$(RELEASE_DIR)/$(TARGET): $(SOURCES) $(HEADERS)
	mkdir -p $(RELEASE_DIR)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) $(INCLUDES) $(SOURCES) -o $@

$(TEST_DIR)/$(TEST_TARGET): $(TEST_SOURCES) $(TEST_COMMON_SOURCES) $(HEADERS)
	mkdir -p $(TEST_DIR)
		$(CC) $(CFLAGS) $(TEST_FLAGS) $(INCLUDES) \
	    $(TEST_SOURCES) $(TEST_COMMON_SOURCES) -o $@

docs:
	rm -rf docs
	doxygen Doxyfile
	
clean:
	rm -rf build docs