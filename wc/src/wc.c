#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [file2...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "rb");
        if (!f) {
            perror(argv[i]);
            continue;
        }

        size_t lines = 0, words = 0, bytes = 0;
        int in_word = 0, c;
        while ((c = fgetc(f)) != EOF) {
            bytes++;
            if (c == '\n') lines++;
            if (isspace(c)) in_word = 0;
            else if (!in_word) {
                in_word = 1;
                words++;
            }
        }
        fclose(f);
        printf("%7zu %7zu %7zu %s\n", lines, words, bytes, argv[i]);
    }
    return EXIT_SUCCESS;
}
