#include <stdarg.h>
#include <stdio.h>
void print_int(int num)
{
    if (num < 0)
    {
        putchar('-');
        num = -num;
    }
    int power = 1;
    while (power <= num / 10)
    {
        power *= 10;
    }

    while (power > 0)
    {
        int digit = num / power;
        putchar('0' + digit);
        num %= power;
        power /= 10;
    }
}
void print_hex(int num)
{
    unsigned int mask = 0xF0000000;
    int shift = 28;

    while (shift >= 0)
    {
        int digit = (num & mask) >> shift;
        if (digit < 10)
        {
            putchar('0' + digit);
        }
        else
        {
            putchar('A' + digit - 10);
        }
        mask >>= 4;
        shift -= 4;
    }
}
void print_ptr(void *ptr)
{
    unsigned long address = (unsigned long)ptr;
    print_hex((int)(address > 32));
    print_hex((int)address);
}
int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int character = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case 'd':
            {
                int num = va_arg(args, int);
                print_int(num);
                break;
            }
            case 'f':
            {
                double floatNum = va_arg(args, double);
                int intPart = (int)floatNum;
                print_int(intPart);
                break;
            }
            case 's':
            {
                character++;
                char *str = va_arg(args, char *);
                while (*str)
                {
                    putchar(*str);
                    str++;
                }
                break;
            }
            case 'c':
            {
                character++;
                char character = va_arg(args, int);
                putchar(character);
                break;
            }
            case 'x':
            {
                int hexNum = va_arg(args, int);
                print_hex(hexNum);
                break;
            }
            case 'p':
            {
                void *ptr = va_arg(args, void *);
                print_ptr(ptr);
                break;
            }
            case '%':
                putchar('%');
                break;
            default:
                break;
            }
        }
        else
        {
            putchar(*format);
            character++;
        }

        format++;
    }
    va_end(args);
    return character;
}

int main()
{
    int num = 42;
    float floatNum = 3.14;
    char character = 'A';

    my_printf("integer: %d\n", num);
    my_printf("float: %f\n", floatNum);
    my_printf("character: %c\n", character);

    return 0;
}
