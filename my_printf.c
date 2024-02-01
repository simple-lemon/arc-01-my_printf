#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int a;
  for (char b = ' '; b <= 'z'; b++)
  {
    a = 0;
    for (int i = 1; i < argc; i++)
    {
      for (int j = 0; j < strlen(argv[i]); j++)
      {
        if (argv[i][j] == b)
        {
          a++;
        }
      }
    }
    if (a > 0)
    {
      printf("%c:%d\n", b, a);
    }
  }

  return 0;
}
