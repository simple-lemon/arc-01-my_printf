#include<unistd.h> 
#include <stdarg.h>
#include <stdio.h>
int my_len(char* arr){
    int i;
    for(i = 0; i <= arr[i];){
        i++;
    }
    return i;
}
void my_param(char ab) {
    write(1,&ab,1);
}
void my_hz(char* arr) {
    while (*arr) {
        my_param(*arr);
        arr++;
    }
}
int my_string(unsigned long gcc) {
    my_hz("0x");
    char place[20];
    int i = 0;
    if (gcc == 0) {
        my_param('0');
        return 1;  
    }
    while (gcc>0) {
        int cd = gcc % 16;
        place[i++] = (cd < 10) ? cd + '0' : cd - 10 + 'a';
        gcc /= 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        my_param(place[j]);
    }
    return i + 2;  
}
int my_js(unsigned long gcc) {
    char place[20];
    int i = 0;
    if (gcc == 0) {
        my_param('0');
        return 1;
    }
    while(gcc > 0) {
        int cd = gcc % 16;
        place[i++] = (cd < 10) ? cd + '0' : cd - 10 + 'A';
        gcc /= 16;
    }
    for (int k = i - 1; k >= 0; k--) {
        my_param(place[k]);
    }
    return i + 2;  
}
int my_cd(unsigned int gcc) {
    char place[20];
    int i = 0;
    if (gcc == 0) {
        my_param('0');
        return 1; 
    }
    for(i = 0;gcc > 0;) {
        int cd = gcc % 8;
        place[i++] = cd + '0';
        gcc /= 8;
    }
    for (int a = i - 1; a >= 0; a--) {
     my_param(place[a]);
    }
    return i;  
}    
void my_masiv(void* len1) {
    my_string((unsigned long)len1);
}
void my_down(char* hz, int param) {
    int len = 0;
    int def = param - 1;
    while (len < def) {
        char temp = hz[len];
        hz[len] = hz[def];
        hz[len] = temp;
        len++;
        def--;
    }
}
void my_str(int sum, char* buffer) {
    int i = 0;
    while (sum != 0) {
        buffer[i++] = sum % 10 + '0';
        sum /= 10;
    }
    buffer[i] = '\0';
    my_down(buffer, i);
}
void my_add(double num, char* buffer, int precision) {
    int part = (int)num;
    double frac = num - part;
    my_str(part, buffer);
    int len2 = my_len(buffer);
    buffer[len2++] = '.';
    int i = 0;
    while(i < precision) {
        frac *= 10;
        int digit = (int)frac;
        buffer[len2++] = digit + '0';
        frac -= digit;
        i++;
    }
    buffer[len2] = '\0';
}
void my_int(double num2, int precision) {
    char join[50];
    my_add(num2, join, precision);
    my_hz(join);
}
int my_gandalf(int num2) {
    char join[22];  
    int i = 0;
    int len3 = 0;
    if (num2 == 0) {
        my_param('0');
        len3++;  
    }
    if (num2 < 0) {
        my_param('-');
        num2 = -num2;
        len3++;  
    }
    for(i = 0;num2 > 0;) {
        join[i++] = num2 % 10 + '0';
        num2 /= 10;
    }
    for (int b = i - 1; b >= 0; b--) {
        my_param(join[b]);
        len3++;  
    }
    return len3;  
}
int my_printf(char* zed, ...) {
    va_list args;
    va_start(args, zed);
    int len4 = 0;
    while (*zed) {
        if (*zed == '%') {
            zed++;
            if (*zed == 'd' || *zed == 'i'){
                int num2 = va_arg(args, int);
                len4 += my_gandalf(num2);
            }
            else if (*zed == 's'){
                char* abc = va_arg(args, char*);
               if (abc == NULL) {
                   my_hz("(null)");
                   len4 += my_len("(null)");
               } else {
                   my_hz(abc);
                   len4 += my_len(abc);
                }
            }       
            else if (*zed == 'u'){
                len4 += my_gandalf(va_arg(args, int));
            }
            else if (*zed == 'c'){
                my_param(va_arg(args, int));
                len4++;
            }
            else if (*zed == 'p' || *zed == 'P'){
                void* ptr = va_arg(args, void*);
                my_string((unsigned long)ptr);
                len4 += 14;
            }
            else if (*zed == 'x' || *zed == 'X') {
                int x = va_arg(args, int);
                my_js((unsigned long)x);
                len4 += 1;
            }
            else if (*zed == 'o' || *zed == 'O'){
                len4 += my_cd(va_arg(args, unsigned int));
            }           
            }
        else if (*zed == '\n') {
            my_param('\n');
            len4++; 
        }    
        else {
            my_param(*zed);
            len4++; 
        }
        zed++;
    }
    va_end(args);
    return len4;
}