# Welcome to My Printf
<h3>Description</h3>
<h2>NAME</h2>
<p><code>int my_printf(char * restrict format, ...);</code></p>
<h2>Prolog</h2>
<p>The very first thing we do when learning a programming language is to write "Hello World !" on the screen. Well guess what ? This custom comes from a notebook called ... <strong>Programming in C: A Tutorial</strong> !</p>
<p>Unfortunately for you, this project will bring you back in the 1970s, before the existence of this book, and you will have to write your own function to greet the world.</p>
<p>Fortunately for you, you will strengthen your programming skills and learn new programming concepts: variadic functions and variable argument lists. Recoding printf is also a good exercise to learn to have
a well structured code organisation. Modularity is the key here since printf has a lot of different options that you will have to recode yourself. Adding a new option feature should be easy and smooth if
the code is well designed !</p>
<h2>DESCRIPTION</h2>
<p>The <strong>my_printf()</strong> function produce output according to a format as described below. The <em>my_printf()</em> functions write output to stdout, the standard output stream;</p>
<p>This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.</p>
<p>The format string is composed of zero or more directives: ordinary characters (not PERCENT), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.</p>
<p>Each conversion specification is introduced by the PERCENT character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the PERCENT, the following appear in sequence:</p>
<ul>
<li>
<strong>doux</strong> The <em>int</em> (or appropriate variant) argument is converted to signed decimal (<strong>d</strong>). unsigned octal (<strong>o</strong>), unsigned decimal (<strong>u</strong>), unsigned hexadecimal (<strong>x</strong>).</li>
<li>
<strong>c</strong> The int argument is converted to an unsigned char, and the resulting character is written.</li>
<li>
<strong>s</strong> The <em>char *</em> argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.</li>
<li>
<strong>p</strong> The void * pointer argument is printed in hexadecimal.</li>
</ul>
<h2>Requirements</h2>
<ul>
<li>Your code must be compiled with the flags <strong>-Wall -Wextra -Werror</strong>.</li>
</ul>
<h2>Hint(s)</h2>
<ul>
<li>
<p>• man printf</p>
</li>
<li>
<p>• man 3 stdarg</p>
</li>
<li>
<p>• Watch out for <strong>memory leaks</strong> !</p>
</li>
<li>
<p>• You can test your code against memory errors by compiling with the debugging flags <strong>-g3 -fsanitize=address</strong></p>
</li>
<li>
<p>• <strong>Global variables are strictly FORBIDDEN</strong></p>
</li>
<li>
<p>• <strong>Static variables are strictly FORBIDDEN</strong></p>
</li>
</ul>
<h2>Authorized function(s)</h2>
<ul>
<li>• write(2)</li>
<li>• malloc</li>
<li>• free</li>
<li>• va_start, va_arg, va_copy, va_end (see man 3 stdarg)</li>
</ul>
<h2>(Obvious) Unauthorized functions</h2>
<ul>
<li>printf and co. (fprintf, sprintf, snprintf, asprintf, dprintf, vprintf, vfprintf, vsprintf, vsnprintf, vasprintf, vdprintf)</li>
<li>Multiline macros are forbidden</li>
<li>Include another .c is forbidden</li>
<li>Macros with logic (while/if/variables/...) are forbidden</li>
</ul>
<h2>Epilog</h2>
<p>Good luck!</p>

<p></p>

## Usage
To use the `my_printf` function in your C code, follow these steps:

1. Include the `my_printf` function definition in your code.
2. Call `my_printf` in your program, passing the format string and any additional arguments as needed.
   
   ```c
   my_printf("Format string", argument1, argument2, ...);

# Format Specifiers

### my_printf supports the following format specifiers:

    %s - Prints a string.
    %d - Prints a signed integer.
    %c - Prints a single character.
    %u - Prints an unsigned integer.
    %o - Prints an octal number.
    %x - Prints a hexadecimal number (lowercase).
    %p - Prints a pointer address in hexadecimal.

## Installation

To use the `my_printf` function in your project, follow these steps:

1. Copy the `my_printf` function code into your C project.
2. Include the necessary header files (`stdio.h`, `unistd.h`, `stdarg.h`) in your project where you intend to use `my_printf`.
3. Compile your project along with the file containing the `my_printf` function.

## Example

Here's an example demonstrating how to use `my_printf`:

```c
#include <stdio.h>

int main() {
    int num = 42;
    char* str = "Hello, World!";
    printf("Using my_printf: ");
    my_printf("Number: %d, String: %s\n", num, str);

    return 0;
}
```

### Notes

- Ensure that the header files (stdio.h, unistd.h, stdarg.h) are accessible and included properly in your project.
- Handle memory allocation and NULL checks appropriately for %s specifier to avoid segmentation faults.

Feel free to modify and enhance the my_printf function to suit your specific needs or add additional format specifiers as required.