#include <stdio.h>

#define COL_SIZE 10
#define TAB_SIZE 8
#define CUR_TAB_LEN(c) (TAB_SIZE - ((c) % TAB_SIZE))

int findLastBlank(char[], int);

int main() {
  int c;
  int col = 0;
  int pos = 0;
  char line[COL_SIZE + 1];

  while ((c = getchar()) != EOF) {
    line[pos++] = c;
    col += (c == '\t') ? CUR_TAB_LEN(col) : 1;

    if (col >= COL_SIZE || c == '\n') {
      line[pos] = '\0';

      int lastBlank = findLastBlank(line, pos);

      if (lastBlank == -1) {
        for (int i = 0; i < pos; i++)
          putchar(line[i]);

        pos = 0;
        col = 0;
      } else {
        for (int i = 0; i < lastBlank; i++)
          putchar(line[i]);

        int i = 0;
        col = 0;

        for (int j = lastBlank + 1; j < pos; j++) {
          line[i++] = line[j];
          col += (c == '\t') ? CUR_TAB_LEN(col) : 1;
        }

        pos = i;
      }

      putchar('\n');
    }
  }

  return 0;
}

int findLastBlank(char arr[], int size) {
  int place = -1;

  for (int i = 0; i < size; i++)
    if (arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\n')
      place = i;

  return place;
}
