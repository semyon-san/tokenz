#include <stdio.h>

#include "../tokenz.h"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <string> <token>\n", argv[0]);
        return 1;
    }

    char *string = argv[1];
    char *delim  = argv[2];

    const int SIZE = 8;
    char buffer[SIZE];

    struct token t;
    for (t = tokenz(string, delim); t.end != NULL; t = tokenz(t.end, delim)) {
        if (toknstr(buffer, &t, SIZE) >= SIZE)
            puts("The buffer was truncated!");
        printf("%s\n", buffer);
    }
}
