/*
    Algoritimo:
        - Entrada:
            1 - Entrada das linhas e colunas com um espaço em branco entre os dois.
            2 - Ler as matrizes como foi feito no exercício anterior
            3 - Ler um caracter, T para 'Inversa'  I para 'Transposta' e D para 'Determinante'
            4 - 1 <= m,n <= 10 e -50 <= a, b <= 50
        - Saída:
             1 - Se I, imprimir a matriz inversa de A
             2 - Se T, imprimir a matriz transposta de A
             3 - Se D, imprimir o determinante da matriz

             pix - 62981154735 
*/ 

#include <stdio.h>
#include <stdlib.h>

int calculaDeterminante(int [][], int , int);

int main() {
    int linhas, colunas;
    char operacao;
    int diagPrin, diagSec;

    scanf("%d %d", &linhas, &colunas);

    if (linhas < 1 || linhas > 10) {
        printf("ERROR");
        return 0;
    }
    else if (colunas < 1 || colunas > 10) {
        printf("ERROR");
        return 0;
    }

    int matA[linhas][colunas], matRes[linhas][colunas];

    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            scanf("%d", &matA[l][c]);
            if (matA[l][c] < -50 || matA[l][c] > 50) {
                printf("ERROR");
                return 0;
            }
        }
    }

    scanf("%*c%c", &operacao);
    
    if (operacao == 'D') {
        if (linhas > 2 || colunas > 2) {
        }
    }
}

int calculaDeterminante(int matriz[][], int n, int n) {
    int det = 0;
    int coluna;

    if (n == 2) {
        return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    }

    for (coluna = 0; coluna < n; coluna++) {
        int cofator = 0, l = 0, c = 0;
        int sinal = (coluna % 2 == 0) ? 1 : -1;

        int matrizMenor[n - 1][n - 1];

        for (l = 0; l < n; l++) {
            int colunaMenor = 0;
            for (c = 0; c < n; c++) {
                matrizMenor[l - 1][colunaMenor] = matriz[l][c];
                colunaMenor++;
            }
        }

        cofator = sinal * matriz[0][coluna] * calculaDeterminante(matrizMenor);

        det += cofator;
    }  

    return det;
}
