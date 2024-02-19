#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format) {
        if (*format == '%') {
            format++;

        
            if (*format == 's') {
                char *str = va_arg(args, char*);
                while (*str) {
                    putchar(*str);
                    str++;
                    printed_chars++;
                }
            }

            else if (*format == 'd') {
                int num = va_arg(args, int);
                printf("%d", num);
                printed_chars++;
            }

          
            else if (*format == 'c') {
                char c = (char) va_arg(args, int);
                putchar(c);
                printed_chars++;
            }

            else if (*format == 'u') {
                unsigned int num = va_arg(args, unsigned int);
                printf("%u", num);
                printed_chars++;
            }
            else if (*format == 'x') {
                unsigned int num = va_arg(args, unsigned int);
                printf("%x", num);
                printed_chars++;
            }

            else if (*format == 'p') {
                void *ptr = va_arg(args, void*);
                printf("%p", ptr);
                printed_chars++;
            }

            
            else if (*format == 'n') {
                putchar('\n');
                printed_chars++;
            }

            format++;
        }
        else {
            putchar(*format);
            printed_chars++;
            format++;
        }
    }

    va_end(args);
    return printed_chars;
}

int main() {
    my_printf("Hello, %s! You have %d apples. Character: %c. Unsigned integer: %u. Hexadecimal: %x. Pointer: %p. Newline:%n",
            "world", 5, 'A', 10, 255, (void*)main, NULL);
    return 0;
}
