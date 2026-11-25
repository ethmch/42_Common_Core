*This project has been created as part of the 42 curriculum by emechali.*

# ft_printf

## Description

ft_printf is the second C project of the 42 common core. The goal is to
rewrite the libc `printf` function and ship it as a static library,
`libftprintf.a`, that later projects can link instead of the standard one.
The only system call used is `write`.

The project trains variadic functions (`stdarg.h`), type promotions,
recursion for number conversion, and the exact return value contract of
`printf`: the number of characters written.

### The function

```c
int	ft_printf(const char *format, ...);
```

It writes `format` on the standard output, replacing each conversion with
the next argument, and returns the number of characters written.

| Conversion | Argument read | Output |
|---|---|---|
| `%c` | `int`, printed as a character | one character |
| `%s` | `char *` | the string, or `(null)` for a NULL pointer |
| `%p` | `void *` | the address in lowercase hexadecimal with `0x`, or `(nil)` for NULL |
| `%d`, `%i` | `int` | signed decimal, `INT_MIN` included |
| `%u` | `unsigned int` | unsigned decimal |
| `%x`, `%X` | `unsigned int` | hexadecimal, lowercase or uppercase |
| `%%` | none | a literal `%` |

### Files

| File | Content |
|---|---|
| `ft_printf.h` | prototypes used in the function |
| `ft_printf.c` | `ft_printf` and the static dispatcher `ft_put_params` |
| `ft_putft.c` | the four print helpers, each returning what it wrote |
| `ft_hexa.c` | used to print numbers in hexadecimal base |

### Technical choices

- Every print helper returns the number of characters it wrote. The total
  is added up as the output goes, so no argument is read twice.
- The `va_list` is passed to the dispatcher by address (`va_list *`). The C
  standard leaves a `va_list` passed by value indeterminate in the caller
  once the callee used `va_arg` on it; passing a pointer is the portable form.
- `va_arg` reads the promoted type: `int` for `%c`, `unsigned int` for
  `%u`, `%x` and `%X`, `void *` for `%p`.
- The function ft_putnbr is used to print number in base 10, and ft_hexa.c 
  is used to print number in base 16.
- `%d` copies the `int` into a `long` before changing its sign, so
  `INT_MIN` does not overflow.
- NULL strings and pointers print `(null)` and `(nil)`, like the glibc.
- Edge cases: `ft_printf(NULL)` and a format ending with a single `%` return
  -1. An unknown conversion such as `%y` is printed as is, like the glibc.

## Instructions

Build the library:

```bash
make
```

This compiles each source file with `cc -Wall -Wextra -Werror`, then
archives the objects with `ar rcs libftprintf.a`. Running `make` again does
nothing until a source file or `ft_printf.h` changes.

Other rules:

| Rule | Effect |
|---|---|
| `make clean` | removes the object files |
| `make fclean` | removes the object files and `libftprintf.a` |
| `make re` | `fclean`, then a full build |

Use the library in a program:

```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("%s is %d, %x in hex\n", "answer", 42, 42);
	ft_printf("%d characters written\n", len);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror -I main.c -L. -lftprintf -o test
```

`-L.` tells the linker where to look, and `-lftprintf` names
`libftprintf.a`.

### Testing

Each conversion was compared with the real `printf` byte by byte, return
value included, on 14 cases: NULL strings and pointers, `INT_MIN`,
`INT_MAX`, `UINT_MAX`, `ULONG_MAX` as a pointer, `%x` of -1, `%%`
sequences and a mixed format. The same tests run clean under
`-fsanitize=address,undefined`.

## Resources

### C and variadic functions

- `man 3 printf` for the expected output and return value, and
  `man 3 stdarg` for `va_start`, `va_arg`, `va_copy` and `va_end`.
- [cppreference, variadic functions](https://en.cppreference.com/w/c/variadic)
- The C11 standard, section 7.16, for the rules on `va_list` and type
  promotions.
- [System V x86-64 ABI](https://gitlab.com/x86-psABIs/x86-64-ABI), to see
  how arguments are passed in registers and how `va_list` is laid out.
- [The 42 Norm](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf)
  and the `norminette` tool.
- [GNU make manual](https://www.gnu.org/software/make/manual/make.html),
  for pattern rules and automatic variables.

### Use of AI

AI was used as a tutor and reviewer. It explained variadic functions,
default argument promotions, how `va_list` works in memory, and how a
recursive function returns a count.
