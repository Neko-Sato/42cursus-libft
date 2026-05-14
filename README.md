*This project has been created as part of the 42 curriculum by hshimizu.*

# 42cursus-libft

## Description

`libft` is a custom C library that reimplements a set of fundamental standard C library functions, along with several additional utility functions commonly used in low-level and systems programming.

## Installation

Build the library:

```sh
$ git clone <repository url>
$ cd 42cursus-libft
$ make
```

Compile your program with `libft`:

```sh
$ cc your_program.c -I<libft_path> -L<libft_path> -lft
```

---

## Reference

### ft_ctype

| Function | Description |
|---|---|
| `ft_isalpha` | Checks whether a character is alphabetic (`A-Z`, `a-z`). |
| `ft_isdigit` | Checks whether a character is a decimal digit (`0-9`). |
| `ft_isalnum` | Checks whether a character is alphanumeric. |
| `ft_isascii` | Checks whether a character belongs to the ASCII set (`0-127`). |
| `ft_isprint` | Checks whether a character is printable, including space. |
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |

---

### ft_string

| Function | Description |
|---|---|
| `ft_strlen` | Returns the length of a string. |
| `ft_strchr` | Finds the first occurrence of a character in a string. |
| `ft_strrchr` | Finds the last occurrence of a character in a string. |
| `ft_strncmp` | Compares two strings up to `n` characters. |
| `ft_strnstr` | Searches for a substring within a bounded string. |
| `ft_strdup` | Duplicates a string using dynamic allocation. |
| `ft_strlcpy` | Copies a string with size limitation. |
| `ft_strlcat` | Concatenates strings with size limitation. |
| `ft_substr` | Extracts a substring from a string. |
| `ft_strjoin` | Concatenates two strings into a newly allocated string. |
| `ft_strtrim` | Trims specified characters from both ends of a string. |
| `ft_split` | Splits a string using a delimiter character. |
| `ft_striteri` | Applies a function to each character of a string in-place. |
| `ft_strmapi` | Creates a transformed string using a mapping function. |
| `ft_memset` | Fills a memory region with a byte value. |
| `ft_bzero` | Sets a memory region to zero. |
| `ft_memcpy` | Copies memory from source to destination. |
| `ft_memmove` | Copies memory safely for overlapping regions. |
| `ft_memchr` | Searches for a byte inside a memory region. |
| `ft_memcmp` | Compares two memory regions. |

---

### ft_putx

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

---

### ft_stdlib

| Function | Description |
|---|---|
| `ft_calloc` | Allocates zero-initialized memory. |
| `ft_atoi` | Converts a string to an integer. |
| `ft_itoa` | Converts an integer to a string. |

---

### ft_list

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new linked list node. |
| `ft_lstadd_front` | Inserts a node at the beginning of a list. |
| `ft_lstsize` | Returns the number of nodes in a list. |
| `ft_lstlast` | Returns the last node of a list. |
| `ft_lstadd_back` | Inserts a node at the end of a list. |
| `ft_lstdelone` | Deletes a single node. |
| `ft_lstclear` | Clears and frees an entire list. |
| `ft_lstiter` | Applies a function to each node of a list. |
| `ft_lstmap` | Creates a new list by transforming each node. |

---

## Resources

- [42cursus-libft Repository](https://github.com/Neko-Sato/42cursus-libft)
- [FreeBSD Repository](https://github.com/freebsd/freebsd-src)
- [musl libc Repository](https://github.com/kraj/musl)
