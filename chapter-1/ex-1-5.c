#include <stdio.h>

int main()
{
    int fahr;

    printf("Convert Fahrenheit to Celcius for F = 300, 280, ..., 0\n");

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}

