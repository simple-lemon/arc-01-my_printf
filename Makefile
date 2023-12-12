CFLAGS = -Wall -Wextra -Werror
SRC = my_printf.c
TARGET = my_printf  

$(TARGET) : $(SRC)
	gcc $(CFLAGS) -o $@ $<

start :
	gcc $(CFLAGS) -o $(TARGET) $(SRC)
	./$(SRC)

.Phony : fclean

fclean :
	@rm -r $(TARGET)
