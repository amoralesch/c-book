#include <stdio.h>

#define MAX_LEN 20

/*
 * Print a histogram of the lengths of words in input
 */

int main() {
  int c;
  int len = 0;
  int max = 0;
  int counts[MAX_LEN];

  for (int i = 0; i < MAX_LEN; i++)
    counts[i] = 0;


  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (len != 0)  {
        if (len > MAX_LEN)
          len = MAX_LEN;

        ++counts[len - 1];
      }

      len = 0;
    } else
      ++len;
  }

  printf("Word length frequency histogram\n\n");

  for (int i = 0; i < MAX_LEN; i++) {
    printf("%4d", i + 1);

    for (int j = 0; j < counts[i]; j++)
      printf("#");

    printf("\n");
  }
}
