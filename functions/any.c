#include <stdio.h>

#define MAX_LINE 100

int any(char[], char[]);
void getFullLine(char[], int);

int main()
{
    char s1[MAX_LINE];
    char s2[MAX_LINE];

    printf("Introduce first line: ");
    getFullLine(s1, MAX_LINE);

    printf("Introduce second line: ");
    getFullLine(s2, MAX_LINE);

    printf("First occurrence: %d", any(s1, s2));

    return 0;
}

void getFullLine(char line[], int max)
{
    int i = 0;

    for (int c = getchar(); c != EOF && c != '\n'; c = getchar())
        if (i < max - 1)
            line[i++] = c;

    line[i] = '\0';
}

int any(char s1[], char s2[])
{
    int i = 0;
    int pos = MAX_LINE + 1;

    while (s2[i] != '\0') {
        int j = 0;

        while (s1[j] != '\0') {
            if (s2[i] == s1[j] && j < pos)
                pos = j;

            j++;
        }

        i++;
    }

    return pos < MAX_LINE ? pos : -1;
}
