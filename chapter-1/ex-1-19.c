#include <stdio.h>

#define MAXLINE 8192    /* maximum input line size */
#define IN      1
#define OUT     0

int getline(char line[], int maxline);
void reverse(char line[], int size);

/* remove trailing blanks and tabs from each line, and delete entirely blnak lines */
int main()
{
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(line, len - 1);  /* exclude the newline character */
        printf("%s", line);
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

void reverse(char line[], int size)
{
    int i, c;
    for (i = 0; i < size / 2; ++i) {
        c = line[i];
        line[i] = line[size - 1 - i];
        line[size - 1 - i] = c;
    }
}
