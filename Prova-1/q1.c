#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float calcula_polinomio(int base, int* coef, int n, int i);

float calcula_polinomio(int base, int* coef,  int n, int i) {
    float soma = 0;

    soma = coef[i] * pow(base, i);

    if (i > n) {
        return 0;
    }
    else {
        return soma + calcula_polinomio(base, coef, n, i + 1);
    }
}

int main() {
    int n, t;
    int i = 0;
    
    scanf("%d %d", &t, &n);

    int* coef = (int*)calloc(n + 1 ,sizeof(int));
    int* bases = (int*)calloc(t, sizeof(int));
    
    for (i = 0; i <= n; i++) {
        scanf("%d", &coef[i]);
    }

    for (i = 0; i < t; i++) {
        scanf("%d", &bases[i]);
    }

    for (i = 0; i < t; i++) {
        printf("%.1f\n", calcula_polinomio(bases[i], coef, n, 0));
    }
 
    return 0;
}