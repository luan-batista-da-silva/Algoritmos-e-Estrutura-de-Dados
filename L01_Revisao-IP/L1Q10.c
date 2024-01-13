#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265

int main() {
    
    int R, r, l1, l2, l3, B, H, b;
    float p;
    int qntFig;
    char tipoFig;
    int i = 0;
    

    scanf("%d%*c", &qntFig);
    if (qntFig < 1) {
        return 0;
    }
    
    float areas[qntFig];
    
    for (i = 0; i < qntFig; i++) {
        scanf(" %c", &tipoFig);

        if (tipoFig == 'C') {
            scanf("%d%*c", &R);
            areas[i] = PI*pow(R, 2);
        }
        else if (tipoFig == 'E') {
            scanf("%d %d%*c", &R, &r);
            areas[i] = PI*R*r;
        }
        else if (tipoFig == 'T') {
            scanf("%d %d %d%*c", &l1, &l2, &l3);
            p = (float)(l1 + l2 + l3) / 2;
            areas[i] = sqrt(p*(p - l1)*(p - l2)*(p - l3));
        }
        else if (tipoFig == 'Z') {
            scanf("%d %d %d%*c", &B, &b, &H);
            areas[i] = (B + b)*H / 2;
        }
    }

    for(i = 0; i < qntFig; i++) {
        printf("%.0f\n", areas[i]);
    }

    return 0;
}