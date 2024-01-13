/*
    Questão 7 -

    Os atuais caixas automáticos dos bancos, ou ATMs – Automated Teller Machines, são uma ótima invenção mas, às vezes, precisamos de dinheiro trocado e a máquina nos entrega notas de R$100,00. Noutras vezes, desejamos sacar um valor um pouco maior e, por questão de segurança, gostaríamos de receber todo o valor em notas de R$100,00, mas a máquina nos entrega um monte de notas de R$20,00.
    Para conquistar clientes, o Banco Inteligente (BI) está tentando minimizar este problema dando aos
    clientes a possibilidade de escolher o valor das notas na hora do saque. Para isso, eles precisam da sua ajuda
    para saber a resposta para a seguinte questão: dado um determinado valor S de saque (em reais) e quantas
    notas de cada valor a máquina tem, qual é o número de maneiras distintas que há para entregar o valor S ao
    cliente?
    Sabe-se que nas ATMs do BI há escaninhos para notas de 2, 5, 10, 20, 50 e de 100 reais.
    Por exemplo, suponha que para certo cliente X tenha-se que S = 22 e que o número de notas de cada valor
    presente na ATM no momento da solicitação deste saque é:

        N2 = 5
        N5 = 4
        N10 = 3
        n20 = 10
        N100 = 10

    Assim, há QUATRO maneiras distintas da máquina entregar o valor do saque solicitado:
        1ª : uma nota de R$20,00 e uma nota de R$2,00 (duas notas);
        2ª : duas notas de R$10,00 e uma nota de R$2,00 (três notas);
        3ª : uma nota de R$10,00, duas notas de R$5,00 e uma nota de R$2,00 (quatro notas);
        4ª : quatro notas de R$5,00 e uma nota de R$2,00 (cinco notas).

    Tarefa
        Escrever, em C, um programa que seja capaz de determinar o número de maneiras possíveis de atender
        à solicitação de saque do cliente.

    Entrada
        A primeira linha da entrada contém o número natural S expressando, em reais, o valor do saque desejado.
        A segunda linha contém seis inteiros N2, N5, N10, N20, N50 e N100, respectivamente, indicando o número de
        notas de 2, 5, 10, 20, 50 e 100 reais disponíveis na ATM no momento do saque. Os números estão separados
        por um único espaço em branco entre eles.
    
    Saída
        Seu programa deve imprimir um único número natural: a quantidade de maneiras distintas da máquina
        atender ao saque solicitado.

    Restrições
        • 0 ≤ S ≤ 5000 e Ni ≤ 500, ∀i ∈ {2,5,10,20,50,100}.

    Exemplos
        -----------------------------------------
        |   Entrada             |   Saída       |
        |   22                  |   4           |
        |   5 4 3 10 0 10       |               |
        -----------------------------------------
        |   Entrada             |   Saída       |
        |   1000                |   34201       |
        |   20 20 20 20 20 20   |               |
        -----------------------------------------
        |   Entrada             |   Saída       |
        |   50                  |   0           |
        |   1 1 1 1 0 1         |               |
        -----------------------------------------
*/

/*
    Algoritimo:
        - Ler o saque
        - Ler a quantidade de cédulas para cada valor de nota
        - Ver qual o máximo das maiores notas que se pode utilizar
        - Ao ver, não utilizar mais as notas maiores
*/



#include <stdio.h>
#define NOTAS 6

int countManeiras(int, int [], int [], int );

int main(){
    int saque, n2, n5, n10, n20, n50, n100;
    int i = 0;
    scanf("%d", &saque);

    if (saque < 0 || saque > 5000) {
        return 0;
    }

    scanf("%d %d %d %d %d %d", &n2, &n5, &n10, &n20, &n50, &n100);

    int notas[] = {2, 5, 10, 20, 50, 100};
    int quantidade[] = {n2, n5, n10, n20, n50, n100};

    for (i = 0; i < NOTAS; i++) {
        if (quantidade[i] > 500) {
            return 0;
        }
    }
 
    printf("%d", countManeiras(saque, notas, quantidade, 5));

    return 0;
}

int countManeiras(int saque, int notas[], int quantidade[], int index){

    if(saque == 0){
        return 1;
    } 
    if(saque < 0 || index < 0){
        return 0;
    }

    int maneiras = 0;

    int i;
    for(i = 0; i <= quantidade[index]; i++){
        if(saque >= i * notas[index]){
            maneiras += countManeiras(saque - i * notas[index], notas, quantidade, index - 1);
        }
    }

    return maneiras;

}