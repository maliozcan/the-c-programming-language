#include <stdio.h>

int main()
{
    int c;
    long num_of_blank, num_of_tabs, num_of_newline;

    num_of_blank = 0;
    num_of_tabs = 0;
    num_of_newline = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++num_of_blank;
        if (c == '\t')
            ++num_of_tabs;
        if (c == '\n')
            ++num_of_newline;
    }
    printf("%ld %ld %ld\n", num_of_blank, num_of_tabs, num_of_newline);
}
