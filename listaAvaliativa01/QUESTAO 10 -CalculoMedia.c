/*Faça um programa que leia 10 inteiros e imprima sua média.*/

#include <stdio.h>

int main() {
    int numeros[10];
    int soma = 0;
    int quantidade = 0;

    printf("------------------------\n");
    printf("Calculadora de medias:\n ");
    printf("------------------------\n");

    for (int i = 0; i < 10; i++) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &numeros[i]);

     
        if (numeros[i] < 0) {
            continue;
        }

        soma += numeros[i];
        quantidade++;
    }

    if (quantidade > 0) {
        float media = (float)soma / quantidade;
        printf("A media dos numeros positivos eh: %.2f\n", media);
    } else {
        printf("Nao foi possivel calcular a media.\n");
    }

    return 0;
}
