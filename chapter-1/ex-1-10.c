#include <stdio.h>

int main()
{
    int c, print;

    while ((c = getchar()) != EOF) {
        print = 1;
        if (c == '\t') {
            printf("\\t");
            print = 0;
        }
        if (c == '\b') {
            printf("\\b");
            print = 0;
        }
        if (c == '\\') {
            printf("\\");
            print = 0;
        }
        if (print)
            putchar(c);
    }
}

