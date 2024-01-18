CC = gcc
CFLAGS = -Wall -Wextra -pedantic

all: my_printf

my_printf: my_printf.o
	$(CC) $(CFLAGS) -o my_printf my_printf.o

my_printf.o: my_printf.c
	$(CC) $(CFLAGS) -c my_printf.c

clean:
	rm -f my_printf *.o
