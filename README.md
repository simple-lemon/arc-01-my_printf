# Welcome to My Printf
***

## Task

The my_printf.c file contains the implementation of the my_printf function, which is a custom implementation of the printf function in C. 
The purpose of my_printf is to print formatted output to the console.
The my_printf function takes a format string (p1) as its first argument, followed by a variable number of arguments (...) 
that correspond to the values to be formatted and printed. The function iterates over the characters in the format string 
and performs specific actions based on the format specifiers encountered.
Here's an overview of the different format specifiers and their corresponding actions within the switch statement:
When executed, the program will execute the my_printf function with the specified format strings and display the formatted output on the console.
That's an overview of the my_printf.c project. It provides a custom implementation of a formatted printing function in C, allowing for flexible and customizable output formatting.

## Description

'c': This specifier expects an int argument and prints the corresponding character to the console.
's': This specifier expects a char* argument (a string) and prints the string to the console.
'd': This specifier expects an int argument and converts the integer to a string representation using the int_to_char_two function. The resulting string is then printed to the console.
'o': This specifier expects an int argument and converts the integer to an octal (base 8) string representation using the int_to_char function. The resulting string is then printed to the console.
'u': This specifier expects an unsigned int argument and converts the unsigned integer to a string representation using the int_to_char_two function. The resulting string is then printed to the console.
'x': This specifier expects an int argument and converts the integer to a hexadecimal (base 16) string representation using the dec_to_hex function. The resulting string is then printed to the console.
'p': This specifier expects an unsigned long int argument and converts the unsigned long integer to a hexadecimal string representation using the dec_to_hex function. The resulting string is preceded by "0x" and then printed to the console.

## Installation

The my_printf function utilizes several helper functions defined in the file:
push_str: This function prints a null-terminated string to the console by iterating over its characters and using the write function from <unistd.h>.
my_strlen: This function calculates the length of a null-terminated string.
my_reverse: This function reverses a given string by swapping characters.
int_to_char_two: This function converts a number to a string representation in base 10, taking care of negative numbers.
int_to_char: This function converts a number to a string representation in base 8 (octal).
dec_to_hex: This function converts a number to a string representation in base 16 (hexadecimal).
At the end of the file, there is a basic main function that serves as the entry point of the program. You can modify this main function to test and demonstrate the usage of the my_printf function by calling it with different format strings and arguments.
To compile and run the program, you can use a C compiler such as GCC: gcc -o my_printf my_printf.c
./my_printf

## Usage

The code you provided contains a switch statement inside the my_printf function. 
The switch statement is used to evaluate the value of a given expression (p1[i] in this case) 
and execute the code block associated with the matching case.
In your code, the switch statement is used to handle different format specifiers that can be passed to my_printf. 
Each case inside the switch statement corresponds to a different format specifier (e.g., 'c', 's', 'd', 'o', 'u', 'x', 'p'). 
When the expression matches a specific case, the corresponding code block is executed.
For example, if the format specifier is 'c', the code block under the case 'c' will be executed. 
Similarly, for the format specifier 's', the code block under the case 's' will be executed, and so on.
Each case block contains specific code to handle the respective format specifier, such as printing a character, 
printing a string, converting an integer to a string, or converting a decimal number to hexadecimal.
Overall, the switch statement allows the code to determine the appropriate action based on the value of the format specifier, 
providing flexibility and modularity to the my_printf function.


### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
