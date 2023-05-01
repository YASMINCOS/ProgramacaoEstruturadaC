/*Elabore um algoritmo que permita ao usuário realizar a compra de frutas. Assim,
apresente a lista de frutas disponíveis, abaixo, com seus respectivos valores. O algoritmo
deve permitir ao usuário retomar o menu frutas quantas vezes quiser, e solicitar a quantidade
de frutas. Ao final, apresente o valor total da compra. */

#include <stdio.h>

int main() {

    float precos[3] = {5.0, 1.0, 4.0};
    char frutas[3][10] = {"ABACAXI", "MACSA", "PERA"};
    
    int opcao, quantidade;
    float total = 0.0;
    char continuar;

    printf("------------------------\n");
    printf("Bem vindo(a) a frutaria:\n");
    printf("------------------------\n");
    
    do {
        
        printf("Aqui esta a lista de frutas disponiveis:\n");
        for (int i = 0; i < 3; i++) {
            printf("%d - %s - R$%.2f\n", i+1, frutas[i], precos[i]);
        }
        
       
        printf("Digite o numero da fruta desejada: ");
        scanf("%d", &opcao);
        
        if (opcao < 1 || opcao > 3) {
            printf("Opcao invalida. Tente novamente.\n");
            continue;
        }
        
        printf("Digite a quantidade desejada: ");
        scanf("%d", &quantidade);
        
        total += precos[opcao-1] * quantidade;
        
        printf("Deseja continuar comprando? (S/N) ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
    
    printf("Total da compra: R$%.2f\n", total);
    
    return 0;
}
