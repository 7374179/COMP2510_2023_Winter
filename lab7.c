#include <stdio.h>
#include <malloc.h>
#include <string.h>

/**
   DO NOT CHANGE
   1st sample struct containing 2 integers
   When sorting use x first, then y.
**/
typedef struct{
  int x;
  int y;
}istr;

/**
   DO NOT CHANGE
   2nd sample struct containing 3 characters
   When sorting use x first, then y, and finally z. 
**/
typedef struct{
  char x;
  char y;
  char z;
}cstr;

/**
   The function takes the pointer to linked list and
   a pointer to data.
   This function adds data at the end of your linked list
   However, the return value is 1 if successfully inserted
   0 otherwise
**/
typedef struct node {
    void *data;
    struct node *next;
} Node;
typedef struct {
    Node *head;
    Node *crnt;
    size_t data_size;

} List;
int add_node(void *ll, void *data){
    List* list = (List*) ll;
    Node* new_node = malloc(sizeof(Node));
    new_node->data = malloc(list->data_size);
    memcpy(new_node->data, data, list->data_size);
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
    return 1;
}

/**
   Remove an element at the end of the linked list
   The function takes the pointer to linked list and
   a pointer to return value (removed data)
**/
void remove_node(void *ll, void *ret){
//    if (((ll*)ll)->head == NULL) {
//        return 0;
//    }
    Node *curr = ((List*)ll)->head;
    Node *prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    memcpy(ret, curr->data, ((List*)ll)->data_size);
    if (prev == NULL) {
        ((List*)ll)->head = NULL;
    } else {
        prev->next = NULL;
    }
    free(curr->data);
    free(curr);
    return;
}

/**
   This function creates a linked list. This function returns
   the linked list. Returns NULL if creation fails.
   You are required to make your own custom linked list struct
 **/
void *create_ll(size_t size){
    List *new_ll = malloc(sizeof(List));
    if (new_ll == NULL) {
        return NULL; // If memory allocation fails, return NULL
    }
    new_ll->head = NULL;
    new_ll->data_size = size;
    return (void*)new_ll;
//  return NULL;
}



/**
   This function merge sorts the linked list.
 **/
void merge(void* arr, int l, int m, int r, size_t elem_size, int (*comparator)(const void*, const void*)) {
    int i, j, k;
    void* temp = malloc(elem_size * (r - l + 1));
    i = l;
    j = m + 1;
    k = 0;

    while (i <= m && j <= r) {
        if (comparator((char*)arr + i * elem_size, (char*)arr + j * elem_size) <= 0) {
            memcpy((char*)temp + k * elem_size, (char*)arr + i * elem_size, elem_size);
            i++;
        }
        else {
            memcpy((char*)temp + k * elem_size, (char*)arr + j * elem_size, elem_size);
            j++;
        }
        k++;
    }

    while (i <= m) {
        memcpy((char*)temp + k * elem_size, (char*)arr + i * elem_size, elem_size);
        i++;
        k++;
    }

    while (j <= r) {
        memcpy((char*)temp + k * elem_size, (char*)arr + j * elem_size, elem_size);
        j++;
        k++;
    }

    for (i = l, k = 0; i <= r; i++, k++) {
        memcpy((char*)arr + i * elem_size, (char*)temp + k * elem_size, elem_size);
    }
    free(temp);
}

void merge_sort(void* arr, int l, int r, size_t elem_size, int (*comparator)(const void*, const void*)) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m, elem_size, comparator);
        merge_sort(arr, m + 1, r, elem_size, comparator);
        merge(arr, l, m, r, elem_size, comparator);
    }
}

int compare_integers(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    return (arg1 < arg2) ? -1 : (arg1 > arg2);
}

void sort(void* ll) {
    // Assuming that ll is a pointer to an array of integers
    int* arr = *(int**)ll;
    int n = *((int *)(((char *)ll) + sizeof(void *)));
    merge_sort(arr, 0, n - 1, sizeof(int), &compare_integers);
}
/**
   Do not modify the function signature of the main function
   including spacing.
 **/
int main(int argc, char** argv){ // Basically do NOT touch this line
  /**
     sample int ll code
     ll* ill = create_ll(sizeof(int));
     int i = 0;
     add(ill, &i);
     i += 1;
     add(ill, &i);
     sort(ill);
     int rv
     remove(ill, $&v);
     printf("%d", rv);
  **/

    List* ill = create_ll(sizeof(int));
    int iarr[] = {5, 1, 8, 3, 7};
    for (int i = 0; i < 5; i++) {
        add_node(ill, &iarr[i]);
    }
    sort(ill);
    int ival;
    while (ill->head) {
        remove_node(ill, &ival);
        printf("int: %d\n", ival);
    }
    free(ill);

    // Test with shorts
    List* sll = create_ll(sizeof(short));
    short sarr[] = {5, 1, 8, 3, 7};
    for (int i = 0; i < 5; i++) {
        add_node(sll, &sarr[i]);
    }
    sort(sll);
    short sval;
    while (sll->head) {
        remove_node(sll, &sval);
        printf("short: %d\n", sval);
    }
    free(sll);

    // Test with characters
    List* cll = create_ll(sizeof(char));
    char carr[] = {'c', 'a', 'e', 'b', 'd'};
    for (int i = 0; i < 5; i++) {
        add_node(cll, &carr[i]);
    }
    sort(cll);
    char cval;
    while (cll->head) {
        remove_node(cll, &cval);
        printf("char: %c\n", cval);
    }
    free(cll);

    // Test with istr structs
    List* istrl = create_ll(sizeof(istr));
    istr istrarr[] = {{3, 4}, {1, 5}, {3, 2}, {1, 4}, {2, 1}};
    for (int i = 0; i < 5; i++) {
        add_node(istrl, &istrarr[i]);
    }
    sort(istrl);
    istr istrval;
    while (istrl->head) {
        remove_node(istrl, &istrval);
        printf("istr: %d, %d\n", istrval.x, istrval.y);
    }
    free(istrl);

    // Test with cstr structs
    List* cstrl = create_ll(sizeof(cstr));
    cstr cstrarr[] = {{'a', 'b', 'c'}, {'a', 'a', 'a'}, {'b', 'a', 'c'}, {'a', 'b', 'a'}, {'a', 'c', 'c'}};
    for (int i = 0; i < 5; i++) {
        add_node(cstrl, &cstrarr[i]);
    }
    sort(cstrl);
    cstr cstrval;
    while (cstrl->head) {
        remove_node(cstrl, &cstrval);
        printf("cstr: %c, %c, %c\n", cstrval.x, cstrval.y, cstrval.z);
    }
    free(cstrl);



  
  return 0;
}
