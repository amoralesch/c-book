#include <stdio.h>

/*
 * Print Celsius-Fahrenheit table.
 * for celsius = 0, 20, ..., 300
 */

int main()
{
  printf("Celcius Fahr\n");

  for (int celsius = 0; celsius < 300; celsius += 20)
    printf("%3d %7.1f\n", celsius, ((9.0 / 5.0) * celsius) + 32.0);
}
