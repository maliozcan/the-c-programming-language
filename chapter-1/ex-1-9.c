#include <stdio.h>

int main()
{
    int c, is_it_blank;

    is_it_blank = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' && is_it_blank == 0) {
            putchar(c);
            is_it_blank = 1;
        }
        if (c != ' ') {
            putchar(c);
            is_it_blank = 0;
        }
    }
}

