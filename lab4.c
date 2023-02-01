#include <stdio.h>
#include <stdlib.h>

struct Coordinate {
    int x, y;
    struct Coordinate *next;
};

void addCoordinate(int x, int y, int x1, int y1, struct Coordinate** head, struct Coordinate** tail) {
    while (x != x1 || y != y1) {
        if (x1 > x) {
            x1--;
        } else if (x1 < x) {
            x1++;
        }
        if (y1 > y) {
            y1--;
        } else if (y1 < y) {
            y1++;
        }

        struct Coordinate *new_coord = (struct Coordinate *) malloc(sizeof(struct Coordinate));
        new_coord->x = x1;
        new_coord->y = y1;
        new_coord->next = NULL;

        if (*head == NULL) {
            *head = new_coord;
            *tail = new_coord;
        } else {
            (*tail)->next = new_coord;
            *tail = new_coord;
        }
    }
}

int main(int argc, char *argv[]) {
    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    struct Coordinate *head = NULL;
    struct Coordinate *tail = NULL;

    int x, y;
    int x1 , y1;

// Add the first coordinate (-1, -1)
    x = -1, y = -1;
    struct Coordinate *new_coord = (struct Coordinate *) malloc(sizeof(struct Coordinate));
    new_coord->x = x;
    new_coord->y = y;
    new_coord->next = NULL;
    head = new_coord;
    tail = new_coord;

    x1 = x;
    y1 = y;

// Add the second coordinate (-1, 20)
    x = -1, y = 20;
    addCoordinate(x, y, x1 ,y1, &head, &tail);
    x1 = x;
    y1 = y;

// Add the third coordinate (20, -1)
    x = 20, y = 20;
    addCoordinate(x, y, x1 ,y1, &head, &tail);
    x1 = x;
    y1 = y;

// Add the fourth coordinate (20, 20)
    x = 20, y = -1;
    addCoordinate(x, y, x1 ,y1, &head, &tail);
    x1 = x;
    y1 = y;

// go back to the original coordinate
    x = -1, y = -1;
    addCoordinate(x, y, x1 ,y1, &head, &tail);

    struct Coordinate *current = head;
    int min_x = current->x, max_x = current->x, min_y = current->y, max_y = current->y;
    while (current != NULL) {
        if (current->x < min_x) min_x = current->x;
        if (current->x > max_x) max_x = current->x;
        if (current->y < min_y) min_y = current->y;
        if (current->y > max_y) max_y = current->y;
        current = current->next;
    }

    for (int j = max_y; j >= min_y; j--) {
        for (int i = min_x; i <= max_x; i++) {
            int found = 0;
            current = head;
            while (current != NULL) {
                if (current->x == i && current->y == j) {
                    found = 1;
                    fprintf(output, "*");

                    break;
                }
                current = current->next;
            }
            if (!found) fprintf(output, " ");
        }
        fprintf(output, "\n");
    }

    fclose(output);
    return 0;
}
