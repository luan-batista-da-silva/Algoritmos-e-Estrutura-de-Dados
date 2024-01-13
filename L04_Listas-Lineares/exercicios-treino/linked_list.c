#include "linked_list.h"

struct _sNode
{
    int val;
    SNode* next;
};

struct _linkedList
{
    SNode* begin;
    SNode* end;
    size_t size;
};

SNode* SNode_create(int val) {
    SNode* snode = (SNode*)malloc(sizeof(SNode));
    snode->val = val;
    snode->next = (SNode*)NULL;

    return snode;
}

LinkedList* LinkedList_create() {
    LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
    L->begin = (SNode*)NULL;
    L->end = (SNode*)NULL;
    L->size = 0;

    return L;
}

bool LinkedList_is_empty(const LinkedList* L) {
    return (L->begin == NULL && L->end == NULL && L->size == 0);
}
// void LinkedList_add_first(LinkedList* L, int val) {
//     SNode* p = SNode_create(val);
//     p->next = L->begin;
//     L->begin = p;
// }

void LinkedList_destroy(LinkedList** L_ref) {
    puts("Chamando Destroy");
    LinkedList* L = *L_ref;

    SNode* p = L->begin;
    SNode* aux = (SNode*)NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }

    free(L);
    *L_ref = (LinkedList*)NULL;
}


void LinkedList_add_first(LinkedList* L, int val) {
    SNode* p = SNode_create(val);
    p->next = L->begin;
    
    if (LinkedList_is_empty(L)) {
        L->end = p;
    }
    
    L->begin = p;
    L->size++;
}

void LinkedList_add_last(LinkedList* L, int val) {
    SNode* q = SNode_create(val);
    if (LinkedList_is_empty(L)) {
        L->begin = q;
        L->end = q;
        L->size++;
    }
    else {
        SNode* p = L->end;

        p->next = q;
        L->end = q;
        L->size++;
/*
        // Navegando até o último Nó
        while (p->next != NULL) {
            p = p->next;
        }
        // Aqui o ponteiro p, aponta para o nó final da lista
        p->next = q;
        L->end = q;
*/
    }
}

void LinkedList_remove(LinkedList* L, int val) {
    if (!LinkedList_is_empty(L)) {
        SNode* prev = (SNode*)NULL;
        SNode* pos = L->begin;
        
        while (pos != NULL && pos->val != val) {
            prev = pos;
            pos = pos->next;
        }

        if (pos != NULL) {
            if (L->end == pos) {
                L->end = prev;
            }
            if (L->begin == pos) {
                L->begin = pos->next;
            }
            else {
                prev->next = pos->next;
            }
            free(pos);
            L->size--;
            puts("Elemento Removido com Sucesso!");
        }
        else {
            puts("[ERROR] Nao foi possivel remover o Elemento!");
        }
    }
    else {
        puts("[ERROR] A Lista eh vazia, portanto nao foi possivel remover o elemento!");
    }

/*
    if (!LinkedList_is_empty(L)) {
        // Caso 1 - Removendo no Início da lista
        if (L->begin->val == val) {
            SNode* pos = L->begin;

            if (L->begin == L->end) {
                L->end = (SNode*)NULL;
            }

            L->begin = L->begin->next;
            free(pos);
        }
        // Caso 2 - Removendo no meio da lista
        else {
            SNode* pos = L->begin->next;
            SNode* prev = L->begin;
            while (pos != NULL && pos->val != val) {
                prev = pos;
                pos = pos->next;
            }

            if (pos != NULL) {
                prev->next = pos->next;
                // Caso 3 - Removendo e corrigindo a remoção no final da lista
                if (pos->next == NULL) {
                    L->end = prev;
                }
                free(pos);
            } 
        }
    }
*/
}

void LinkedList_print(const LinkedList* L) {
    SNode* p = L->begin;

    printf("L -> ");
    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    puts("NULL");

    printf("L->begin = %d\n", L->begin->val);
    printf("L->end   = %d\n", L->end->val);
    printf("L->size  = %lu\n", L->size);

}

size_t LinkedList_size(const LinkedList* L) {
    return L->size;
}

int LinkedList_first_val(const LinkedList* L) {
    if (LinkedList_is_empty(L)) {
        puts("[ERROR] A lista esta vazia!");
        return -1;
    }

    return L->begin->val;
}

int LinkedList_last_val(const LinkedList* L) {
    return L->end->val;
}

int LinkedList_get_val(const LinkedList* L, int index) {
    SNode* p = L->begin;

    if (index < 0 || index >= L->size) {
        return -1;
    }
    else {
        for (int i = 0; i < L->size; i++) {
            if (i == index) {
                return p->val;
            }
            p = p->next;
        }
    }

    
}