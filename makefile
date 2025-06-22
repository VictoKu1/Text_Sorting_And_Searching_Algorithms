# Text Sorting and Searching Algorithms Makefile
# Author: [Your Name]
# Course: B.Sc Computer Science and Mathematics

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -O2
LDFLAGS = 

# Directories
SRCDIR = .
OBJDIR = obj
BINDIR = bin

# Source files
SOURCES = isort.c txtfind.c
OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)
TARGETS = $(BINDIR)/isort $(BINDIR)/txtfind

# Default target
all: directories $(TARGETS)

# Create necessary directories
directories:
	@mkdir -p $(OBJDIR) $(BINDIR)

# Build isort executable
$(BINDIR)/isort: $(OBJDIR)/isort.o
	$(CC) $(OBJDIR)/isort.o -o $@ $(LDFLAGS)

# Build txtfind executable
$(BINDIR)/txtfind: $(OBJDIR)/txtfind.o
	$(CC) $(OBJDIR)/txtfind.o -o $@ $(LDFLAGS)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c headers.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Install executables to /usr/local/bin (requires sudo)
install: all
	sudo cp $(BINDIR)/* /usr/local/bin/

# Uninstall executables
uninstall:
	sudo rm -f /usr/local/bin/isort /usr/local/bin/txtfind

# Run tests
test: all
	@echo "Running insertion sort test..."
	@echo "5\n3\n1\n4\n2" | $(BINDIR)/isort
	@echo "Running text find test..."
	@echo "hello\na\nworld\nhello world" | $(BINDIR)/txtfind

# Show help
help:
	@echo "Available targets:"
	@echo "  all       - Build all executables (default)"
	@echo "  clean     - Remove build artifacts"
	@echo "  install   - Install executables to /usr/local/bin"
	@echo "  uninstall - Remove executables from /usr/local/bin"
	@echo "  test      - Run basic tests"
	@echo "  help      - Show this help message"

.PHONY: all clean install uninstall test help directories