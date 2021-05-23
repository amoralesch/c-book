#include <stdio.h>

#define MAX_LINE 100

void squeeze(char[], char[]);
void getFullLine(char[], int);

int main()
{
    char s1[MAX_LINE];
    char s2[MAX_LINE];

    printf("Introduce first line: ");
    getFullLine(s1, MAX_LINE);

    printf("Introduce second line: ");
    getFullLine(s2, MAX_LINE);

    squeeze(s1, s2);

    printf("First line squeezed: %s", s1);

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

void squeeze(char s1[], char s2[])
{
    int i = 0;

    while (s2[i] != '\0') {
        int j = 0;

        while (s1[j] != '\0') {
            if (s2[i] == s1[j]) {
                int k = j;

                while (s1[k] != '\0') {
                    s1[k] = s1[k + 1];
                    k++;
                }
            }

            j++;
        }

        i++;
    }
}
