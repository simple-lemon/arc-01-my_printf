#include <unistd.h>
#include <stdarg.h>
int put_char(char c) {
    return write(1, &c, 1);
}
int put_str(const char* str) {
    int count = 0;
    while (*str != '\0') {
        count += put_char(*str++);
    }
    return count;
}
int put_int(int number) {
    int count = 0;
    if (number < 0) {
        count += put_char('-');
        number = -number;
    }
    int digits = 0;
    int temp = number;
    do {
        digits++;
        temp /= 10;
    } while (temp != 0);
    if (number == 0) {
        count += put_char('0');
        return count;}
    char buffer[digits];
    for (int i = digits - 1; i >= 0; i--) {
        buffer[i] = (number % 10) + '0';
        number /= 10;}
    count += write(1, buffer, digits);
    return count;}
int my_printf(const char* restrict format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;
    while (*format != '\0') {
        if (*format == '%' && *(format + 1) != '\0') {
            format++;
            if (*format == 'd') {
                int number = va_arg(args, int);
                count += put_int(number);
            } else if (*format == 's') {
                char* str = va_arg(args, char*);
                count += put_str(str);
            } else {
                count += put_char('%');
                count += put_char(*format); }
        } else {
            count += put_char(*format);
        }
        format++;}
    va_end(args);
    return count;
}
int main() {
    char param[] = " H e l l o ";
    my_printf("%s", param);
    return 0;
}

