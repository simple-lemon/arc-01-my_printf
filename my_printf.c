#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

char *convert_int_to_string(int justNum)
{
     int numberlength = 0;
     int numbercopy = justNum;

     if (justNum == 0)
     {
          char *resultstr = malloc(2 * sizeof(char));
          resultstr[0] = '0';
          resultstr[1] = '\0';
          return resultstr;
     }

     while (numbercopy != 0)
     {
          numbercopy /= 10;
          numberlength++;
     }

     if (justNum < 0)
     {
          numberlength++;
     }

     char *resultstr = malloc((numberlength + 1) * sizeof(char));

     if (resultstr == NULL)
     {
          return NULL;
     }

     int counter = numberlength - 1;
     numbercopy = justNum;

     if (justNum < 0)
     {
          resultstr[0] = '-';
          numbercopy = -numbercopy;
     }

     while (numbercopy != 0)
     {
          resultstr[counter] = '0' + (numbercopy % 10);
          numbercopy /= 10;
          counter--;
     }

     resultstr[numberlength] = '\0';
     return resultstr;
}

char *convert_unsigned_int_to_string(unsigned int justNum, int base)
{
     unsigned int numbercopy = justNum;
     int numberlength = 0;

     do
     {
          numbercopy /= base;
          numberlength++;
     } while (numbercopy != 0);

     char *resultstr = (char *)malloc((numberlength + 1) * sizeof(char));

     if (resultstr == NULL)
     {
          return NULL;
     }

     int counter = numberlength - 1;

     do
     {
          resultstr[counter] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[justNum % base];
          justNum /= base;
          counter--;
     } while (justNum != 0);

     resultstr[numberlength] = '\0';
     return resultstr;
}

char *convert_pointer_to_string(void *ptr)
{
     uintptr_t ptrvalue = (uintptr_t)ptr;
     int charcount = sizeof(ptr) * 2;
     char *resultstr = (char *)malloc((charcount + 3) * sizeof(char));

     if (resultstr == NULL)
     {
          return NULL;
     }

     resultstr[0] = '0';
     resultstr[1] = 'x';

     for (int i = 0; i < charcount; i++)
     {
          unsigned char halfbyte = (ptrvalue >> (4 * (charcount - i - 1))) & 0xF;

          if (halfbyte < 10)
          {
               resultstr[i + 2] = '0' + halfbyte;
          }
          else
          {
               resultstr[i + 2] = 'a' + (halfbyte - 10);
          }
     }

     resultstr[charcount + 2] = '\0';

     char *alteredString = malloc(14);
     alteredString[0] = '0';
     alteredString[1] = 'x';

     for (int i = 2; i < 14; i++)
     {
          alteredString[i] = resultstr[i + 4];
     }

     return alteredString;
}

int write_char_to_output(char ch)
{
     write(1, &ch, 1);
     return 1;
}

int write_string_to_output(char *resultstr)
{
     int i = 0;

     while (resultstr[i] != '\0')
     {
          write_char_to_output(resultstr[i]);
          i++;
     }

     return i;
}

int my_printf(char *restrict format, ...)
{
     va_list args;
     va_start(args, format);

     int written_chars = 0;

     while (*format != '\0')
     {
          if (*format == '%')
          {
               format++;
               switch (*format)
               {
               case 'd':
               {
                    int justNum = va_arg(args, int);
                    char *num_str = convert_int_to_string(justNum);
                    written_chars += write_string_to_output(num_str);
                    free(num_str);
                    break;
               }
               case 'o':
               {
                    unsigned int justNum = va_arg(args, unsigned int);
                    char *num_str = convert_unsigned_int_to_string(justNum, 8);
                    written_chars += write_string_to_output(num_str);
                    free(num_str);
                    break;
               }
               case 'u':
               {
                    unsigned int justNum = va_arg(args, unsigned int);
                    char *num_str = convert_unsigned_int_to_string(justNum, 10);
                    written_chars += write_string_to_output(num_str);
                    free(num_str);
                    break;
               }
               case 'x':
               {
                    unsigned int justNum = va_arg(args, unsigned int);
                    char *num_str = convert_unsigned_int_to_string(justNum, 16);
                    written_chars += write_string_to_output(num_str);
                    free(num_str);
                    break;
               }
               case 'c':
               {
                    char ch = va_arg(args, int);
                    written_chars += write_char_to_output(ch);
                    break;
               }
               case 's':
               {
                    char *resultstr = va_arg(args, char *);
                    if (resultstr == NULL)
                    {
                         char null_str[] = "(null)";
                         written_chars += write_string_to_output(null_str);
                    }
                    else
                    {
                         written_chars += write_string_to_output(resultstr);
                    }
                    break;
               }
               case 'p':
               {
                    void *ptr = va_arg(args, void *);
                    char *ptr_str = convert_pointer_to_string(ptr);
                    written_chars += write_string_to_output(ptr_str);
                    free(ptr_str);
                    break;
               }
               default:
                    written_chars += write_char_to_output(*format);
                    break;
               }
          }
          else
          {
               written_chars += write_char_to_output(*format);
          }

          format++;
     }

     va_end(args);

     return written_chars;
}
