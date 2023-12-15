#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int my_putchar(char character)
{
    int fir_number = 0;
    int sec_number = 1;

    if (character != '\n')
    {
        write(1, &character, 1);
        return sec_number;
    }
    else
    {
        return fir_number;
    }
}

int per_d(int number)
{
    int swetch = 0;
    if (number < 0)
    {
        swetch += my_putchar('-');
        number *= -1;
    }
    if (number > 9)
        swetch += per_d(number / 10);
    return (swetch + my_putchar(number % 10 + '0'));
}

int per_u_d(unsigned int number)
{
    int swetch = 0;

    if (number > 9)
    {
        swetch += per_u_d(number / 10);
        return (swetch + my_putchar(number % 10 + '0'));
    }
}

int per_o(unsigned int number)
{
    int swetch = 0;
    if (number > 7)
    {
        swetch += printfo(number / 8);
        return (swetch + my_putchar(number % 8 + '0'));
    }
}

int per_x(unsigned long int number)
{

    int swetch = 0;
    if (number > 15)
    {
        swetch += per_x(number / 16);
    }

    if (number % 16 > 9 && number % 16 < 16)
    {
        return (swetch + my_putchar(number % 16 - 10 + 'A'));
    }

    else
    {
        return (swetch + my_putchar(number % 16 + '0'));
    }
}

int putStr(char *string)
{
    int swetch = 0;

    for (int i = 0; string[i]; i++)
    {
        swetch += my_putchar(*string);
    }

    return swetch;
}

int my_printf(char *struc, ...)
{

    va_list application;
    char *s, c;
    int d;
    unsigned int u;
    intptr_t x;
    int swetch = 0;

    va_start(application, struc);

    while (*struc)
    {
        if (*struc == '%')
        {
            switch (*++struc)
            {
            case 's':
                s = va_arg(application, char *);
                if (!s || !*s)
                {
                    swetch += putStr("(null)");
                    swetch += 6;
                }
                else
                    swetch += putStr(s);
                break;

            case 'd':
                d = va_arg(application, int);
                swetch += per_d(d);
                break;

            case 'c':
                c = va_arg(application, int);
                swetch += my_putchar(c);
                break;

            case 'u':
                u = va_arg(application, unsigned int);
                swetch += per_u_d(u);
                break;

            case 'o':
                u = va_arg(application, unsigned int);
                swetch += printfo(u);
                break;

            case 'x':
                x = va_arg(application, intptr_t);
                swetch += printx(x);
                break;

            case 'p':
                x = va_arg(application, intptr_t);
                swetch += putStr("0x") + printx(x);
                break;

            default:
                swetch += my_putchar('%');
            }
            struc++;
        }
        if (*struc != '%')
        {
            swetch += my_putchar(*struc);
            struc++;
        }
    }
    va_end(application);

    return (swetch);
}