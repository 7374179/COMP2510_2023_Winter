#include <stdio.h>
#include <stdlib.h>

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
        printf("Error! There is same data\n");
//        Remove(&p, p->data);
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
        PrintTree(fop, p->left);
        fprintf(fop, "%d\n", p->data);
        PrintTree(fop, p->right);
    }
}

int main(int argc, char **argv) {
    FILE *fip1, *fip2, *fop;
    int data;
    BinNode *root = NULL;

    fip1 = fopen(argv[1], "r");
    fip2 = fopen(argv[2], "r");
    fop = fopen(argv[3], "w");

    if (fip1 == NULL || fip2 == NULL || fop == NULL) {
        printf("Failed to open file\n");
    }

    while (fscanf(fip1, "%d", &data) != EOF) {
        root = Add(root, data);
    }
    while (fscanf(fip2, "%d", &data) != EOF) {
        root = Add(root, data);
    }
    PrintTree(fop, root);

    fclose(fip1);
    fclose(fip2);
    fclose(fop);

    free(root);

    return 0;
}

