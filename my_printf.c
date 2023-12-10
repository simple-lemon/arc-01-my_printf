#include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
 int my_printf(const char* f, ...);
 
 void my_print_char(char c) {
     putchar(c);
 }
 
 void my_print_string(const char* str) {
     while (*str != '\0') {
         my_print_char(*str);
         str++;
     }
 }
 
 void my_print_unsigned_int(unsigned int n, int rok) {
     char digits[20];
     int index = 0;
 
     if (n == 0) {
         my_print_char('0');
         return;
     }
 
     while (n > 0) {
         digits[index] = '0' + (n % rok);
         n /= rok;
         index++;
     }
 
     for (int i = index - 1; i >= 0; i--) {
         my_print_char(digits[i]);
     }
 }
 
 void my_print_int(int n, int rok) {
     if (n < 0) {
         my_print_char('-');
         n = -n;
     }
     my_print_unsigned_int(n, rok);
 }
 
 void my_print_hex_uint(unsigned int n) {
     char hex_digits[] = "0123456789ABCDEF";
     char hex_str[9];
     int index = 0;
 
     if (n == 0) {
         my_print_string("0x0");
         return;
     }
 
     while (n > 0) {
         hex_str[index] = hex_digits[n % 16];
         n /= 16;
         index++;
     }
 
     for (int i = index - 1; i >= 0; i--) {
         my_print_char(hex_str[i]);
     }
 }
 
 void my_print_octal(unsigned int n) {
     char octal_digits[] = "01234567";
     char octal_str[12];
     int index = 0;
 
     if (n == 0) {
         my_print_char('0');
         return;
     }
 
     while (n > 0) {
         octal_str[index] = octal_digits[n % 8];
         n /= 8;
         index++;
     }
 
     for (int i = index - 1; i >= 0; i--) {
         my_print_char(octal_str[i]);
     }
 }
 
 void my_print_pointer(void* ptr) {
     unsigned long long address = (unsigned long long)ptr;
     char hex_digits[] = "0123456789ABCDEF";
     char hex_str[17];
     int index = 0;
 
     my_print_string("0x");
 
     for (int i = 60; i >= 0; i -= 4) {
         hex_str[index] = hex_digits[(address >> i) & 0xF];
         index++;
     }
 
     hex_str[index] = '\0';
     my_print_string(hex_str);
 }
 
 int my_count_digits(unsigned int n, int rok) {
     int count = 0;
 
    if (n == 0) {
   return 1;
   }
   while (n > 0) {
   n /= rok;
   count++;
   }
    return count;
     } 
      int my_printf(const char* f, ...) {
       va_list args;
        va_start(args, f);
         int count = 0;
          const char* cur = f;
           while (*cur != '\0') {
            if (*cur == '%') {
             cur++;
              if (*cur == '\0') {
               break;
                }
                 int width = 0;
                  int precision = -1;
                   int rok = 10;
                    char padding = ' ';
                     if (*cur == '0') {
                      padding = '0';
                       cur++;
                        }
                         while (*cur >= '0' && *cur <= '9') {
                          width = width * 10 + (*cur - '0');
                           cur++;
                            } 
                             if (*cur == '.') {
                              cur++;
                               precision = 0;
                              while (*cur >= '0' && *cur <= '9') {
                             precision = precision * 10 + (*cur - '0');
                            cur++;
                           }
                          }
                         switch (*cur) {
                        case 'c': {
                       char c = (char)va_arg(args, int);
                      my_print_char(c);
                     count++;
                    break;
                   }
                  case 's': {
                 const char* str = va_arg(args, const char*);
                if (str == NULL) {
               str = "(null)";
              }
             int len = strlen(str);
            if (precision >= 0 && len > precision) {
           len = precision;
          }
         if (width > len) {
        for (int i = 0; i < width - len; i++) {
       my_print_char(padding);
      count++;
     }
    }
   for (int i = 0; i < len; i++) {
   my_print_char(str[i]);
   count++;
    }
     break;
      }
      case 'u': {
       unsigned int n = va_arg(args, unsigned int);
        my_print_unsigned_int(n, rok);
         count += my_count_digits(n, rok);
          break;
           }
            case 'd': {
             int n = va_arg(args, int);
              my_print_int(n, rok);
               count += my_count_digits(n, rok);
                break;
                 }
                  case 'x': {
                   unsigned int n = va_arg(args, unsigned int);
                    rok = 16;
                     my_print_hex_uint(n);
                      count += my_count_digits(n, rok) + 2;  
                       break;
                        }
                         case 'o': {
                          unsigned int n = va_arg(args, unsigned int);
                           rok = 8;
                            my_print_octal(n);
                             count += my_count_digits(n, rok);
                              break;
                               }
                                case 'p': {
                                 void* ptr = va_arg(args, void*);
                                my_print_pointer(ptr);
                              count += 16;  
                             break;
                            }
                          default: {
                         my_print_char(*cur);
                       count++;
                      break;
                   }
                }
              } else {my_print_char(*cur);
             count++;
         }cur++;
     }va_end(args);
     return count;}
 int main() {
     int result = my_printf("Hello, World!\n");
     my_printf("The number is %d\n", 42);
     my_printf("The hexadecimal number is %x\n", 0xABCD);
     my_printf("The octal number is %o\n", 0777);
     my_printf("The pointer is %p\n", main);
     my_printf("The string is %-10s\n", "Hello");
     my_printf("The integer is %05d\n", 123);
     return 0;
 }
