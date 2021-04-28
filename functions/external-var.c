#include <stdio.h>

#define MAX_LINE 1000

int max;
char line[MAX_LINE];
char longest[MAX_LINE];

int getLine(void);
void copy(void);

int main(void) {
  int len;
  extern int max;
  extern char longest[];

  max = 0;

  while ((len = getLine()) > 0)
    if (len > max) {
      max = len;
      copy();
    }

  if (max > 0)
    printf("%s", longest);

  return 0;
}

int getLine(void) {
  int c;
  int i;
  extern char line[];

  for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

void copy(void) {
  int i = 0;
  extern char line[];
  extern char longest[];

  while ((longest[i] = line[i]) != '\0')
    ++i;
}
