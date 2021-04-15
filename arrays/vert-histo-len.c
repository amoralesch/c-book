#include <stdio.h>

#define MAX_LEN 20

/*
 * Print a vertical histogram of the lengths of words in input
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

  for (int i = 0; i < MAX_LEN; i++)
    if (counts[i] > max)
      max = counts[i];

  printf("Word length frequency vertical histogram\n\n");

  for (int i = 0; i < max; i++) {
    printf("%3d", max - i);

    for (int j = 0; j < MAX_LEN; j++)
      if ((counts[j] - max + i) >= 0)
        printf("  #");
      else
        printf("   ");

    printf("\n");
  }

  printf("   ");
  for (int i = 0; i < MAX_LEN; i++)
    printf("%3d", i + 1);

  printf("\n");
}
