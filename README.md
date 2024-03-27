# my_printf Implementation in C

This C program provides a simplified implementation of the `printf` function, allowing basic formatting for strings (`%s`) and characters (`%c`). The program is designed to be easy to understand and extend.

## Table of Contents

- [File Structure](#file-structure)
- [Functions](#functions)
- [Usage](#usage)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## File Structure

- **my_printf.c**: Contains the source code for the `my_printf` implementation.
- **README.md**: The documentation file you are currently reading.

## Functions

- **my_putchar(int c):**
  Writes a character to the standard output.

- **my_putstr(const char *str):**
  Writes a string to the standard output and returns the number of characters written.

- **proceed_flag(va_list *arg, char flag):**
  Processes format specifiers (`%s` and `%c`) and calls corresponding functions to handle them.

- **my_printf(const char* format, ...):**
  Implements a simplified version of the `printf` function. Supports `%s` for strings and `%c` for characters.

## Usage

To use the `my_printf` function in your C program, include the `my_printf.c` file in your project. Use the following functions:

- `my_printf(const char* format, ...)`: Formats and prints the given arguments based on the format string.

## Example

```c
#include "my_printf.c"

int main() {
    my_printf("Hello, everybody\n");
    my_printf("Hello world! this is five: %d\n", 5);
    my_printf("%c\n", 'H');
    my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o');
    my_printf("%d!\n", 1337);

    return 0;
}
