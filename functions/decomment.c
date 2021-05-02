/*
 * Program to remove comments from a C file.
 * Should deal with block comments
 * and one liners like // this
 */

// This is a one liner comment

#include <stdio.h>

void insideQuote(char);
void insideBlockComment();
void insideInlineComment();

int main() {  // I can be at the end of a line
  int c;

  printf("Testing block comments inside /* quotes */\n");
  printf("Testing line comments inside // quotes\n");

  while ((c = getchar()) != EOF) /* block comment can be inside code */ {
    if (c == '/') {
      int d = getchar();

      if (d == '*')
        insideBlockComment();
      else if (d == '/') {
        insideInlineComment();
      } else {
        putchar(c);
        putchar(d);
      }
    } else if (c == '\'' || c == '"') {
      insideQuote(c);
    } else
      putchar(c);
  }

  return 0;
}

void insideInlineComment() {
  int c = getchar();

  while (c != '\n' && c != EOF)
    c = getchar();

  putchar('\n');
}

void insideBlockComment() {
  int c = getchar();
  int d = getchar();

  while (c != '*' || d != '/') {
    c = d;
    d = getchar();
  }
}

void insideQuote(char delimiter) {
  putchar(delimiter);

  int d;

  while ((d = getchar()) != delimiter) {
    putchar(d);

    if (d == '\\')
      putchar(getchar());
  }

  putchar(d);
}
