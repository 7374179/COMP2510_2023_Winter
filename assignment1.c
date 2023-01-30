#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    char line[11];

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
            fputc(line[i], output);
            char_count++;
        }
    }
    fclose(input);
    fclose(output);
}
