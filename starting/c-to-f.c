#include <stdio.h>

float fahr(int);

/*
 * Print Celsius-Fahrenheit table.
 * for celsius = 0, 20, ..., 300
 */

int main()
{
  printf("Celcius Fahr\n");

  for (int celsius = 300; celsius >= 0; celsius -= 20)
    printf("%3d %7.1f\n", celsius, fahr(celsius));
}

float fahr(int celsius) {
  return ((9.0 / 5.0) * celsius) + 32.0;
}
