#include <stdio.h>

int power(int, int);

/*
 * Power function
 */

int main() {
  for (int i = 0; i < 10; i++)
    printf("%2d %3d %6d\n", i, power(2, i), power(-3, i));

  return 0;
}

/*
 * powerr: raise base to n-th power
 * n >= 0
 */

int power(int base, int n) {
  int p;

  for (p = 1; n > 0; n--)
    p *= base;

  return p;
}
