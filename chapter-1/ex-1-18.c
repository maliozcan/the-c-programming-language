#include <stdio.h>

#define MAXLINE 8192    /* maximum input line size */
#define IN      1
#define OUT     0

int getline(char line[], int maxline);
int remove_trailing_blank_lines(char line[], int size);

/* remove trailing blanks and tabs from each line, and delete entirely blnak lines */
int main()
{
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
        if (remove_trailing_blank_lines(line, len) > 0)
            printf("%s", line);

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int remove_trailing_blank_lines(char line[], int size)
{
    int c, i, loc, state;

    state = OUT;
    loc = -1;
    /* line[size - 1] should be '\n', so we don't need to consider it. */
    for (i = 0; i < size - 1; ++i) {
        c = line[i];
        if (c == ' ' || c == '\t') {
            if (state == IN)
                loc = i;
            state = OUT;
        } else
            state = IN;
    }

    if (loc == -1 && state == IN)
        loc = size;
    else if (loc == -1 && state == OUT)
        loc = 0;
    else if (state == OUT) {
        line[loc] = '\n';
        ++loc;
        line[loc] = '\0';
    } else
        loc = size;

    return loc;
}
