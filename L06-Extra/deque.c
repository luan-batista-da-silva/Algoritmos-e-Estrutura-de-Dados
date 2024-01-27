#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCESSO 1
#define FALHA -1

// =============== deque.h ======================

typedef struct Deque deque;
typedef struct Node node;

bool dequeIsEmpty(const deque* d);
int criarDeque(deque** d);
node* criarNode(int elem);
int destroyDeque(deque* d);
int pushEsquerda(deque* d, int elem);
int pushDireita(deque* d, int elem);
int listEsquerda(const deque* d);
int listDireita(const deque* d);
int popEsquerda(deque* d);
int popDireita(deque* d);

// =============== deque.c ======================

typedef struct Node
{
    int elem;
    node* next;
    node* prev; 
} node;


typedef struct Deque
{
    node* begin;
    node* end;
    size_t size;
} deque;


bool dequeIsEmpty(const deque* d) {
    return (d->begin == NULL && d->end == NULL && d->size == 0);
}

int criarDeque(deque** d) {
    (*d) = (deque*)calloc(1, sizeof(deque));

    (*d)->begin = (node*)NULL;
    (*d)->end = (node*)NULL;
    (*d)->size = 0;

    if (dequeIsEmpty((*d))) {
        return SUCESSO;
    }
    else {
        puts("falha");
        return FALHA;
    }
}


node* criarNode(int elem) {
    node* p = (node*)calloc(1, sizeof(node));

    p->elem = elem;
    p->prev = (node*)NULL;
    p->next - (node*)NULL;

    return p;
}

int destroyDeque(deque* d) {
    if (dequeIsEmpty(d)) {
        free(d);
        d = (deque*)NULL;
        return SUCESSO;
    }
    else {
        node* p = d->begin;
        node* aux = (node*)NULL;
        while (p != NULL) {
            aux = p;
            p = p->next;
            free(aux);
        }
        free(d);
        d = (deque*)NULL;

        return SUCESSO;
    }

    puts("falha");
    return FALHA;
}

int pushEsquerda(deque* d, int elem) {
    node* p = criarNode(elem);

    p->next = d->begin;

    if (dequeIsEmpty(d)) {
        d->end = p;
    } 
    else {
        d->begin->prev = p;
    }

    d->begin = p;
    d->size++;

    return SUCESSO;
}

int pushDireita(deque* d, int elem) {
    node* p = criarNode(elem);

    if (dequeIsEmpty(d)) {
        d->begin = p;
    }
    else {
        d->end->next = p;
    }

    p->prev = d->end;
    d->end = p;
    d->size++;

    return SUCESSO;
}

int listEsquerda(const deque* d) {
    node* p = d->begin;

    if(dequeIsEmpty(d)) {
        puts("vazio");
        return SUCESSO;
    }
    else {
        while (p != NULL)
        {
            printf("%d ", p->elem);
            p = p->next;
        }
        puts("");
        return SUCESSO;
    }

    puts("falha");
    return FALHA;    
}

int listDireita(const deque* d) {
    node* p = d->end;

    if(dequeIsEmpty(d)) {
        puts("vazio");
        return SUCESSO;
    }
    else {
        while (p != NULL)
        {
            printf("%d ", p->elem);
            p = p->prev;
        }
        puts("");
        return SUCESSO;
    }

    puts("falha");
    return FALHA;    
}

int popEsquerda(deque* d) {
    node* p = d->begin;
    node* aux = (node*)NULL;
    int elem;

    if (dequeIsEmpty(d)) {
        puts("falha");
        return FALHA;
    }
    else {
        aux = p;
        p = p->next;
        d->begin = p;
        p->prev = aux->prev;
        
        elem = aux->elem;

        free(aux);
        d->size--;
        
        return elem;
    }
}

int popDireita(deque* d) {
    node* p = d->end;
    node* aux = (node*)NULL;
    int elem;

    if (dequeIsEmpty(d)) {
        puts("falha");
        return FALHA;
    }
    else {
        aux = p;
        p = p->prev;
        d->end = p;
        d->end->next = aux->next;
        elem = aux->elem;

        free(aux);
        d->size--;
        
        return elem;
    }
}

// =================== main.c =========================

int main () {
    deque* d;

    criarDeque(&d);
    pushEsquerda(d, 3);
    pushEsquerda(d, 7);
    pushDireita(d, 8);
    pushEsquerda(d, 5);
    listEsquerda(d);
    popEsquerda(d);
    listEsquerda(d);
    popEsquerda(d);
    listDireita(d);
    
    return 0;
}