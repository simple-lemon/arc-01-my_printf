CC = gcc
CFLAGS = -Wall -Wextra

SRC = main.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = my_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(EXECUTABLE)

PHONY: all clean
