#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x, y, xV, yV;
} Point;

int main(int argc, char *argv[]) {
    FILE *fip, *fop;

    fip = fopen(argv[1], "r");
    fop = fopen(argv[2], "w");
    int sec = atoi(argv[3]);

    //sets the array to draw the x, y coordinator.
    char coor[22][22] = {" "};

    int x, y, xV, yV;
    int count = 0;
    Point *points = NULL;

    int n = 21;

    points = (Point *) malloc(sizeof(Point));

    //bring the data from file.
    while (fscanf(fip, "%d,%d,%d,%d", &x, &y, &xV, &yV) != EOF) {
        if (count == 0) {
            points = (Point *) malloc(sizeof(Point));
        } else {
            points = (Point *) realloc(points, (count + 1) * sizeof(Point));
        }
        points[count].x = x + 1;
        points[count].y = y + 1;
        points[count].xV = xV;
        points[count].yV = yV;
        count++;
    }

    //draws '*' when x or y are on the board.
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || i == n || j == 0 || j == n) {
                coor[i][j] = '*';
            } else {
                coor[i][j] = ' ';
            }
        }
    }

    int tmpX[100], tmpY[100], tmpCount = 0, k = 0;

    // sets the changing location according to seconds.
    int i;
    for (int j = 0; j < sec; j++) {
        for (i = 0; i < count; i++) {
            points[i].x = points[i].x + points[i].xV;
            points[i].y = points[i].y + points[i].yV;

            if (points[i].x > 21 || points[i].x < 0) {
                points[i].xV = -points[i].xV;
            }
            if (points[i].y > 21 || points[i].y < 0) {
                points[i].yV = -points[i].yV;
            }
            points[i].x = (points[i].x / 21) % 2 == 0 ? abs(points[i].x % 21) : abs(21 - abs(points[i].x % 21));
            points[i].y = (points[i].y / 21) % 2 == 0 ? abs(points[i].y % 21) : abs(21 - abs(points[i].y % 21));
        }
        i = 0;

        // saves the values when two points are collided.
        int m = i + 1;
        while (m < count) {
            if (points[i].x == points[m].x && points[i].y == points[m].y) {
                tmpX[tmpCount] = points[i].x;
                tmpY[tmpCount] = points[i].y;
                m++;
                tmpCount++;
            } else {
                m++;
            }
        }
        int w = 0;
        // removes x, y values.
        for (int q = 0; q < tmpCount; q++) {
            while (w < count) {
                if (tmpX[q] == points[w].x && tmpY[q] == points[w].y) {
                    for (int p = w + 1; p <= count; p++) {
                            points[p - 1].x = points[p].x;
                            points[p - 1].y = points[p].y;
                            points[p - 1].xV = points[p].xV;
                            points[p - 1].yV = points[p].yV;
                        }
                    count--;
                    w=0;
                }else{
                    w++;
                }
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (points[k].x == i && points[k].y == j) {
                if ((points[k].x) % 21 == 0 || (points[k].y) % 21 == 0) {
                    coor[21 - j][i] = '*';
                    k++;
                } else {
                    coor[21 - j][i] = '+';
                    k++;
                    i = 0;
                    j = -1;
                    if (k == count) {
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            fprintf(fop, "%c", coor[i][j]);
        }
        fprintf(fop, "\n");
    }

    fclose(fip);
    fclose(fop);

    free(points);

    return 0;
}