#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
int my_printff (char l) {
    write(1, &l, 1);
    return (1);
}

int chorni_tex (int ryzen) {
    int param = 0;
    int arguz;
    if (ryzen < 0) {
        param += my_printff('-');
        ryzen *= -1;
    }
    if (ryzen > 9)
        param += chorni_tex(ryzen / 10);
    arguz = ryzen % 10 + '0';
    return (param + my_printff(arguz));
}

int my_chorni (unsigned int argcc) {
    int param = 0;
    if (argcc > 9)
        param += my_chorni(argcc / 10);
    return (param + my_printff(argcc % 10 + 48));
}

int my_file (unsigned int argv) {
    int param = 0;
    if (argv > 7)
        param += my_file(argv / 8);
    return (param + my_printff(argv % 8 + 48));
}

int strx (unsigned long int argv1) {
    int param1 = 0;
    int sms;
    if (argv1 > 15)
        param1 += strx(argv1 / 16);
    if (argv1%16 > 9 && argv1%16 < 16){
        sms = (argv1%16-10 + 65);
        return (param1 + my_printff(sms));
    }
    else{
        sms = argv1 % 16  + 48;
        return (param1 + my_printff(sms));
    }
}
int printp (unsigned long int argv2) {
    int param2 = 0;
    int bbc;
    if (argv2 > 15)
        param2 += printp(argv2 / 16);
    if (argv2%16 > 9 && argv2%16 < 16) {
    bbc = argv2%16-10 + 97;
        return (param2 + my_printff(bbc));
    }
    else
        return (param2 + my_printff(argv2 % 16  + 48));
}
int my_css(char *a) {
    int i = 0;
    for(i = 0; *a;){
        i += my_printff(*a++);
    }
    return i;
}
int my_printf(char* tex_1, ...) {

    va_list ab;
    char *such, ch;
    int son;
    unsigned int onlik;
    intptr_t xac;
    int num1 = 0;

    va_start(ab, tex_1);
    while (*tex_1) {
        if (*tex_1 == '%') {
            switch (*++tex_1) {
                case 's':
                    such = va_arg(ab, char *);
                    if(!such || !*such) {
                        num1 += my_css("(null)");
                    }
                    else
                    num1 += my_css(such);
                    break;

                case 'd':
                    son = va_arg(ab, int);
                    num1 += chorni_tex(son);
                    break;

                case 'c':
                    ch = va_arg(ab, int);
                    num1 += my_printff(ch);
                    break;

                case 'u':
                    onlik = va_arg(ab, unsigned int);
                    num1 += my_chorni(onlik);
                    break;

                case 'o':
                    onlik = va_arg(ab, unsigned int);
                    num1 += my_file(onlik);
                    break;

                case 'x':
                    xac = va_arg(ab, intptr_t);
                    num1 += strx(xac);
                    break;

                case 'p':
                    xac = va_arg(ab, intptr_t);
                    num1 += my_css("0x") + printp(xac);
                    break;

                default:
                    num1 += my_printff('%');
            }
            tex_1++;
        }
        if (*tex_1 != '%') {
            num1 += my_printff(*tex_1);
            tex_1++;
        }
    }
    va_end(ab);
    return (num1);
}
