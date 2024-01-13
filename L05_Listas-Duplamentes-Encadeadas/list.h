#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct _doubly_node DoublyNode, Node;
typedef struct _doubly_linked_list DoublyLinkedList, List;

List* List_create();
Node* Node_create(int val);

void List_destroy(List** L_ref);
bool List_is_empty(const List* L);
void List_add_first(List* L, int val);
void List_add_last(List* L, int val);

#endif
