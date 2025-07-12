#include <stdio.h>

#define MAXSIZE         8192
#define TABWIDTH        8


int getline(char line[], int maxsiz);
void entab(char line[], int size);

/* entab */
int main()
{
    int len;
    char line[MAXSIZE];

    while ((len = getline(line, MAXSIZE)) > 0) {
        entab(line, len);
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

void do_entab(int last_pos, int nblank, int tab) {
    int i, remainder, ntabstop, current_pos, nchar_to_tabstop;
    if (nblank == 0 && tab == 1) {
        putchar('\t');
        return;
    }

    current_pos = last_pos - nblank;
    remainder = current_pos - (current_pos / TABWIDTH) * TABWIDTH; /* We don't know % operator currently. */
    nchar_to_tabstop = TABWIDTH - remainder;
    if (remainder + nblank < TABWIDTH) {
        if (tab == 1)
            putchar('\t');
        else
            for (i = 0; i < nblank; ++i)
                putchar(' ');
    } else {
        /* Add one tab */
        putchar('\t');
        current_pos = current_pos + nchar_to_tabstop;
        nblank = nblank - nchar_to_tabstop;

        ntabstop = nblank / TABWIDTH;
        for (i = 0; i < ntabstop; ++i)
            putchar('\t');

        remainder = nblank - ntabstop * TABWIDTH; /* We don't know % operator currently. */
        if (tab == 1)
            putchar('\t');
        else
            for (i = 0; i < remainder; ++i)
                putchar(' ');

    }
}

#define IN      1       /* inside a blank*/
#define OUT     0       /* outside a blank*/

void entab(char line[], int size)
{
    int i, remainder, nspace, nblank, state;
    nspace = nblank = 0;
    state = OUT;
    for (i = 0; i < size; ++i) {
        if (line[i] == ' ') {
            state = IN;
            ++nblank;
            ++nspace;
            if (i == size - 1)
                do_entab(nspace, nblank, 0);
        } else if (line[i] == '\t') {
            remainder = nspace - (nspace / TABWIDTH) * TABWIDTH; /*We don't know % operator currently. */
            if (state == IN)
                do_entab(nspace, nblank, 1);
            else
                putchar('\t');
            nspace = nspace + nblank;
            nspace = nspace + (TABWIDTH - remainder);
            state = OUT;
            nblank = 0;
        } else {
            if (state == IN)
                do_entab(nspace, nblank, 0);
            putchar(line[i]);
            ++nspace;
            state = OUT;
            nblank = 0;
        }
    }
}
