CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = my_printf

SRCS = my_printf.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY:fclean

fclean: 
	rm -rf $(TARGET)
