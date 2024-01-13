/*
    Questão 6 -

        Pode-se definir uma função ¨f (n), fatorial duplo de n, com n ∈ N, como sendo o produto de todos os
    números naturais ímpares de 1 até n, inclusive este, quando ele é ímpar. Assim, por exemplo, tem-se que:

    f (1) = 1
    f (2) = 1
    f (3) = 3
    f (5) = 15    

        Você deve escrever uma função recursiva, em C, que seja capaz de, recebendo n, imprimir o valor de
    f (n).

    Entrada:

        A única linha de entrada contém o valor de n, com 1 ≤ n ≤ 100.

    Saída:

        Imprima uma única linha de saída, com o valor de f (n).

    Exemplos:
    --------------------------------
    |   Entrada        |   Saída   |
    |   1              |   1       |
    --------------------------------
    |   Entrada        |   Saída   |
    |   7              |   105     |
    --------------------------------
    |   Entrada        |   Saída   |
    |   10             |   945     |
    --------------------------------

*/

#include <stdio.h>
#include <stdlib.h>

long double fatDuplo(int , int );

int main() {
    int n;
    long double result;

    scanf("%d", &n);

    if (n < 1 || n > 100) {
        return 0;
    }

    result = fatDuplo(n, 1);

    printf("%0.Lf", result);

}

long double fatDuplo(int n, int count) {

    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        if (count == n) {
            return count;
        }
        else if (count > n) {
            return 1;
        }
        else {
            return count * fatDuplo(n, count + 2);
        }
    }
}