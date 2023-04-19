#include <stdio.h>

float le_valida_media() {
    float media;
    printf("Informe uma nota (ou valor negativo/acima de 10 para sair): ");
    scanf("%f", &media);
    while (media < 0 || media > 10) {
        printf("Valor invalido! Para sair, digite um valor negativo ou acima de 10.\n");
        printf("Informe uma nota (ou valor negativo/acima de 10 para sair): ");
        scanf("%f", &media);
    }
    return media;
}

float calcular_media(int quantidade, float soma) {
    return soma / quantidade;
}

int main() {
    int reprovados = 0, aprovados = 0, quantidade = 0;
    float media, menor_media = 10, maior_media = 0, soma = 0;
    do {
        media = le_valida_media();
        if (media >= 0 && media <= 10) {
            quantidade++;
            soma += media;
            if (media < menor_media) {
                menor_media = media;
            }
            if (media > maior_media) {
                maior_media = media;
            }
            if (media < 6.9) {
                reprovados++;
            } else {
                aprovados++;
            }
        }
    } while (quantidade < 25 && media >= 0 && media <= 10);

    float media_turma = calcular_media(quantidade, soma);
    printf("\n------------------\nRelatorio da turma\n------------------\n");
    printf("Media da turma: %.1f\nMaior nota: %.1f\nMenor nota: %.1f\nReprovados: %d\nAprovados: %d\n", media_turma, maior_media, menor_media, reprovados, aprovados);
    printf("------------------\n    BSB - 2023\n");
    return 0;
}
