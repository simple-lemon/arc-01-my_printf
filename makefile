CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -g3 -fsanitize=address

TARGET = my_printf
SRC = my_printf.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)

fclean: clean
	rm -f $(TARGET)
