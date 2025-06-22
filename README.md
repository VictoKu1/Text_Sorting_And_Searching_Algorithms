# Text Sorting and Searching Algorithms

A C implementation of fundamental sorting and text searching algorithms, developed as part of a B.Sc in Computer Science and Mathematics curriculum.

## Overview

This project implements two main algorithms:

1. **Insertion Sort** (`isort`) - An efficient comparison-based sorting algorithm
2. **Text Search** (`txtfind`) - A text processing utility for finding words and similar patterns

## Features

### Insertion Sort (`isort`)
- **Algorithm**: Classic insertion sort implementation
- **Time Complexity**: O(n²) worst case, O(n) best case
- **Space Complexity**: O(1) in-place sorting
- **Input**: 50 integers from stdin
- **Output**: Sorted array in comma-separated format

### Text Search (`txtfind`)
- **Substring Search**: Find lines containing a specific word
- **Similarity Search**: Find words similar to a target word (with 1 character difference tolerance)
- **Input Processing**: Handles text input from stdin
- **Robust Parsing**: Proper word and line extraction with error handling

## Project Structure

```
Text_Sorting_And_Searching_Algorithms/
├── headers.h         # Header file with function declarations and constants
├── isort.c           # Insertion sort implementation
├── txtfind.c         # Text search implementation
├── makefile          # Build configuration (Linux/macOS)
└── README.md         # This file
```

## Building the Project

### Prerequisites

#### Linux/macOS
- GCC compiler (version 4.8 or higher)
- Make utility
- Standard C library

### Compilation

#### Linux/macOS
```bash
# Build all executables
make

# Build with specific target
make isort
make txtfind

# Clean build artifacts
make clean

# Run tests
make test
```

The executables will be created in the `bin/` directory (Linux/macOS)

### Setting Up Development Environment


#### Linux
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install build-essential

# CentOS/RHEL/Fedora
sudo yum groupinstall "Development Tools"
# or
sudo dnf groupinstall "Development Tools"
```

#### macOS
```bash
# Install Xcode Command Line Tools
xcode-select --install
```

## Usage

### Insertion Sort (`isort`)

#### Linux/macOS
```bash
./bin/isort
```

**Input Format**: Enter 50 integers, one per line
**Output**: Sorted array in comma-separated format

**Example**:
```bash
$ echo -e "5\n3\n1\n4\n2" | ./bin/isort
Enter 50 integers (one per line):
Sorted array:
1,2,3,4,5
```

### Text Search (`txtfind`)

#### Linux/macOS
```bash
./bin/txtfind
```

**Input Format**:
1. Enter the target word
2. Enter operation type:
   - `a` - Find lines containing the word
   - `b` - Find similar words
3. Enter text to search through (lines of text)

**Example**:
```bash
$ echo -e "hello\na\nworld\nhello world" | ./bin/txtfind
# Enter: hello
# Enter: a
# Output: hello world
```

## Algorithm Details

### Insertion Sort
The insertion sort algorithm works by building a sorted array one element at a time. It takes each element from the unsorted part and inserts it into its correct position in the sorted part.

**Pseudocode**:
```
for i = 1 to n-1
    key = A[i]
    j = i - 1
    while j >= 0 and A[j] > key
        A[j+1] = A[j]
        j = j - 1
    A[j+1] = key
```

### Text Search Algorithms

#### Substring Search
Uses a simple sliding window approach to find substrings within words.

#### Similarity Search
Implements a basic edit distance algorithm to find words that differ by at most one character from the target word.

## Technical Implementation

### Code Quality Features
- **Error Handling**: Comprehensive input validation and error checking
- **Memory Management**: Proper allocation and deallocation
- **Buffer Safety**: Protection against buffer overflows
- **Documentation**: Detailed function documentation with Doxygen-style comments
- **Consistent Naming**: Clear, descriptive function and variable names

### Constants and Limits
- `ARRAY_SIZE`: 50 (maximum array size for sorting)
- `MAX_LINE_LENGTH`: 257 (maximum line length for text processing)
- `MAX_WORD_LENGTH`: 31 (maximum word length)

### Compiler Flags
- `-Wall -Wextra`: Enable all warnings
- `-std=c99`: Use C99 standard
- `-g`: Include debug information
- `-O2`: Optimize for performance

## Testing

### Linux/macOS
```bash
make test
```

## Installation

### Linux/macOS
To install the executables system-wide (requires sudo):

```bash
make install
```

To uninstall:

```bash
make uninstall
```

## Development

### Adding New Features
1. Add function declarations to `headers.h`
2. Implement functions in appropriate `.c` files
3. Update the makefile and build.bat if new source files are added
4. Add tests to the `test` target

### Code Style
- Use consistent indentation (4 spaces)
- Follow C99 standard
- Include proper error handling
- Add comprehensive documentation
- Use descriptive variable names

## Performance Considerations

### Insertion Sort
- **Best Case**: O(n) when array is already sorted
- **Worst Case**: O(n²) when array is reverse sorted
- **Average Case**: O(n²)
- **Space**: O(1) in-place sorting

### Text Search
- **Substring Search**: O(n*m) where n is line length, m is word length
- **Similarity Search**: O(n) where n is the length of the longer string
- **Memory**: O(1) additional space per operation

## Troubleshooting

### Common Issues

#### "gcc: command not found"
- **Linux**: Install build-essential package
- **macOS**: Install Xcode Command Line Tools

#### "make: command not found"
- **Linux/macOS**: Install make package

#### Compilation errors
- Ensure you're using C99 standard (`-std=c99`)
- Check that all required headers are included
- Verify function declarations match implementations

## Contributing

This is an academic project, but suggestions for improvements are welcome:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests if applicable
5. Submit a pull request

## License

This project is part of academic coursework and is provided for educational purposes.

## Author

Developed as part of B.Sc Computer Science and Mathematics curriculum.