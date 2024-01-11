CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
TARGET = my_printf
SRC = my_printf.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean fclean re

clean:
	rm -f $(TARGET)

fclean: clean

re: fclean all


