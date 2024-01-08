#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>  
#include <unistd.h> 

void my_putschr(char* p1);
char* my_string_putschr(char* p1);
int my_character_putschr(char c);
int my_strlen(char* p1);
char* my_reverse(char* p1, int flag);
long int my_pow(long int num, long int pow);
char* my_stringcpy(char* p1, char* p2);
int num_length(long int num);
char* my_itoa(long int number);
char* my_octal_print(int octal_number);
char* my_unsigned_number_print(int unsigned_number);
char* my_hexadecimal_print(int hexadecimal_number);
char* my_pointer_print(long int pointer_number);
char* my_string_print(char* my_string);
int my_printf(char* text, ...);

void my_putschr(char* p1) // created to print %d.
{
  for (int i = 0; p1[i]; i++) 
  {
    write(1, &p1[i], 1);
  }
}

char* my_string_putschr(char* p1) // created to print %s (string).
{
  if (p1 != NULL) 
  {
    for(int i = 0; p1[i]; i++)
    {
      write(1, &p1[i], 1);
    } 
  }
  else 
  {
    return NULL;
  }
  return 0;
}

int my_character_putschr(char c) // created to print %c (characters).
{
  return write(1, &c, 1);
}


int my_strlen(char* p1) // used in my_reverse function to get the length of string just in case of to reverse %d and print it.
{
  int length = 0;

  while (p1[length] != '\0')
  {
    length++;
  }

  return length;
}

char* my_reverse(char* p1, int flag) // cretaed to reverse string in %d.
{
  int index = 0 ;
  char* reversed_string = calloc(my_strlen(p1) + 4, sizeof(char));
  if (flag == 1)
  {
    reversed_string[0] = '-';
    index++;
  } 
    
  for (int i = my_strlen(p1) - 1; i >= 0; i--) 
  {
    reversed_string[index++] = p1[i];
  }
  free(p1);
  return reversed_string;
}

long int my_pow(long int num, long int pow) // implementation of pow(); created to calculate power of the given number.
{
  long int  result = 1;
  for (int i = 1; i <= pow; i++) {
    result *= num; 
  }
  
  return result ;
}

char* my_stringcpy(char* p1, char* p2) // implentation of strcpy(); created to copy from one string to another string.
{    
  for (int i = 0; p2[i] != '\0'; i++) 
  {
    p1[i] = p2[i];
  }

  return p1;
}

int num_length(long int num) // created to count the length of array string.
{
  int counter = 0;
  while (num != 0)
  {
    counter++;
    num /= 10;
  }
  return counter;
}

char* my_itoa(long int number) // implementation of itoa(); created it to change in number to string to print %d.
{
  int flag = 0;
  if (number < 0) 
  {
    flag = 1;
    number *= -1;
  }
  int number_of_decimals = num_length(number);
  char* number_to_string = calloc(sizeof(char), number_of_decimals + 1);

  int ind = 0;

  for (int i = 0; number > 0; i++ ) 
  {
    number_to_string[ind] = number % 10 + 48;
    ind++;
    number /= 10;
  }
  
  return my_reverse(number_to_string, flag);

}

char* my_octal_print(int octal_number) // created to print %c (octal numbers).
{
  int number_of_decimals = num_length(octal_number);
  char* octal_numbers = calloc(sizeof(char), number_of_decimals);

  int ind = 0;

  for (int i = 0; octal_number > 0; i++ ) 
  {
    octal_numbers[ind] = octal_number % 8 + 48;
    ind++;
    octal_number /= 8;
  }
  
  return my_reverse(octal_numbers, 0);
}

char* my_unsigned_number_print(int unsigned_number) // created to print %u (unsigned decimal).
{
  char* str;
  if (unsigned_number >= 0)
  {
    str = my_itoa(unsigned_number);
  }
  else {
    unsigned_number *= -1;
    int long print_value = my_pow(2, 32) - unsigned_number;
    str = my_itoa(print_value);
  }
  return str;
}

char* my_hexadecimal_print(int hexadecimal_number) // created to print %x (hexadecimal).
{

  int number_of_hexadecimal = num_length(hexadecimal_number);
  char* hexadecimal_numbers = calloc(sizeof(char), number_of_hexadecimal + 1);
  int reminder;
  int ind = 0;
  for (int  i = 0; hexadecimal_number != 0; i++) {
    reminder = hexadecimal_number % 16;
    if (hexadecimal_number < 10 ) 
    {
      hexadecimal_numbers[ind++] = reminder + 48;
    }
    else 
    {
      hexadecimal_numbers[ind++] = reminder + 87;
    }

    hexadecimal_number /= 16;
  }

  
  char* reversed_one = my_reverse(hexadecimal_numbers, 0);
  return reversed_one;
}
     

char* my_pointer_print(long int pointer_number) //  created to print %p (pointer).
{
  if (pointer_number < 0) pointer_number *= -1;
  int number_of_hexadecimal = num_length(pointer_number);
  char* pointer_numbers = calloc(number_of_hexadecimal + 1,sizeof(char));
  int ind = 0;
  for (int  i = 0; pointer_number > 0; i++) {
    long int remainder = pointer_number % 16;
    if (remainder < 10 ) 
    {
      pointer_numbers[ind] = remainder + 48;
      ind++;
    }
    else if (remainder > 10)
    {
      pointer_numbers[ind] = remainder + 55;
      ind++;
    }
    pointer_number /= 16;
  }

  my_stringcpy(&pointer_numbers[ind], "x0");
  return my_reverse(pointer_numbers, 0);
}



char* my_string_print(char* my_string) // created to print %s (string).
{
  int number_of_charecters = my_strlen(my_string);

  my_string = calloc(sizeof(char), number_of_charecters);

  char* string_arr = calloc(sizeof(char), number_of_charecters);
  my_stringcpy(my_string, string_arr);

  return 0;
}



int my_printf(char* text, ...) // implementation of printf(); created to print all the characters and strings that are given in main() function that prints my implementation of printf()
{
  va_list params;
  va_start(params,text);

  for (int i = 0; text[i]; i++) 
  {
    if (text[i] == '%' && text[i + 1] == 'd') 
    {
      int num = va_arg(params, int);
      char* str = my_itoa(num);
      my_putschr(str);
      free(str);
      i++;
    }
    else if (text[i] == '%' && text[i + 1] == 's') 
    {
      char* my_string = va_arg(params, char*);
      my_string_putschr(my_string);
      i++;
    }
    else if (text[i] == '%' && text[i + 1] == 'c') 
    {
      char characters = va_arg(params, int);
      my_character_putschr(characters);
      i++;
    }
    else if (text[i] == '%' && text[i + 1] == 'o') 
    {
      int oct_num = va_arg(params, int);
      char* str = my_octal_print(oct_num);
      my_putschr(str);
      free(str);
      i++;
    }
    else if (text[i] == '%' && text[i + 1] == 'u') 
    {
      int unsigned_number = va_arg(params, int);
      char* str = my_unsigned_number_print(unsigned_number);
      my_putschr(str);
      free(str);
      i++;
    }
    else if (text[i] == '%' && text[i + 1] == 'x') 
    {
      int hexadecimal_number = va_arg(params, int);
      char* str = my_hexadecimal_print(hexadecimal_number);
      my_putschr(str);
      free(str);
      i++;
    }
    else if (text[i] == '%' && text[i + 1] == 'p') 
    {
      long int pointer_number = va_arg(params, long int);
      char* str = my_pointer_print(pointer_number);
      my_putschr(str);
      free(str);
      i++;
    }
    else 
    {
      write(1, &text[i], 1);
    }
  }

  return 0;
}

int main()
{
  char* my_string = calloc(sizeof(char), 6);
  my_stringcpy(my_string, "Hello");
  my_printf("%s\n", my_string); // testing the %s.


  my_printf("%d\n", 5); // testing the %d.
  my_printf("%c\n", 'a'); // testing the %c.
  my_printf("%u\n", -100); // testing the %u.
  printf("%u\n", -100); // testing the %u.
  my_printf("%x\n", 43); // testing the %x.
  // printf("%x\n", 43);

  char a ='s';
  my_printf("%p\n", &a); // testing the %p.

  free(my_string);
  return 0;
}

