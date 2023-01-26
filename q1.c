#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// returns 1 if canagram and 0 otherwise
int canagram(char *c1, char *c2, int n1, int n2) {
    int tmpC1 = 0;
    int tmpC2 = 0;
    int c2Le=strlen(c2);
    int count=0;


    while (c1[tmpC1] != NULL) {
        while (c2[tmpC2] != NULL) {
            if (c1[tmpC1] == 'a' || c1[tmpC1] == 'e' || c1[tmpC1] == 'i' || c1[tmpC1] == 'o' || c1[tmpC1] == 'u')
                tmpC1++;
                continue;
            if (c2[tmpC2] == 'a' || c2[tmpC2] == 'e' || c2[tmpC2] == 'i' || c2[tmpC2] == 'o' || c2[tmpC2] == 'u') {
                tmpC2++;
                continue;
            }

            if (c1[tmpC1] == c2[tmpC2]) {
                tmpC1++;
                tmpC2++;
                count++;

                if(c2Le==count){
                    return 1;
                }
            } else {
                tmpC1++;
            }
        }
    }
    return 0;
}

// do not touch below
int main(int argc, char **argv) {
    int res = canagram(argv[1], argv[2], strlen(argv[1]), strlen(argv[2]));

    if (res) printf("1");
    else printf("0");

    return 0;
}