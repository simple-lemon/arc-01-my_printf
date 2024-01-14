TARGET = my_printf
CC = gcc
SRC = my_printf.c


$(TARGET) : $(TARGET)
  $(CC) $(SRC) -o $(TARGET) 

clean : 
  rm TARGET *.exe