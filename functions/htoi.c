#include <stdio.h>

void convertValue();

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c != '0')
            printf("invalid input\n");
        else {
            c = getchar();

            if (c != 'x' && c != 'X')
                printf("invalid input\n");
            else
                convertValue();
        }
    }

    return 0;
}

void convertValue()
{
    int value = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            value = (value * 16) + (c - '0');
        else if (c >= 'a' && c <= 'f')
            value = (value * 16) + (c - 'a' + 10);
        else if (c >= 'A' && c <= 'F')
            value = (value * 16) + (c - 'A' + 10);
        else if (c == '\n') {
            printf("value = %d\n", value);
            return;
        } else {
            printf("invalid input\n");
            return;
        }
    }
}
