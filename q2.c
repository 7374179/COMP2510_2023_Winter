#include <stdio.h>
#include <stdlib.h>

/**
   -implement the below function
   -you can use a helper function
   -you are NOT allowed to add any printf function anywhere
**/
void csort(char *arr, int n) {
    char tmp[n];
    for (int i = 0; i < n; i++) {
        tmp[i] = arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tmp[i] > tmp[j]) {
                char ch = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = ch;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] = tmp[i];
    }
}

// do NOT modify the below main function
int main(int argc, char** argv){
    csort(argv[1], atoi(argv[2]));
    printf("%s", argv[1]);
    return 0;
}