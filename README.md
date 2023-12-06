# Welcome to My Printf

## Task

This project involves implementing a custom `printf` function, `my_printf`, to write output to the standard output stream according to a given format string. The goal is to strengthen your programming skills, understand variadic functions, and organize code effectively.

### Project Structure

- **Submit Directory:** .
- **Submit File:** `my_printf.c`

## Description

The `my_printf` function produces output based on a format string, similar to the standard `printf`. The format string consists of ordinary characters, copied unchanged to the output stream, and conversion specifications introduced by the PERCENT character (%). Conversion specifications fetch subsequent arguments for output.

## Installation

- **d, o, u, x:** Convert int (or appropriate variant) to signed decimal (d), unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
- **c:** Convert int to an unsigned char, and write the resulting character.
- **s:** Expect a char * argument, a pointer to a string. Write characters from the array up to (but not including) the terminating NUL character.
- **p:** Print the void * pointer argument in hexadecimal.
