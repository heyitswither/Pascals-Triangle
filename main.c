#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int str_isdigit(char* str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void print_padding(int c, char* str)
{
    for (int i = 0; i <= c; i++) {
        printf("%s", str);
    }
}

void make_pascals(int rows)
{
    int (*tri)[rows-1][rows-1] = malloc(sizeof(*tri));
    for (int i = 0; i < rows; i++) {
        print_padding(rows-i, " ");
        for (int y = 0; y <= i; y++) {
            if ((y == 0) || (y == i)) {
                (*tri)[i][y] = 1;
                printf("%d ", 1);
            } else {
                (*tri)[i][y] = (*tri)[i-1][y] + (*tri)[i-1][y-1];
                printf("%d ", (*tri)[i-1][y] + (*tri)[i-1][y-1]);
            }
        }
        printf("\n");
    }
    free(tri);
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <rows>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (!str_isdigit(argv[1])) {
        fprintf(stderr, "rows must be an integer\n");
        return EXIT_FAILURE;
    }
    int rows;
    sscanf(argv[1], "%d", &rows);
    if (rows == 0)
        return EXIT_SUCCESS;
    make_pascals(rows);
    return EXIT_SUCCESS;
}

