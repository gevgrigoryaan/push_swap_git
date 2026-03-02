*This project has been created as part of the 42 curriculum by gegrigor.*

# Libft

## Description

Libft is a custom C library that reimplements a part of the standard C library and adds additional utility functions.  
The goal of this project is to improve understanding of C programming, memory management, and data structures.

The library can be reused in other projects as a personal standard library.

## Instructions

### Compilation

To compile the library:

```bash
make
```

This command creates the static library `libft.a`.

### Cleaning

Remove object files:

```bash
make clean
```

Remove object files and the library:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

## Usage

Include the header in your source file:

```c
#include "libft.h"
```

Compile your program with the library:

```bash
cc main.c libft.a -o program
```

## Library Content

The library includes:

- Reimplemented standard functions (e.g. `ft_strlen`, `ft_memcpy`, `ft_strdup`, `ft_atoi`, etc.)
- Additional string and memory utilities (e.g. `ft_split`, `ft_strjoin`, `ft_substr`, `ft_itoa`, etc.)
- Output functions using file descriptors (e.g. `ft_putchar_fd`, `ft_putstr_fd`, etc.)
- Linked list functions (`ft_lst*` functions)

## Resources

- C standard library documentation (man pages, cppreference)
- 42 project subject and guidelines

AI was used for understanding concepts, debugging, and improving explanations.  
All implementations were written by the author.
