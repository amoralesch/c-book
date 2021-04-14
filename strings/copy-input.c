#include <stdio.h>

/*
 * Copy input to output
 */

int main()
{
  int c;

  printf(">>> value of EOF: %d\n", EOF);

  while ((c = getchar()) != EOF)
    putchar(c);
}
