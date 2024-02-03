CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

TARGET = my_printf
SRCS = my_printf.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY: fclean
fclean: clean
	rm -f $(TARGET)