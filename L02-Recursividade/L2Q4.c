/*
    Todo número natural estritamente positivo n ∈ N∗ possui um número reverso correspondente.
    Por exemplo, considere que n seja escrito da seguinte maneira:

        n = dkdk−1dk−2 ···d2d1d0

    onde k ∈ N∗ corresponde ao número de dígitos significativos que formam n, ou seja, dk ∈ {1,2,3,...,9} e
    di ∈ {0,1,2,...,9}, com 0 ≤ i < k. O número reverso de n é n  r = d`d`−1d`−2 ···dk−2dk−1dk, 
    sendo d` o primeiro dígito não nulo, tomados nesta ordem, dentre dkdk−1dk−2 ...d2d1d0 do número original n.
    Escreva uma função recursiva, em C, que seja capaz de determinar o número reverso de um certo número
    natural estritamente positivo n fornecido como entrada

    Entrada
    A única linha da entrada contém um único número natural estritamente positivo, n, 1 ≤ n ≤ 106.
    
    Saída
    Seu programa deve imprimir uma única linha com o valor de nr, o número reverso de n.

    Exemplos:

    --------------------------------
    |   Entrada     |   Saída      |
    |   411         |   114        |
    --------------------------------
    |   Entrada     |   Saída      |
    |   1230        |   321        |
    --------------------------------
    |   Entrada     |   Saída      |
    |   138000      |   831        |
    --------------------------------
*/

#include <stdio.h>
#include <math.h>

int inverteNum(int ,int );

int main() {
    int num = 0, aux = 0;
    int tam = 0;

    scanf("%d", &num);

    if (num < 1 || num > pow(10, 6)) {
        return 0;
    }

    aux = num;

    while (1)
    {
        aux /= 10;
        tam++;

        if (aux <= 0) {
            break;
        }
    }

    printf("%d", inverteNum(num, tam));

    return 0;
}

int inverteNum(int n, int tam) {
    static int i = 0;
    int aux = n;
    int soma = 0;

    if (tam <= 0) {
        return n;
    }
    else {
        aux /= pow(10, tam - 1);
        soma = aux * pow(10, i);
        n -= aux * pow(10, tam - 1);
        i++;
        
        return soma + inverteNum(n, tam - 1);
    }
        
}