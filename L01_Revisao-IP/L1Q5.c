#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

int main() {
    int qntNums;
    int countResto = 0, auxResto, auxNum;
    int restos[MAX];
    int i = 0, j = 0;

    scanf("%d", &qntNums);

    if (qntNums < 1 || qntNums > 100) {
        return 0;
    }

    int nums[qntNums];

    if (qntNums >= 1 && qntNums <= 100) {
        for (i = 0; i < qntNums; i++) {
        scanf("%d", &nums[i]);
        }

        for (i = 0; i < qntNums; i++) {
            auxNum = nums[i];

            if (auxNum >= 4) {
                while (auxNum >= 4)
                {
                    auxResto = auxNum % 4;
                    restos[countResto] = auxResto; 
                    auxNum /= 4;
                    countResto++;
                }

                restos[countResto] = auxNum;
                countResto++;

                for (j = countResto - 1; j >= 0; j--) {
                    if (restos[j] == 0) {
                        printf("%c", 'A');
                    } 
                    else if (restos[j] == 1) {
                        printf("%c", 'C');
                    }
                    else if (restos[j] == 2) {
                        printf("%c", 'G');
                    }
                    else if (restos[j] == 3) {
                        printf("%c", 'T');
                    } 
                }
                printf("\n");
                
                countResto = 0;
            }
        else {
            restos[countResto] = auxNum;

            for (j = countResto; j >= 0; j--) {
                if (restos[j] == 0) {
                    printf("%c", 'A');
                } 
                else if (restos[j] == 1) {
                    printf("%c", 'C');
                }
                else if (restos[j] == 2) {
                    printf("%c", 'G');
                }
                else if (restos[j] == 3) {
                    printf("%c", 'T');
                } 
            }
            printf("\n");

            countResto = 0;
        }
    }
    }
    else {
        printf("[ERRO] Insira numeros entre 1 e 100!");
        return 1;
    }

    

    

    
    
}