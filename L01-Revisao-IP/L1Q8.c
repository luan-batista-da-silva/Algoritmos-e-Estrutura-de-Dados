#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int qntNums;
    int ehPrimo = 0;
    int i = 0, d = 0;

    scanf("%d", &qntNums);

    if (qntNums < 1 || qntNums > 100) {
        return 0;
    }

    unsigned long int nums[qntNums];

    for (i = 0; i < qntNums; i++) {
        scanf("%lu", &nums[i]);
        if (nums[i] < 2 || nums[i] > pow(2, 64) - 1) {
            return 0;
        }
    }

    for (i = 0; i < qntNums; i++) {
        for (d = 2; d <= nums[i]; d++) {
            if (nums[i] != 2 && nums[i] % 2 == 0) {
                ehPrimo += 2;
                break;
            }
            if (nums[i] % d == 0) {
                ehPrimo++;
            }
            else {
                continue;
            }
        }
        
        if(ehPrimo > 1) {
            printf("composto\n");
        }
        else if (ehPrimo == 1){
            printf("primo\n");
        }

        ehPrimo = 0;
    }

    return 0;
}