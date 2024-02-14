#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int my_putchar(char c){
    write(1, &c, 1);
    return 1;
}

int my_putstr(char* p1){
    int counter = 0;
    for(int i = 0; p1[i]; i++){
        counter += my_putchar(p1[i]);
    }
    return counter;
}

int my_strlen(char* p1){
    int i = 0;
    while(p1[i]){
        i++;
    }
    return i;
}

int my_reverse_printer(char* str){
    int counter = 0, len_str = my_strlen(str);
    for(int i = len_str - 1; i >= 0; i--){
        counter += my_putchar(str[i]);
    }
    return counter;
}

int my_int_priniter(int num){
    int i = 0, counter = 0, flag = 0;
    char c;
    char* result = calloc(sizeof(char), 11);
    if(num < 0){
        num *= -1;
        flag = 1;
    }
    while(num > 0){
        c = (num % 10) + 48;
        num = num / 10;
        result[i++] = c;
    }
    if(flag == 1){
        result[i] = '-';
    }
    return counter += my_reverse_printer(result);
}

int my_int_long_priniter(int long num){
    int i = 0, counter = 0, flag = 0;
    char c;
    char* result = calloc(sizeof(char), 21);
    if(num < 0){
        num *= -1;
        flag = 1;
    }
    while(num > 0){
        c = (num % 10) + 48;
        num = num / 10;
        result[i++] = c;
    }
    if(flag == 1){
        result[i] = '-';
    }
    return counter += my_reverse_printer(result);
}

int my_octal_printer(int num){
    int i = 0, counter = 0;
    char c;
    char* result = calloc(sizeof(char), 11);
    while(num > 0){
        c = (num % 8) + 48;
        num /= 8;
        result[i++] = c;
    }
    return counter += my_reverse_printer(result);
}



int my_hx_long_printer(long int num){
    int i = 0, counter = 0, temp;
    char* result = calloc(sizeof(char), 11);
    while( num > 0){
        temp = (num % 16);
        if( temp < 10){
            result[i] = temp + 48;
        }else{
            result[i] = temp + 87;
        }
        num /= 16;
        i++;
    }
    return counter += my_reverse_printer(result);
}

int my_hx_printer(int num){
    int i = 0, counter = 0, temp;
    char* result = calloc(sizeof(char), 11);
    if(num < 0){
        int long pow_of_two = 4294967296 + num;
        my_hx_long_printer(pow_of_two);
    }
    while( num > 0){
        temp = (num % 16);
        if( temp < 10){
            result[i] = temp + 48;
        }else{
            result[i] = temp + 87;
        }
        num /= 16;
        i++;
    }
    return counter += my_reverse_printer(result);
}

int my_unsigned_num_printer(int unsigned_num){
    int long pow_of_two = 4294967296 + unsigned_num;
    int counter = 0;
    if(unsigned_num >= 0){
        return counter += my_int_priniter(unsigned_num);
    }
    return counter += my_int_long_priniter((pow_of_two));
}

char* my_strdup(char* str){
    char* result = calloc(sizeof(char), my_strlen(str) + 1);
    for(int i = 0; str[i]; i++){
        result[i] = str[i];
    }
    return result;
}

int my_printf(char* str, ...){
    int i = 0, counter = 0;
    va_list ptr;
    va_start(ptr, str);
    while(str[i]){
        if(str[i] == '%'){
            if(str[i+1] == 'd'){
                i+=2;
                int num_1 = va_arg(ptr, int);
                counter += my_int_priniter(num_1);
            }
            else if(str[i+1] == 'c'){
                i+=2;
                char c = va_arg(ptr, int);
                counter += my_putchar(c);
            }else if( str[i + 1] == 's'){
                i+=2;
                char* string = my_strdup(va_arg(ptr, char*));
                counter += my_putstr(string);
            }else if(str[i+1] == 'o'){
                i += 2;
                int num_2 = (va_arg(ptr, int));
                counter += my_octal_printer(num_2);
            }else if(str[i +1] == 'x'){
                i+=2;
                int num_3 = va_arg(ptr, int);
                counter += my_hx_printer(num_3);
            }else if(str[i+1] == 'p'){
                i+=2;
                long int addres = va_arg(ptr, int);
                counter += my_putstr("0x");
                counter += my_hx_long_printer(addres);
            }else if(str[i+1] == 'u'){
                i+=2;
                int unsigned_num = va_arg(ptr, int);
                counter += my_unsigned_num_printer(unsigned_num);
            }
        }
        else{
            counter += my_putchar(str[i]);
            i++;
        }
    }
    return counter;
}
int main() {
    char c = 'H';
    char* str = "ello World";
    int num = 42;
    int unsigned_num = 123;
    int octal_num = 63;
    long int address = 0x12345678;

    my_printf("%c%s\n", c, str);
    my_printf("%p\n", address);
    my_printf("%d\n", num);
    my_printf("%u\n", unsigned_num);
    my_printf("%o\n", octal_num);

    return 0;
}
