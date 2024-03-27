CC = gcc 
CFLAGS = -Wall -Wextra -std=c99
TARGET = my_printf
SRC = my_printf.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -fr $(TARGET)
