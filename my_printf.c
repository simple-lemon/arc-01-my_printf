#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int my_putchar(char c) {
    return write(1, &c, 1);
}

int my_putstr(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        my_putchar(str[len]);
        len++;
    }
    return len;
}

int my_putnbr(int n) {
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        my_putnbr(n / 10);
    }
    my_putchar(n % 10 + '0');
    return 0;
}

int my_printf(char *restrict format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    char *str_arg;
    int int_arg;

    while (*format != '\0') {
        if (*format == '%') {
            format++;

            switch (*format) {
                case 'c':
                    int_arg = va_arg(args, int);
                    count += my_putchar((char)int_arg);
                    break;
                case 's':
                    str_arg = va_arg(args, char *);
                    count += my_putstr(str_arg);
                    break;
                case 'd':
                    int_arg = va_arg(args, int);
                    count += my_putnbr(int_arg);
                    break;
                default:
                    break;
            }
        } else {
            count += my_putchar(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}