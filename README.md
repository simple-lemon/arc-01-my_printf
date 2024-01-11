# Welcome to My Printf
My_printf project

## Task
To create an implementation of printf() function to print specifiers.

## Description
In the project "My_printf" I implemented %d, %c, %s, %p, %u, and %x. To create an implementation of this format, specifiers used some implemented functions, which are: my_stringcpy(), my_putschr(), my_string_putschr(), my_character_putschr(), my_strlen(), my_reverse(), my_pow(), num_length(), my_itoa(), my_octal_print(), my_unsigned_number_print(), my_hexadecimal_print(), my_pointer_print(), my_string_print().
• my_putschr() - is created to print the %d format specifier.
• my_string_putschr() - is created to print the %s string.
• my_character_putschr() - is created to print %c characters.
• my_strlen() - is created to get the length of the string just in case to reverse %d and print it.
• my_reverse() - is used to reverse the string in %d.
• my_pow() - an implementation of pow(); used to calculate the power of the given number.
• my_stringcpy() - is the implementation of strcpy(); It is used to copy from one string to another.
• num_length() - is used to count the length of the array string.
• my_itoa() - is implementation of itoa(); Used it to change a number to a string to print %d.
• my_octal_print() - is used to print %c (octal numbers).
• my_unsigned_number_print() - is used to print %u (unsigned decimal).
• my_hexadecimal_print() - is used to print %x (hexadecimal).
• my_pointer_print() - is used to print %p (pointer).
•my_string_print() - is used to print %s (strings).
• my_printf() - is the implementation of printf(); Used to print all the characters and strings that are given in the main() function.
In the project used "flag" to check if it was true or false. Eliminated memory leaks by using the free() function. Allocated strings are created by using calloc() and malloc(). Used va_list, va_start, and va_arg to declare, initialize, and modify the variable. write() function is used to print the variables instead of printf() function.

## Installation
first:
write make on terminal and call ./my_printf

## Usage
You may check it via gandalf tests

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
