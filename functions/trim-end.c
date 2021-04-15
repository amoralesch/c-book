#include <stdio.h>

#define MAX_LINE 1000  // maximum input line size

int getline1(char[], int);
int rTrim(char[], int);

/*
 * Remove trailing blanks and tabs
 * It also deletes blank lines
 */

int main() {
  int len;  // current line length
  char line[MAX_LINE];  // current input line

  while ((len = getline1(line, MAX_LINE)) > 0)
    if (rTrim(line, len) > 0)
      printf("%s", line);

  return 0;
}

/*
 * getline1: read a line into s, return length
 */
int getline1(char s[], int lim) {
  int c;
  int i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    i++;
  }

  s[i] = '\0';

  return i;
}

/*
 * rTrim: Right trims a string, removing whitespaces, returns lenght
 */
int rTrim(char s[], int len) {
  if (len <= 1)
    return 0;

  int c;
  int lastPos = 0;

  for (int i = 0; i < len; i++) {
    c = s[i];

    if (c != ' ' && c != '\t' && c != '\n')
      lastPos = i;
  }

  if (c == '\n')
    s[++lastPos] = c;

  s[lastPos + 1] = '\0';

  return lastPos;
}
