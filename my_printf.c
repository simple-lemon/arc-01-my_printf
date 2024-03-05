#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int my_putchar(char c){
    return write(1, &c, 1);
}

int my_putstr(char* str){
    int i;
    for(i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return i;
}

int my_putint(int n){
    int count = 0;
    if(n < 0){
        count += my_putchar('-');
        n = -n;
    }
    if(n > 9)
        count += my_putint(n / 10);
    count += my_putchar(n % 10 + '0');
    return count;
}

int my_putunsig(unsigned n){
    int count = 0;
    if(n > 9)
        count += my_putunsig(n / 10);
    count += my_putchar(n % 10 + '0');
    return count;
}

int my_putoct(unsigned n){
    int count = 0;
    if(n > 7)
        count += my_putoct(n / 8);
    count += my_putchar(n % 8 + '0');
    return count;
}

int my_puthex(unsigned n){
    int count = 0;
    if(n > 15)
        count += my_puthex(n / 16);
    count += my_putchar("0123456789abcdef"[n % 16]);
    return count;
}

int my_putptr(void *ptr){
    int count = 0;
    uintptr_t p = (uintptr_t)ptr;
    if(p > 15)
        count += my_putptr((void*)(p / 16));
    count += my_putchar("0123456789ABCDEF"[p % 16]);
    return count;
}

int my_printf(char * restrict format, ...){
    va_list args;
    va_start(args, format);

    int count = 0;

    for(int i = 0; format[i] != '\0'; i++){
        if(format[i] == '%'){
            if(format[i+1] == 'd'){
                int d = va_arg(args, int);
                count += my_putint(d);
                i++;
            }
            else if(format[i+1] == 'o'){
                unsigned o = va_arg(args, unsigned);
                count += my_putoct(o);
                i++;
            }
            else if(format[i+1] == 'u'){
                unsigned u = va_arg(args, unsigned);
                count += my_putunsig(u);
                i++;
            }
            else if(format[i+1] == 'x'){
                unsigned x = va_arg(args, unsigned);
                count += my_puthex(x);
                i++;
            }
            else if(format[i+1] == 'c'){
                char c = va_arg(args, int);
                count += my_putchar(c);
                i++;
            }
            else if(format[i+1] == 's'){
                char* s = va_arg(args, char*);
                count += my_putstr(s);
                i++;
            }
            else if(format[i+1] == 'p'){
                void *p = va_arg(args, void *);
                count += my_putstr("00");
                count += my_putptr(p);
                i++;
            }
            else if(format[i+1] == '%'){
                count += my_putchar(format[i+1]);
                i++;
            }
            else
                count += my_putchar(format[i]);
        }
        else
            count += my_putchar(format[i]);
    }
    va_end(args);
    
    return count;
}

int main(){
    int a = 12345;
    char c = 'c';
    char* str = "Hello World";
    my_printf("Decimal:\t\t%d\nOctal:\t\t\t%o\nUnsigned:\t\t%u\nHexadecimal:\t\t%x\nChar:\t\t\t%c\nString:\t\t\t%s\nPointer:\t\t%p\n", a, a, a, a, c, str, &str);

    return 0;
}
