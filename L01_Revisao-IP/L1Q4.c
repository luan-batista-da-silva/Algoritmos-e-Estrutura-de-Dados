#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int qntNum = 0;
    int uni, dez, cent, mil;
    int aux, auxNum;
    int liberacaoNum = 0;
    char res[20];

    scanf("%d%*c", &qntNum);

    int  nums[qntNum];

    if (qntNum < 1) 
    {
        printf("[ERRO] Insira uma quantidade de numeros no minimo 1!");
    }
    else 
    {
        for (int i = 0; i < qntNum; i++) 
        {
            scanf("%d", &auxNum);
            if (auxNum >= 1000 && auxNum <= 9999) {
                nums[i] = auxNum;
            }
            else {
                liberacaoNum = 1;
                printf("[ERRO] Insira um numero de apenas 4 digitos!");
                break;
            }
        }

        if (liberacaoNum == 0){
            for (int i = 0; i < qntNum; i++) 
            {
                mil = nums[i] / 1000;
                aux = nums[i] - (mil * 1000);

                cent = aux / 100;
                aux = aux - (cent * 100);

                dez = aux / 10;
                aux = aux - (dez * 10);

                uni = aux;
                
                if (mil == uni && cent == dez) 
                {
                    strcpy(res, "Yes");
                }
                else 
                {
                    strcpy(res, "No");
                }

                printf("%s ", res);
            }
        }
    }

    
    return 0;
}