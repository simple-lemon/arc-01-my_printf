CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2

TARGET = my_printf

all: $(TARGET)

$(TARGET): my_printf.c
	$(CC) $(CFLAGS) -o $(TARGET) my_printf.c

clean:
	rm -f $(TARGET)
