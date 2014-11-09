#include <stdio.h>

#include "../tokenz.h"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <string> <tokens>\n", argv[0]);
        return 1;
    }

    char *string = argv[1];
    char *delims = argv[2];

    struct token t;
    for (t = tokenz(string, delims); t.end != NULL; t = tokenz(t.end, delims))
        tokprintln(&t);
}
