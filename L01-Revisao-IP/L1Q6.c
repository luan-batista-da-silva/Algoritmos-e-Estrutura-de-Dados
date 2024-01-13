
#include <stdio.h>
#include <stdlib.h>

int main() {
    int qntRot, tiposBalas;
    int countEnv = 0;
    int i = 0;

    scanf("%d %d", &qntRot, &tiposBalas);

    if (qntRot < 1 && qntRot > 1000) {
        return 0;
    }
    else {
        if (tiposBalas < 1 && tiposBalas > 20) {
            return 0;
        }
    }

    int rotulos[qntRot];


    for (i = 0; i < qntRot; i++) {
        scanf("%d", &rotulos[i]);
    }

    for (i = 0; i < qntRot; i++) {
        if (rotulos[i] == tiposBalas) {
            countEnv++;
        }
    }
    printf("%d", countEnv);
        

    

    

}