#include <stdio.h>

/*
 * Print Fahrenheit-Celsius table.
 * for fahr = 0, 20, ..., 300
 */

int main()
{
  printf("Fahr  Celcius\n");

  for (int fahr = 0; fahr <= 300; fahr += 20)
    printf("%3d %7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}
