#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    char line[100];

    FILE *input;
    FILE *output;
    int char_count = 0;

    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Invalid input!\n");
        return 1;
    }

    fseek(input, 0, SEEK_END);
    if (ftell(input) == 0) {
        printf("input.txt is empty\n");
        return 1;
    }

    fseek(input, 0, SEEK_SET);


    output = fopen(argv[2], "w");

    while (fgets(line, sizeof(line), input)) {
        for (int i = 0; i < sizeof(line); i++) {
            if (char_count == 10) {
                char_count = 0;
                fputs("\n", output);
            }
            if (line[i] == '\0') {
                break;
            }
            if (line[i] == 'I') {
                fprintf(output, "Aei");

            } else if (line[i] == 's' && line[i + 1] == 't' && line[i + 2] == 'u' && line[i + 3] == 'd' &&
                       line[i + 4] == 'e' && line[i + 5] == 'n' && line[i + 6] == 't') {
                fprintf(output, "worker");
                i += 6;

            } else if (line[i] == 'f' && line[i + 1] == 'r' && line[i + 2] == 'i' && line[i + 3] == 'e' &&
                       line[i + 4] == 'n' && line[i + 5] == 'd') {
                fprintf(output, "stranger");
                i += 5;

            } else if (line[i] == 'i' && line[i + 1] == 's') {
                fprintf(output, "iizz");
                i += 1;

            } else if (line[i] == 'i' && line[i + 1] == 'n' && line[i + 2] == 'g') {
                fprintf(output, "eeng");
                i += 2;

            } else if (line[i] == '.') {
                fprintf(output, "[.]");
                i += 2;

            } else if (line[i] == 'e' && line[i + 1] == 'r') {
                fprintf(output, "erre");
                i += 2;

            } else if (line[i] == 'p' && line[i + 1] == 'r' && line[i + 2] == 'o' && line[i + 3] == 'f' &&
                       line[i + 4] == 'e' && line[i + 5] == 's' && line[i + 6] == 's' && line[i + 7] == 'o' &&
                       line[i + 8] == 'r') {
                fprintf(output, "king");
                i+=8;
            } else if (line[i] == 's' && line[i + 1] == 'k' && line[i + 2] == 'y' && line[i + 3] == 't' &&
                       line[i + 4] == 'r' && line[i + 5] == 'a' && line[i + 6] == 'i' && line[i + 7] == 'n') {
                fprintf(output, "sloth");
                i += 7;
            } else if (line[i] == 'c' && line[i + 1] == 'l' && line[i + 2] == 'a' && line[i + 3] == 's' &&
                       line[i + 4] == 's') {
                fprintf(output, "ccamp");

            } else {
                fputc(line[i], output);
                char_count++;
            }

        }
    }
    fclose(input);
    fclose(output);

}
