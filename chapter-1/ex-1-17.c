#include <stdio.h>

#define MAXLINE 8192    /* maximum input line size */

/* You must compile with a C standard, or you get compilation error
 * since getline() is an extension.
 * 
 * Ref: https://en.cppreference.com/w/c/experimental/dynamic/getline
 * */
int getline(char line[], int maxline);    

/* print every input line which its size is larger than 80 characters */
int main()
{
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > 80)
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
