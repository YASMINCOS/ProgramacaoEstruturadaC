/*Elabore um programa que faça a leitura de vários números inteiros até que se digite
um número negativo. O programa tem de retornar o maior e o menor número lido*/

#include <stdio.h>

int main() {
    int num, maior, menor;

    printf("------------------------\n");
    printf("Calculo de interios: \n");
    printf("------------------------\n");

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    maior = menor = num;
    
    while(num >= 0) {
        if(num > maior) {
            maior = num;
        }
        if(num < menor) {
            menor = num;
        }
        printf("Digite um numero inteiro: ");
        scanf("%d", &num);
    }
    
    printf("O maior numero lido foi %d e o menor foi %d.", maior, menor);
    
    return 0;
}
