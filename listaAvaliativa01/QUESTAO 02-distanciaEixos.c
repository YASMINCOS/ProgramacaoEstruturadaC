/*Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no
plano, p1(x1, y1) e p2(x2, y2) e calcule a distância entre eles, mostrando 4 casas decimais
após a vírgula, segundo a fórmula:*/

#include <stdio.h>
#include <math.h>

int main() {
   float x1, y1, x2, y2, d;

    printf("-------------------------- \n");
    printf("Calcule a distancia entre os eixos \n");
    printf("------------------------- \n-"); 

   printf("Entre com o valor de x do primeiro ponto (p1): ");
   scanf("%f", &x1);
   printf("Entre com o valor de y do primeiro ponto (p1): ");
   scanf("%f", &y1);

   printf("Entre com o valor de x do segundo ponto (p2): ");
   scanf("%f", &x2);
   printf("Entre com o valor de y do segundo ponto (p2): ");
   scanf("%f", &y2);

   d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

   printf("A distancia entre os pontos (%.2f, %.2f) e (%.2f, %.2f) eh =: %.4f\n", x1, y1, x2, y2, d);

   return 0;
}
