#include <stdio.h>

#define IN                      1
#define OUT                     0
#define MAX_WORD_LENGTH         32    
#define HORIZONTAL              1
#define VERTICAL                0

int main()
{
    int c, i, j, state, word_length;
    int hist[MAX_WORD_LENGTH];
    float hist2[MAX_WORD_LENGTH];
    int direction = VERTICAL;
    int limit = 30;
    float max;

    for (i = 0; i < MAX_WORD_LENGTH; ++i)
        hist[i] = 0;

    state = OUT;
    word_length = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN && word_length < MAX_WORD_LENGTH)
                ++hist[word_length];
            state = OUT;
        }
        else if (state == OUT) {
            word_length = 1;
            state = IN;
        }
        else if (state == IN)
            ++word_length;
    }

    max = 0;
    for (i = 1; i < MAX_WORD_LENGTH; ++i)
        if (max < hist[i])
            max = hist[i];

    for (i = 1; i < MAX_WORD_LENGTH; ++i) {
        hist2[i] = (hist[i] / max) * limit;
    }

    if (direction == HORIZONTAL) {
        printf("     ");
        for (i = 1; i <= limit; ++i)
            printf(" %2.0f", i * max / limit);
        printf("\n     ");
        for (i = 1; i <= limit; ++i)
            printf("---");
        printf("\n");
        for (i = 1; i < MAX_WORD_LENGTH; ++i) {
            printf("%2d | ", i);
            for (j = 0; j < hist2[i]; ++j)
                printf("---");
            putchar('\n');
        }
    } else {
        for (j = limit; j > 0; --j) {
            printf("%2.0f | ", j * max / limit);
            for (i = 1; i < MAX_WORD_LENGTH; ++i) {
                if (i >= 10)
                    printf(" ");
                if (j > hist2[i])
                    printf("  ");
                else
                    printf(" *");
            }
            putchar('\n');
        }
        for (i = 1; i < MAX_WORD_LENGTH * 3 - 5; ++i)
            printf("-");
        printf("\n     ");
        for (i = 1; i < MAX_WORD_LENGTH; ++i)
            printf(" %d", i);
        printf("\n");
    }
}
