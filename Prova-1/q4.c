#include <stdio.h>
#include <stdlib.h>


typedef struct numsTeste NumsTeste;
int calc_mdc(NumsTeste* nums, int index);

struct numsTeste {
    int num1;
    int num2;
    int num3;
};

int calc_mdc(NumsTeste* nums, int index) {
    int menor;
    int countDiv = 0;
    menor = nums[index].num1;

    if (menor > nums[index].num2) {
        menor = nums[index].num2;
    }
    if (menor > nums[index].num3) {
        menor = nums[index].num3;
    }

    for (int i = menor; i >= 1; i--) {
        if (nums[index].num1 % i == 0) {
            countDiv++;
        }
        if (nums[index].num2 % i == 0) {
            countDiv++;
        }
        if (nums[index].num3 % i == 0) {
            countDiv++;
        }

        if (countDiv == 3) {
            return i;
        }
        countDiv = 0;
    }
}

int main() {
    NumsTeste* nums = (NumsTeste*)NULL;
    int casosTest;
    int num1, num2, num3;
    int mdc;

    scanf("%d", &casosTest);

    nums = (NumsTeste*)calloc(casosTest, sizeof(NumsTeste));

    for (int i = 0; i < casosTest; i++) {
        scanf("%d %d %d", &num1, &num2, &num3);
        nums[i].num1 = num1;
        nums[i].num2 = num2;
        nums[i].num3 = num3;
    }

    for (int i = 0; i < casosTest; i++) {
        mdc = calc_mdc(nums, i);
        printf("%d\n", mdc);
    }

    free(nums);

    return 0;
}