#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int f_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char *f_strcpy(char *dest, const char *src)
{
    char *original_dest = dest;
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return original_dest;
}

char *f_reverse(char *str)
{

    int i = 0, len = f_strlen(str), j = len - 1;
    char temp_char;
    while (i < len / 2)
    {
        temp_char = str[i];
        str[i++] = str[j];
        str[j--] = temp_char;
    }
    return str;
}

char *f_desToMulti(long int dec, int status)
{
    int i = 0, temp, divided, flag = 0;
    char *RESULT = calloc(21, sizeof(char));
    if (status <= 0)
    {
        while (dec > 0)
        {
            temp = dec % 16;
            if (temp < 10)
            {
                RESULT[i] = temp + '0';
            }
            else
            {
                if (status == 0)
                {
                    RESULT[i] = temp - 10 + 'a';
                }
                else
                {
                    RESULT[i] = temp - 10 + 'A';
                }
            }
            dec = dec / 16;
            i++;
        }
        flag = 1;
    }
    else
    {
        if (status == 1)
        {
            divided = 8;
        }
        else
        {
            divided = 10;
        }
        for (int i = 0; dec > 0; i++)
        {
            RESULT[i] = (dec % divided) + '0';
            dec /= divided;
        }
        flag = 1;
    }
    if (flag == 0)
    {
        RESULT[0] = dec + '0';
    }

    return f_reverse(RESULT);
}

char *f_itoa(long int num, int status)
{
    int i = 0, flag = 0, numsize;
    if (status == 0)
    {
        numsize = 11;
    }
    else
    {
        numsize = 21;
    }
    char *res = calloc(numsize, sizeof(char));

    if (num < 0)
    {
        num = -(num);
        flag = 1;
    }
    while (num > 0)
    {
        res[i] = 48 + (num % 10);
        num /= 10;
        i++;
    }
    if (i == 0)
    {
        res[i++] = num + '0';
    }
    else if (flag == 1)
    {
        res[i++] = '-';
    }
    res[i] = '\0';
    return f_reverse(res);
}

void my_printf(char *buffer, ...)
{
    int p = 0, resLen, bufferSize = 256;
    char *result = (char *)calloc(bufferSize, sizeof(char));
    va_list arglist;

    va_start(arglist, buffer);

    for (int i = 0; buffer[i]; i++)
    {
        if (p > bufferSize - 1)
        {
            result = realloc(result, bufferSize *= 2);
        }
        else if (buffer[i] != '%')
        {
            result[p++] = buffer[i];
        }
        else
        {
            i++;
            resLen = f_strlen(result);
            if (buffer[i] == 'c')
            {
                char tmpChar = (char)va_arg(arglist, int);
                result[p++] = tmpChar;
            }
            else if (buffer[i] == 'd')
            {
                char *tmpNum = f_itoa(va_arg(arglist, int), 0);
                int tmpNumLen = f_strlen(tmpNum);
                f_strcpy(result + resLen, tmpNum);
                p += tmpNumLen;
                free(tmpNum);
            }
            else if (buffer[i] == 's')
            {
                char *tmpstr = va_arg(arglist, char *);
                int tmpStrLen = f_strlen(tmpstr);
                f_strcpy(result + resLen, tmpstr);
                p += tmpStrLen;
            }
            else if (buffer[i] == 'x')
            {
                long int tmpdes = va_arg(arglist, long int);
                char *tmpHx = f_desToMulti(tmpdes, 0);
                int tmpHxLen = f_strlen(tmpHx);
                f_strcpy(result + resLen, tmpHx);
                p += tmpHxLen;
                free(tmpHx);
            }
            else if (buffer[i] == 'p')
            {
                long int tmpld = va_arg(arglist, long int);
                char *tmpp = f_desToMulti(tmpld, -1);
                int tmpldLen = f_strlen(tmpp);
                f_strcpy(result + resLen, "0x");
                f_strcpy(result + resLen + 2, tmpp);
                p += tmpldLen + 2;
                free(tmpp);
            }
            else if (buffer[i] == 'o')
            {
                long int intOct = va_arg(arglist, long int);
                char *tmpOc = f_desToMulti(intOct, 1);
                int tmpOctLen = f_strlen(tmpOc);
                f_strcpy(result + resLen, tmpOc);
                p += tmpOctLen;
                free(tmpOc);
            }
            else if (buffer[i] == 'u')
            {
                char *tmpU;
                long int tmp_u_num = va_arg(arglist, long int);
                if (tmp_u_num < 0)
                {
                    long int unum = 4294967296 + tmp_u_num;
                    tmpU = f_itoa(unum, 1);
                    int tmpULen = f_strlen(tmpU);
                    f_strcpy(result + resLen, tmpU);
                    p += tmpULen;
                    free(tmpU);
                }
                else
                {
                    tmpU = f_itoa(tmp_u_num, 0);
                    int tmpULen = f_strlen(tmpU);
                    f_strcpy(result + resLen, tmpU);
                    p += tmpULen;
                    free(tmpU);
                }
            }
        }
    }
    va_end(arglist);
    write(1, result, f_strlen(result));
    free(result);
}

int main()
{
    int num = 12345678;
    char str[] = "hello world";
    char c = 'a';

    my_printf("\t---P---\nmy Printf: %p\n", &num);
    printf("org Printf: %p\n", &num);

    my_printf("\t---o---\nmy Printf: %o\n", num);
    printf("org Printf: %o\n", num);

    my_printf("\t---x---\nmy Printf: %x\n", num);
    printf("org Printf: %x\n", num);

    my_printf("\t---d---\nmy Printf: %d\n", -num);
    printf("org Printf: %d\n", -num);

    my_printf("\t---c---\nmy Printf: %c\n", c);
    printf("org Printf: %c\n", c);

    my_printf("\t---s---\nmy Printf: %s\n", str);
    printf("org Printf: %s\n", str);

    my_printf("\t---u---\nmy Printf: %u\n", -num);
    printf("org Printf: %u\n", -num);

    my_printf("\t---u---\nmy Printf: %u\n", num);
    printf("org Printf: %u\n", num);
}
