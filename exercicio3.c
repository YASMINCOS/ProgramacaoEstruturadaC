#include <stdio.h>
#include <math.h>

#define CONSUMO_TINTA 0.3 
#define QUANTIDADE_TINTA_LATA 2 

int main() {
    float largura, altura, area_parede, quantidade_tinta, quantidade_latas;

    printf("Digite a largura da parede em metros: ");
    scanf("%f", &largura);

    printf("Digite a altura da parede em metros: ");
    scanf("%f", &altura);

    area_parede = largura * altura;
    quantidade_tinta = area_parede * CONSUMO_TINTA;
    quantidade_latas = ceil(quantidade_tinta / QUANTIDADE_TINTA_LATA);

    printf("Será necessária a quantidade de %.0f lata(s) de tinta para pintar a parede.\n", quantidade_latas);

    return 0;
}