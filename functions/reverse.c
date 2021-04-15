#include <stdio.h>

#define MAX_LINE 1000  // maximum input line size

int getline1(char[], int);
void reverse(char[], int);

/*
 * Reverse a string S
 */

int main() {
  int len;
  char line[MAX_LINE];

  while ((len = getline1(line, MAX_LINE)) > 0) {
    reverse(line, len);
    printf("%s", line);
  }

  return 0;
}

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

void reverse(char s[], int len) {
  int c = 0;
  char reversed[len];

  for (int i = len - 1; i >= 0; i--)
    if (s[i] != '\n') {
      reversed[c] = s[i];

      ++c;
    }

  if (s[len - 1] == '\n')
    reversed[c] = '\n';

  for (int i = 0; i < len; i++)
    s[i] = reversed[i];
}
