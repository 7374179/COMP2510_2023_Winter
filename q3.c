#include <stdio.h>
#include <stdlib.h>

int count(char *books, int n) {
    int max = 0;
    int tmp = 0;
    for (int i = 1; i < n; i++) {
        if (books[i - 1] > books[i]) {
            tmp = tmp + books[i-1];
        } else {
            if (tmp > max) {
                max = tmp;
            }
            tmp = 0;
            tmp=tmp+books[i-1];
        }
    }
    max=tmp;
    return max;
}

int main(int argc, char **argv) {

    count(argv[1], atoi(argv[2]));
    printf("%s", argv[1]);

    return 0;

}
