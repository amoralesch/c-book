#include <stdio.h>

#define IN 1   // inside a word
#define OUT 0  // outside a word

/*
 * Cout lines, words and characters in input
 */

int main() {
  int c = 0;
  int nl = 0;
  int nw = 0;
  int nc = 0;
  int state = OUT;

  while ((c = getchar()) != EOF) {
    ++nc;

    if (c == '\n')
      ++nl;

    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);
}
