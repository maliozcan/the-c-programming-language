#include <stdio.h>

/*
 You can test EOF by usind ^D command.
 Ref: https://en.wikipedia.org/wiki/End-of-Transmission_character
*/

int main()
{
    int c;
    while (c = getchar() != EOF)
        printf("%d", c);
    printf("\n%d\n", c);
}
