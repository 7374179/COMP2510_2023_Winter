#include <stdio.h>
#include <malloc.h>

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
typedef struct node{
    void* data;
    struct node * next;
} Node;
typedef struct {
    Node *head;
    Node *crnt;
} List;
int add_node(void *ll, void *data){
//    void *new_node = malloc(sizeof(istr));
//    memcpy((char *) new_node + sizeof(void *),data);
    Node *ptr = ll -> head;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next = ll->crnt = calloc(1, sizeof(Node));
    ll->data = data;
//    ll->next = next;
  return 1;
}

/**
   Remove an element at the end of the linked list
   The function takes the pointer to linked list and
   a pointer to return value (removed data)
**/
void remove_node(void *ll, void *ret){
  return;
}

/**
   This function creates a linked list. This function returns
   the linked list. Returns NULL if creation fails.
   You are required to make your own custom linked list struct
 **/
void *create_ll(size_t size){
    void *s = malloc(sizeof(void));
    s->data = 0;
    s->x = size;

  return NULL;
}

/**
   This function merge sorts the linked list.
 **/
void sort(void *ll){
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
