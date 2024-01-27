#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _doubly_node DoublyNode, Node;
typedef struct _doubly_linked_list DoublyLinkedList, List;

List* List_create();
Node* Node_create(int val);

void List_destroy(List** L_ref);
bool List_is_empty(const List* L);
void List_add_first(List* L, int val);
void List_add_last(List* L, int val);
void List_print(const List* L);
void List_inverted_print(const List* L);
void List_remove_first(List* L);
void List_remove_last(List* L);
void List_remove_first_val(List* L, int val);
void List_remove_all_val(List* L, int val);

#endif
