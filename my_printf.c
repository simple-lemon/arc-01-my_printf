#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

char* int_to_str(unsigned int num, int base, int use_uppercase);

int my_printf(char * restrict format, ...);

char* int_to_str(unsigned int num, int base, int use_uppercase) 
{
    static char buffer[32];
    int i = 30;
    buffer[i--] = '\0';

    if (num == 0) {
        buffer[i--] = '0';
    } else {
        while (num > 0) {
            char digit;
            if (num % base > 9) {
                if (use_uppercase) {
                    digit = 'A' + num % base - 10;
                } else {
                    digit = 'a' + num % base - 10;
                }
            } else {
                digit = '0' + num % base;
            }
            buffer[i--] = digit;
            num /= base;
        }
    }

    return &buffer[i + 1];
}

int my_printf(char * restrict format, ...) {
    va_list args;
    va_start(args, format);

    int total = 0;
    char ch;

    while ((ch = *format++)) {
        if (ch != '%') {
            total += write(1, &ch, 1);
        } else {
            ch = *format++;
            switch (ch) {
                case 'c': {
                    char char_arg = va_arg(args, int);
                    total += write(1, &char_arg, 1);
                    break;
                }
                case 's': {
                    char* str_arg = va_arg(args, char*);
                    if (str_arg != NULL) {
                        total += write(1, str_arg, strlen(str_arg));
                    } else {
                        total += write(1, "(null)", 6);
                    }
                    break;
                }
                case 'd': {
                    int num_arg = va_arg(args, int);
                    if (num_arg < 0) {
                        total += write(1, "-", 1);
                        total += write(1, int_to_str(-num_arg, 10, 0), strlen(int_to_str(-num_arg, 10, 0)));
                    } else {
                        total += write(1, int_to_str(num_arg, 10, 0), strlen(int_to_str(num_arg, 10, 0)));
                    }
                    break;
                }
                case 'o':
                case 'x': {
                    unsigned int num_arg = va_arg(args, unsigned int);
                    total += write(1, int_to_str(num_arg, (ch == 'o') ? 8 : 16, (ch == 'x')), strlen(int_to_str(num_arg, (ch == 'o') ? 8 : 16, (ch == 'x'))));
                    break;
                }
                case 'u': {
                    unsigned int uns_arg = va_arg(args, unsigned int);
                    total += write(1, int_to_str(uns_arg, 10, 0), strlen(int_to_str(uns_arg, 10, 0)));
                    break;
                }
                case 'p': {
                    total += write(1, "0x", 2); 
                    total += write(1, int_to_str((long)va_arg(args, void*), 16, 0), strlen(int_to_str((long)va_arg(args, void*), 16, 0)));
                    break;
                }
                default:
                    total += write(1, &ch, 1);
                    break;
            }
        }
    }

    va_end(args);
    return total;
}