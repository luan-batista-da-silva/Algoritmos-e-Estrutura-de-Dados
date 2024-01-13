#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int memMax;
    int num1, num2;
    char res[30];
    char oper;

    scanf("%d", &memMax);
    scanf("%d %c%*c %d", &num1, &oper, &num2);

    if (oper == '+') {
        if ((num1 + num2) <= memMax) {
            strcpy(res, "no overflow");
            printf("%s", res);
        } 
        else {
            strcpy(res, "overflow");
            printf("%s", res);
        }
    }
    else {
        if ((num1 * num2) <= memMax) {
            strcpy(res, "no overflow");
            printf("%s", res);
        }
        else {
            strcpy(res, "overflow");
            printf("%s", res);
        }
    }

    return 0;
}