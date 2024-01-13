#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _doubly_node {
    int val;
    struct _doubly_node* prev;
    struct _doubly_node* next;
} DoublyNode, Node;

typedef struct _doubly_linked_list {
    Node* begin;
    Node* end;
    size_t size;
} DoublyLinkedList, List;

List* List_create() {
    List* L = (List*)calloc(1, sizeof(List));

    L->begin = (Node*)NULL;
    L->end = (Node*)NULL;
    L->size = 0;

    return L;
}

Node* Node_create(int val) {
    Node* node = (Node*)calloc(1, sizeof(Node));

    node->prev = (Node*)NULL;
    node->next = (Node*)NULL;
    node->val = val;

    return node;
}

void List_destroy(List** L_ref) {
    List* L = *L_ref;
    Node* aux = (Node*)NULL;

    for (Node* p = L->begin; p != NULL; p = p->prev) {
        aux = p;
        p = p->next;
        free(aux);
    }

    free(L);
    *L_ref = (List*)NULL;
}

bool List_is_empty(const List* L) {
    return (L->begin == NULL && L->end == NULL && L->size == 0);
}

void List_add_first(List* L, int val) {
    Node* p = Node_create(val);

    if (List_is_empty(L)) {
        L->end = p;
    }
    p->next = L->begin;
    L->begin->prev = p;
    L->begin = p;
    L->size++;
}


void List_add_last(List* L, int val) {
    Node* p = Node_create(val);

    L->end->next = p;
    p->prev = L->end;
    L->end;
    L->size++;
}