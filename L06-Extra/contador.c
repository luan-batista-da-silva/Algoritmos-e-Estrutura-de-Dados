#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int countDig(char num[], char digProc, int index);



int main() {
    int strg[20];
    int casosTeste = 0;
    int i = 0;
    char digProc;
    char strgNum[15];
    // char* pStrg = &strgNum;

    scanf("%d", &casosTeste);

    if (casosTeste < 1 || casosTeste > 50) {
        return 0;
    }

    int* vetNums = (int*)calloc(casosTeste, sizeof(int));

    scanf("%*c%c", &digProc);

    for (i = 0; i < casosTeste; i++) {
        scanf("%d", &vetNums[i]); 
    }

    for (i = 0; i < casosTeste; i++) {
        itoa(vetNums[i], strgNum, 10);
        printf("%d ", countDig(strgNum, digProc, 0));
    }

    free(vetNums);

    return 0;
}

int countDig(char num[], char digProc, int index) {
    int countEquals = 0;

    if (num[index] == digProc) {
        countEquals++;
    }

    if (index <= strlen(num) - 1) {
        return countEquals + countDig(num, digProc, index + 1);
    }
    else {
        return countEquals;
    }
}