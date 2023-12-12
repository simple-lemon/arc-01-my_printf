#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int put_char(char param_c) {
    int neg_number = 0;
    int pos_number = 1;

    if (param_c != '\0') {
        write(1, &param_c, 1);
        return pos_number;
    }

    return neg_number;
}

int percent_d(int number) {
    int temp = 0;

    if (number < 0) {
        temp += put_char('-');
        number *= -1;
    }

    if (number > 9) {
        temp += percent_d(number / 10);
    }

    return temp + put_char(number % 10 + '0');
}

int unsig_d(unsigned int number) {
    int temp = 0;
    if (number > 9) {
        temp += unsig_d(number / 10);
    }
    return temp + put_char(number % 10 + '0');
}

int percent_o(unsigned int number) {
    int temp = 0;
    if (number > 7) {
        temp += percent_o(number / 8);
    }
    return temp + put_char(number % 8 + '0');
}

int percent_x(unsigned long int number) {
    int temp = 0;
    if (number > 15) {
        temp += percent_x(number / 16);
    }
    if (number % 16 > 9 && number % 16 < 16) {
        return temp + put_char(number % 16 - 10 + 'A');
    } else {
        return temp + put_char(number % 16 + '0');
    }
}

int putStr(char *string) {
    int temp = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        temp += put_char(string[i]);
    }

    return temp;
}

int my_printf(char *param, ...) {
    va_list ap;
    char *str;
    int d, design = 0;
    unsigned int u;
    intptr_t x;

    va_start(ap, param);

    for (; *param; param++) {
        if (*param == '%') {
            param++;
            switch (*param) {
                case 's':
                    str = va_arg(ap, char *);
                    if (!str || !*str) {
                        design += putStr("(null)");
                        design += 6;
                    } else {
                        design += putStr(str);
                    }
                    break;
                case 'd':
                    d = va_arg(ap, int);
                    design += percent_d(d);
                    break;
                case 'c':
                    d = va_arg(ap, int);
                    design += put_char(d);
                    break;
                case 'u':
                    u = va_arg(ap, unsigned int);
                    design += unsig_d(u);
                    break;
                case 'o':
                    u = va_arg(ap, int);
                    design += percent_o(u);
                    break;
                case 'x':
                    x = va_arg(ap, intptr_t);
                    design += percent_x(x);
                    break;
                case 'p':
                    x = va_arg(ap, intptr_t);
                    design += put_char('0') + percent_x(x);
                    break;
                default:
                    design += put_char('%');
                    break;
            }
        } else {
            design += put_char(*param);
        }
    }

    va_end(ap);

    return design;
}

int main() {
    char* param = "string";

    my_printf("%s", param);

    return 0;
}
