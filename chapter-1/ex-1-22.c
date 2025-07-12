#include <stdio.h>

#define MAXLINE     8192    /* maximum input line size */
#define N           80      /* maximum length of a line */
#define IN          1
#define OUT         0
#define NOHYPEN     0
#define HYPEN       1
#define NONEWLINE   0
#define NEWLINE     1

int getline(char line[], int maxline);    
void fold(char s[], int size);
void print(char s[], int begin, int end, int hyphen, int newline);
int remainder(int a, int b);
void copy(char to[], char from[], int begin, int end);

/* Test Inputs

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaB
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaBc
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaBaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaCaaa

a b
a b c d e
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaB
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaBc

*/

int main()
{
    int len; 
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        fold(line, len);

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

void fold(char s[], int size)
{
    int i, state, begin, end, min;
    char c;

    state = OUT;
    begin = end = 0;
    for (i = 0; i < size; ++i) {
        c = s[i];
        if (c == ' ' || c == '\t' || c == '\n') {
            if (c == '\n')
                end = i;
            state = OUT;
        } else {
            if (state == OUT)
                end = i;
            state = IN;
        }
        if (c == '\n' || (i == size - 1 && remainder(i, N) != 0)) {
            if (begin == end) { /* There is no white space before */
                if (c == '\n') {
                    end = begin + (i + 1);
                    print(s, begin, end, NOHYPEN, NONEWLINE);
                } else { /* i == size - 1, and in the case of no newline */
                    end = size;
                    print(s, begin, end, NOHYPEN, NEWLINE);
                }
                begin = end;
            } else {
                if (c == '\n' && i == size - 1) {
                    ++end;
                    print(s, begin, end, NOHYPEN, NONEWLINE);
                }
                else if (c != '\n' && i == size - 1) { /* In a case of no newline */
                    end = size;
                    print(s, begin, end, NOHYPEN, NEWLINE);
                } else
                    print(s, begin, end, NOHYPEN, NONEWLINE);
                begin = end;
            }
        } else if (i > 0 && remainder(i, N) == 0) {
            if (begin == end) { /* There is no white space before */
                min = N;
                if (min > i + 1 - begin) {
                    min = i + 1 - begin;
                }
                end = begin + min;
                print(s, begin, end, HYPEN, NEWLINE);
                begin = end;
            } else {
                if (i == size - 1)
                    ++end;
                print(s, begin, end, NOHYPEN, NEWLINE);
                begin = end;
            }
        }
    }
    if (state == IN && end == size - 1)
        printf("%c\n", c);
}

void print(char s[], int begin, int end, int hyphen, int newline)
{
    char p[N + 1];
    if (end <= begin)
        return;
    copy(p, s, begin, end);
    p[end - begin] = '\0';
    printf("%s", p);
    if (hyphen == 1)
        printf("-");
    if (newline == 1) {
        printf("\n");
    }
}

int remainder(int a, int b)
{
    return a - (a / b) * b; /* We don't know % operator currently. */
}

void copy(char to[], char from[], int begin, int end)
{
    int i;

    for (i = begin; i < end; ++i)
        to[i - begin] = from[i];
}
