#include <stdio.h>

#define MAXLINE 8192    /* maximum input line size */

/* You must compile with a C standard, or you get compilation error
 * since getline() is an extension.
 * 
 * Ref: https://en.cppreference.com/w/c/experimental/dynamic/getline
 * */
int getline(char line[], int maxline);    
void copy(char from[], char to[]);

/* print the length of the longest line, as much as possible of the longest line */
int main()
{
    int len;                    /* current line length */
    int max;                    /* maximum length of all lines */
    char line[MAXLINE];         /* current input line */
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(line, longest);
        }


    printf("The length of the longest line is %d\n", max); 
    printf("The Longest line: %s\n", longest);
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
    /* If the buffer exhaust, keep to count character */
    if (c != EOF && c != '\n') {
        ++i;
        while ((c = getchar()) != EOF && c != '\n')
            ++i;
    }
    return i;
}

void copy(char from[], char to[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
