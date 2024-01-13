/*
Questão 1 -

Por algum tempo houve polêmica quanto ao numeral 0 (zero) pertencer, ou não, aos números naturais,
já que, habitualmente, não se inicia uma contagem pelo valor “zero”. Entretanto ele representa um conceito
importante: a ausência de elementos num conjunto, seja ele abstrato ou concreto.
A Matemática contemporânea representa o conjunto destes números por meio do símbolo N, incluindo o 0
(zero). Para excluí-lo utiliza-se o asterisco como expoente: N∗, como feito no exemplo inicial desta questão.
A partir deste conceito inicial a respeito dos números naturais, deseja-se que você escreva um programa,
em C, para imprimir os n primeiros números naturais usando o conceito de recursividade, que os define da
seguinte maneira:


n0 = 0
ni+1 = ni +1,i ∈ {0,1,2,...}

Entrada
A única linha da entrada contém um único natural n, indicando que se deseja imprimir os n primeiros
números naturais, sendo que n ∈ N∗ e n ≤ 5000.

Saída
Seu programa deve imprimir uma única linha, contendo os n primeiros números naturais separados por
um único espaço em branco entre eles.

Exemplos:

Entrada     |    Saída
37          |    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
            |    26 27 28 29 30 31 32 33 34 35 36 37
___________________________________________________________________________________
Entrada     |   Saída
50          |   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
            |   26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47
            |   48 49 50
*/

#include <stdio.h>
#include <stdlib.h>

int imprimeNaturais(int);

int main() {
    int quantNums;

    scanf("%d", &quantNums);

    if (quantNums < 1 || quantNums > 5000) {
        return 0;
    }

    imprimeNaturais(quantNums);

    return 0;
}

int imprimeNaturais(int n) {
    static int i = 1;

    if (i == n) {
        printf("%d ", i);
        i++;
        return i;
    }
    else {
        printf("%d ", i);
        i++;
        return imprimeNaturais(n);
    }
    
}