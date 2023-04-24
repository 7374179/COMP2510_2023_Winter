#include <stdio.h>
#include <stdlib.h>
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

typedef struct node {
    void *data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    size_t data_size;
} List;

int compare(void* a, void* b, size_t size) {
    if (size == sizeof(int)) {
        int x = *(int*)a;
        int y = *(int*)b;
        return y - x;
    } else if (size == sizeof(short)) {
        short x = *(short*)a;
        short y = *(short*)b;
        return y - x;
    } else if (size == sizeof(char)) {
        char x = *(char*)a;
        char y = *(char*)b;
        return  y - x;
    } else if (size == sizeof(istr)) {
        istr* x = (istr*)a;
        istr* y = (istr*)b;
        int diff = y->x - x->x;
        return diff ? diff : y->y - x->y;
    } else if (size == sizeof(cstr)) {
        cstr* x = (cstr*)a;
        cstr* y = (cstr*)b;
        int diff = y->x - x->x;
        if (diff) return diff;
        diff = y->y - x->y;
        return diff ? diff : y->z - x->z;
    }
    return 0;
}

Node* merge(Node* a, Node* b, size_t size) {
    Node dummy;
    Node* tail = &dummy;
    while (a && b) {
        if (compare(a->data, b->data, size) <= 0) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

void merge_sort(Node** headRef, size_t size) {
    Node* head = *headRef;
    if (!head || !head->next) return;

    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* a = head;
    Node* b = slow->next;
    slow->next = NULL;

    merge_sort(&a, size);
    merge_sort(&b, size);

    *headRef = merge(a, b, size);
}

/**
   The function takes the pointer to linked list and
   a pointer to data.
   This function adds data at the end of your linked list
   However, the return value is 1 if successfully inserted
   0 otherwise
**/
int add_node(void *ll, void *data){
    List* list = (List*) ll;
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) return 0;

    new_node->data = malloc(list->data_size);
    if (!new_node->data) {
        free(new_node);
        return 0;
    }
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
void sort(void *ll){
    List *list = (List *)ll;
    if (!list || !list->head) return;
    merge_sort(&list->head, list->data_size);
    return;
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


    return 0;

}
