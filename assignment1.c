#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 25

void justify(char *str, char **argv) {
    FILE *output;
    output = fopen(argv[2],"w");
    int word_count = 0;
    int space_count = 0;
    int str_len = strlen(str);
    int last_space = 0;
    int start = 0;

    for (int i = 0; i < str_len; i++) {
        if (str[i] == ' ') {
            space_count++;
            last_space = i;
        } else {
            word_count++;
        }
    }

    for (int i = 0; i < str_len / MAX_LENGTH; i++) {
        int end = start + MAX_LENGTH;

        while (end < str_len && str[end] != ' ') {
            end--;
        }

        if (end == str_len) {
            end = last_space;
        }

        int line_word_count = 0;
        int line_len = 0;
        for (int j = start; j <= end; j++) {
            if (str[j] != ' ') {
                line_word_count++;
                line_len++;
            } else {
                line_len++;
            }
        }

        int spaces_needed = MAX_LENGTH - line_len;
        int spaces_per_word = spaces_needed / (line_word_count - 1);
        int extra_spaces = spaces_needed % (line_word_count -1);

        for (int j = start; j <= end; j++) {
            fprintf(output,"%c", str[j]);
            if (str[j] == ' ') {
                for (int k = 0; k < spaces_per_word; k++) {
                    fprintf(output,"%c",' ');
                }
                if (extra_spaces >= 0) {

                    fprintf(output,"%c",' ');
                    extra_spaces--;
                }
            }
        }

        fprintf(output,"\n");
        start = end + 1;
    }

    if (start < str_len) {
        int sc = 0;
        int wc = 0;
        int line_len = 0;
        int last_space = -1;

        for (int i = start; i < str_len; i++) {
            if (str[i] == ' ') {
                sc++;
                last_space = i;
            } else {
                wc++;
                line_len++;
            }
        }

        if (line_len > MAX_LENGTH) {
            int new_start = last_space + 1;
            line_len -= (last_space - start + 1);
            sc--;
            wc--;
            int space = MAX_LENGTH - line_len;
            for (int j = start; j <= last_space; j++) {

                fprintf(output,"%c", str[j]);
                if (str[j] == ' ') {
                    for (int k = 1; k < space / (wc - 1); k++) {
                        fprintf(output," ");
                    }
                    wc--;
                    space -= space / (wc - 1);
                }
            }
            fprintf(output,"\n");
            start = new_start;
        }

        int space = MAX_LENGTH - line_len;
        for (int j = start; j < str_len; j++) {
            fprintf(output,"%c", str[j]);
            if (str[j] == ' ') {
                if (sc != 1 && sc > 1) {
                    for (int k = 0; k < space / (wc - 1); k++) {
                        fprintf(output," ");
                    }
                    wc--;
                    space -= space / (wc - 1);
                } else if (sc == 1) {
                    for (int k = 1; k < space; k++) {
                        fprintf(output," ");
                    }
                }
            }
        }
        fprintf(output,"\n");
    }

    fclose(output);
}

int main(int argc, char **argv) {

    char line[100];
    FILE *input;
    char translated[100];

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

    int i = 0;
    int j = 0;

    while (fgets(line, strlen(line), input)) {
        for (i = 0; i < sizeof(line); i++) {
            if (line[i] == '\0') {
                break;
            }
            if (line[i] == 'I') {
                translated[j++] = 'A';
                translated[j++] = 'e';
                translated[j++] = 'i';

            } else if (line[i] == 's' && line[i + 1] == 't' && line[i + 2] == 'u' && line[i + 3] == 'd' &&
                       line[i + 4] == 'e' && line[i + 5] == 'n' && line[i + 6] == 't') {
                translated[j++] = 'w';
                translated[j++] = 'o';
                translated[j++] = 'r';
                translated[j++] = 'k';
                translated[j++] = 'e';
                translated[j++] = 'r';
                i += 6;

            } else if (line[i] == 'f' && line[i + 1] == 'r' && line[i + 2] == 'i' && line[i + 3] == 'e' &&
                       line[i + 4] == 'n' && line[i + 5] == 'd') {
                translated[j++] = 's';
                translated[j++] = 't';
                translated[j++] = 'r';
                translated[j++] = 'a';
                translated[j++] = 'n';
                translated[j++] = 'g';
                translated[j++] = 'e';
                translated[j++] = 'r';
                i += 5;

            } else if (line[i] == 'i' && line[i + 1] == 's') {
                translated[j++] = 'i';
                translated[j++] = 'i';
                translated[j++] = 'z';
                translated[j++] = 'z';
                i += 1;

            } else if (line[i] == 'i' && line[i + 1] == 'n' && line[i + 2] == 'g') {
                translated[j++] = 'e';
                translated[j++] = 'e';
                translated[j++] = 'n';
                translated[j++] = 'g';
                i += 2;

            } else if (line[i] == '.') {
                translated[j++] = '[';
                translated[j++] = '.';
                translated[j++] = ']';
                i += 0;

            } else if (line[i] == 'e' && line[i + 1] == 'r') {
                translated[j++] = 'e';
                translated[j++] = 'r';
                translated[j++] = 'r';
                translated[j++] = 'e';
                i += 1;

            } else if (line[i] == 'p' && line[i + 1] == 'r' && line[i + 2] == 'o' && line[i + 3] == 'f' &&
                       line[i + 4] == 'e' && line[i + 5] == 's' && line[i + 6] == 's' && line[i + 7] == 'o' &&
                       line[i + 8] == 'r') {
                translated[j++] = 'k';
                translated[j++] = 'i';
                translated[j++] = 'n';
                translated[j++] = 'g';
                i += 8;
            } else if (line[i] == 's' && line[i + 1] == 'k' && line[i + 2] == 'y' && line[i + 3] == 't' &&
                       line[i + 4] == 'r' && line[i + 5] == 'a' && line[i + 6] == 'i' && line[i + 7] == 'n') {
                translated[j++] = 's';
                translated[j++] = 'l';
                translated[j++] = 'o';
                translated[j++] = 't';
                translated[j++] = 'h';
                i += 7;
            } else if (line[i] == 'c' && line[i + 1] == 'l' && line[i + 2] == 'a' && line[i + 3] == 's' &&
                       line[i + 4] == 's') {
                translated[j++] = 'c';
                translated[j++] = 'c';
                translated[j++] = 'a';
                translated[j++] = 'm';
                translated[j++] = 'p';

                i += 5;

            } else if (line[i] == 't' && line[i + 1] == 'i' && line[i + 2] == 'o' && line[i + 3] == 'n') {
                translated[j++] = 'e';
                translated[j++] = 'r';
                translated[j++] = 't';
                translated[j++] = 'i';
                translated[j++] = 'o';
                translated[j++] = 'n';
                translated[j++] = 'e';
                translated[j++] = 'r';
                i += 4;
            }
            else{
                translated[j++] = line[i];
            }
        }
    }
    translated[j] = '\0';

    fclose(input);

    for(int i =0; i<strlen(translated); i++){
//        printf("%c", (char) translated[i]);
    }
//    printf("\n");

    justify(translated, argv);

}
