/*
    Algorítimo:
        1 - Ler o número de pedras do caminho e o de sapos na mesma linha(1<=P<=50) (1<=S<=100)
        2 - Ler dois inteiros nas proximas linhas
        3 - Representando a posição inicial do sapo e a distância de pulo dele
        4 - Saída -> Indica a possibilidade de ter ou n um sapo nessa posição, 1 para aquelas que podem ter um sapo, e 0 para aquelas que não podem ter nenhum sapo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSAP 50
#define MAXPED 100

int main() {
    int qntPedras, qntSapos;
    int posSapos[MAXPED];
    int distSapo, posIniSapo;
    int i = 0, t = 0, f = 0;

    scanf("%d %d", &qntPedras, &qntSapos);
    
    if (qntPedras > MAXPED || qntPedras <= 0) {
        return 0;
    }
    else if (qntSapos > MAXSAP || qntSapos <= 0) {
        return 0;
    }

    for (i = 0; i < qntPedras; i++) {
        posSapos[i] = 0;
    }

    for (i = 0; i < qntSapos; i++) {
        scanf("%d %d", &posIniSapo, &distSapo);

        for (t = posIniSapo - 1; t >= 0; t -= distSapo) {
            posSapos[t] = 1;
        }

        for (f = posIniSapo - 1; f <= qntPedras; f += distSapo) {
            posSapos[f] = 1;
        }    
    }

    for (i = 0; i < qntPedras; i++) {
        printf("%d\n", posSapos[i]);
    }

    return 0;
}   