#include <stdio.h>

int main() {
  unsigned char previousBlank = 0;
  int c;

  while ((c = getchar()) != EOF)
    if (c == ' ') {
      if (previousBlank == 0) {
        putchar(c);
        ++previousBlank;
      }
    } else {
      putchar(c);
      previousBlank = 0;
    }
}
