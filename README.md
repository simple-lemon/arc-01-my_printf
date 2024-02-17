# Custom Print Function

This code provides a custom print function called `my_print` that can be used to print formatted strings. It supports the following format specifiers:

- `%d` or `%i`: Print a signed decimal integer.
- `%o`: Print an unsigned octal integer.
- `%u`: Print an unsigned decimal integer.
- `%x`: Print an unsigned hexadecimal integer.
- `%c`: Print a character.
- `%s`: Print a string.
- `%p`: Print a pointer.

To use the `my_print` function, include the provided code in your program. Then, you can call the function with a format string and a variable number of arguments. The format string should contain the format specifiers described above, and the arguments should be the values to be printed.

Here is an example of how to use the `my_print` function:

```c
#include <stdarg.h>
#include <unistd.h>

// ... (Include the provided code here)

int main(){
    my_print("hello world");
    my_print("The answer is %d", 42);
    my_print("The answer is %o", 42);
    my_print("The answer is %u", 42);
    my_print("The answer is %x", 42);
    my_print("The answer is %c", 'A');
    my_print("The answer is %s", "A");
    my_print("The answer is %p", (void *) 0x12345678);
    return 0;
}