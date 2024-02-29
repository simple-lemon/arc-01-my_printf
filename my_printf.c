#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

char *my_upcase(char *s) {
	int n = 0;

	while (*s != '\0') {
		if (*s >= 'a' && *s <= 'z')
			*s -= 'a' - 'A';
			
		++s;
		++n;
	}

	return s - n;
}

void reverse_string(char *s) {
	int i = 0;
	
	while(s[i] != '\0')
		i++;

	for (int j = 0, k = i - 1; j < k; j++, k--) {
		int temp = s[j];
		s[j] = s[k];
		s[k] = temp;
	}
}

void itoa(long long int n, char *s, int base) {
	int i = 0;
	int t = 0;

	if (n == 0) {
		s[i++] = '0';
		s[i] = '\0';
	}

	if (n < 0 && base == 10) {
		n = -n;
		t = 1;
	}

	while (n > 0) {
		int remainder = n % base;

		if (remainder > 9)
			s[i++] = remainder - 10 + 'a';
		else
			s[i++] = remainder + '0';

		n /= base;
	}

	if (t)
		s[i++] = '-';

	s[i] = '\0';

	reverse_string(s);
}


void my_putchar(char *c) {
	write(1, c, 1);
}

int my_putstr(char *s) {
	int n = 0;
	while(*s != '\0') {
		my_putchar(s);
		s++;
		n++;
	}

	return n;
}

int my_printf(char *fmt, ...)   /* '...' is C syntax for a variadic function */
{
	va_list ap;
	int d, o, x;
	char c;
	char *s;
	char *Ox = "0x";
	long int p;
	int counter = 0;

	va_start(ap, fmt);
	while (*fmt) 
		if (*fmt++ == '%')
			switch (*fmt++) {
			case 's':              				/* string */
				s = va_arg(ap, char *);
				if (s)
					counter += my_putstr(s);
				else {
					s = "(null)";
					counter += my_putstr(s);
				}
				break;
			case 'd':              				/* int */
			case 'i':
			case 'u':
				d =  va_arg(ap, int);
				char buffer[200];
				itoa(d, buffer, 10);
				counter += my_putstr(buffer);
				break;
			case 'c':              				/* char */
				c = (char) va_arg(ap, int);		// need a cast here since va_arg only takes fully promoted types
				my_putchar(&c);
				counter++;
				break;
			case 'p':					/* pointer */
				p =  va_arg(ap, long int);
				char buffer3[200];
				itoa(p, buffer3, 16);
				counter += my_putstr(Ox);
				counter += my_putstr(buffer3);
				break;
			case 'o':					/* octal */
				o = va_arg(ap, int);
				char buffer1[200];
				itoa(o, buffer1, 8);
				counter += my_putstr(buffer1);
				break;
			case '%':					/* % */
				my_putchar(fmt-1);
				counter++;
				break;
			case 'x':					/* hexadecimal */
			case 'X':
				x = va_arg(ap, int);
				char buffer2[200];
				itoa(x, buffer2, 16);
				counter += my_putstr(my_upcase(buffer2));
				break;
			}
		else {
			my_putchar(fmt-1);
			counter++;
		}
	
	va_end(ap);

	return counter;
}

//  warren main
int main(void) {
    char test[] = "NULL STRING (null)!\n" ;
    char test2[] = "ABC";
    char test3[] = "\n";
    char test4[] = "\t";
    // int my_int = my_printf("NULL STRING (null)!\n%s", (char *)NULL);
    int std_p = printf("%s", (char *)NULL);
    // printf("my %i\nstd %i\n", my_int, std_p);
}
