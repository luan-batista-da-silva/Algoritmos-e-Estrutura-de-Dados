#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EULER 2.7182818285


typedef struct lista Lista;
typedef struct massa Massa;

struct massa
{
    float m0;
    float k;
    float t;
};

int main() {
    float m0;
    float k;
    float t;
    int mx;
    int c;

    scanf("%d", &c);
    if (c > 10 || c < 1) {
        return 0;
    }

    Massa* casos = (Massa*)calloc(c, sizeof(Massa));

    for (int i = 0; i < c; i++) {
        scanf("%f %f %f", &m0, &k, &t);
        casos[i].m0 = m0;
        casos[i].k = k;
        casos[i].t = t;
    }

    for (int i = 0; i < c; i++) {
        m0 = casos[i].m0;
        k = casos[i].k;
        t = casos[i].t;
        
        mx = m0 / pow(EULER, k * t);
        printf("%d\n", mx);
    }

    return 0;
}