#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_d(int num, int *characters) {
    char buffer[20];
    int i;

    if (num == 0) {
        i = 1;
    } else {
        i = 0;
    }

    int isNegative = 0;
    if (num < 0) {
        num = -num;
        isNegative = 1;
    }

    while (num) {
        buffer[i++] = num % 10 + '0';
        num /= 10;
    }

    if (isNegative) {
        buffer[i++] = '-';
    }

    while (i) {
        putchar(buffer[--i]);
        (*characters)++;
    }
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

void print_f(double num, int *characters) {
    char buffer[20];
    int i = 0;

    int isNegative = 0;
    if (num < 0) {
        num = -num;
        isNegative = 1;
    }

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
        buffer[i] = '0';
        i++;
    } else {
        while (intptr) {
            int digit = intptr % 16;
            if (digit < 10) {
                buffer[i] = digit + '0';
            } else {
                buffer[i] = digit - 10 + 'a';
            }
            i++;
            intptr /= 16;
        }
    }

    while (i) {
        i--;
        putchar(buffer[i]);
        (*characters)++;
    }
}


void print_x(unsigned int num, int *characters) {
    char buffer[20];
    int i = 0;

    while (num) {
        int digit = num % 16;
        if (digit < 10) {
            buffer[i] = digit + '0';
        } else {
            buffer[i] = digit - 10 + 'a';
        }
        i++;
        num /= 16;
    }

    while (i) {
        i--;
        putchar(buffer[i]);
        (*characters)++;
    }
}


void print_u(unsigned int num, int *characters) {
    char buffer[20];
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
    char buffer[20];
    int i = 0;

    while (num) {
        buffer[i++] = num % 8 + '0';
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


int main(void) {
  my_printf("Hello %s\n", "World");
  printf("number is %d\n", 42);
  printf("float is %f\n", 3.14);
  printf("pointer is %p\n", (void *)1234);
  printf("hex is Ox%x\n", 255);
  printf("unsigned is %u\n", 128);
  printf("octal is %o\n", 61);
  return 0;
}
