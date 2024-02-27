#include <unistd.h>
#include <stdarg.h>

void my_putchar(char c){
    write(1, &c, 1);
}

void my_putstr(char* str){
    for(int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

void my_putint(int n){
    if(n < 0){
        my_putchar('-');
        n = -n;
    }
    if(n > 9)
        my_putint(n / 10);
    my_putchar(n % 10 + '0');
}

void my_putunsig(unsigned n){
    if(n > 9)
        my_putunsig(n / 10);
    my_putchar(n % 10 + '0');
}

void my_putoct(unsigned n){
    if(n > 7)
        my_putoct(n / 8);
    my_putchar(n % 8 + '0');
}

void my_puthex(unsigned n){
    if(n > 15)
        my_puthex(n / 16);
    my_putchar("0123456789abcdef"[n % 16]);
}

void my_putptr(unsigned n){
    if(n > 15)
        my_putptr(n / 16);
    my_putchar("0123456789ABCDEF"[n % 16]);
}

void my_printf(char * restrict format, ...){
    va_list args;
    va_start(args, format);

    for(int i = 0; format[i] != '\0'; i++){
        if(format[i] == '%'){
            if(format[i+1] == 'd'){
                int d = va_arg(args, int);
                my_putint(d);
                i++;
            }
            else if(format[i+1] == 'o'){
                unsigned o = va_arg(args, unsigned);
                my_putoct(o);
                i++;
            }
            else if(format[i+1] == 'u'){
                unsigned u = va_arg(args, unsigned);
                my_putunsig(u);
                i++;
            }
            else if(format[i+1] == 'x'){
                unsigned x = va_arg(args, unsigned);
                my_puthex(x);
                i++;
            }
            else if(format[i+1] == 'c'){
                char c = va_arg(args, int);
                my_putchar(c);
                i++;
            }
            else if(format[i+1] == 's'){
                char* s = va_arg(args, char*);
                my_putstr(s);
                i++;
            }
            else if(format[i+1] == 'p'){
                void *p = va_arg(args, void *);
                my_putstr("00");
                my_putptr((unsigned)p);
                i++;
            }
            else if(format[i+1] == '%'){
                my_putchar(format[i+1]);
                i++;
            }
            else
                my_putchar(format[i]);
        }
        else
            my_putchar(format[i]);
    }
    va_end(args);
}

int main(){
    int a = 12345;
    char c = 'c';
    char* str = "Hello World";
    my_printf("Decimal:\t\t%d\nOctal:\t\t\t%o\nUnsigned:\t\t%u\nHexadecimal:\t\t%x\nChar:\t\t\t%c\nString:\t\t\t%s\nPointer:\t\t%p\n", a, a, a, a, c, str, &str);

    return 0;
}