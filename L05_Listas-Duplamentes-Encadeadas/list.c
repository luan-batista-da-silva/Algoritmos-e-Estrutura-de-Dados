#include "list.h"


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
    printf("Chamando Destroy\n");
    List* L = *L_ref;
    Node* p = L->begin;
    Node* aux = (Node*)NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }

    // for (Node* p = L->begin; p != NULL; p = p->prev) {
    //     aux = p;
    //     p = p->next;
    //     free(aux);
    // }

    free(L);
    *L_ref = (List*)NULL;
}

bool List_is_empty(const List* L) {
    return (L->begin == NULL && L->end == NULL && L->size == 0);
}

void List_add_first(List* L, int val) {
    Node* p = Node_create(val);
    p->next = L->begin;

    if (List_is_empty(L)) {
        L->end = p;
    }
    else {
        L->begin->prev = p;
    }
    L->begin = p;
    L->size++;
}


void List_add_last(List* L, int val) {
    Node* p = Node_create(val);

    if (List_is_empty(L)) {
        L->begin = p;
    }
    else {
        L->end->next = p;
    }

        p->prev = L->end;
        L->end = p;
        L->size++;    
}

void List_print(const List* L) {
    Node* p = L->begin;

    printf("L -> begin -> ");
    while(p != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");

    if (L->end == NULL) {
        puts("L->end = NULL");
    } 
    else {
        printf("L->end = %d\n", L->end->val);
    }
    
    printf("Size = %lu\n", L->size);
}

void List_inverted_print(const List* L) {
    Node* p = L->end;

    printf("L -> end -> ");
    while(p != NULL) {
        printf("%d -> ", p->val);
        p = p->prev;
    }
    printf("NULL\n");

    if (L->begin == NULL) {
        puts("L->begin = NULL");
    }
    else {
        printf("L->begin = %d\n", L->begin->val);
    }
    
    printf("Size = %lu\n", L->size);
}