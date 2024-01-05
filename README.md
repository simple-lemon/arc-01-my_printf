Printf Function Implementation in C
This code provides an implementation of the my_printf function in C, which is a simplified version of the standard C library function printf. The my_printf function allows you to print formatted output to the console. It supports format specifiers such as %s for strings, %d for integers, %x for hexadecimal numbers, %c for characters, %o for octal numbers, %p for pointers, and %u for unsigned integers.

Functions
The code includes several utility functions:

my_strcpy: Copies a string from str_2 to str_1.
my_strlen: Computes the length of a string.
my_reverse: Reverses a string.
my_itoa: Converts an integer to a string representation.
my_longInt_itoa: Converts a long integer to a string representation.
dec_to_hex: Converts a decimal number to a hexadecimal string representation.
dec_to_oct: Converts a decimal number to an octal string representation.
my_u_num: Converts an integer to an unsigned string representation.
Usage
To use the my_printf function, you can uncomment the main function at the bottom of the code and run it. The main function demonstrates the usage of my_printf by printing various types of data.

Format Specifiers
The my_printf function recognizes the following format specifiers:

%s: Prints a string.
%d: Prints a signed decimal integer.
%x: Prints an unsigned hexadecimal integer.
%c: Prints a character.
%o: Prints an unsigned octal integer.
%p: Prints a pointer in hexadecimal format.
%u: Prints an unsigned decimal integer.
Note that the format specifiers must be preceded by a % symbol.

