*This project has been created as part of the 42 curriculum by <gegrigor>, <rafhovha>.*

# get_next_line

## Description
The goal of the get_next_line project is to implement a function that reads a file descriptor line by line. The function must return a single line at each call, including the terminating newline character if present, and maintain internal state between calls. This project introduces low-level file I/O, static storage, and careful memory management in C. It also teaches how to design robust behavior for edge cases such as multiple file descriptors, end-of-file handling, and partial reads.

The mandatory version supports reading from one file descriptor, while the bonus version extends functionality to handle multiple file descriptors simultaneously using separate internal buffers.

---

## Function Prototype
```c
char *get_next_line(int fd);
```

Allowed functions:
- read
- malloc
- free

---

## Instructions

### Compilation
Clone the repository and compile:
```bash
cd get_next_line
```

This will generate object files for the project.

### Usage Example
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

Compile:
```bash
gcc main.c get_next_line.c get_next_line_utils.c
./a.out
```

---

## Features
- Reads one line per function call
- Works with any file descriptor (files, stdin, pipes)
- Handles arbitrary BUFFER_SIZE values
- No memory leaks
- Bonus: supports multiple file descriptors simultaneously

---

## Algorithm Explanation

The core of the algorithm is based on incremental buffered reading combined with persistent storage. Each call to get_next_line reads up to BUFFER_SIZE bytes from the file descriptor and appends them to a static buffer (often called a stash). This static storage preserves leftover data between calls, allowing the function to continue where it previously stopped.

The function repeatedly reads and appends data until a newline character is found or EOF is reached. Once a newline exists in the stash, the function extracts the portion up to and including the newline and returns it as the current line. The remaining data after the newline is kept inside the static buffer for the next call.

In the bonus version, the algorithm is extended by replacing a single static buffer with an indexed structure (usually an array indexed by file descriptor). This allows independent buffers per descriptor, enabling simultaneous reading from multiple files without mixing states.

This approach ensures efficiency because it minimizes system calls and avoids re-reading already processed data. It also guarantees correctness by maintaining strict ownership of allocated memory and freeing intermediate buffers when no longer needed.

---

## Technical Choices
- Static storage to persist data between function calls
- Dynamic allocation to return lines of arbitrary length
- Manual string utilities to comply with 42 restrictions
- Defensive checks for invalid file descriptors and read errors

---

## Resources
- Linux manual: https://man7.org/linux/man-pages/man2/read.2.html
- Static variables in C: https://en.cppreference.com/w/c/language/static_storage_duration
- File descriptor concepts: https://man7.org/linux/man-pages/man2/open.2.html
- Memory management best practices in C

### AI Usage
AI tools were used for:
- Reviewing algorithm correctness
- Understanding edge cases and memory safety
- Structuring documentation and README formatting

All implementation logic and debugging were performed manually to ensure full understanding of the project requirements.
