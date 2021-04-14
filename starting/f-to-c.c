#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float celsius(int);

/*
 * Print Fahrenheit-Celsius table.
 * for fahr = 0, 20, ..., 300
 */

int main()
{
  printf("Fahr  Celcius\n");

  for (int fahr = LOWER; fahr <= UPPER; fahr += STEP)
    printf("%3d %7.1f\n", fahr, celsius(fahr));
}

float celsius(int fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
}
