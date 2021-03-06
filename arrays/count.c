#include <stdio.h>

/*
 * Count digits, white space and others
 */

int main() {
  int c;
  int nwhite = 0;
  int nother = 0;
  int ndigit[10];

  for (int i = 0; i < 10; ++i)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF)
    if (c >= '0' && c <= '9')
      ++ndigit[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;

  printf("digits =");

  for (int i = 0; i < 10; ++i)
    printf(" [%d]=%d", i, ndigit[i]);

  printf(", white space = %d, other = %d\n", nwhite, nother);
}
