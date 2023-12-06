CC = gcc
CFLAGS = -Wall -Wextra -pedantic

TARGET = my_printf
SOURCE = my_printf.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean