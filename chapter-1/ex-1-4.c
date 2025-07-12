#include <stdio.h>

int main()
{
    float fahr, celcius;
    int lower, upper, step;

    printf("Convert Celcius to Fahrenheit for C = -20, 0, ..., 300\n");

    lower = -20;
    upper = 300;
    step = 20;

    celcius = lower;
    while (fahr <= upper) {
        fahr = celcius * (9.0 / 5.0) + 32.0;
        printf("%3.0f %6.1f\n", celcius, fahr);
        celcius = celcius + step;
    }
}

