#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int write_char(char c) {
    return write(1, &c, 1);
}

int write_string(const char *str) {
    return write(1, str, strlen(str));
}

int print_hex(unsigned int number) {
    int len = 0;
    if (number > 15)
        len += print_hex(number / 16);
    if (number % 16 < 10)
        return (len + write_char(number % 16 + '0'));
    else
        return (len + write_char(number % 16 + 'a' - 10));
}

char* convert_to_octal(int num) {
    char* str = malloc(20);
    char* res = malloc(20);
    int i = 0;
    while (num) {
        str[i++] = num % 8 + '0';
        num /= 8;
    }
    i = 0;
    for (int j = strlen(str) - 1; j >= 0; j--) {
        res[i++] = str[j];
    }
    return res;
}

char* convert_to_string(int num) {
    if (num == 0) return "0";
    char* string = malloc(20);
    char* reverse = malloc(20);
    int i = 0;

    if (num < 0) {
        num *= -1;
        while (num) {
            string[i++] = num % 10 + '0';
            num /= 10;
        }
        string[i++] = '-';
        i = 0;
        for (int j = strlen(string) - 1; j >= 0; j--) {
            reverse[i++] = string[j];
        }
    } else {
        while (num) {
            string[i++] = num % 10 + '0';
            num /= 10;
        }
        i = 0;
        for (int j = strlen(string) - 1; j >= 0; j--) {
            reverse[i++] = string[j];
        }
    }
    return reverse;
}

int my_printf(char * str, ...) {
    int num;
    intptr_t x;
    char c;
    int size = 0;
    char* string = malloc(20);
    va_list list;
    va_start(list, str);

    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            i++;
            switch (str[i]) {

            case 'c':
                c = va_arg(list, int);
                write_char(c);
                size++;
                break;

            case 's':
                string = va_arg(list, char*);
                if (string == NULL) {
                    string = "(null)";
                }
                size += write_string(string);
                break;

            case 'd':
                num = va_arg(list, int);
                string = convert_to_string(num);
                size += write_string(string);
                break;

            case 'o':
                num = va_arg(list, int);
                string = convert_to_octal(num);
                size += write_string(string);
                break;

            case 'u':
                num = va_arg(list, int);
                string = convert_to_string(num);
                size += write_string(string);
                break;

            case 'x':
                x = va_arg(list, intptr_t);
                size += print_hex(x);
                break;

            case 'p':
                x = va_arg(list, intptr_t);
                size += write_string("0x") + print_hex(x);
                break;
            }
        } else {
            size++;
            write_char(str[i]);
        }
    }

    va_end(list);
    return size;
}

int main(void) {
    int size =  my_printf("%d!\n", -434);
    printf("%d", size);
    return 0;
}
