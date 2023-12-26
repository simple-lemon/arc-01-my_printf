G = gcc
SRC = my_printf.c
TARGET = my_printf
FLAGS = -Wall -Wextra -Werror 

$(TARGET) : $(SRC)
	@$(G) $(FLAGS) -o $(TARGET) $(SRC)

.PHONY : fclean

fclean :
	@rm -r $(TARGET)