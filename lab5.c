#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char studentID[100];
    char a[1];
    int ID;
} Student;

void *InsertionSort(Student arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        Student tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1].ID > tmp.ID ||
                    (arr[j - 1].ID == tmp.ID && strlen(arr[j - 1].studentID) > strlen(tmp.studentID)) ||
                    (arr[j - 1].ID == tmp.ID && strlen(arr[j - 1].studentID) == strlen(tmp.studentID) &&
                     arr[j - 1].a < tmp.a); j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

int main(int argc, char **argv) {
    FILE *fip, *fop;

    fip = fopen(argv[1], "r");
    fop = fopen(argv[2], "w");
    int num = 0;

    Student *student;
    student = (Student *) malloc(sizeof(Student) * 100);

    for (int i = 0; fscanf(fip, "%s", student[i].studentID) != EOF; i++) {
        num++;
    }

    int tmp = 0;

    for (int i = 0; i < num; i++) {
        if (student[i].studentID[0] == 'A') {
            student[i].a[0] = 'A';
        } else if (student[i].studentID[0] == 'a') {
            student[i].a[0] = 'a';
        } else if (student[i].studentID[0] == ' ') {
            student[i].a[0] = ' ';
        }
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < strlen(student[i].studentID); j++) {
            if (('a' <= student[i].studentID[j] && student[i].studentID[j] <= 'z') ||
                ('A' <= student[i].studentID[j] && student[i].studentID[j] <= 'Z') ||
                student[i].studentID[j] == '.') {
                continue;
            } else {
                tmp = tmp * 10 + student[i].studentID[j] - '0';
            }
        }
        student[i].ID = tmp;
        tmp = 0;
    }

    InsertionSort(student, num);

    for (int i = 0; i < num; i++) {
        fprintf(fop, "%s", student[i].studentID);
        if(i==num-1){
            break;
        }
        fprintf(fop, "\n");
    }

    fclose(fip);
    fclose(fop);
    free(student);

    return 0;
}