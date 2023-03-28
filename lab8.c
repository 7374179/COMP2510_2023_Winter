#include <stdio.h>
#include <stdlib.h>

typedef struct bnode {
    int data;
    struct bnode *left;
    struct bnode *right;
} BinNode;

static BinNode *AllocBinNode(void) {
    return calloc(1, sizeof(BinNode));
}

static void SetBinNode(BinNode *n, int data, BinNode *left, BinNode *right) {
    n->data = data;
    n->left = left;
    n->right = right;
}

//int MemberNoCmp(const BinNode x, const BinNode y){
//    return x.data < y.data ? -1 : x.data > y.data ? 1: 0;
//}


BinNode *Add(BinNode *p, int data) {
//    int cond;
//    if (p == NULL) {
//        p = AllocBinNode();
//        SetBinNode(p, data, NULL, NULL);
//    } else if (cond < 0) {
//        p->left = Add(p->left, data);
//    } else {
//        p->right = Add(p->right, data);
//    }
//    return p;
    if (p == NULL) {
        p = AllocBinNode();
        SetBinNode(p, data, NULL, NULL);
    }else if(data == p->data){
        printf("Error! There is same data");
    } else if (data < p->data) {
        p->left = Add(p->left, data);
    } else {
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

int main(int argc, char** argv) {
    FILE *fip, *fop;
    int data;
    BinNode *root = NULL;

    fip=fopen(argv[1], "r");
    fop=fopen(argv[2],"w");

    if(fip==NULL || fop==NULL){
        printf("Failed to open file\n");
    }

    while(fscanf(fip,"%d", &data) !=EOF){
        root=Add(root, data);
    }
    PrintTree(fop, root);

    fclose(fip);
    fclose(fop);

    free(root);

    return 0;

}

