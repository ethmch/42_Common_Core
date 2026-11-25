*This activity has been created as part of the 42 curriculum by emechali.*

# get_next_line

## Description

`get_next_line` is a C function that returns one line read from a file
descriptor each time it is called:

```c
char	*get_next_line(int fd);
```

- Each call returns the next line, including its terminating `\n`. The last
  line of a file that does not end with `\n` is returned without it.
- When there is nothing left to read, or when an error occurs, the function
  returns `NULL`.
- It works on regular files, on the standard input (keyboard, redirection
  `< file`) and on pipes.
- The returned line is allocated with `malloc`: the caller must `free` it.

The goal of the project is to learn how to read from a file descriptor with
the `read` system call, and how to keep data between two calls of the same
function with a `static` variable, without using global variables.

Only `read`, `malloc` and `free` are used. `lseek` and the libft are not used.

## Instructions

The repository contains three files:

| File | Content |
|---|---|
| `get_next_line.c` | `get_next_line` |
| `get_next_line_utils.c` | the helper functions |
| `get_next_line.h` | the prototypes and the default `BUFFER_SIZE` |

The project has no Makefile. Compile the files together with your own `main`:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

`BUFFER_SIZE` is the number of bytes asked to `read` at each call. It can be
changed with `-D BUFFER_SIZE=n`. Without this option, the default value from
the header (42) is used.

Usage example:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

To read the standard input, call `get_next_line(0)`.

## Algorithm

### The problem

`read` returns blocks of at most `BUFFER_SIZE` bytes, with no notion of lines.
A block can contain the end of one line and the beginning of the next one, or
several lines, or only a part of a long line. Since `lseek` is forbidden, the
bytes read after a `\n` cannot be given back to the file: they must be kept
in memory until the next call.

### The solution

A single `static char *line` keeps the **stash**: everything that has been
read but not returned yet. Each call works in four steps:

1. **Read** (`ft_read`): while the stash contains no `\n` and `read` does not
   return 0, read `BUFFER_SIZE` bytes into a buffer, end it with `'\0'`, and
   append it to the stash with `ft_strjoin`. The old stash is freed after
   each join.
2. **Stop if empty**: if the stash is empty, the file is finished. The stash
   is freed, set back to `NULL`, and the function returns `NULL`.
3. **Extract** (`ft_line_stop`): copy the beginning of the stash up to and
   including the first `\n` (or up to the end if there is no `\n`). This copy
   is the returned line.
4. **Keep the rest** (`ft_rest`): the rest starts at index
   `length of the returned line`. A new stash is created with what follows;
   if nothing follows, the stash is freed and set to `NULL`.

Example with the file `Bonjour\nle\nmonde` and `BUFFER_SIZE=5`:

| Call | Reads | Stash before extraction | Returned | Stash after |
|---|---|---|---|---|
| 1 | `Bonjo`, `ur\nle` | `Bonjour\nle` | `Bonjour\n` | `le` |
| 2 | `\nmond` | `le\nmond` | `le\n` | `mond` |
| 3 | `e`, then 0 | `monde` | `monde` | `NULL` |
| 4 | 0 | empty | `NULL` | `NULL` |

### Why this choice

- **A pointer, not a static array**: the stash can grow as much as needed, so
  a line longer than `BUFFER_SIZE` needs no special case.
- **Reading stops at the first `\n`**: the function reads as little as
  possible. On the keyboard it returns a line as soon as Enter is pressed,
  instead of waiting for more input.
- **Every exit path leaves a clean state**: on a read error, a `malloc`
  failure or the end of the file, the stash is freed and set to `NULL`.
  The next call starts again from a valid state, with no double free.
- **The buffer is allocated with `malloc`**, not declared on the stack, so a
  very large `BUFFER_SIZE` (10000000) does not overflow the stack.

### Limits

- **Cost of copies**: the stash is copied at each `read` and at each line.
  With a very long line and a small `BUFFER_SIZE`, or a very large
  `BUFFER_SIZE` and many short lines, the total cost grows with the square of
  the size. It is fast for normal use (`BUFFER_SIZE=42`).
- **One stash for all file descriptors**: alternating between two files
  before the end of the first one mixes their data. This case is not
  required by the subject.
- **Binary files** (containing `'\0'` bytes) are undefined behavior, as stated
  in the subject.
- If the caller stops before the end of the file, the stash is still
  allocated when the program ends (reported as "still reachable" by
  valgrind). It is freed if the caller reads until `NULL`.

## Resources

- `man 2 read`, `man 2 open`, `man 2 close`
- *The C Programming Language*, Kernighan and Ritchie: storage classes and
  `static` variables
- Valgrind documentation: https://valgrind.org/docs/manual/mc-manual.html
- The 42 Norm

### Use of AI

AI was used as a tutor :

- It wrote an explanatory document on the concepts of the project: memory
  segments, `static` variables, file descriptors, `read`, the preprocessor and
  `BUFFER_SIZE`, stack and heap, and memory ownership.
- It was used to test function and to find the bugs of program.
