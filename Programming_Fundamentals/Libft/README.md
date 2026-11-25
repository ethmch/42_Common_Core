*This project has been created as part of the 42 curriculum by emechali.*

# libft

## Description

Libft is the first C project of the 42 common core. The goal is to write a
personal C library, `libft.a`, that later projects can reuse instead of the
standard library. Each function is rewritten from scratch, with the `ft_`
prefix, using only `malloc`, `free` and `write` from the system.

The project trains the basics of C: pointers and memory, strings, dynamic
allocation and its failure paths, function pointers, linked lists, and
building a static library with a Makefile.

## Library contents

### Part 1: libc functions

| Category | Functions |
|---|---|
| Character tests and conversion | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Conversion | `ft_atoi` |

### Part 2: additional functions

| Function | Description |
|---|---|
| `ft_substr` | Allocates and returns a substring of `s` starting at `start`, of at most `len` characters |
| `ft_strjoin` | Allocates and returns the concatenation of `s1` and `s2` |
| `ft_strtrim` | Allocates and returns a copy of `s1` without the characters of `set` at its beginning and end |
| `ft_split` | Splits `s` with the separator `c` into a `NULL`-terminated array of allocated strings |
| `ft_itoa` | Allocates and returns the string representation of an `int` |
| `ft_strmapi` | Allocates a new string made of `f(i, s[i])` for each character |
| `ft_striteri` | Applies `f(i, &s[i])` to each character, modifying the string in place |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write a character, a string, a string followed by a newline, or an integer to a file descriptor |

### Bonus: linked lists

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Allocates a new node with the given content and `next` set to `NULL` |
| `ft_lstadd_front` | Adds a node at the beginning of the list |
| `ft_lstadd_back` | Adds a node at the end of the list |
| `ft_lstsize` | Counts the nodes of the list |
| `ft_lstlast` | Returns the last node of the list |
| `ft_lstdelone` | Frees the content of a node with `del`, then frees the node |
| `ft_lstclear` | Deletes and frees every node of the list, and sets the list pointer to `NULL` |
| `ft_lstiter` | Applies `f` to the content of every node |
| `ft_lstmap` | Creates a new list by applying `f` to each content, and frees everything if an allocation fails |

### Implementation choices

- Comparisons in `ft_memcmp`, `ft_strncmp`, `ft_memchr` are made on `unsigned char`, as in the libc.
- `ft_memmove` copies backwards when the destination is located after the source, so that overlapping areas are handled correctly.
- `ft_strlcpy` and `ft_strlcat` never compute `size - 1`, so that `size == 0` cannot cause an unsigned underflow.
- `ft_calloc` checks that `nmemb * size` does not overflow before calling `malloc`.
- `ft_itoa` and `ft_putnbr_fd` use a `long` so that `INT_MIN` is handled without signed overflow.
- `ft_split`, `ft_lstmap` free everything they already allocated when an allocation fails.

## Instructions

Build the library:

```bash
make
```

This compiles every `ft_*.c` file with `cc -Wall -Wextra -Werror`, then
archives the objects with `ar rcs libft.a`. Running `make` again does
nothing until a source file or `libft.h` changes.

Other rules:

| Rule | Effect |
|---|---|
| `make clean` | removes the object files |
| `make fclean` | removes the object files and `libft.a` |
| `make re` | `fclean`, then a full build |

Use the library in a program:

```c
#include "libft.h"

int	main(void)
{
	ft_putendl_fd("hello", 1);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror -I. main.c -L. -lft -o hello
```

`-L.` tells the linker where to look, and `-lft` names `libft.a`.

## Resources

### References

- The `man` pages of each original function, section 3: `man 3 strlcpy`,
  `man 3 memmove`, and so on.
- [cppreference, C standard library](https://en.cppreference.com/w/c)
- [The 42 Norm](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf)
  and the `norminette` tool.
- [GNU make manual](https://www.gnu.org/software/make/manual/make.html),
  for pattern rules and automatic variables.
- `man ar`, for static archives.
- `man leaks` on macOS, and the
  [Valgrind quick start](https://valgrind.org/docs/manual/quick-start.html)
  on Linux, to check for memory leaks.

### Use of AI

AI was used as a tutor only. It explained C concepts, such as
pointers, `size_t`, `const`, function pointers and Makefile rules. It wrote
practice tests that compare each function with the libc, and failure tests
that make `malloc` return NULL. It reviewed my code and pointed out edge
cases. The code of the library was written and typed by me.

Every function of the library was written, tested and checked against the Norm by me, and I am able to explain each line.
