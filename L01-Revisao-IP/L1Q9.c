/*
    Algoritimo:
        1 - Ler a quantidade de casos testes
        2 - Ler os casos testes
        3 - Fazer a multiplicação desses casos
        4 - Adicionar esse número a um vetor
*/

#include <stdio.h>
#include <stdlib.h>
#define MaxDig 40

int main() {
    int casosTestes;
    unsigned long int num1, num2;
    char res[MaxDig];

    scanf("%d", &casosTestes);

    if (casosTestes < 1 || casosTestes > 50) {
        printf("[ERRO] Insira a quantidade de casos entre 1 e 50");
        return 0;
    }

    scanf("%ld %ld", &num1, &num2);

    printf("%ld", num1 * num2);


    return 0;
}