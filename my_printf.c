#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int my_putchar(char );
int my_putstr(const char *);
void reverse(char [], int );
char *my_itoa(int , int );
int my_handle_octal(va_list );
int my_handle_hexadecimal(va_list );
int my_handle_pointer(va_list );
int my_handle_(va_list );
int my_printf(const char *, ...);

int main() {
  my_printf("Decimal: %d\n", 42);
  my_printf("Octal: %o\n", 042);
  my_printf("Hexadecimal: %x\n", 0x2A);
  my_printf("Pointer: %p\n", (void *)0x12345678);
  my_printf(": %u\n", 42);

  return 0;
}

int my_putchar(char c) {
  write(1, &c, 1);
  return 1;
}

int my_putstr(const char *str) {
  int count = 0;
  while (str[count] != '\0') {
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

char *my_itoa(int num, int base) {
  int isNegative = 0;
  int length = 1;

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

  char *result = (char *)malloc(length + isNegative);

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
  int octal_num = va_arg(ap, int);
  char *buffer = my_itoa(octal_num, 8);
  int count = my_putstr(buffer);
  free(buffer);
  return count;
}

int my_handle_hexadecimal(va_list ap) {
  int hex_num = va_arg(ap, int);
  char *buffer = my_itoa(hex_num, 16);
  int count = my_putstr(buffer);
  free(buffer);
  return count;
}

int my_handle_pointer(va_list ap) {
  void *ptr = va_arg(ap, void *);
  char *buffer = my_itoa((long)ptr, 16);
  int count = my_putstr(buffer);
  free(buffer);
  return count;
}

int my_handle_(va_list ap) {
  int _num = va_arg(ap, int);
  char *buffer = my_itoa(_num, 10);
  int count = my_putstr(buffer);
  free(buffer);
  return count;
}

int my_printf(const char *format, ...) {
  size_t i = 0, counter = 0;
  va_list ap;
  va_start(ap, format);

  while (format[i]) {
    if (format[i] == '%') {
      i++;
      if (format[i] == 'c') {
        counter += my_putchar(va_arg(ap, int));
      } else if (format[i] == 'd') {
        char *buffer = my_itoa(va_arg(ap, int), 10);
        counter += my_putstr(buffer);
        free(buffer);
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
      } else if (format[i] == 'u') {
        counter += my_handle_(ap);
      }
    } else {
      counter += my_putchar(format[i]);
    }
    i++;
  }

  va_end(ap);
  return counter;
}
