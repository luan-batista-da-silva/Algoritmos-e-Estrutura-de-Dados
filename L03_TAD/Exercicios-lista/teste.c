#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SUCESSO 1
#define FALHA 0
#define CRESCENTE 1
#define DECRESCENTE 0

// Estrutura do Conjunto
typedef struct C {
    long int *elementos;
    int size;
} Conjunto;

// Protótipos das Funções
int criaConjunto(Conjunto** C);
int conjuntoVazio(Conjunto* C);
int destroiConjunto(Conjunto* C);
int insereElementoConjunto(long int x, Conjunto **C);
int insereElementosConjunto(int elementos[], int numElementos, Conjunto **C);
void mostraConjunto(Conjunto* C, int ordem);

int main() {
    Conjunto* varConj;
    int operacao = 1;
    int retorno;
    long int x;

    while (operacao != 0) {
        puts("+-------------------------------------------+");
        puts("| Escolha a operacao a ser feita:           |");
        puts("|                                           |");
        puts("| 0 - Finalizar o programa                  |");
        puts("| 1 - Criar conjunto vazio                  |");
        puts("| 2 - Destruir o conjunto                   |");
        puts("| 3 - Verificar se Conjunto e Vazio         |");
        puts("| 4 - Adicionar um Elemento ao Conjunto     |");
        puts("| 5 - Adicionar Vários Elementos ao Conjunto|");
        puts("+-------------------------------------------+");

        scanf("%d", &operacao);

        if (operacao == 1) {
            retorno = criaConjunto(&varConj);
            if (retorno == SUCESSO) {
                puts("Conjunto C criado com Sucesso!");
            } else {
                puts("[ERROR] Nao foi possível criar o conjunto!");
            }
        } else if (operacao == 2) {
            retorno = destroiConjunto(varConj);
            puts("Deu tudo certo!");
        } else if (operacao == 3) {
            retorno = conjuntoVazio(varConj);
            if (retorno == true) {
                puts("O Conjunto eh Vazio!");
            } else {
                puts("O Conjunto nao eh Vazio!");
            }
        } else if (operacao == 4) {
            printf("Digite o Elemento: ");
            scanf("%ld", &x);
            retorno = insereElementoConjunto(x, &varConj);

            if (retorno == SUCESSO) {
                puts("O elemento foi adicionado!");
            } else if (retorno == FALHA) {
                puts("O elemento não foi adicionado!");
            }
        } else if (operacao == 5) {
            int numElementos;
            printf("Digite o número de elementos a serem adicionados: ");
            scanf("%d", &numElementos);

            int novosElementos[numElementos];

            printf("Digite os elementos separados por espaço: ");
            for (int i = 0; i < numElementos; i++) {
                scanf("%ld", &novosElementos[i]);
            }

            retorno = insereElementosConjunto(novosElementos, numElementos, &varConj);

            if (retorno == SUCESSO) {
                puts("Os elementos foram adicionados com sucesso!");
            } else if (retorno == FALHA) {
                puts("Falha ao adicionar os elementos!");
            }
        }
    }

    printf("Aqui acabou tudo\n");

    return 0;
}

int criaConjunto(Conjunto** C) {
    *C = (Conjunto*)malloc(sizeof(Conjunto));
    if (*C != NULL) {
        (*C)->elementos = NULL;
        (*C)->size = 0;
        return SUCESSO;
    } else {
        return FALHA;
    }
}

int conjuntoVazio(Conjunto* C) {
    if (C == NULL || C->elementos == NULL || C->size == 0) {
        return true;
    } else {
        return false;
    }
}

int destroiConjunto(Conjunto* C) {
    if (C != NULL) {
        free(C->elementos);
        free(C);
        return SUCESSO;
    } else {
        return FALHA;
    }
}

int insereElementoConjunto(long int x, Conjunto **C) {
    int size = (*C)->size;

    *C = (Conjunto*)realloc(*C, (size + 1) * sizeof(Conjunto));

    if (*C != NULL) {
        (*C)->elementos[size] = x;
        (*C)->size++;
        return SUCESSO;
    } else {
        return FALHA;
    }
}

int insereElementosConjunto(int elementos[], int numElementos, Conjunto **C) {
    int i;

    for (i = 0; i < numElementos; i++) {
        int retorno = insereElementoConjunto(elementos[i], C);

        if (retorno == FALHA) {
            return FALHA;
        }
    }

    return SUCESSO;
}

void mostraConjunto(Conjunto* C, int ordem) {
    for (int i = 0; i < C->size; i++) {
        printf("Elemento %d = %ld\n", i, C->elementos[i]);
    }
}







