#include <stdio.h>

float fahr_to_celcius(int fahr);

int main()
{
    float fahr;
    int lower, upper, step;

    printf("Convert Fahrenheit to Celcius for F = 0, 20, ..., 300\n");

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, fahr_to_celcius(fahr));
        fahr = fahr + step;
    }
}

float fahr_to_celcius(int fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}
