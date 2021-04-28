#include <stdio.h>

#define MAX_LINE 1000
#define TAB_SIZE 8

int main()
{
  int pos = 0;
  char input;

  while ((input = getchar()) != EOF) {
    if (input == '\t') {
      putchar(' ');
      pos++;

      while ((pos % TAB_SIZE) != 0) {
        putchar(' ');
        pos++;
      }
    } else {
      putchar(input);
      pos++;

      if (input == '\n')
        pos = 0;
    }
  }

  return 0;
}
