#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[BUFFER_SIZE];
    int printed = vsnprintf(buffer, BUFFER_SIZE, format, args);

    if (printed >= BUFFER_SIZE) {
        fprintf(stderr, "Error: Output exceeded buffer size.\n");
    } else {
        write(1, buffer, printed);
    }

    va_end(args);
}

int main() {
    int num = 42;
    char ch = 'A';
    char *str = "Hello, World!";
    void *ptr = (void *)main;

    my_printf("Integer: %d\nCharacter: %c\nString: %s\nPointer: %p\n", num, ch, str, ptr);

    return 0;
}
