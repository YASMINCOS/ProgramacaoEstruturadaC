#include <stdio.h>

/*
	ENTRADA: idade
	OBJETIVO: Mostre uma mensagem de acordo com a idade de cada individuo.
	SAÍDA: situacao de acordo com a idade
*/


int main() {
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if(idade > 70) {
        printf("Novos 50\n");
    }
    else if(idade > 21) {
        printf("Adulto\n");
    }
    else {
        printf("Jovem\n");
    }

    return 0;
}
