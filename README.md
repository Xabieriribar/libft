# Libft

Libft is my first reusable C library from the 42 Lausanne Common Core. It reimplements a focused set of standard C library functions and adds utilities for strings, memory, output and linked lists.

The project is designed to be linked into later C projects, giving me direct control over the behavior, allocation and error handling of the functions I use.

## Included functionality

### Character and conversion

- ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii and ft_isprint
- ft_toupper and ft_tolower
- ft_atoi and ft_itoa

### Memory

- ft_memset, ft_bzero, ft_memcpy and ft_memmove
- ft_memchr, ft_memcmp and ft_calloc

### Strings

- ft_strlen, ft_strlcpy and ft_strlcat
- ft_strchr, ft_strrchr, ft_strncmp and ft_strnstr
- ft_strdup, ft_substr, ft_strjoin, ft_strtrim and ft_split
- ft_strmapi and ft_striteri

### File-descriptor output

- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

### Linked lists

- ft_lstnew
- ft_lstadd_front and ft_lstadd_back
- ft_lstsize and ft_lstlast
- ft_lstdelone and ft_lstclear
- ft_lstiter and ft_lstmap

## Build

~~~bash
make
~~~

Build the linked-list bonus:

~~~bash
make bonus
~~~

The result is a static library named libft.a.

Cleanup targets:

~~~bash
make clean
make fclean
make re
~~~

## What this project demonstrates

- Manual memory management in C
- Defensive handling of null pointers and allocation failures
- Reimplementation of familiar APIs from their contracts
- Building and linking a static library with Make
- Consistent naming, headers and code organization under the 42 Norm
