#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
int my_putchar (char c) {
    write(1, &c, 1);
    return (1);
}

int printd (int nbr) {
    int len = 0;
    if (nbr < 0) {
        len += my_putchar('-');
        nbr *= -1;
    }
    if (nbr > 9)
        len += printd(nbr / 10);
    return (len + my_putchar(nbr % 10 + '0'));
}

int printud (unsigned int nbr) {
    int len = 0;
    if (nbr > 9)
        len += printud(nbr / 10);
    return (len + my_putchar(nbr % 10 + '0'));
}

int printfo (unsigned int nbr) {
    int len = 0;
    if (nbr > 7)
        len += printfo(nbr / 8);
    return (len + my_putchar(nbr % 8 + '0'));
}

int printx (unsigned long int nbr) {

    int len = 0;
    if (nbr > 15)
        len += printx(nbr / 16);
    if (nbr%16 > 9 && nbr%16 < 16)
        return (len + my_putchar(nbr%16-10 + 'A'));
    else
        return (len + my_putchar(nbr % 16  + '0'));
}




int my_putstr(char *s) {
    int len = 0;
    while (*s)
        len += my_putchar(*s++);
    return len;
}





int my_printf(char* format, ...) {

    va_list ap;
    char *s, c;
    int d;
    unsigned int u;
    intptr_t x;
    int len = 0;

    va_start(ap, format);

    while (*format) {
        if (*format == '%') {
            switch (*++format) {
                case 's':
                    s = va_arg(ap, char *);
                    if(!s || !*s) {
                        len += my_putstr("(null)");
                        len += 6;
                    }
                    else
                    len += my_putstr(s);
                    break;

                case 'd':
                    d = va_arg(ap, int);
                    len += printd(d);
                    break;

                case 'c':
                    c = va_arg(ap, int);
                    len += my_putchar(c);
                    break;

                case 'u':
                    u = va_arg(ap, unsigned int);
                    len += printud(u);
                    break;

                case 'o':
                    u = va_arg(ap, unsigned int);
                    len += printfo(u);
                    break;

                case 'x':
                    x = va_arg(ap, intptr_t);
                    len += printx(x);
                    break;

                case 'p':
                    x = va_arg(ap, intptr_t);
                    len += my_putstr("0x") + printx(x);
                    break;

                default:
                    len += my_putchar('%');
            }
            format++;
        }
        if (*format != '%') {
            len += my_putchar(*format);
            format++;
        }
    }
    va_end(ap);

    return (len);
}
