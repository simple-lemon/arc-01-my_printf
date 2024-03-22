CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: my_printf

my_printf: my_printf.o
	$(CC) $(CFLAGS) -o $@ $^

my_printf.o: my_printf.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f my_printf my_printf.o
