/*Elabore um programa utilizando as estruturas Professor, Disciplina e Estudante.

Professor (nome, funcional, titulacao (especialista, mestre ou doutor)).
Disciplina (nome, codigo, carga_horaria, professor_responsavel (escolhidos dentre os professores cadastrados)).
Estudante (nome, matricula, idade).

Serão cadastrados 3 professores, 2 disciplinas e no máximo 15 estudantes distribuídos entre as duas disciplinas, uma disciplina não poderá ter mais que 10 estudantes matriculados.

Apresente um relatório dos alunos matriculados na primeira disciplina ordenados por idade.
codigo_disciplina   nome_professor  nome_estudante  idade_estudante

Apresente um relatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente.
codigo_disciplina   nome_professor  nome_estudante  idade_estudante

Utilize o bubble sort para ordenação utilizano um procedimento com passagem de parâmetros por referência.

Idade do estudante deverá estar validada entre 16 e 26 por meio de uma função le_valida_idade.



*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PROFESSORES 3
#define MAX_DISCIPLINAS 2
#define MAX_ESTUDANTES 15

typedef struct {
    char nome[50];
    int funcional;
    char titulacao[20];
} Professor;

typedef struct {
    char nome[50];
    int codigo;
    int carga_horaria;
    Professor* professor_responsavel;
} Disciplina;

typedef struct {
    char nome[50];
    int matricula;
    int idade;
} Estudante;

void bubbleSort(Estudante* estudantes, int n) {
    int i, j;
    Estudante temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (estudantes[j].idade > estudantes[j + 1].idade) {
                temp = estudantes[j];
                estudantes[j] = estudantes[j + 1];
                estudantes[j + 1] = temp;
            }
        }
    }
}

int le_valida_idade() {
    int idade;
    do {
        printf("Digite a idade do estudante (entre 16 e 26): ");
        scanf("%d", &idade);
    } while (idade < 16 || idade > 26);
    return idade;
}

void limpar_tela() {
    system("clear");
}

void imprimir_relatorio(Disciplina* disciplina, Estudante* estudantes, int numEstudantes) {
    printf("Relatório dos alunos matriculados na disciplina %d ordenados por idade\n", disciplina->codigo);
    printf("----------------------------------------------------------------------------\n");
    printf("Código da Disciplina\tNome do Professor\t\tNome do Estudante\tIdade do Estudante\n");
    for (int i = 0; i < numEstudantes; i++) {
        printf("%d\t\t\t%s\t\t\t\t%s\t\t\t%d\n", disciplina->codigo,
               disciplina->professor_responsavel->nome, estudantes[i].nome, estudantes[i].idade);
    }
}

int main() {
    Professor professores[MAX_PROFESSORES];
    Disciplina disciplinas[MAX_DISCIPLINAS];
    Estudante estudantes[MAX_ESTUDANTES];
    Estudante estudantes_disciplina1[MAX_ESTUDANTES];
    Estudante estudantes_disciplina2[MAX_ESTUDANTES];

    int i, j;

    for (i = 0; i < MAX_PROFESSORES; i++) {
        limpar_tela();
        printf("Cadastro do Professor %d\n", i + 1);
        printf("-------------------------\n");
        printf("Digite o nome: ");
        scanf("%s", professores[i].nome);
        printf("Digite o funcional: ");
        scanf("%d", &professores[i].funcional);
        
        int opcaoTitulacao;
        printf("Digite a titulacao (1 - especialista, 2 - mestre, 3 - doutor): ");
        scanf("%d", &opcaoTitulacao);

        switch (opcaoTitulacao) {
            case 1:
                strcpy(professores[i].titulacao, "especialista");
                break;
            case 2:
                strcpy(professores[i].titulacao, "mestre");
                break;
            case 3:
                strcpy(professores[i].titulacao, "doutor");
                break;
            default:
                strcpy(professores[i].titulacao, "titulação inválida");
                break;
        }
    }

    for (i = 0; i < MAX_DISCIPLINAS; i++) {
        limpar_tela();
        printf("Cadastro da Disciplina %d\n", i + 1);
        printf("--------------------------\n");
        printf("Digite o nome: ");
        scanf("%s", disciplinas[i].nome);
        printf("Digite o codigo: ");
        scanf("%d", &disciplinas[i].codigo);
        printf("Digite a carga horaria: ");
        scanf("%d", &disciplinas[i].carga_horaria);

        printf("Opções de professores responsáveis:\n");
        for (j = 0; j < MAX_PROFESSORES; j++) {
            printf("%d - %s\n", j + 1, professores[j].nome);
        }

        int numeroProfessor;
        printf("Digite o número do professor responsável (1 a %d): ", MAX_PROFESSORES);
        scanf("%d", &numeroProfessor);

        while (numeroProfessor < 1 || numeroProfessor > MAX_PROFESSORES) {
            printf("Opção inválida. Digite novamente: ");
            scanf("%d", &numeroProfessor);
        }

        disciplinas[i].professor_responsavel = &professores[numeroProfessor - 1];
    }

    int numEstudantesDisciplina1;
    do {
        limpar_tela();
        printf("Cadastro de Estudantes (Disciplina 1)\n");
        printf("-------------------------------------\n");
        printf("Digite o número de estudantes para a primeira disciplina (máximo 10): ");
        scanf("%d", &numEstudantesDisciplina1);
    } while (numEstudantesDisciplina1 > 10 || numEstudantesDisciplina1 < 0);

    for (i = 0; i < numEstudantesDisciplina1; i++) {
        limpar_tela();
        printf("Cadastro do Estudante %d (Disciplina 1)\n", i + 1);
        printf("---------------------------------------\n");
        printf("Digite o nome: ");
        scanf("%s", estudantes_disciplina1[i].nome);
        printf("Digite a matricula: ");
        scanf("%d", &estudantes_disciplina1[i].matricula);
        estudantes_disciplina1[i].idade = le_valida_idade();
    }

    bubbleSort(estudantes_disciplina1, numEstudantesDisciplina1);

    int numEstudantesDisciplina2;
    do {
        limpar_tela();
        printf("Cadastro de Estudantes (Disciplina 2)\n");
        printf("-------------------------------------\n");
        printf("Digite o número de estudantes para a segunda disciplina (máximo 10): ");
        scanf("%d", &numEstudantesDisciplina2);
    } while (numEstudantesDisciplina2 > 10 || numEstudantesDisciplina2 < 0);

    for (i = 0; i < numEstudantesDisciplina2; i++) {
        limpar_tela();
        printf("Cadastro do Estudante %d (Disciplina 2)\n", i + 1);
        printf("---------------------------------------\n");
        printf("Digite o nome: ");
        scanf("%s", estudantes_disciplina2[i].nome);
        printf("Digite a matricula: ");
        scanf("%d", &estudantes_disciplina2[i].matricula);
        estudantes_disciplina2[i].idade = le_valida_idade();
    }

    bubbleSort(estudantes_disciplina2, numEstudantesDisciplina2);

    int numEstudantesTotal = numEstudantesDisciplina1 + numEstudantesDisciplina2;
    memcpy(estudantes, estudantes_disciplina1, numEstudantesDisciplina1 * sizeof(Estudante));
    memcpy(estudantes + numEstudantesDisciplina1, estudantes_disciplina2, numEstudantesDisciplina2 * sizeof(Estudante));

    bubbleSort(estudantes, numEstudantesTotal);

    limpar_tela();
    printf("Relatório dos alunos matriculados nas disciplinas ordenados por idade\n");
    printf("---------------------------------------------------------------------\n");
    printf("Código da Disciplina\tNome do Professor\t\tNome do Estudante\tIdade do Estudante\n");
    for (i = 0; i < numEstudantesTotal; i++) {
        if (i < numEstudantesDisciplina1) {
            printf("%d\t\t\t%s\t\t\t\t%s\t\t\t%d\n", disciplinas[0].codigo,
                   disciplinas[0].professor_responsavel->nome, estudantes[i].nome, estudantes[i].idade);
        } else {
            printf("%d\t\t\t%s\t\t\t\t%s\t\t\t%d\n", disciplinas[1].codigo,
                   disciplinas[1].professor_responsavel->nome, estudantes[i].nome, estudantes[i].idade);
        }
    }

    return 0;
}