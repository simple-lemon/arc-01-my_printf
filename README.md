# My Printf
This code is an implementation of a function from the standard library `<stdio.h>` called *printf*.

The code was written by [Abdussamad Turdixojayev](https://github.com/Abuuu2007).

## Content
- [Description](#description)
- [Usage](#usage)
- [Code Component](#code-component)
- [Main function](#main-function)
  
## Description
My custom version of `printf`, according to the instructions, should have 7 format specifiers, namely:
1. `%d` - signed decimal
2. `%o` - unsigned octal
3. `%u` - unsigned decimal
4. `%x` - unsigned hexadecimal
5. `%c` - char
6. `%s` - string
7. `%p` - pointer

But with all this, it was possible to use a limited number of functions, namely:

* write(2)
* malloc()
* free()
* va_list, va_start, va_arg, va_copy, va_end

`malloc` and `free` were not used.

## Usage

The function's usage is similar to standard `printf`.

## Code component
### Creating a `my_putchar` to output a character
```c
int my_putchar(char c){
    return write(1, &c, 1);
}
```
### Creating `my_putstr` to output strings
```c
int my_putstr(char* str){
    int i;
    for(i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return i;
}
```
### Creating `my_putint` to output integers
```c
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
```
### Creating `my_putunsig` to output unsigned decimal
```c
int my_putunsig(unsigned n){
    int count = 0;
    if(n > 9)
        count += my_putunsig(n / 10);
    count += my_putchar(n % 10 + '0');
    return count;
}
```
### Creating `my_putoct` to output unsigned octal
```c
int my_putoct(unsigned n){
    int count = 0;
    if(n > 7)
        count += my_putoct(n / 8);
    count += my_putchar(n % 8 + '0');
    return count;
}
```
### Creating `my_puthex` to output unsigned hexadecimal 
```c
int my_puthex(unsigned n){
    int count = 0;
    if(n > 15)
        count += my_puthex(n / 16);
    count += my_putchar("0123456789abcdef"[n % 16]);
    return count;
}
```
### Creating `my_putptr` to output pointer
```c
int my_putptr(void *ptr){
    int count = 0;
    uintptr_t p = (uintptr_t)ptr;
    if(p > 15)
        count += my_putptr((void*)(p / 16));
    count += my_putchar("0123456789ABCDEF"[p % 16]);
    return count;
}
```
### And finally, I write `my_printf`, where I write down the possibility of using all 7 format specifiers
```c
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
```
## `Main` function
### And in the main function I wrote three variables that will be used to demonstrate the capabilities of `my_printf`, and a call to the function itself:
```c
int main(){
    int a = 12345;
    char c = 'c';
    char* str = "Hello World";
    my_printf("Decimal:\t\t%d\nOctal:\t\t\t%o\nUnsigned:\t\t%u\nHexadecimal:\t\t%x\nChar:\t\t\t%c\nString:\t\t\t%s\nPointer:\t\t%p\n", a, a, a, a, c, str, &str);

    return 0;
}
```
### The following text is displayed in the console:
```
Decimal:                12345
Octal:                  30071
Unsigned:               12345
Hexadecimal:            3039
Char:                   c
String:                 Hello World
Pointer:                0061FF14
```
---

### The note! This Readme file was written and translated from Russian, therefore some semantic errors may occur
