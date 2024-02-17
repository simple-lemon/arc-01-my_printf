#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    for (const char *p = format; *p; ++p) {
        if (*p == '%') {
            ++p;
            switch (*p) {
                case 'd': {
                    int arg = va_arg(args, int);
                    printf("%d", arg);
                    break;
                }
                case 'c': {
                    int arg = va_arg(args, int);
                    printf("%c", arg);
                    break;
                }
                case 's': {
                    const char *arg = va_arg(args, const char *);
                    printf("%s", arg);
                    break;
                }
                case 'p': {
                    void *arg = va_arg(args, void *);
                    printf("%p", arg);
                    break;
                }
                case 'x': {
                    int arg = va_arg(args, int);
                    printf("%x", arg);
                    break;
                }
                case 'u': {
                    int arg = va_arg(args, int);
                    printf("%u", arg);
                    break;
                }
                case 'o': {
                    int arg = va_arg(args, int);
                    printf("%o", arg);
                    break;
                }
                default:
                    putchar(*p);
                    break;
            }
        } else {
            putchar(*p);
        }
    }

    va_end(args);
}

int main() {
    my_printf("Hello, %s! Your number is %d.\n", "Alice", 42);
    my_printf("Here is a pointer: %p\n", &main);
    return 0;
}