#include <stdio.h>

int main() {
  int blanks = 0;
  int tabs = 0;
  int newLines = 0;
  int c;

  while ((c = getchar()) != EOF)
    if (c == ' ')
      ++blanks;
    else if (c == '\t')
      ++tabs;
    else if (c == '\n')
      ++newLines;

  printf("Blanks: %d\n", blanks);
  printf("Tabs: %d\n", tabs);
  printf("New lines: %d\n", newLines);
}
