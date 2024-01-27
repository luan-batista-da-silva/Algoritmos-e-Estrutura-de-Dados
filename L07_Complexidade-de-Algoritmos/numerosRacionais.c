#include <stdio.h>
#include <stdlib.h>

int rationals_enumeration(int pos);
int mdc(int n, int d);


int main() {
    int pos = -1, i = 0, j = 0;
    int* vetPos = (int*)malloc(sizeof(int));

    while (pos != 0) {
        scanf("%d", &pos);

        vetPos = (int*)realloc(vetPos, (i + 1)*sizeof(int));
        vetPos[i] = pos;

        i++;
    }

    for (j = 0; j < i; j++) {
        rationals_enumeration(vetPos[j]);
    }

    return 0;
}

int rationals_enumeration(int pos) {
    int d = 1, n = 0;
    int countPos = 1;

    for (d = 1; d >= 1; d++) {
        for (n = 0; n <= d; n++) {
            if (mdc(n, d) == 1 && countPos == pos) {
                printf("%d/%d\n", n, d);
                return 0;
                
            }
            countPos++;
        }
    }

}

int mdc(int n, int d) {
    int i;
    int maior = 0;

    for (i = 1; i < d; i++) {
        if (n % i == 0 && d % i == 0) {
            maior = i;
        }
    }

    return maior;

}