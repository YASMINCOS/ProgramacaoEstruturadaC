#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDANTES 20
#define MAX_DISCIPLINAS 3

typedef struct {
    char nome[50];
    int carga_horaria;
    float notas[4];
} Disciplina;

typedef struct {
    char nome[50];
    int matricula;
    int idade;
    Disciplina disciplinas[MAX_DISCIPLINAS];
} Estudante;

void cadastrar_estudantes(Estudante estudantes[], int *num_estudantes) {
    printf("=== Cadastro de Estudantes ===\n\n");
    *num_estudantes = 0;

    while (*num_estudantes < MAX_ESTUDANTES) {
        printf("Estudante %d\n", *num_estudantes + 1);
        printf("Nome: ");
        scanf(" %[^\n]", estudantes[*num_estudantes].nome);
        printf("Matrícula: ");
        scanf("%d", &estudantes[*num_estudantes].matricula);
        printf("Idade: ");
        scanf("%d", &estudantes[*num_estudantes].idade);

       for (int i = 0; i < MAX_DISCIPLINAS; i++) {
        printf("Disciplina %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", estudantes[*num_estudantes].disciplinas[i].nome);
        printf("Carga horária: ");
        scanf("%d", &estudantes[*num_estudantes].disciplinas[i].carga_horaria);
        printf("Notas:\n");

        for (int j = 0; j < 4; j++) {
            printf("Nota %d: ", j+1);
            scanf("%f", &estudantes[*num_estudantes].disciplinas[i].notas[j]);
        }
}

        (*num_estudantes)++;
        char c;
        printf("Deseja cadastrar mais um estudante? (S/N): ");
        scanf(" %c", &c);
        if (c == 'N' || c == 'n') {
            break;
        }
    }
}

void calcular_medias(Estudante estudantes[], float medias[], int num_estudantes) {
    for (int i = 0; i < num_estudantes; i++) {
        float soma_notas = 0.0;
        int num_notas = 0;

        for (int j = 0; j < MAX_DISCIPLINAS; j++) {
            soma_notas += estudantes[i].disciplinas[j].notas[0] + 
                          estudantes[i].disciplinas[j].notas[1] + 
                          estudantes[i].disciplinas[j].notas[2] + 
                          estudantes[i].disciplinas[j].notas[3];
            num_notas += 4;
        }

        medias[i] = soma_notas / num_notas;
    }
}
void imprimir_media(Estudante estudantes[], float medias[], int num_estudantes) {
    printf("=== Médias dos estudantes ===\n\n");

    for (int i = 0; i < num_estudantes; i++) {
        printf("Estudante %d\n", i + 1);
        printf("Nome: %s\n", estudantes[i].nome);
        printf("Idade: %d\n", estudantes[i].idade);
        printf("Média das notas: %.2f\n", medias[i]);
        printf("\n");
    }
}

void calcular_maior_menor_media(Estudante estudantes[], float medias[], int num_estudantes, float *maior_media, float *menor_media) {
    *maior_media = medias[0];
    *menor_media = medias[0];

    for (int i = 1; i < num_estudantes; i++) {
        if (medias[i] > *maior_media) {
            *maior_media = medias[i];
        }

        if (medias[i] < *menor_media) {
            *menor_media = medias[i];
        }
    }
}

int main() {
    Estudante estudantes[MAX_ESTUDANTES];
    float medias[MAX_ESTUDANTES];
    int num_estudantes;
    float maior_media, menor_media;

    cadastrar_estudantes(estudantes, &num_estudantes);
    calcular_medias(estudantes, medias, num_estudantes);
    imprimir_media(estudantes, medias, num_estudantes);
    calcular_maior_menor_media(estudantes, medias, num_estudantes, &maior_media, &menor_media);

    printf("=== Maior e Menor Média ===\n\n");
    printf("Maior média: %.2f\n", maior_media);
    printf("Estudante(s) com a maior média:\n");

    for (int i = 0; i < num_estudantes; i++) {
        if (medias[i] == maior_media) {
            printf("%s\n", estudantes[i].nome);
        }
    }

    printf("\nMenor média: %.2f\n", menor_media);

    return 0;
}
