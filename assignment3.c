#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct bnode {
    int data;
    struct bnode *left;
    struct bnode *right;
} BinNode;

int Remove(BinNode **root, int data);
BinNode *Add(BinNode *p, int data);

static BinNode *AllocBinNode(void) {
    return calloc(1, sizeof(BinNode));
}

static void SetBinNode(BinNode *n, int data, BinNode *left, BinNode *right) {
    n->data = data;
    n->left = left;
    n->right = right;
}

int Remove(BinNode **root, int data) {
    BinNode *next, *temp;
    BinNode **left;
    BinNode **p = root;

    while (1) {
        if (*p == NULL) {
            printf("Error! %d is not here\n", data);
            return -1;
        } else if (data == (*p)->data) {
            break;
        } else if (data < (*p)->data) {
            p = &((*p)->left);
        } else if (data > (*p)->data) {
            p = &((*p)->right);
        } else{
            *p = Add(*p, (*p)->data);
        }
    }

    if ((*p)->left == NULL) {
        next = (*p)->right;
    } else {
        left = &((*p)->left);
        while ((*left)->right != NULL){
            left = &(*left)->right;
        }
        next = *left;
        *left = (*left)->left;
        next->left = (*p)->left;
        next->right = (*p)->right;
    }
    temp = *p;
    *p = next;
    free(temp);

    return 0;
}

BinNode *Add(BinNode *p, int data) {
    if (p == NULL) {
        p = AllocBinNode();
        SetBinNode(p, data, NULL, NULL);
    }
    else if (data == p->data) {
//        printf("Error! There is same data\n");
        Remove(&p, p->data);
    } else if (data < p->data) {
//        Add(p->left, data);
        p->left = Add(p->left, data);
    } else if (data > p->data){
//        Add(p->right, data);
        p->right = Add(p->right, data);
    }
    return p;
}

void PrintTree(FILE *fop, const BinNode *p) {
    if (p != NULL) {
        fprintf(fop, "%d\n", p->data);
        PrintTree(fop, p->left);
        PrintTree(fop, p->right);
    }
}

int isFileEmpty(FILE *f) {
    int c;
    while ((c = fgetc(f)) != EOF) {
        if (!isspace(c)) {
            if (c == '\n') {
                // Empty line found, return 0
                return 0;
            } else if (!isspace(c)) {
                // Non-whitespace character found, return 0
                ungetc(c, f);
                return 0;
            }
        }
        // End of file reached, return 1
        return 1;
    }
}

void freeTree(BinNode * root){
    if(root == NULL){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(int argc, char **argv) {
    FILE *fip1, *fip2, *fop;
    char* input = (char*)malloc(sizeof(char));
    int data;
    BinNode *root = NULL;

    fip1 = fopen(argv[1], "r");
    fip2 = fopen(argv[2], "r");
    fop = fopen(argv[3], "w");

    if (fip1 == NULL || fip2 == NULL || fop == NULL) {
        printf("Failed to open file\n");
    }
    if(isFileEmpty(fip1)|| isFileEmpty(fip2)){
        printf("COMP2510ERROR: input file is empty or contains only white space characters\n");
        return 1;
    }

    char* endptr;
    while (fscanf(fip1, "%s", input) != EOF) {
        long data = strtol(input, &endptr, 10);
        if (*endptr != '\0') {
            printf("COMP2510ERROR: input file contains non-numeric characters\n");
            return 1;
        }
        root = Add(root, data);
    }
    while (fscanf(fip2, "%s", input) != EOF) {
        long data = strtol(input, &endptr, 10);
        if (*endptr != '\0') {
            printf("COMP2510ERROR: input file contains non-numeric characters\n");
            return 1;
        }
        root = Add(root, data);
    }
    PrintTree(fop, root);

    fclose(fip1);
    fclose(fip2);
    fclose(fop);

    freeTree(root);
    free(input);

    return 0;
}
