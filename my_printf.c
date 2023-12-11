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

