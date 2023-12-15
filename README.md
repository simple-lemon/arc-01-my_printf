# Welcome to my printf code

## Task 


## Project Structure
- **Submit Directory:** 
- **Submit File:** `my_printf.c`

## Description
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

## Installation
- First, include the declaration of your my_printf function in a header file (let's call it my_printf.h)
- Create a source file (let's call it my_printf.c) where you define the actual implementation of your my_printf function
- Compile your source files (my_printf.c and other necessary files) into an object file using a C compiler. `gcc -c my_printf.c -o my_printf.o`
- Write a test program that includes the my_printf header and links to the compiled object file
- Compile your test program and link it with the my_printf.o object file `gcc main.c my_printf.o -o my_program`
- Run the compiled program `./my_program`