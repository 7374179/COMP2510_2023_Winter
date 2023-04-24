#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    int y;
    char xy;
    struct node *next;
} Node;

void draw(Node *h, FILE *fp2, int maxX, int maxY) {
    for (int j = maxY; j >= 0; j--) {
        for (int i = 0; i <= maxX; i++) {
            Node *curr = h;
            while (curr != NULL) {
                if (curr->y == j && curr->x == i) {
                    fprintf(fp2, "x");
                    break;
                }
                curr = curr->next;
            }
            if (curr == NULL) {
                fprintf(fp2, " ");
            }
        }
        fprintf(fp2, "\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *fp1;
    FILE *fp2;
    int maxX = 0;
    int maxY = 0;
    int x, y;
    int xx, yy;

    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }
    fp2 = fopen(argv[2], "w");

    Node *head = NULL;
    Node *tail = NULL;
    Node *curr = NULL;

    head = (Node *) malloc(sizeof(Node));

    if (head == NULL) {
        printf("Error: Unable to allocate memory for head node.\n");
        fclose(fp1);
        return 1;
    }

    fscanf(fp1, "%d,%d", &x, &y);
    xx = x;
    yy = y;
    head->x = xx;
    head->y = yy;
    tail = head;

    while (fscanf(fp1, "%d,%d", &x, &y) == 2) {
        while (xx != x || yy != y) {
            if (xx < x) {
                xx++;
            } else if(xx > x) {
                xx--;
            } else if(yy < y) {
                yy++;
            } else if(yy > y) {
                yy--;
            }
            curr = (Node *) malloc(sizeof(Node));
            curr->x = xx;
            curr->y = yy;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
        }
        xx = x;
        yy = y;
    }

    Node *ptr = head;

    while (ptr != NULL) {
        if (ptr->x > maxX) {
            maxX = ptr->x;
        }
        ptr = ptr->next;
    }

    ptr = head;
    while (ptr != NULL) {
        if (ptr->y > maxY) {
            maxY = ptr->y;
        }
        ptr = ptr->next;
    }

    draw(head, fp2, maxX, maxY);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
