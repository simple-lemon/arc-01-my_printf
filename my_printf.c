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
    if (i == 0) // If the number is 0, represent it as '0'
        str[i++] = '0';
    i = 0;
    for (int j = strlen(str) - 1; j >= 0; j--) {
        res[i++] = str[j];
    }
    free(str); // Free the allocated memory
    return res;
}

char* convert_to_string(int num) {
    char* string = malloc(20);
    char* reverse;
    int i = 0;
    if (num < 0) {
        num *= -1;
        while (num) {
            string[i++] = num % 10 + '0';
            num /= 10;
        }
        string[i++] = '-';
    } else {
        while (num) {
            string[i++] = num % 10 + '0';
            num /= 10;
        }
    }
    if (i == 0) // If the number is 0, represent it as '0'
        string[i++] = '0';
    string[i] = '\0';
    reverse = malloc(strlen(string) + 1);
    for (int j = strlen(string) - 1, k = 0; j >= 0; j--, k++) {
        reverse[k] = string[j];
    }
    reverse[strlen(string)] = '\0';
    free(string); // Free the allocated memory
    return reverse;
}

int my_printf(char * str, ...) {
    int num;
    intptr_t x;
    char c;
    int size = 0;
    char* string;
    va_list list;
    va_start(list, str);

    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            i++;
            switch (str[i]) {
            case 'c':
                c = va_arg(list, int);
                size += write_char(c);
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

            case 'u':
                num = va_arg(list, int);
                string = convert_to_string(num);
                size += write_string(string);
                free(string); // Free the allocated memory
                break;

            case 'o':
                num = va_arg(list, int);
                string = convert_to_octal(num);
                size += write_string(string);
                free(string); // Free the allocated memory
                break;

            case 'x':
                x = va_arg(list, intptr_t);
                size += print_hex(x);
                break;

            case 'p':
                x = va_arg(list, intptr_t);
                size += print_hex(x);
                break;
            }
        } else {
            size += write_char(str[i]);
        }
    }

    va_end(list);
    return size;
}

int main(void) {
  printf("Hello %s\n", "World");
  printf("number is %d\n", 42);
  printf("float is %f\n", 3.14);
  printf("pointer is %p\n", (void *)1234);
  printf("hex is Ox%x\n", 255);
  printf("unsigned is %u\n", 128);
  printf("octal is %o\n", 61);
  return 0;
}