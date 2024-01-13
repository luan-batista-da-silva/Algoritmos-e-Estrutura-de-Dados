/*
Questão 2 -

Vamos a um problema envolvendo-a:
Considere que seja dado um número n, n ∈ N∗. Usando o conceito de recursividade, elabore um programa em C para imprimir até o n-ésimo termo da “Série de Fibonacci”.
Observação: Note que a contagem dos termos foi iniciada com o termo 0 (zero): f0 = 0.

Entrada
A única linha da entrada contém um número natural n, indicando a ordem máxima dos termos desejados
da “Série de Fibonacci”. Sabe-se que 1 ≤ n ≤ 1000.

Saída
Seu programa deve imprimir uma única linha contendo até o n-ésimo termo da série, sempre separados
por um único espaço em branco.

Exemplos:

Entrada        |     Saída
0              |     0
_________________________________________________
Entrada        |     Saída
1              |     0 1
_________________________________________________
Entrada        |     Saída
8              |     0 1 1 2 3 5 8 13 21

*/

#include <stdio.h>
#include <stdlib.h>


int calcFibonacci(int );

int main() {
    int casaDesejada;
    int i = 0;

    scanf("%d", &casaDesejada);

    if(casaDesejada < 0 || casaDesejada > 1000) {
        return 0;
    }

    for (i = 0; i <= casaDesejada; i++) {
        printf("%d ", calcFibonacci(i));
    }
    
    return 0;
}

int calcFibonacci(int n) {

    if (n == 0) {
        return 0;
    }
    else if (n ==  1) {
        return 1;
    }
    else {
        return calcFibonacci(n - 2) + calcFibonacci(n - 1);
    }
 
    
}