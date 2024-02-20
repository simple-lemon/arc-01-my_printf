#include <stdarg.h>
#include <unistd.h>

static void prnt_int(int num, int base) {
    static char digits[] = "0123456789abcdef";
    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }
    if (num >= base)
        prnt_int(num / base, base);
    write(1, &digits[num % base], 1);
}

static void pnt_str(const char *str) {
    for (; *str; str++)
        write(1, str, 1);
}

int My_Printf(const char * restrict format, ...) {
    va_list args;
    va_start(args, format);
    for (; *format; format++) {
        if (*format != '%') {
            write(1, format, 1);
            continue;
        }
        format++;
        switch (*format) {
            case 'd':
            case 'i':
                prnt_int(va_arg(args, int), 10);
                break;
            case 'o':
                prnt_int(va_arg(args, unsigned int), 8);
                break;
            case 'u':
                prnt_int(va_arg(args, unsigned int), 10);
                break;
            case 'x':
                prnt_int(va_arg(args, unsigned int), 16);
                break;
            case 'c':
                write(1, &(char){va_arg(args, int)}, 1);
                break;
            case 's':
                pnt_str(va_arg(args, const char *));
                break;
            case 'p':
                pnt_str("0x");
                prnt_int(va_arg(args, unsigned long), 16);
                break;
            default:
                write(1, format - 1, 1);
                break;
        }
    }
    va_end(args);
}
int main() {
    
    My_Printf("MY Printf\n");

    My_Printf("%c\n", 'X');

    My_Printf("%s\n", "Asror");

    My_Printf("%d\n", 17);
  
    return 0;
}