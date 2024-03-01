#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int put_char(char c){
    write(1, &c, 1);
    return 1;
}

int put_str(char *str){
    int count = 0;
    int i = 0;
    while(str[i] != '\0'){
        count += put_char(str[i]);
        i++;
    }
    return count;
}

int my_strlen(char *len){
    int i = 0;
    while(len[i] != '\0'){
        i++;
    }
    return i;
}

char *my_reverse(char *p1){
    char c;
    int len = my_strlen(p1);
    int i = 0;
    while(i < len / 2){
        c = p1[len - i - 1];
        p1[len - i - 1] = p1[i];
        p1[i] = c;
        i++;
    }
    return p1;
}

char *my_itoa(int num, char *str, int base){
    int i = 0;
    if(num < 0){
        str[i+1] = '-';
        num = -num;
    }
    while(num > 0){
        if((num % base) < 10){
            str[i++] = (num % base) + '0';
        }else{
            str[i++] = (num % base) - 10 + 'a';
        }
        num /= base;
    }
    return my_reverse(str);
}

int my_printf(char *str, ...){
    va_list my_list;
    va_start(my_list, str);
    int count = 0;
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == '%'){
            i++;
            if(str[i] == 'd'){
                int num = va_arg(my_list, int);
                char *num_str = calloc(12, sizeof(char));
                num_str = my_itoa(num, num_str, 10);
                count += put_str(num_str);
            }else if(str[i] == 'o'){
                int num = va_arg(my_list, int);
                char *num_str = calloc(12, sizeof(char));
                num_str = my_itoa(num, num_str, 8);
                count += put_str(num_str);
            }else if(str[i] == 'u'){
                int num = va_arg(my_list, int);
                char *num_str = calloc(12, sizeof(char));
                num_str = my_itoa(num, num_str, 10);
                count += put_str(num_str);
            }else if(str[i] == 'x'){
                int num = va_arg(my_list, int);
                char *num_str = calloc(12, sizeof(char));
                num_str = my_itoa(num, num_str, 16);
                count += put_str(num_str);
            }else if(str[i] == 'c'){
                char c = va_arg(my_list, int);
                count += put_char(c);
            }else if(str[i] == 's'){
                char *str_arg = va_arg(my_list, char *);
                count += put_str(str_arg);
            }else if(str[i] == 'p'){
                int num = va_arg(my_list, int);
                char *num_str = calloc(20, sizeof(char));
                num_str = my_itoa(num, num_str, 16);
                count += put_str("0x");
                count += put_str(num_str);
            }
        }else{
            count += put_char(str[i]);
        }
        i++;
    }
    va_end(my_list);
    return count;
}

int main(){
    
    return 0;
}