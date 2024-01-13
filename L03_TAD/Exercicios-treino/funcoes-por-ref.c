#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int soma;
    int sub;
} Soma_Sub;

void soma_sub(Soma_Sub* strct_somaSub, int x, int y );

int main() {

    Soma_Sub somaSub;
    Soma_Sub* pSomaSub;
    Soma_Sub** pPSomaSub;
    int x, y;

    pSomaSub = &somaSub;
    pPSomaSub = &pSomaSub;
    
    printf("Digite o primeiro numero: ");
    scanf("%d", &x);
    printf("Digite o segundo numero: ");
    scanf("%d", &y);

    soma_sub(pSomaSub, x, y);

    printf("Soma = %d\n", (*pPSomaSub)->soma);
    printf("Subtracao = %d", (*pSomaSub).sub);

    return 0; 
}

void soma_sub(Soma_Sub* strct_somaSub, int x, int y ) {
    strct_somaSub->soma = x + y;
    strct_somaSub->sub = x - y;
}
