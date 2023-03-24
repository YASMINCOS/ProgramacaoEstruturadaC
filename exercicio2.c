#include <stdio.h>

#define PI 3.14159

int main() {
    float raio, area;

    printf("Digite o valor do raio do circulo: ");
    scanf("%f", &raio);

    area = PI * raio * raio;

    printf("A area do circulo e: %.2f", area);

    return 0;
}