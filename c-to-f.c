#include <stdio.h>

/*
 * Print Celsius-Fahrenheit table.
 * for celsius = 0, 20, ..., 300
 */

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;    // lower limit of temperature
  upper = 300;  // upper limit
  step = 20;    // step size

  printf("Celcius Fahr\n");
  celsius = lower;
  while (celsius <= upper) {
    fahr = ((9.0 / 5.0) * celsius) + 32.0;

    printf("%4.0f %7.1f\n", celsius, fahr);

    celsius = celsius + step;
  }
}
