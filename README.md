## my_printf: A simplified implementation of printf

This code implements a simplified version of the standard `printf` function. It provides basic functionality for formatted output similar to `printf`.

### Functionality

* Takes a format string (`format`) and a variable number of arguments (`...`).
* The format string can contain normal characters to be printed directly and format specifiers starting with `%`.
* Supported format specifiers include:
    * `c`: Prints a single character argument.
    * `s`: Prints a null-terminated string argument. Prints "(null)" for NULL arguments.
    * `d`: Prints a signed decimal integer argument.
    * `o`: Prints an unsigned octal integer argument.
    * `x`: Prints an unsigned hexadecimal integer argument (lowercase).
    * `u`: Prints an unsigned decimal integer argument.
    * `p`: Prints a pointer argument in hexadecimal format, prefixed with "0x".

### Dependencies

The code includes the following standard C libraries:

* `<stdarg.h>`: For handling variable arguments.
* `<unistd.h>`: For the `write` function used to write output.
* `<string.h>`: For the `strlen` function used to get string length.
* `<stdio.h>`:  Likely included for standard library function prototypes, although not explicitly used.

### Usage

```c
#include "my_printf.h"

int main() {
  int num = 123;
  char* str = "Hello, world!";
  void* ptr = &num;

  my_printf("This is a number: %d\n", num);
  my_printf("This is a string: %s\n", str);
  my_printf("This is a pointer: %p\n", ptr);
  return 0;
}
```

This example code will output:

```
This is a number: 123
This is a string: Hello, world!
This is a pointer: 0x... (address of num)
```

**Note:** The address printed for the pointer will vary depending on your system.

### Limitations

This is a simplified implementation and lacks functionalities present in the standard `printf`:

* Does not handle floating-point numbers.
* Does not support precision control for specifying the number of decimal places.
* Lacks flags like `-` for left justification of output.


