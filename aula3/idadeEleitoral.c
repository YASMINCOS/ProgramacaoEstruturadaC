#include <stdio.h>

int main() {
    int idade;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    if(idade < 0) {
        printf("Você ainda não nasceu.\n");
    } else {
        if(idade <= 15) {
            printf("Você não pode votar.\n");
        }
        if(idade >= 16) {
            if(idade >= 18 && idade <= 65) {
                printf("Seu voto é obrigatório.\n");
            }
            if(idade >= 16 && idade <= 17) {
                printf("Seu voto é opcional.\n");
            }
            if(idade > 65 && idade != 88) {
                printf("Seu voto é opcional.\n");
            }
            if(idade == 41 || idade == 88) {
                printf("Você somente ganha prêmio e não vota.\n");
            }
        }
    }

    return 0;
}
