CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SOURCE = my_printf.c
TARGET = my_printf

$(TARGET): $(SOURCE)
 $(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
 rm -f $(TARGET)
