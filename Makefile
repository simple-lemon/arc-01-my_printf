CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = my_printf
SRC = my_printf.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean