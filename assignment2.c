#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct point {
    char Fname[10];
    char Lname[10];
    char MonthOfBirth[3];
    int YearOfBirth;
    int DayOfBirth;
    float Gpa;
    char DI;
    int Toefl;
} Point;

void swap(Point *a, Point *b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}


int *QuickSort(Point *arr, int start, int end) {
    if (start >= end) {
        return 0;
    }
    int key = start;
    int pl = start;
    int pr = end - 1;
    Point tmp;
    srand(time(NULL));
    int ranNum = rand() % (end - start+1);
    int pivot = arr[ranNum].YearOfBirth;
    while (pl <= pr) {
        while (arr[pl].YearOfBirth < pivot) {
            pl++;
        }
        while (arr[pr].YearOfBirth > pivot) {
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
            QuickSort(arr, start, pr);
            start = pl;
        } else {
            QuickSort(arr, pl, end);
            end = pr + 1;
        }
    }

}

//int main(int argc, char **argv){
int main() {
    FILE *fip, *fop;
//    fip = fopen(argv[1], "r");
//    fop = fopen(argv[2],"w");
    fip = fopen("input.txt", "r");
    fop = fopen("output.txt", "w");
    int count = 0;
    Point *points;
    int capacity = 2;
    int used = 0;
    int num_elements = 0;

    points = (Point *) malloc(sizeof(Point) * capacity);

    for (int i = 0; fscanf(fip, "%s %s %3s-%d-%d %f %c %d", &points[i].Fname, &points[i].Lname, &points[i].MonthOfBirth,
                           &points[i].DayOfBirth, &points[i].YearOfBirth, &points[i].Gpa, &points[i].DI,
                           &points[i].Toefl) != EOF; i++) {
        used++;
        num_elements++;

        if (used == capacity) {
            capacity = capacity * 2;
            points = (Point *) realloc(points, sizeof(Point) * capacity);
        }
        printf("%s", points[i].Fname);
    }

    Point *new_points = (Point *) malloc(sizeof(Point) * num_elements);
    for (int i = 0; i < num_elements; i++) {
        new_points[i] = points[i];
    }
    free(points);
    points = new_points;

    QuickSort(points, 0, num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("\n");
        printf("%s %s %3s-%d-%d %f %c %d", points[i].Fname, points[i].Lname, points[i].MonthOfBirth,
               points[i].DayOfBirth, points[i].YearOfBirth, points[i].Gpa, points[i].DI, points[i].Toefl);
    }


    return 0;
}


//void quick_sort(Person arr[], int n) {
//    quick_sort_helper(arr, 0, n - 1);
//}
//
//void quick_sort_helper(Person arr[], int low, int high) {
//    if (low < high) {
//        int pivot = partition(arr, low, high);
//        quick_sort_helper(arr, low, pivot - 1);
//        quick_sort_helper(arr, pivot + 1, high);
//    }
//}
//
//int partition(Person arr[], int low, int high) {
//    Person pivot = arr[high];
//    int i = low - 1;
//    for (int j = low; j <= high - 1; j++) {
//        // Compare by name first, then age
//        if (strcmp(arr[j].name, pivot.name) < 0 || (strcmp(arr[j].name, pivot.name) == 0 && arr[j].age < pivot.age)) {
//            i++;
//            swap(&arr[i], &arr[j]);
//        }
//    }
//    swap(&arr[i + 1], &arr[high]);
//    return i + 1;
//}
//
//void swap(Person* a, Person* b) {
//        Person temp = *a;
//        *a = *b;
//        *b = temp;
//}