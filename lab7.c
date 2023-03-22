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
void sort(void *ll){
    if(((List*)ll)->head == NULL || ((List*)ll)->head->next == NULL) {
        return;
    }}

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

//    List* ill = create_ll(sizeof(int));
//    int i = 0;
//    add_node(ill, &i);
//    i += 1;
//    add_node(ill, &i);
//    sort(ill);
//    int rv;
//    remove_node(ill, &rv);
//    printf("%d\n", rv);

    List* ill = create_ll(sizeof(int));
    char i = 'a';
    add_node(ill, &i);
    i += 1;
    add_node(ill, &i);
    i += 1;
    add_node(ill, &i);
    sort(ill);
    int rv;
    remove_node(ill, &rv);
    printf("%c\n", rv);


  
  return 0;
}
