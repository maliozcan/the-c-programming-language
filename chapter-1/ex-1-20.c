#include <stdio.h>

#define MAXSIZE         8192
#define TABWIDTH        8

int getline(char line[], int maxsiz);
void detab(char line[], int size);

/* detab */
int main()
{
    int len;
    char line[MAXSIZE];

    while ((len = getline(line, MAXSIZE)) > 0) {
        detab(line, len);
    }

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

void detab(char line[], int size)
{
    int i, j, remainder, nspace;
    nspace = 0;
    for (i = 0; i < size; ++i) {
        if (line[i] == '\t') {
            remainder = nspace - (nspace / TABWIDTH) * TABWIDTH; /* We don't know % operator currently. */
            for (j = 0; j < (TABWIDTH - remainder); ++j)
                putchar(' ');
            nspace = nspace + TABWIDTH - remainder;
        } else {
            putchar(line[i]);
            ++nspace;
        }
    }
}

