#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <add|sub|mul|div> <num1> <num2> [...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *op = argv[1];
    double result = atof(argv[2]);
    for (int i = 3; i < argc; i++) {
        double x = atof(argv[i]);
        if      (strcmp(op, "add") == 0) result += x;
        else if (strcmp(op, "sub") == 0) result -= x;
        else if (strcmp(op, "mul") == 0) result *= x;
        else if (strcmp(op, "div") == 0) result /= x;
        else {
            fprintf(stderr, "Operatore non supportato: %s\n", op);
            return EXIT_FAILURE;
        }
    }

    printf("Risultato: %.6g\n", result);
    return EXIT_SUCCESS;
}
