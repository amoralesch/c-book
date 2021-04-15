#include <stdio.h>

#define MAX_LINE 1000  // maximum input line size
#define FILTER_SIZE 80

int getline1(char[], int);

/*
 * Print input lines longer that 80 chars
 */

int main() {
  int len;  // current line length
  int max = 0;  // maximum length seen so far

  char line[MAX_LINE];  // current input line
  char longest[MAX_LINE];  // longest line saved here

  while ((len = getline1(line, MAX_LINE)) > 0)
    if (len > FILTER_SIZE)
      printf("%s", line);

  return 0;
}

/*
 * getline: read a line into s, return length
 */
int getline1(char s[], int lim) {
  int c;
  int i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
