#include <stdio.h>
#include <stdlib.h>



int buscaBinRec(int vet[], int limInf, int limSup, int elemBusc);
int compara(const void *x, const void *y);

int buscaBinRec(int vet[], int limInf, int limSup, int elemBusc) {
    if (limSup <= limInf) {
        int meio = (limInf + limSup) / 2;

        if (elemBusc == vet[meio]) {
            return meio;
        }
        else if (elemBusc < vet[meio]) {
            return buscaBinRec(vet, limInf, meio - 1, elemBusc);
        }
        else if (elemBusc > vet[meio]) {
            return buscaBinRec(vet, meio + 1, limSup, elemBusc);
        }
        else {
            return -1;
        }   
    }

}

int compara(const void *x, const void *y)
{
 if (*(int *)x > *(int *)y)
    return 1;
 else if (*(int *) x == *(int *) y )
    return 0;
 else if ( *(int *) x < *(int *) y )
    return -1;
}

// qsort(vetor, (size_t) tamanho, sizeof(int), compara);

int main() {
    int* vet = (int*)calloc(1, sizeof(int));
    int casosTeste = 0;
    int elemBusc = 0;
    int i = 0, j = 0;
    int tamVet;
    

    scanf("%d", &casosTeste);

    int vetRes[casosTeste];

    

    for (j = 0; j < casosTeste; j++) {
        scanf("%d", &elemBusc);

        while (vet[i] != -1) {
            if (i != 0) {
                vet = (int*)realloc(vet, (i + 1) * sizeof(int));
            }

            scanf("%d", &vet[i]);
            i++;
        }

        tamVet = sizeof(vet) / sizeof(vet[0]);
        qsort(vet, (size_t) tamVet, sizeof(int), compara);

        vetRes[j] = buscaBinRec(vet, 0, tamVet, elemBusc);
    }

    for (int k = 0; k < casosTeste; k++) {
        if (vetRes[k] == -1) {
            printf("ausente\n");
        }
        else {
            printf("%d", vetRes[k]);
        }
    }
        

    return 0;
}