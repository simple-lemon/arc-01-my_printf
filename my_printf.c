#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int my_printf(char * restrict format, ...) {
    va_list args;
    va_start(args, format);

    char *p = format;
    while (*p != '\0') {
        if (*p == '%') {
            p++; 
            switch (*p) {
                case 'd':
                    break;

                case 'o':
                    break;

                default:
                    write(1, "%", 1);
                    break;
            }
        } else {
            write(1, p, 1);
        }
        p++;
    }

    va_end(args);
    return 0;
}

int main() {
    int num = 42;
    char ch = 'A';
    char *str = "Hello, World!";
    void *ptr = (void *)main;

    my_printf("Integer: %d\nCharacter: %c\nString: %s\nPointer: %p\n", num, ch, str, ptr);

    return 0;
}
