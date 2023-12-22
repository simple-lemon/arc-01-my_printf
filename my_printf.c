#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_d(int num, int *characters){
    char buffer[20];
    int i = num == 0;
    int isNegative = (num < 0) ? (num = -num, 1) : 0;

    while (num) buffer[i++] = num % 10 + '0', num /= 10;
    if (isNegative) buffer[i++] = '-';

    while (i) putchar(buffer[--i]), (*characters)++;
}

void print_c(char c, int *characters){
    putchar(c);
    (*characters)++;
}

void print_s(char *s, int *characters){
    while(*s){
        putchar(*s);
        s++;
        (*characters)++;
    }
}

void print_f(double num, int *characters){
    char buffer[20];
    int i = 0;
    int isNegative = (num < 0) ? (num = -num, 1) : 0;
    int int_part = (int)num;
    double fractional_part = num - int_part;
    while (int_part) {
        buffer[i++] = int_part % 10 + '0';
        int_part /= 10;
    }
    if (isNegative) {
        buffer[i++] = '-';
    }
    if (fractional_part > 0) {
        buffer[i++] = '.';
        int decimal_places = 2;
        for (int j = 0; j < decimal_places; j++) {
            fractional_part *= 10;
            buffer[i++] = (int)fractional_part + '0';
            fractional_part -= (int)fractional_part;
        }
    }

    while (i) {
        putchar(buffer[--i]);
        (*characters)++;
    }
}

void print_p(void *ptr, int *characters) {
    uintptr_t intptr = (uintptr_t)ptr;
    char buffer[20];
    int i = 0;

    if (intptr == 0) {
        buffer[i++] = '0';
    } else {
        while (intptr) {
            int digit = intptr % 16;
            buffer[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
            intptr /= 16;
        }
    }
    while (i) {
        putchar(buffer[--i]);
        (*characters)++;
    }
}

void print_x(unsigned int num, int *characters) {
    char buffer[20];
    int i = 0;
    while (num) {
        int digit = num % 16;
        buffer[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
        num /= 16;
    }
    while (i) {
        putchar(buffer[--i]);
        (*characters)++;
    }
}

void print_u(unsigned int num, int *characters) {
    char buffer [20];
    int i = 0;
    while (num) {
        buffer[i++] = num % 10 + '0';
        num /= 10;
    }
    while (i) {
        putchar(buffer[--i]);
        (*characters)++;
    }
}

void print_o(unsigned int num, int *characters) {
    char buffer [20];
    int i = 0;
    while (num) {
        buffer[i++] = num % 10 + '0';
        num /= 8;
    }
    while (i) {
        putchar(buffer[--i]);
        (*characters)++;
    }
}

int my_printf(const char *format, ...) {
    int characters = 0;
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'd') {
                print_d(va_arg(args, int), &characters);
            } else if (*format == 'c') {
                print_c(va_arg(args, int), &characters);
            } else if (*format == 's') {
                print_s(va_arg(args, char *), &characters);
            } else if (*format == 'f') {
                print_f(va_arg(args, double), &characters);
            } else if (*format == 'p') {
                print_p(va_arg(args, void *), &characters);
            } else if (*format == 'x') {
                print_x(va_arg(args, unsigned int), &characters);
            } else if (*format == 'u') {
                print_u(va_arg(args, unsigned int), &characters);
            } else if (*format == 'o') {
                print_o(va_arg(args, unsigned int), &characters);
            } else {
                putchar('%');
                putchar(*format);
                characters += 2;
            }
        } else {
            putchar(*format);
            characters++;
        }
        format++;
    }

    va_end(args);
    return characters;
}


int main(void)
{
  my_printf("Hello %s, number is %d, float is %f, pointer is %p, hex is 0x%x, unsigned is %u, octal is %o\n", "World", 42, 3.14, (void *)1234, 255, 129, 63);
    return 0;
}
