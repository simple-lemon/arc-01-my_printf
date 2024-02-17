Custom printf Function

This is a custom implementation of the printf function in C. It supports the following conversion specifiers:

%d: Signed decimal integer
%c: Character
%s: String
%p: Pointer
%x: Unsigned hexadecimal integer
%u: Unsigned decimal integer
%o: Unsigned octal integer
Usage
To use this function, simply include the source code in your program and call the my_printf function with a format string and a variable number of arguments. The format string should contain the conversion specifiers as placeholders for the values, and the arguments should be the values themselves.


Implementation Details
The my_printf function uses the va_start, va_arg, and va_end macros to access the variable number of arguments. The function iterates over the format string and checks for conversion specifiers. When a conversion specifier is found, the corresponding argument is retrieved using va_arg and passed to the appropriate printf-like function, such as vprintf or vdprintf.