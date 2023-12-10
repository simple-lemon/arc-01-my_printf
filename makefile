CC = gcc
 CFLAGS = -Wall -Wextra -pedantic
 
 TARGET = my_program
 
 SRCS = my_printf.c
 OBJS = $(SRCS:.c=.o)
 
 .PHONY: all clean
 
 all: $(TARGET)
 
 $(TARGET): $(OBJS)
  $(CC) $(CFLAGS) $(OBJS) -o $@
 
 %.o: %.c
  $(CC) $(CFLAGS) -c $< -o $@
 
 clean:
  rm -f $(OBJS) $(TARGET)
