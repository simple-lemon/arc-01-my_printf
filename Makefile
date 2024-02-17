TARGET = my_printf
CC = gcc 
SRC = my_printf.c
FLAGS = -Wall -Wextra -Werror 

all : $(TARGET)
$(TARGET) : $()
 $(CC) $(FLAGS) -o $(TARGET) $(SRC)


clean : 
 rm  -r $(TARGET) 
 .PHONY : fclean

fclean:
 rm -rf $(TARGET)

re : fclean all
