#include <stdio.h>
/*
    Primeiro ano após o ano 00 que o cometa foi visto -> 10
    
    Algoritimo:
        1 -> Determinar o próximo ano de passagem do cometa
        2 -> "Ano Zero" = 10, entre 0 e 10^4 
        3 -> Não pode ser menor ou igual ao ano digitado, deve ser sempre o próximo a se passar
*/

int main() {
    int proxPass = 10;
    int anoAtual;

    scanf("%d", &anoAtual);

    if (anoAtual >= 0 && anoAtual <= 10000) {
        while (1) {
            if (proxPass <= anoAtual) {
                proxPass += 76;
                continue;
            } else {
                break;
            }
        }
    }
    else {
        printf("[ERRO] Insira um ano entre 0 e 10000!");
    }
    
    printf("%d", proxPass);
    
}