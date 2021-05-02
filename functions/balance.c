/*
 * Program to check if the source file has a balanced number
 * of braces, bracket and parenthesis
 */

#include <stdio.h>

int braces = 0;
int brackets = 0;
int parenthesis = 0;

void insideQuote(char);
void insideBlockComment();
void insideInlineComment();
void check(char);

int main() {
  int c;
  extern int braces;
  extern int brackets;
  extern int parenthesis;

  while ((c = getchar()) != EOF) {
    if (c == '/') {
      int d = getchar();

      if (d == '*')
        insideBlockComment();
      else if (d == '/')
        insideInlineComment();
    } else if (c == '\'' || c == '"') {
      insideQuote(c);
    } else
      check(c);
  }

  if (braces != 0)
    printf("Unbalanced braces\n");

  if (brackets != 0)
    printf("Unbalanced brackets\n");

  if (parenthesis != 0)
    printf("Unbalanced parenthesis\n");

  if (braces == 0 && brackets == 0 && parenthesis == 0)
    printf("All is good\n");

  return 0;
}

void insideInlineComment() {
  int c = getchar();

  while (c != '\n' && c != EOF)
    c = getchar();
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
  int d;

  while ((d = getchar()) != delimiter)
    if (d == '\\')
      getchar();
}

void check(char c) {
  extern int braces;
  extern int brackets;
  extern int parenthesis;

  switch (c) {
    case '(':
      ++parenthesis;
      break;
    case ')':
      --parenthesis;
      break;
    case '[':
      ++brackets;
      break;
    case ']':
      --brackets;
      break;
    case '{':
      ++braces;
      break;
    case '}':
      --braces;
      break;
    default:
      break;
  }
}