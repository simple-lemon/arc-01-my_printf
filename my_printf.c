#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

int my_putchar(char c) {
  write(1, &c, 1);
  return 1;
}

int my_putstr(const char *str) {
  int count = 0;
  while (*str != '\0') {
    write(1, str++, 1);
    count++;
  }
  return count;
}

void reverse(char str[], int length) {
  int start = 0;
  int end = length - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

char *my_itoa(size_t num, size_t base) {
  size_t isNegative = 0;
  size_t length = 1;

  if (num == 0) {
    char *result = (char *)malloc(2);
    result[0] = '0';
    result[1] = '\0';
    return result;
  }

  if (num < 0 && base != 10) {
    isNegative = 1;
    num = -num;
  }

  int temp = num;
  while (temp != 0) {
    temp /= base;
    length++;
  }

  char *result = (char *)malloc(length + isNegative + 1);

  int i = 0;
  while (num != 0) {
    int remainder = num % base;
    result[i++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
    num /= base;
  }

  if (isNegative && base == 10) {
    result[i++] = '-';
  }

  result[i] = '\0';

  reverse(result, i);

  return result;
}

int my_handle_octal(va_list ap) {
  unsigned int octal_num = va_arg(ap, unsigned int);
  char *buffer = my_itoa(octal_num, 8);
  int count = my_putstr(buffer);
  free(buffer);
  return count;
}

int my_handle_hexadecimal(va_list ap) {
  unsigned int hex_num = va_arg(ap, unsigned int);
  char *buffer = my_itoa(hex_num, 16);
  int count = my_putstr(buffer);
  free(buffer);
  return count;
}

int my_handle_pointer(va_list ap) {
  size_t ptr = va_arg(ap, size_t);
  char * buffer = my_itoa((size_t)ptr, 16);
  // if windows 
  int count = my_putstr("0000");
  // if mac os
  // int count = my_putstr("0x");
  count += my_putstr(buffer);
  free(buffer);
  return count;
}


int my_handle_(va_list ap) {
  int _num = va_arg(ap, int);
  char *buffer = my_itoa(_num, 10);
  int count;
  if (_num < 0) {
    count = my_putchar('-');
    count += my_putstr(buffer + 1);
  } else {
    count = my_putstr(buffer);
  }
  free(buffer);
  return count;
}

int my_printf(const char *format, ...) {
  int i = 0, counter = 0;
  va_list ap;
  va_start(ap, format);

  while (format[i]) {
    if (format[i] == '%') {
      i++;
      if (format[i] == 'c') {
        counter += my_putchar(va_arg(ap, int));
      } else if (format[i] == 'd' || format[i] == 'u') {
        counter += my_handle_(ap);
      } else if (format[i] == 's') {
        char *s = va_arg(ap, char *);
        if (s != NULL) {
          counter += my_putstr(s);
        }
      } else if (format[i] == 'o') {
        counter += my_handle_octal(ap);
      } else if (format[i] == 'x') {
        counter += my_handle_hexadecimal(ap);
      } else if (format[i] == 'p') {
        counter += my_handle_pointer(ap);
      }
    } else {
      counter  += my_putchar(format[i]);
    }
    i++;
  }

  va_end(ap);
  return counter;
}

int main() {
  my_printf("\t-s-\t\n");
  my_printf("Hello, %s!\n", "world");
  printf("Hello, %s!\n", "world");
  my_printf("\t-d-\t\n");
  my_printf("The answer is %d.\n", 991);
  printf("The answer is %d.\n", 991);
  my_printf("\t-o-\t\n");
  my_printf("Octal value: %o\n", 991);
  printf("Octal value: %o\n", 991);
  my_printf("\t-u-\t\n");
  my_printf("Unsigned decimal: %u\n", 991);
  printf("Unsigned decimal: %u\n", 991);
  my_printf("\t-x-\t\n");
  my_printf("Hexadecimal: %x\n", 991);
  printf("Hexadecimal: %x\n", 991);
  my_printf("\t-p-\t\n");
  my_printf("Address: %p\n", (void *)main);
  printf("Address: %p\n", (void *)main);
  my_printf("\t-c-\t\n");
  my_printf("Character: %c\n", 'A');
  printf("Character: %c\n", 'A');
}