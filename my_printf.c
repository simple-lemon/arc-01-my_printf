#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int my_putChar(char strings_c) {
    if (strings_c != '\0') {
        write(1, &strings_c, 1);
        return 1;
    }

    return 0;
}

int print_d(int num) {
    int box = 0;

    if (num < 0) {
     box += my_putChar('-');
        num *= -1;
    }

    if (num > 9) {
     box += print_d(num / 10);
    }

    return box + my_putChar(num % 10 + '0');
}

int unsigned_d(unsigned int num) {
    int box = 0;
    if (num > 9) {
     box += unsigned_d(num / 10);
    }
    return box + my_putChar(num % 10 + '0');
}

int print_o(unsigned int num) {
    int box = 0;
    if (num > 7) {
     box += print_o(num / 8);
    }
    return box + my_putChar(num % 8 + '0');
}

int print_x(unsigned long int num) {
    int box = 0;
    if (num > 15) {
     box += print_x(num / 16);
    }
    if (num % 16 > 9 && num % 16 < 16) {
        return box + my_putChar(num % 16 - 10 + 'A');
    } else {
        return box + my_putChar(num % 16 + '0');
    }
}

int my_putStr(char *s) {
    int box = 0;

    for (int i = 0; s[i] != '\0'; i++) {
     box += my_putChar(s[i]);
    }

    return box;
}

int my_printf(char *strings, ...) {
    va_list ap;
    char *s;
    int d, design = 0;
    unsigned int u;
    intptr_t x;

    va_start(ap, strings);

    for (; *strings; strings++) {
        if (*strings == '%') {
            strings++;
            switch (*strings) {
                case 's':
                    s = va_arg(ap, char *);
                    if (!s || !*s) {
                        design += my_putStr("(null)");
                        design += 6;
                    } else {
                        design += my_putStr(s);
                    }
                    break;
                case 'd':
                    d = va_arg(ap, int);
                    design += print_d(d);
                    break;
                case 'c':
                    d = va_arg(ap, int);
                    design += my_putChar(d);
                    break;
                case 'u':
                    u = va_arg(ap, unsigned int);
                    design += unsigned_d(u);
                    break;
                case 'o':
                    u = va_arg(ap, int);
                    design += print_o(u);
                    break;
                case 'x':
                    x = va_arg(ap, intptr_t);
                    design += print_x(x);
                    break;
                case 'p':
                    x = va_arg(ap, intptr_t);
                    design += my_putChar('0') + print_x(x);
                    break;
                default:
                    design += my_putChar('%');
                    break;
            }
        } else {
            design += my_putChar(*strings);
        }
    }

    va_end(ap);

    return design;
}

int main() {
    int strings = 5;

    my_printf("%d", strings);

    return 0;
}
