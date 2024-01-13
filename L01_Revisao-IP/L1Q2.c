#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char num1[4], num2[4];
    char newNum1[4], newNum2[4];
    int countPos = 0;
    int maior;
    int i = 0;

    scanf("%s %s", num1, num2);

    if (strlen(num1) == 3 && strlen(num2) == 3) {
        for (i = 2; i >= 0; i--) {
        newNum1[countPos] = num1[i];
        newNum2[countPos] = num2[i];
        countPos++;
        }
        newNum1[3] = '\0';
        newNum2[3] = '\0';
        
        if (atoi(newNum1) < atoi(newNum2)) {
            maior = atoi(newNum2);
        } else {
            maior = atoi(newNum1);
        }
        
        printf("%d", maior);
    } 
    else {
        printf("[ERRO] Insira numeros de apenas de 3 digitos!");
    }

    
    return 0;


}