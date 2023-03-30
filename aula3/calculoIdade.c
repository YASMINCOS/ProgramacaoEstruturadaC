#include <stdio.h>
/*
	ENTRADA: idade
	OBJETIVO: Mostrar que se a caso a idade seja menor que 30 o individuo é jovem
	SAÍDA: mensagem exibindo que é jovem
*/


int main() {

    printf("Calculo idade \n");
    printf("-------------- \n");
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if(idade < 30) {
        printf("Você é muito jovem\n");
    }

    return 0;
}
