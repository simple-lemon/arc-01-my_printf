# my_printf Project

## Introduction
This project involves implementing a simplified version of the printf function in the C programming language. The custom function, `my_printf`, will be responsible for formatting and writing output to the standard output stream.

## Description
The `my_printf` function processes a format string, which may contain ordinary characters and conversion specifications. Conversion specifications are introduced by the PERCENT character (%) and specify how subsequent arguments should be converted for output. The supported conversion specifiers include:
- `%c`: Convert an integer argument to an unsigned char and write the resulting character.
- `%s`: Expect a pointer to a string (char *) and write characters from the array up to the null terminator.
- `%d`, `%o`, `%u`, `%x`: Convert integer arguments to signed decimal, unsigned octal, unsigned decimal, and unsigned hexadecimal, respectively.
- `%p`: Print the value of a void pointer in hexadecimal.

## Requirements
- The code must be compiled with the flags `-Wall -Wextra -Werror`.
- Memory leaks should be avoided, and the code can be tested against memory errors using debugging flags `-g3 -fsanitize=address`.
- Global variables and static variables are strictly forbidden.
- The following functions are authorized: `write(2)`, `malloc`, `free`, `va_start`, `va_arg`, `va_copy`, `va_end` (as specified in `man 3 stdarg`).
- The use of printf and related functions is not allowed.

## Usage

1. Clone the repository:
```bash
   git clone https://github.com/GlitchLxrd/my_printf.git
```
2. Navigate to the project directory:
```bash
   cd my_printf
```

3. Build the executable:
```bash
make
```

4. Run the executable:
```bash
./my_printf
```
This will demonstrate the usage of the my_printf function with sample input.


5. If you want to use it in your code then :
```bash
#include "my_printf.h"

int main() {
    my_printf("Hello, %s! The answer is %d.\n", "World", 42);

    return 0;
}
```

## Dev Team

- a.malikov@st.astrum.uz