#include <stdio.h>

#define MAXSIZE         2048
#define IN              1
#define OUT             0

int getline(char s[], int lim);
int is_valid_escape_seq(char c);
int print_white_spaces(char s[], int size);

/* Check C source code */
/* TODO: You may show errors in the line */
/* TODO: You may check whether there is one character in a character constant. */
int main()
{
    int i, c, len, paranthesis_num, bracket_num, brace_num, double_quote_num, single_quote_num;
    int in_str, in_char, in_comment;
    char line[MAXSIZE];
    
    paranthesis_num = bracket_num = brace_num = double_quote_num = single_quote_num = 0;
    in_str = in_char = in_comment = OUT;
    while ((len = getline(line, MAXSIZE)) > 0) {
        for (i = 0; i < len; ++i) {
            c = line[i];
            if (in_str == IN || in_char == IN || in_comment == IN) {
                if (in_comment == OUT && c == '\\' && i + 1 < len) {
                    if (is_valid_escape_seq(line[i + 1]) == 1)
                        ++i;
                    else {
                        printf("%s", line);
                        print_white_spaces(line, i);
                        putchar('^');
                        putchar('\n');
                        printf("\\%c is not a valid escape sequence character\n\n", line[i + 1]);
                    }
                } else if (c == '"')
                    in_str = OUT;
                else if (c == '\'')
                    in_char = OUT;
                else if (c == '*' && i + 1 < len && line[i + 1] == '/')
                    in_comment = OUT;
            } else {
                if (c == '(')
                    ++paranthesis_num;
                else if (c == '[')
                    ++bracket_num;
                else if (c == '{')
                    ++brace_num;
                else if (c == ')')
                    --paranthesis_num;
                else if (c == ']')
                    --bracket_num;
                else if (c == '}')
                    --brace_num;
                else if (c == '"')
                    in_str = IN;
                else if (c == '\'')
                    in_char = IN;
                else if (c == '/' && i + 1 < len && line[i + 1] == '*') {
                    in_comment = IN;
                    ++i;
                }
            }
        }
        if (in_str == IN)
            ++double_quote_num;
        if (in_char == IN)
            ++single_quote_num;
        in_str = in_char = OUT;
    }

    if (paranthesis_num != 0)
        printf("Number of open paranthesis = %d\n", paranthesis_num);
    if (bracket_num != 0)
        printf("Number of open bracket = %d\n", bracket_num);
    if (brace_num != 0)
        printf("Number of open brace = %d\n", brace_num);
    if (double_quote_num != 0)
        printf("Number of open double quotes = %d\n", double_quote_num);
    if (single_quote_num != 0)
        printf("Number of open single quotes = %d\n", single_quote_num);
    if (in_comment == IN)
        printf("There is a open comment\n");

    return 0;
}

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

int is_valid_escape_seq(char c)
{
    int valid = 0;

    if (c == '\'' || c == '"' || c == '\?' || c == '\\' || c == '0' ||
        c == 'a'  || c == 'b' || c == 'n'  || c == 'r'  || c == 't')
        valid = 1;

    return valid;
}

int print_white_spaces(char s[], int size)
{
    int j;
    for (j = 0; j < size; ++j)
        if (s[j] == '\t')
            putchar('\t');
        else
            putchar(' ');
    return 0;
}

