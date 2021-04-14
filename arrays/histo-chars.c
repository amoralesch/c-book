#include <stdio.h>

int main() {
  int digits['9' - '0' + 1];
  int lower['z' - 'a' + 1];
  int upper['Z' - 'A' + 1];
  int others = 0;

  for (int i = 0; i <= ('9' - '0'); i++)
    digits[i] = 0;

  for (int i = 0; i <= ('z' - 'a'); i++)
    lower[i] = 0;

  for (int i = 0; i <= ('Z' - 'A'); i++)
    upper[i] = 0;

  int c;
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')
      ++digits[c - '0'];
    else if (c >= 'a' && c <= 'z')
      ++lower[c - 'a'];
    else if (c >= 'A' && c <= 'Z')
      ++upper[c - 'A'];
    else
      ++others;
  }

  for (int i = 0; i <= ('9' - '0'); i++) {
    if (digits[i] == 0)
      continue;

    printf("%2d", i);

    for (int j = 0; j < digits[i]; j++)
      printf("#");

    printf("\n");
  }

  for (int i = 0; i <= ('z' - 'a'); i++) {
    if (lower[i] == 0)
      continue;

    printf("%2c", ('a' + i));

    for (int j = 0; j < lower[i]; j++)
      printf("#");

    printf("\n");
  }

  for (int i = 0; i <= ('Z' - 'A'); i++) {
    if (upper[i] == 0)
      continue;

    printf("%2c", ('A' + i));

    for (int j = 0; j < upper[i]; j++)
      printf("#");

    printf("\n");
  }

  printf("etc %d\n", others);
}
