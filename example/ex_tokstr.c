#include <stdio.h>

#include "../tokenz.h"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <string> <token>\n", argv[0]);
        return 1;
    }

    char *string = argv[1];
    char *delims = argv[2];

    const int SIZE = 8;
    char buffer[SIZE];

    struct token t;
    for (t = tokenz(string, delims); t.end != NULL; t = tokenz(t.end, delims)) {
        if (toklen(&t) < SIZE) {
            tokstr(buffer, &t);
            printf("%s\n", buffer);
        }
        else {
            puts("Token length is greater than buffer length: wouldn't advice copying to buffer!");
        }
    }
}
