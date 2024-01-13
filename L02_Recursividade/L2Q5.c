/*
    Questão 5 -

        Escreva um programa, em C, que receba um número natural n ∈ N, representado utilizando a notação
    decimal, e o converta para sua notação binária. O programa deve utilizar uma “função recursiva” para
    realizar a conversão.

    Entrada:

    A primeira linha conterá um número natural estritamente positivo k, 1 ≤ k ≤ 1000, que representa o
    número de casos de teste que virão em seguida.
    Cada uma das k linhas seguintes possuem, cada uma, um único número natural, 0 ≤ ni < 106, com 1 ≤ i ≤ k,
    representado utilizando a notação decimal, a ser convertido para sua correspondente representação binária

    Saída:

    Seu programa deve imprimir k linhas, cada uma com a correspondente representação binária de um
    número da entrada.

    Exemplos:

    ---------------------------------------------
    |    Entrada         Saída                  |
    |    5               1                      |
    |    1               10                     |
    |    2               11                     |
    |    3               100                    |
    |    4               101                    |
    |    5                                      |
    ---------------------------------------------
    |    Entrada         Saída                  |
    |    3               101000001              |
    |    321             1011110001             |   
    |    753             11111111               |
    |    255                                    |
    ---------------------------------------------
    |    Entrada         Saída                  |
    |    1               1011011001111100000    |
    |    373728                                 |
    ---------------------------------------------

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double calcBin(int, int);

int main() {
    int qntNums;
    long double result;
    int i = 0;

    scanf("%d", &qntNums);

    if (qntNums < 1 || qntNums > 1000) {
        return 0;
    }

    int nums[qntNums];

    for (i = 0; i < qntNums; i++) {
        scanf("%d", &nums[i]);

    }

    for (i = 0; i < qntNums; i++) {
        result = 0;
        result = calcBin(nums[i], 0);
        printf("%0.Lf\n", result);
    }

    return 0;
}

long double calcBin(int num,int count) {
    int resto = 0;
    long double res = 0;

    if (num < 2) {
        return num * pow(10, count);
    }
    else {
        resto = num % 2;
        num /= 2;
        res = resto * pow(10, count);
        return res + calcBin(num, count + 1);
    }

}