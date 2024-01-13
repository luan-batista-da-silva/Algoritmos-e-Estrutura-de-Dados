#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, *p1, *p2;

    a = 4;
    b = 3;
    p1 = &a; // p1 = Endereço de a
    p2 = p1; // p2 = Endereço de a
    *p2 = *p1 + 3; // a = 7 -> *p1 = 7 -> *p2 = 7
    b = b * (*p1); // b = 21
    (*p1)++; // *p1 == 8
    p1 = &b;

    printf("%d %d\n", *p1, *p2); // Impressão: 21 8
    printf("%d %d\n", a, b); // Impressão: 8 21

    return 0;
}