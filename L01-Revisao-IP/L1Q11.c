#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int linhas, colunas;
    char operacao;
    int l = 0, c = 0, mult = 0;

    scanf("%d %d%*c", &linhas, &colunas);

    if (linhas < 1 || linhas > 10) {
        printf("ERROR");
        return 0;
    }
    else if (colunas < 1 || colunas > 10) {
        printf("ERROR");
        return 0;
    }

    int matrizA[linhas][colunas], matrizB[linhas][colunas], matrizRes[linhas][colunas];

    for (l = 0; l < linhas; l++) {
        for (c = 0; c < colunas; c++) {
            matrizRes[l][c] = 0;
        }
    }

    for (l = 0; l < linhas; l++) {
        for (c = 0; c < colunas; c++) {
            scanf("%d", &matrizA[l][c]);
            if (matrizA[l][c] < -50 || matrizA[l][c] > 50) {
                printf("ERROR");
                return 0;
            }
        }
    }

    scanf("%*c%c\n", &operacao);

    for (l = 0; l < linhas; l++) {
        for (c = 0; c < colunas; c++) {
            scanf("%d", &matrizB[l][c]);
            if (matrizB[l][c] < -50 || matrizB[l][c] > 50) {
                printf("ERROR");
                return 0;
            }
        }
    }

    if (operacao == '+') {
        for (l = 0; l < linhas; l++) {
            for (c = 0; c < colunas; c++) {
                matrizRes[l][c] = matrizA[l][c] + matrizB[l][c];
            }
        }
    }
    else if (operacao == 'x') {
        if (linhas == colunas) {
            for (l = 0; l < linhas; l++) {
                for (c = 0; c < colunas; c++) {
                    for (mult = 0; mult < linhas; mult++) {
                        matrizRes[l][c] += matrizA[l][mult] * matrizB[mult][c];
                    }
                }
            }
        }
        else {
            printf("ERROR");
            return 0;
        }
        
    }

   printf("\n");

    for (l = 0; l < linhas; l++) {
        for (c = 0; c < colunas; c++) {
            printf("%d ", matrizRes[l][c]);
        }
        printf("\n");
    }


    return 0;

}   