#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int my_putchar(char c) {
    return write(1, &c, 1); // Using write() instead of fputc()
}

int int_to_string(int num, char *buffer, int base) {
    int count = 0;
    int is_negative = 0;

    if (num < 0) {
        is_negative = 1;
        num = -num;
    }

    int index = 0;
    do {
        int digit = num % base;
        buffer[index++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
        count++;
        num /= base;
    } while (num != 0);

    if (is_negative) {
        buffer[index++] = '-';
        count++;
    }

    buffer[index] = '\0';

    // Reverse the string
    int i = 0, j = index - 1;
    while (i < j) {
        char temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
        i++;
        j--;
    }

    return count;
}

int my_strlen(char* str)
{
    int size = 0;
    while (str[size])
    {
        size++;
    }
    return size;
}

char* reverse_str(char* str)
{
    char* reversed_one = calloc(my_strlen(str) + 1, sizeof(char));
    int ind = 0;
    for (int i = my_strlen(str) - 1; i >= 0; i--)
    {
        reversed_one[ind++] = str[i];
    }
    return reversed_one;
}

int room_count(unsigned int num)
{
    int counter = 0;
    while (num / 10 != 0)
    {
        counter++;
        num /= 10;
    }
    
    return counter;
}

char* o_option(unsigned int dec_num)
{
    int rooms = room_count(dec_num);
    int index = 0;
    char* o_num = calloc(rooms + 1, sizeof(char));
    
    while (dec_num != 0)
    {
        o_num[index] = (dec_num % 8) + 48;
        index++;
        dec_num /= 8;
    }
    o_num[index] = '\0';
    return reverse_str(o_num);
}

char* x_option(long int dec_num) {
    long int rooms = room_count(dec_num);
    int index = 0;
    char* x_num = calloc(rooms + 1, sizeof(char));
    
    while (dec_num != 0) {
        int remainder = dec_num % 16;
        if (remainder < 10)
            x_num[index] = remainder + '0';
        else
            x_num[index] = remainder - 10 + 'a';
        
        index++;
        dec_num /= 16;
    }
    
    x_num[index] = '\0';
    return reverse_str(x_num);
}

char* u_option(unsigned int dec_num) {
    int rooms = room_count(dec_num);
    int index = 0;
    char* u_num = calloc(rooms + 1, sizeof(char));
    
    do {
        u_num[index++] = (dec_num % 10) + '0';
        dec_num /= 10;
    } while (dec_num != 0);

    u_num[index] = '\0';
    return reverse_str(u_num);
}

char* p_option(void *ptr) {
    // Cast the pointer to uintptr_t for portability
    uintptr_t addr = (uintptr_t)ptr;
    // Use x_option to convert the address to a hexadecimal string
    char* hex_addr = x_option(addr);
    
    // Allocate memory for the final string with '0x' prefix
    char* final_addr = calloc(my_strlen(hex_addr) + 3, sizeof(char));
    
    // Add '0x' prefix
    final_addr[0] = '0';
    final_addr[1] = 'x';
    
    // Copy the hexadecimal address after the '0x'
    int index = 0;
    while (hex_addr[index] != '\0') {
        final_addr[index + 2] = hex_addr[index];
        index++;
    }
    
    free(hex_addr); // Free the memory allocated by x_option
    
    return final_addr;
}






int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    while (*format != '\0') {
        if (*format != '%') {
            my_putchar(*format);
            count++;
        } else {
            // Handle format specifiers
            switch (*++format) {
                case 'd': {
                    int num = va_arg(args, int);
                    char int_buffer[12]; // Buffer to store integer as string
                    count += int_to_string(num, int_buffer, 10);
                    for (int i = 0; int_buffer[i] != '\0'; ++i) {
                        my_putchar(int_buffer[i]); // Print the integer as string
                    }
                    break;
                }
                case 'u': {
                    unsigned int num = va_arg(args, unsigned int);
                    // char int_buffer[12]; // Buffer to store integer as string
                    // count += int_to_string(num, int_buffer, 10);
                    char* int_buffer = u_option(num);
                    for (int i = 0; int_buffer[i] != '\0'; ++i) {
                        my_putchar(int_buffer[i]); // Print the integer as string
                    }
                    break;
                }
                case 'o': {
                    unsigned int num = va_arg(args, unsigned int);
                    //char int_buffer[12]; // Buffer to store integer as string
                    // count += int_to_string(num, int_buffer, 8);
                    char* int_buffer = o_option(num);
                    for (int i = 0; int_buffer[i] != '\0'; ++i) {
                        my_putchar(int_buffer[i]); // Print the integer as string
                    }
                    break;
                }
                case 'x': {
                    unsigned int num = va_arg(args, unsigned int);
                    // char int_buffer[12]; // Buffer to store integer as string
                    // count += int_to_string(num, int_buffer, 16);
                    char* int_buffer = x_option(num);
                    for (int i = 0; int_buffer[i] != '\0'; ++i) {
                        my_putchar(int_buffer[i]); // Print the integer as string
                    }
                    break;
                }
                
                case 'c': {
                    // Use int type for character argument
                    int ch = va_arg(args, int);
                    my_putchar(ch); // Print the character
                    count++;
                    break;
                }

                
                case 's': {
                    char *str = va_arg(args, char *);
                    // Print the string
                    while (*str != '\0') {
                        my_putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }

                case 'p': {
                    void *ptr = va_arg(args, void *);
                    char* ptr_buffer = p_option(ptr);
                    for (int i = 0; ptr_buffer[i] != '\0'; ++i) {
                        my_putchar(ptr_buffer[i]); // Print the pointer as string
                        count++;
                    }
                    free(ptr_buffer); // Free the allocated buffer
                    break;
                }
                
                
                default:
                    my_putchar('%');
                    my_putchar(*format);
                    count += 2;
                    break;
            }
        }
        format++;
    }

    va_end(args);
    return count;
}

int main(void) {
    
    char myLetter = 'D';
    my_printf("%c\n", myLetter);
    
    int count = 2;
    my_printf("Making %s and testing it for %d times.\n", "printf", count);
    
    printf("\n%d\n", 102);
    my_printf("%d\n", 102);
    
    printf("\n%o\n", 102);
    my_printf("%o\n", 102);
    
    printf("\n%x\n", 15);
    my_printf("%x\n", 15);
    
    printf("\n%u\n", 102);
    my_printf("%u\n", 102);
    
    int a = 35;
    printf("\n%p\n", &a);
    my_printf("%p\n", &a);
    

    return 0;
}
