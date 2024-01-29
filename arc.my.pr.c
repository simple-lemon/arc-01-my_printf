#include <stdarg.h>
#include <stdio.h>

int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%' && *(format + 1) != '\0') {
            switch (*(format + 1)) {
                case 'd': {
                    int value = va_arg(args, int);
                    printf("%d", value);
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    if (str != NULL) {
                        printf("%s", str);
                    }
                    break;
                }
                default:
                    putchar(*format);
                    break;
            }
            format += 2; 
        } else {
            putchar(*format);
            format++;
        }
    }

    va_end(args);
    return 0;
}

int main()
{
    my_printf("Welcome to my program! %s\n", "Hello");

    return 0;
}
