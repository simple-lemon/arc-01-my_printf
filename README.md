# My Printf
This is a simplified implementation of the printf function.

## Functionality
The `my_printf` function accepts a format string and additional arguments, and prints the formatted string to the standard output. It supports the following format specifiers:
- `%d` for printing integers
- `%s` for printing strings

## Usage
To use the `my_printf` function, include the appropriate header and call the function with the desired format string and arguments. Here's an example:

```c
#include <stdio.h>
#include "my_printf.h"

int main()
{
    my_printf("Welcome to my program! %d %s\n", "Hello");

    return 0;
}

This will output:

Welcome to my program! Hello

## Compilation
To compile the program, use the provided Makefile. Simply run the command make in the terminal. This will compile the code and generate an executable called my_printf.

## Requirements
The code must be compiled with the following flags: -Wall -Wextra -Werror.

## Limitations
The implementation of my_printf has certain limitations compared to the standard printf function. It does not support all format specifiers or modifiers, and its behavior may vary in certain cases. However, it provides a basic functionality for printing integers and strings in a formatted manner.