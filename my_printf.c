#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *my_strcpy(char *str_1, char *str_2)
{
    int i = 0;
    while (str_2[i] != '\0')
    {
        str_1[i] = str_2[i];
        i++;
    }
    str_1[i] = '\0';
    return str_1;
}

int my_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char *my_reverse(char *str)
{
    int i = 0;
    char *temp_str = (char *)malloc((my_strlen(str) + 1) * sizeof(char));
    temp_str = my_strcpy(temp_str, str);
    int len = my_strlen(temp_str);
    while (i < len / 2)
    {
        char temp = temp_str[i];
        temp_str[i] = temp_str[len - i - 1];
        temp_str[len - i - 1] = temp;
        i++;
    }
    return temp_str;
}

char *my_itoa(int num)
{
    char *str = calloc(11, sizeof(char));
    int i = 0, last_digit = 0, temp = num, flag = 0;
    while (temp > 0)
    {
        last_digit++;
        temp /= 10;
    }
    if (num < 0)
    {
        num = -(num);
        flag = 1;
    }
    while (num > 0)
    {
        str[i] = '0' + (num % 10);
        num /= 10;
        i++;
    }
    if (flag == 1)
    {
        str[i] = '-';
    }
    return my_reverse(str);
}

char *my_longInt_itoa(int long num)
{
    char *str = calloc(21, sizeof(char));
    int i = 0;
    while (num > 0)
    {
        str[i] = '0' + (num % 10);
        num /= 10;
        i++;
    }
    return my_reverse(str);
}

char *dec_to_hex(long int dec)
{
    int i = 0, temp;
    char *hex = calloc(21, sizeof(char));
    while (dec > 0)
    {
        temp = dec % 16;
        if (temp < 10)
        {
            hex[i] = temp + '0';
        }
        else
        {
            hex[i] = temp - 10 + 'a';
        }
        dec = dec / 16;
        i++;
    }
    hex = my_reverse(hex);
    return hex;
}

char *dec_to_oct(int dec)
{
    int i = 0;
    char *octalStr = (char *)calloc(21, sizeof(char));
    while (dec > 0)
    {
        octalStr[i] = dec % 8 + '0';
        dec = dec / 8;
        i++;
    }
    return my_reverse(octalStr);
}

char *my_u_num(int num)
{
    long int unum = 4294967296 + num;
    if (num < 0)
    {
        return my_longInt_itoa(unum);
    }
    return my_itoa(num);
}

void my_printf(char *str, ...)
{
    va_list args;
    va_start(args, str);

    for (int i = 0; str[i]; i++)
    {
        if (str[i] != '%')
        {
            write(0, &str[i], 1);
        }
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 's')
            {
                char *str_1 = va_arg(args, char *);
                write(1, str_1, my_strlen(str_1));
            }
            else if (str[i] == 'd')
            {
                int num = va_arg(args, int);
                char *str_2 = my_itoa(num);
                write(1, str_2, my_strlen(str_2));
            }
            else if (str[i] == 'x')
            {
                int num = va_arg(args, int);
                char *str_3 = dec_to_hex(num);
                write(1, str_3, my_strlen(str_3));
            }
            else if (str[i] == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
            }
            else if (str[i] == 'o')
            {
                int num = va_arg(args, int);
                char *str_4 = dec_to_oct(num);
                write(1, str_4, strlen(str_4));
            }
            else if (str[i] == 'p')
            {
                long int num = va_arg(args, long);
                char *str_5 = dec_to_hex(num);
                write(1, "0x", 2);
                write(1, str_5, my_strlen(str_5));
            }
            else if (str[i] == 'u')
            {
                int num = va_arg(args, int);
                char *str_6 = my_u_num(num);
                write(1, str_6, my_strlen(str_6));
            }
        }
    }
    va_end(args);
}

// int main()
// {
//     int num = 12;
//     char str[]= "hello world";
//     char c = 'a';

//     my_printf("%p\n", &num);
//     printf("%p\n", &num);

//     my_printf("%o\n", num);
//     printf("%o\n", num);

//     my_printf("%x\n", num);
//     printf("%x\n", num);

//     my_printf("%d\n", -num);
//     printf("%d\n", -num);

//     my_printf("%c\n", c);
//     printf("%c\n", c);

//     my_printf("%s\n", str);
//     printf("%s\n", str); 

//     my_printf("%u\n", -num);
//     printf("%u\n", -num);

//     my_printf("%u\n", num);
//     printf("%u\n", num);
// }