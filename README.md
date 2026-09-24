*This project has been created as part of the 42 curriculum by htkyaw

# ft_printf

## Description
This project is a recode of the standard C `printf()` function. It handles the mandatory conversions: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%`. It uses variadic functions to accept a variable number of arguments.

###  Variadic functions in C

`ft_printf` takes a format string and a variable number of arguments.  
The standard header `<stdarg.h>` provides the tools:

- `va_list ap;` — declares a list of arguments.
- `va_start(ap, format);` — initialises the list after the last fixed parameter (`format`).
- `va_arg(ap, type);` — retrieves the next argument, assuming it has the given type.
- `va_end(ap);` — cleans up the list.

###  Supported Conversion specifiers(mandatory part):

| Specifier | Argument type  |        Output example          |               Prints                     |
|-----------|----------------|--------------------------------|------------------------------------------|
| `%c`      | `int` (char)   | `ft_printf("%c", 'A')` → `A`   | a single character                       |
| `%s`      | `char *`       | `ft_printf("%s", "42")` → `42` | a string (`(null)` for a NULL pointer)   |
| `%p`      | `void *`       | `0x7ffd...` or `(nil)`         | a `void *` in hexadecimal, `0x`-prefixed |
| `%d`      | `int`          | `-42`                          | a signed base-10 integer                 |
| `%i`      | `int`          | `42`                           | a signed base-10 integer                 |
| `%u`      | `unsigned int` | `42`                           | a unsigned base-10 integer               |
| `%x`      | `unsigned int` | `ff`                           | an unsigned integer in lowercase hex     |
| `%X`      | `unsigned int` | `FF`                           | an unsigned integer in uppercase hex     |
| `%%`      | none           | `%`                            | a percent sign                           |


## Instructions
Compile the library with:
```bash
make
```

Options
  all -> full build
  clean -> removes .o
  fclean -> clean + libftprintf.a
  re -> fclean + all

Use it via include:

```c
#include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror ./*.c libftprintf.a
```

###  Compilation and testing

Create a `main.c`:

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret;

    ret = ft_printf("Hello %s, %d, %x, %p%%\n", "world", -42, 255, &ret);
    printf("ft_printf returned: %d\n", ret);
    return (0);
}
---

## Resources

- man 
- google
- [The Linux man pages](https://man7.org/linux/man-pages/) — reference for the
  original `printf` function prototypes and documented behavior
- 42's own `ft_printf` subject PDF, distributed as part of the curriculum
- Testers such as https://github.com/Tripouille/libftTester and https://github.com/wxsonz/ bro42 are used to check the final result of the functions.
- norminette 

### AI usage

AI was used as a learning and debugging aid during the project.

It was mainly used for:

* asking questions about C concepts that were not yet understood;
* understanding variadic functions and how `va_list` works;
* checking the reasoning behind the parsing structure;
* investigating bugs and compiler errors;
* checking conversion behavior against the original `printf()`;
* reviewing code for logical errors and edge cases;
* discussing memory allocation and error handling;
* reviewing comments and explaining unfamiliar C syntax.

AI was not used to generate the complete project as a finished solution. The implementation was developed incrementally while researching the concepts, writing the code, testing it, and asking questions about specific problems encountered during development.
