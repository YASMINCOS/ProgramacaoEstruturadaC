/*Leia 2 valores com uma casa decimal (x e y), que devem representar as coordenadas
de um ponto em um plano. A seguir, determine qual o quadrante ao qual pertence o ponto, ou
se está sobre um dos eixos cartesianos ou na origem (x = y = 0). Se o ponto estiver na origem,
escreva a mensagem “Origem”. Se o ponto estiver sobre um dos eixos escreva “Eixo X” ou
“Eixo Y”, conforme for a situação.
*/

#include <stdio.h>

int main() {
    float x, y;

    printf("-------------------------- \n");
    printf("Calculo do quadrante \n");
    printf("------------------------- \n-"); 

    printf("Digite a coordenada x do ponto:");
    scanf("%f", &x);
    printf("Digite a coordenada y do ponto:");
    scanf("%f", &y);
    
    if (x == 0 && y == 0) {
        printf("O ponto esta na Origem.\n");
    } else if (x == 0) {
        printf("O ponto esta sobre o Eixo Y.\n");
    } else if (y == 0) {
        printf("O ponto esta sobre o Eixo X.\n");
    } else if (x > 0 && y > 0) {
        printf("O ponto esta no Quadrante Q1.\n");
    } else if (x < 0 && y > 0) {
        printf("O ponto esta no Quadrante Q2.\n");
    } else if (x < 0 && y < 0) {
        printf("O ponto esta no Quadrante Q3.\n");
    } else {
        printf("O ponto esta no Quadrante Q4.\n");
    }
    
    return 0;
}
