#include<unistd.h> 
#include <stdarg.h>
#include <stdio.h>
int my_string(char* str){
    int i;
    for(i = 0; i <= str[i];){
        i++;
    }
    return i;
}

void my_cat(char hz) {
    write(1,&hz,1);
}
void my_char(char* str) {
    while (*str) {
        my_cat(*str);
        str++;
    }
}

int my_ngram(unsigned long a1) {
    my_char("0x");

    char place[20];
    int i = 0;

    if (a1 == 0) {
        my_cat('0');
        return 1;  
    }
    
    while (a1>0) {
        int a2 = a1 % 16;
        place[i++] = (a2 < 10) ? a2 + '0' : a2 - 10 + 'a';
        a1 /= 16;
    }
    for (int k = i - 1; k >= 0; k--) {
        my_cat(place[k]);
    }

    return i + 2;  
}

int my_square(unsigned long a1) {
    char place[20];
    int i = 0;

    if (a1 == 0) {
        my_cat('0');
        return 1;
    }

    while(a1 > 0) {
        int a2 = a1 % 16;
        place[i++] = (a2 < 10) ? a2 + '0' : a2 - 10 + 'A';
        a1 /= 16;
    }

    for (int j = i - 1; j >= 0; j--) {
        my_cat(place[j]);
    }

    return i + 2;  
}

int my_file(unsigned int a1) {
    char place[20];
    int i = 0;

    if (a1 == 0) {
        my_cat('0');
        return 1; 
    }
    for(i = 0;a1 > 0;) {
        int a2 = a1 % 8;
        place[i++] = a2 + '0';
        a1 /= 8;
    }
    for (int k = i - 1; k >= 0; k--) {
        my_cat(place[k]);
    }

    return i;  
}    
void my_pointer(void* point) {
    my_ngram((unsigned long)point);
}
void my_cpewep(char* str, int length) {
    int main = 0;
    int end = length - 1;
    while (main < end) {
        char temp = str[main];
        str[main] = str[end];
        str[main] = temp;
        main++;
        end--;
    }
}
void my_str(int num, char* buffer) {
    int i = 0;
    while (num != 0) {
        buffer[i++] = num % 10 + '0';
        num /= 10;
    }
    buffer[i] = '\0';
    my_cpewep(buffer, i);
}
void my_git(double num, char* buffer, int precision) {
    int int_part = (int)num;
    double frac_part = num - int_part;

    my_str(int_part, buffer);
    int len = my_string(buffer);
    buffer[len++] = '.';
    int i = 0;
    while(i < precision) {
        frac_part *= 10;
        int digit = (int)frac_part;
        buffer[len++] = digit + '0';
        frac_part -= digit;
        i++;
    }

    buffer[len] = '\0';
}

void my_add(double num, int precision) {
    char place[50];
    my_git(num, place, precision);
    my_char(place);
}

int my_push(int num) {
    char place[22];  
    int i = 0;
    int length = 0;  

    if (num == 0) {
        my_cat('0');
        length++;  
    }

    if (num < 0) {
        my_cat('-');
        num = -num;
        length++;  
    }

    for(i = 0;num > 0;) {
        place[i++] = num % 10 + '0';
        num /= 10;
    }
    
    for (int k = i - 1; k >= 0; k--) {
        my_cat(place[k]);
        length++;  
    }

    return length;  
}
int my_printf(char* hz, ...) {
    va_list args;
    va_start(args, hz);
    int length = 0;
    while (*hz) {
        if (*hz == '%') {
            hz++;
            if (*hz == 'd' || *hz == 'i'){
                int num = va_arg(args, int);
                length += my_push(num);
            }
            else if (*hz == 's'){
                char* sss = va_arg(args, char*);
               if (sss == NULL) {
                   my_char("(null)");
                   length += my_string("(null)");
               } else {
                   my_char(sss);
                   length += my_string(sss);
                }
            }       
            else if (*hz == 'u'){
                length += my_push(va_arg(args, int));
            }
            else if (*hz == 'c'){
                my_cat(va_arg(args, int));
                length++;
            }
            else if (*hz == 'p' || *hz == 'P'){
                void* ptr = va_arg(args, void*);
                my_ngram((unsigned long)ptr);
                length += 14;
            }
            else if (*hz == 'x' || *hz == 'X') {
                int x10lik = va_arg(args, int);
                my_square((unsigned long)x10lik);
                length += 1;
            }
            else if (*hz == 'o' || *hz == 'O'){
                length += my_file(va_arg(args, unsigned int));
            }           
            }
        else if (*hz == '\n') {
            my_cat('\n');
            length++; 
        }    
        else {
            my_cat(*hz);
            length++; 
        }
        hz++;
    }
    va_end(args);
    return length;
}