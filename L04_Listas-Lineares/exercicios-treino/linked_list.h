#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _sNode SNode;
typedef struct _linkedList LinkedList;

SNode* SNode_create(int val);
LinkedList* LinkedList_create();

bool LinkedList_is_empty(const LinkedList* L);
void LinkedList_destroy(LinkedList** L_ref);
void LinkedList_add_first(LinkedList* L, int val);
void LinkedList_add_last(LinkedList* L, int val);
void LinkedList_remove(LinkedList* L, int val);
void LinkedList_print(const LinkedList* L);
size_t LinkedList_size(const LinkedList* L);
// size_t é um apelido para 'unsigned long int'

int LinkedList_first_val(const LinkedList* L);
int LinkedList_last_val(const LinkedList* L);
int LinkedList_get_val(const LinkedList* L, int index);