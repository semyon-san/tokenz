#include <stdio.h>

#include "../tokenz.h"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <string> <token>\n", argv[0]);
        return 1;
    }

    char *string = argv[1];
    char delim  = *argv[2];

    struct token t;
    for (t = tokenzc(string, delim); t.end != NULL; t = tokenzc(t.end, delim))
        tokprintln(&t);
}
