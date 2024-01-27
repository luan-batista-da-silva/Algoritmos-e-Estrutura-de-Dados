#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int cases = 0;
    int c, l, i;
    int countVowels = 0;

    scanf("%d", &cases);

    char matString[cases][10000];
    
    for (i = 0; i < cases; i++) {
        scanf("%*c%[^\n]", matString[i]);
    }


    for (l = 0; l < cases; l++) {
        for (c = 0; matString[l][c] != '\0'; c++) {
            if (matString[l][c] == 'A' || matString[l][c] == 'a') {
                countVowels++;
            }
            else if (matString[l][c] == 'E' || matString[l][c] == 'e') {
                countVowels++;
            }
            else if (matString[l][c] == 'I' || matString[l][c] == 'i') {
                countVowels++;
            }
            else if (matString[l][c] == 'O' || matString[l][c] == 'o') {
                countVowels++;
            }
            else if (matString[l][c] == 'U' || matString[l][c] == 'u') {
                countVowels++;
            }
            else {
                continue;
            }
        }
        printf("%d\n", countVowels);
        countVowels = 0;
    }
    

    return 0;
}