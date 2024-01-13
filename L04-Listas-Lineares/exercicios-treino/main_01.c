#include "linked_list.h"

int main() {
    LinkedList* L = (LinkedList*)NULL;
    int option = -1;
    bool retornoBool = NULL;
    int val;

    while (option != 0)
    {
        puts("+-------------------------------------------+");
        puts("| 0 - Finalizar Programa                    |");
        puts("| 1 - Criar uma Nova Lista Vazia            |");
        puts("| 2 - Verificar se a Lista eh Vazia         |");
        puts("| 3 - Destruir a Lista                      |");
        puts("| 4 - Adicionar Elemento no Inicio da Lista |");
        puts("| 5 - Adicionar Elemento no Final da Lista  |");
        puts("| 6 - Remover Elemento da Lista             |");
        puts("| 7 - Mostrar a Lista                       |");
        puts("| 8 - Mostrar o Tamanho da Lista            |");
        puts("+-------------------------------------------+");
    
        puts("Escolha a Operacao: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            L = LinkedList_create();
            break;
        case 2:
            retornoBool = LinkedList_is_empty(L);
            if (retornoBool == true) {
                puts("A Lista esta vazia!");
            } 
            else {
                puts("A Lista nao esta vazia!");
            }
            break;
        case 3:
            if (LinkedList_is_empty(L)) {
                puts("[ERROR] A lista esta vazia, portanto nao eh possivel destrui-la!");
            }
            else {
                LinkedList_destroy(&L);
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

            LinkedList_add_first(L, val);
            break;  
        case 5:
            puts("Digite o valor a ser Inserido na Lista: ");
            scanf("%d", &val);
            
            LinkedList_add_last(L, val);
            break;
        case 6:
            puts("Digite o valor a ser Removido da Lista: ");
            scanf("%d", &val);

            LinkedList_remove(L, val);
            break;
        case 7:
            LinkedList_print(L);
            break;
        case 8:
            printf("Size = %ld\n", LinkedList_size(L));
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
        LinkedList_destroy(&L);
    }

    return 0;
}




