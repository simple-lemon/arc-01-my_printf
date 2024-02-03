## MY Printf
__**by Xurhid Oqmonov**__

## Task

The task of this project is to implement a custom printf function in C programming language.

## Description

The `my_printf()` function produces output according to a format as described below. The `my_printf()` function writes output to stdout, the standard output stream.

This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of `stdarg(3)`) are converted for output.

The format string is composed of zero or more directives: ordinary characters (not PERCENT), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the PERCENT character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the PERCENT, the following appear in sequence:

- `d`, `o`, `u`, `x`: The `int` (or appropriate variant) argument is converted to signed decimal (d), unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal (x).
- `c`: The `int` argument is converted to an unsigned char, and the resulting character is written.
- `s`: The `char *` argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.
- `p`: The `void *` pointer argument is printed in hexadecimal.

## Installation

To install the project, follow these steps:

- 1.Clone the repository: git clone https://github.com/TheKhurshidOff707/arc-01-my_printf/tree/Xurshid_oqmonov 

- 2.  cd < project-directory > 

- 3.  make

## Usage 

    ./my_printf 



