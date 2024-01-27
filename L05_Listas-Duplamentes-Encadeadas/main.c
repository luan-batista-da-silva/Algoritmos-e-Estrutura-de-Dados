#include "list.h"

int main() {
    List* L = (List*)NULL;
    int option = -1;
    bool retornoBool = NULL;
    int val;

    while (option != 0)
    {
        puts("+-------------------------------------------------+");
        puts("| 0 - Finalizar Programa                          |");
        puts("| 1 - Criar uma Nova Lista Vazia                  |");
        puts("| 2 - Verificar se a Lista eh Vazia               |");
        puts("| 3 - Destruir a Lista                            |");
        puts("| 4 - Adicionar Elemento no Inicio da Lista       |");
        puts("| 5 - Adicionar Elemento no Final da Lista        |");
        puts("| 6 - Remover Elemento do Inicio da Lista         |");
        puts("| 7 - Remover Elemento do Final da Lista          |");
        puts("| 8 - Remover Primeiro Valor Especifico da Lista  |");
        puts("| 9 - Remover Todos Valores Especifico da Lista   |");
        puts("| 10 - Mostrar a Lista                            |");
        puts("| 11 - Mostrar a Lista Invertida                  |");
        puts("+-------------------------------------------------+");
    
        puts("Escolha a Operacao: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            L = List_create();
            break;
        case 2:
            retornoBool = List_create(L);
            if (retornoBool == true) {
                puts("A Lista esta vazia!");
            } 
            else {
                puts("A Lista nao esta vazia!");
            }
            break;
        case 3:
            if (List_is_empty(L)) {
                puts("[ERROR] A lista esta vazia, portanto nao eh possivel destrui-la!");
            }
            else {
                List_destroy(&L);
                if (L == NULL) {
                    puts("Lista destrudia com Sucesso!");
                }
                else {
                    puts("[ERROR] A lista nao foi destruida!");
                }
            }
            break;
        case 4:
            puts("Digite o valor a ser Inserido na Lista: ");
            scanf("%d", &val);

            List_add_first(L, val);
            break;  
        case 5:
            puts("Digite o valor a ser Inserido na Lista: ");
            scanf("%d", &val);
            
            List_add_last(L, val);
            break;
        case 6:
            List_remove_first(L);
            break;
        case 7:
            List_remove_last(L);
            break;
        case 8:
            puts("Digite o valor a ser Removido da Lista: ");
            scanf("%d", &val);

            List_remove_first_val(L, val);
            break;
        case 9:
            puts("Digite o valor a ser Removido de toda a Lista: ");
            scanf("%d", &val);

            List_remove_all_val(L, val);
            break;
        case 10:
            List_print(L);
            break;
        case 11:
            List_inverted_print(L);
            break;
        default:
            break;
        }
    }
    


    // LinkedList_add_last(L, 10); 
    // LinkedList_add_last(L, 2);
    // LinkedList_add_last(L, 4);
    // LinkedList_add_last(L, 5);
    // LinkedList_add_last(L, 7);
    // LinkedList_print(L);

    if (L != NULL) {
        List_destroy(&L);
    }

    puts("Programa Finalizado!");

    return 0;
}




