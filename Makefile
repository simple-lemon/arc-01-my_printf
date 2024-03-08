CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

TARGET = my_printf
SRCS = my_printf.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
 $(CC) $(CFLAGS) -o $@ $^

%.o: %.c
 $(CC) $(CFLAGS) -c -o $@ $<

clean:
 rm -f $(TARGET) $(OBJS)