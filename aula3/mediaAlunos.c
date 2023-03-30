#include <stdio.h>

/*
	ENTRADA: notas
	OBJETIVO: Soma as notas inseridas e calcular a media das 5 notas de um aluno
	SAÍDA: media final
*/

int main() {

    printf("Calculo de medias \n");
    printf("----------------- \n");
    float notas[5];
    float soma = 0;
    float media;
    int i;

    for(i=0; i<5; i++) {
        printf("Digite a %dª nota: ", i+1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    media = soma / 5;

    printf("A media do aluno é: %.2f\n", media);

    return 0;
}
