#include <stdarg.h>
#include <unistd.h>

static void print_int(int num, int base) {
    static const char digits[] = "0123456789abcdef";
    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }
    if (num >= base) {
        print_int(num / base, base);
        num %= base;
    }
    write(1, &digits[num], 1);
}

static void print_str(const char *str) {
    for (; *str; ++str) {
        write(1, str, 1);
    }
}

int my_print(const char * restrict format, ...) {
    va_list args;
    va_start(args, format);
    for (; *format; ++format) {
        if (*format != '%') {
            write(1, format, 1);
        } else {
            ++format;
            switch (*format) {
                case 'd':
                case 'i':
                    print_int(va_arg(args, int), 10);
                    break;
                case 'o':
                    print_int(va_arg(args, unsigned int), 8);
                    break;
                case 'u':
                    print_int(va_arg(args, unsigned int), 10);
                    break;
                case 'x':
                    print_int(va_arg(args, unsigned int), 16);
                    break;
                case 'c':
                    {
                        char c = (char) va_arg(args, int);
                        write(1, &c, 1);
                    }
                    break;
                case 's':
                    print_str(va_arg(args, const char *));
                    break;
                case 'p':
                    {
                        void *ptr = va_arg(args, void *);
                        print_str("0x");
                        print_int((unsigned long) ptr, 16);
                    }
                    break;
                default:
                    write(1, format - 1, 1);
                    break;
            }
        }
    }
    va_end(args);
    return 0;
}
int main(){
    my_print("hello world");
}