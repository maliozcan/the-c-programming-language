#include <stdio.h>

#define MAX_NUM_OF_CHAR         128      /* from ASCII document to cover all letter, digits, and other chars */

int main()
{
    int c, i;
    double total;
    long num_of_chars[MAX_NUM_OF_CHAR];

    for (i = 0; i < MAX_NUM_OF_CHAR; ++i)
        num_of_chars[i] = 0;

    while ((c = getchar()) != EOF)
        if (c < MAX_NUM_OF_CHAR)
            ++num_of_chars[c];

    total = 0;
    for (i = 0; i < MAX_NUM_OF_CHAR; ++i)
        total = total + num_of_chars[i];

    printf("Char ASCII-Code  Frequency\n");
    for (i = 0; i < MAX_NUM_OF_CHAR; ++i)
        if (num_of_chars[i] != 0)
            printf("%c      [%3d]:    %1.6f\n", i, i, num_of_chars[i] / total);
}
