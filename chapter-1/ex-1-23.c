#include <stdio.h>

#define MAXSIZE         8192
#define IN              1               /* inside a comment */
#define OUT             0               /* outside a comment */

int getline(char line[], int maxsiz);
int remove_comments(char s[], int size, int comment);

/* Remove comments from C source code.
 * You may use this file as a test input.
*/
int main()
{
    int len, comment;
    char line[MAXSIZE];

    comment = OUT;
    while ((len = getline(line, MAXSIZE)) > 0) {
        comment = remove_comments(line, len, comment);
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

int remove_comments(char s[], int size, int comment)
{
    int i, in_str;
    in_str = 0;
    for (i = 0; i < size; ++i) {
        if (comment == OUT) {
            if (in_str == 0 && s[i] == '"') {
                putchar(s[i]);
                in_str = 1;
            } else if (in_str == 1) {
                putchar(s[i]);
               if (s[i] == '"' && i > 0 && s[i - 1] != '\\') {
                   in_str = 0;
               } 
            } else if (s[i] == '/' && i + 1 < size && s[i + 1] == '*') {
                comment = IN;
                ++i;
            } else
                putchar(s[i]);
        } else { /* comment == IN */
            if (s[i] == '*' && i + 1 < size && s[i + 1] == '/') {
                comment = OUT;
                ++i;
            }
        }
    }
    return comment;
}

