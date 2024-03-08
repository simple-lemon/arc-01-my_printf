## my_printf: A simplified implementation of printf

### Task

This project implements a custom `my_printf` function that replicates basic functionalities of the standard C library function `printf`.

### Description

`my_printf` allows formatted output based on a format string and variable arguments. It supports essential format specifiers for printing characters, strings, signed and unsigned integers (including octal, hexadecimal, and pointer addresses). 

**Key points:**

* Focuses on core functionalities.
* Lacks features like floating-point number handling, precision control, and formatting flags.


### Installation

This code is designed to be directly integrated into your C project. No separate installation is required.

1. **Copy the code:** Save the provided C code (`my_printf.c` and `int_to_str.c` if the conversion function is in a separate file) into your project directory.
2. **Include the header:** Add `#include "my_printf.h"` (assuming the header file is named `my_printf.h`)  at the beginning of your C source file where you want to use `my_printf`.


### Usage

**1. Include the header:**

```c
#include "my_printf.h"
```

**2. Call `my_printf` with a format string and arguments:**

```c
int number = 42;
char message[] = "This is a message";

my_printf("The number is %d and the message is %s\n", number, message);
```

This code will print:

```
The number is 42 and the message is This is a message
```

**3. Supported format specifiers:**

* `%c`: Prints a single character argument.
* `%s`: Prints a null-terminated string argument.
* `%d`: Prints a signed integer argument.
* `%o`: Prints an unsigned integer argument in octal (base 8).
* `%x`: Prints an unsigned integer argument in hexadecimal (base 16).
* `%u`: Prints an unsigned integer argument.
* `%p`: Prints a pointer argument as a hexadecimal address.
