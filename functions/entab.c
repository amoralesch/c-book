#include <stdio.h>
#include <stdbool.h>

#define MAX_LINE 1000
#define TAB_SIZE 8

int main()
{
  int lastSpacePos = -1;
  int pos = 0;
  char input;
  bool insideSpace = false;

  while ((input = getchar()) != EOF) {
    if (pos % TAB_SIZE == 0 && insideSpace) {
      putchar('\t');
      insideSpace = false;
      lastSpacePos = -1;
    }

    if (input != ' ') {
      if (insideSpace)
        for (int i = lastSpacePos; i < pos; i++)
          putchar(' ');

      putchar(input);

      lastSpacePos = -1;
      insideSpace = false;
    } else {
      if (!insideSpace)
        lastSpacePos = pos;

      insideSpace = true;
    }

    pos++;

    if (input == '\n')
      pos = 0;
  }

  return 0;
}
