#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//#define Jan 1, Feb 2, Mar 3, Apr 4, May 5, Jun 6, Jul 7, Aug 8, Sep 9, Oct 10, Nov 11, Dec 12

typedef struct point {
    char Fname[20];
    char Lname[20];
    char MonthOfBirth[5];
    int YearOfBirth;
    int DayOfBirth;
    float Gpa;
    char DI[2];
    int Toefl;
} Point;

void swap(Point *a, Point *b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(Point *arr, int start, int end, int random) {
    if (start >= end) {
        return;
    }

    //1. YearOfBirth 비교
    int key = start;
    int pl = start;
    int pr = end - 1;
    Point tmp;
//    int ran = Random(start, end);
//    srand(time(NULL));  //random 숫자때문에 정렬이 자꾸 엇나가는듯
//    int ranNum = rand() % (end - start+1);

    int pivot = arr[random].YearOfBirth;
    char pivot1[5];
    strcpy(pivot1, arr[random].MonthOfBirth);
    int pivot2 = arr[random].DayOfBirth;
//    char pivot3 =  arr[random].Lname;
    char pivot3[5];   // Example size of character array
    strcpy(pivot3, arr[random].Lname);
    while (pl <= pr) {
        while (arr[pl].YearOfBirth < pivot) {
//        while (arr[pl].YearOfBirth < pivot || (arr[pl].YearOfBirth == pivot && arr[pl].DayOfBirth < pivot2)) {
            pl++;
        }
        while (arr[pr].YearOfBirth > pivot) {
//        while (arr[pr].YearOfBirth > pivot || (arr[pr].YearOfBirth == pivot && arr[pr].DayOfBirth > pivot2)) {
            pr--;
        }
        if (pl <= pr) {
            swap(&arr[pl], &arr[pr]);
            pl++;
            pr--;
        }
//    if (start < pr) QuickSort(arr, start, pr, random);
//    if (pl < end) QuickSort(arr, pl, end, random);

        if (pr - start < end - pl) {
            QuickSort(arr, start, pr, random);
            start = pl;
        } else {
            QuickSort(arr, pl, end, random);
            end = pr + 1;
        }
    }

//    // 2. MonthOfBirth 비교
//    pl = start;
//    pr = end - 1;
////    char arr[pl].MonthOfBirth[4] = "Jan";   // Example month string
//    int pivot1m;
//
//    if (strcmp(arr[pl].MonthOfBirth, "Jan") == 0) {
//        pivot1m = Jan;
//    }
//    else if (strcmp(arr[pl].MonthOfBirth, "Feb") == 0) {
//        pivot1m = Feb;
//    }
//    else if (strcmp(arr[pl].MonthOfBirth, "Mar") == 0) {
//        pivot1m = Mar;
//    }
//    else if (strcmp(arr[pl].MonthOfBirth, "Apr") == 0) {
//        pivot1m = Apr;
//    }
//    else if (strcmp(arr[pl].MonthOfBirth, "May") == 0) {
//        pivot1m = May;
//    }
//    else if (strcmp(arr[pl].MonthOfBirth, "Jun") == 0) {
//        pivot1m = Jun;
//    }
//    else if (strcmp(arr[pl].MonthOfBirth, "Jul") == 0) {
//        pivot1m = Jul;
//    }
//    else if (strcmp(arr[pl].MonthOfBirth, "Aug") == 0) {
//        pivot1m = Aug;
//    }
//    else if (strcmp(arr[pl].MonthOfBirth, "Sep") == 0) {
//        pivot1m = Sep;
//    }
//    else if (strcmp(arr[pl].MonthOfBirth, "Oct") == 0) {
//        pivot1m = Oct;
//    }
//    else if (strcmp(arr[pl].MonthOfBirth, "Nov") == 0) {
//        pivot1m = Nov;
//    }
//    else if (strcmp(arr[pl].MonthOfBirth, "Dec") == 0) {
//        pivot1m = Dec;
//    }
//    while (pl <= pr) {
//        while (pivot1m < pivot1) {
////        while (arr[pl].YearOfBirth < pivot || (arr[pl].YearOfBirth == pivot && arr[pl].DayOfBirth < pivot1)) {
//            pl++;
//        }
//        while (pivot1m > pivot1) {
////        while (arr[pr].YearOfBirth > pivot || (arr[pr].YearOfBirth == pivot && arr[pr].DayOfBirth > pivot1)) {
//            pr--;
//        }
//        if (pl <= pr) {
//            swap(&arr[pl], &arr[pr]);
//            pl++;
//            pr--;
//        }
////    if (start < pr) QuickSort(arr, start, pr);
////    if (pl < end) QuickSort(arr, pl, end);
//
//        if (pr - start < end - pl) {
//            QuickSort(arr, start, pr, random);
//            start = pl;
//        } else {
//            QuickSort(arr, pl, end, random);
//            end = pr + 1;
//        }
//    }

    //3. DayOfBirth 비교
    pl = start;
    pr = end - 1;
    while (pl <= pr) {
        while (arr[pl].DayOfBirth < pivot2) {
//        while (arr[pl].YearOfBirth < pivot || (arr[pl].YearOfBirth == pivot && arr[pl].DayOfBirth < pivot2)) {
            pl++;
        }
        while (arr[pr].DayOfBirth > pivot2) {
//        while (arr[pr].YearOfBirth > pivot || (arr[pr].YearOfBirth == pivot && arr[pr].DayOfBirth > pivot2)) {
            pr--;
        }
        if (pl <= pr) {
            swap(&arr[pl], &arr[pr]);
            pl++;
            pr--;
        }
//    if (start < pr) QuickSort(arr, start, pr);
//    if (pl < end) QuickSort(arr, pl, end);

        if (pr - start < end - pl) {
            QuickSort(arr, start, pr, random);
            start = pl;
        } else {
            QuickSort(arr, pl, end, random);
            end = pr + 1;
        }
    }

    //4. Last name 비교
//    pl = start;     //여기가 문제임. pl과 pr이 start와 end-1로 초기화가 되야되는데 안됨.
//    pr = end - 1;
    while (pl <= pr) {
        while (arr[pl].Lname < pivot3) {
//        while (arr[pl].YearOfBirth < pivot || (arr[pl].YearOfBirth == pivot && arr[pl].DayOfBirth < pivot3)) {
            pl++;
        }
        while (arr[pr].Lname > pivot3) {
//        while (arr[pr].YearOfBirth > pivot || (arr[pr].YearOfBirth == pivot && arr[pr].DayOfBirth > pivot3)) {
            pr--;
        }
        if (pl <= pr) {
            swap(&arr[pl], &arr[pr]);
            pl++;
            pr--;
        }
//    if (start < pr) QuickSort(arr, start, pr);
//    if (pl < end) QuickSort(arr, pl, end);

        if (pr - start < end - pl) {
            QuickSort(arr, start, pr, random);
            start = pl;
        } else {
            QuickSort(arr, pl, end, random);
            end = pr + 1;
        }
    }
}

int main(int argc, char **argv){
//int main() {
    FILE *fip, *fop;
    fip = fopen(argv[1], "r");
    fop = fopen(argv[2],"w");
//    fip = fopen("input.txt", "r");
//    fop = fopen("output.txt", "w");
    int count = 0;
    Point *points;
    int capacity = 2;
    int used = 0;
    int num_elements = 0;

    points = (Point *) malloc(sizeof(Point) * capacity);

    for (int i = 0; fscanf(fip, "%s %s %3s-%d-%d %f %s %d", points[i].Fname, points[i].Lname, points[i].MonthOfBirth,
                           &points[i].DayOfBirth, &points[i].YearOfBirth, &points[i].Gpa, points[i].DI,
                           &points[i].Toefl) != EOF; i++) {
        used++;
        num_elements++;

        if (used == capacity) {
            capacity = capacity * 2;
            points = (Point *) realloc(points, sizeof(Point) * capacity);
        }
//        printf("%s", points[i].Fname);
    }

    Point *new_points = (Point *) malloc(sizeof(Point) * num_elements);
    for (int i = 0; i < num_elements; i++) {
        new_points[i] = points[i];
    }
    free(points);
    points = new_points;

    int ranNum = rand() % (used);


    QuickSort(points, 0, num_elements, ranNum);
//    QuickSort_day(points, 0, num_elements, ranNum);


//    for (int i = 0; i < num_elements; i++) {
//        printf("\n");
//        printf("%s %s %3s-%d-%d %.1f %c %d", points[i].Fname, points[i].Lname, points[i].MonthOfBirth,
//               points[i].DayOfBirth, points[i].YearOfBirth, points[i].Gpa, points[i].DI, points[i].Toefl);
//    }
    for (int i = 0; i < num_elements; i++) {
//        printf("\n");
        fprintf(fop,"%s %s %3s-%d-%d %.1f %s %d", points[i].Fname, points[i].Lname, points[i].MonthOfBirth,
               points[i].DayOfBirth, points[i].YearOfBirth, points[i].Gpa, points[i].DI, points[i].Toefl);
        fprintf(fop,"\n");
    }

    fclose(fip);
    fclose(fop);
    free(new_points);

    return 0;
}
