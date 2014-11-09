#include <stdio.h>

#include "../tokenz.h"

#define SIZE 16
#define MSG "Hello "
#define MSG_LEN sizeof(MSG)

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <string> <token>\n", argv[0]);
        return 1;
    }

    char *string = argv[1];
    char *delims = argv[2];

    char buffer[SIZE];
    strcpy(buffer, "Hello ");

    struct token t;
    for (t = tokenz(string, delims); t.end != NULL; t = tokenz(t.end, delims)) {
        if (tokncat(buffer, &t, SIZE) >= SIZE)
            puts("The buffer was truncated!");
        printf("%s\n", buffer);
        buffer[6] = '\0'; // reset end of string to end of "Hello "
    }
}
