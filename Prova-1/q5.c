#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SUCESSO 1
#define FALHA -1

typedef struct nodo Apontador;
int Lista_createVazia(Apontador** L);
int Lista_createNo(Apontador** L, unsigned int chave, float dado); 

struct nodo {
    unsigned int chave;
    float dado;
    Apontador* prox;
};


int Lista_createVazia(Apontador** L) {
    *L = NULL;

    return SUCESSO;
}

int Lista_createNo(Apontador** L, unsigned int chave, float dado) {
    Apontador* p = (Apontador*)malloc(sizeof(Apontador));
    if (p == NULL) {
        return FALHA;
    }

    p->chave = chave;
    p->dado = dado;
    p->prox = *L;
    *L =p;

    return SUCESSO;
}

int main() {
    Apontador* primLista = (Apontador*)NULL;
    int retorno;
    unsigned int chave;
    float dado;

    retorno = Lista_createVazia(&primLista);
    if (retorno == SUCESSO) {
        puts("Lista vazia criada com Sucesso!");
    }
    else {
        puts("A lista vazia nao foi criada!");
    }

    puts("Criar Lista com um nó preenchido: ");
    printf("Digite a chave do no: ");
    scanf("%u", &chave);

    printf("Digite o dado do no : ");
    scanf("%f", &dado);

    retorno = Lista_createNo(&primLista, chave, dado);

    if (retorno == SUCESSO) {
        puts("Lista com o primeiro no criada com Sucesso!");
    }
    else {
        puts("A lista com o primeiro no nao foi criada!");
    }

    Apontador* p = primLista;

    while (p != NULL) {
        printf("Chave: %u\n", p->chave);
        printf("Dado: %.1f", p->dado);
        p = p->prox;
    }


    return 0;
}