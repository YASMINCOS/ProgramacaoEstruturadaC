#include <stdio.h>

int main() {
    float n1, n2, n3, media;

    printf("Digite as tres notas do aluno:\n");
    scanf("%f %f %f", &n1, &n2, &n3);

    media = ((n1*2)+(n2*3)+(n3*5))/(2+3+5);

    printf("A media final do aluno eh: %.2f", media);

    return 0;
}
