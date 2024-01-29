CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = my_printf

all: $(TARGET)

$(TARGET): my_printf.o main.o
 $(CC) $(CFLAGS) -o $@ $^

my_printf.o: my_printf.c my_printf.h
 $(CC) $(CFLAGS) -c $< -o $@

main.o: main.c my_printf.h
 $(CC) $(CFLAGS) -c $< -o $@

clean:
 rm -f $(TARGET) *.o

.PHONY: clean all
