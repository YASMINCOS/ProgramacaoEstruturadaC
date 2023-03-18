#include <stdio.h>

int main() {
    float salario_fixo, valor_venda, valor_por_carro, comissao_por_carro, salario_final;
    int num_carros_vendidos;

    printf("Digite o número de carros vendidos: ");
    scanf("%d", &num_carros_vendidos);

    printf("Digite o valor total das vendas: ");
    scanf("%f", &valor_venda);

    printf("Digite o salário fixo: ");
    scanf("%f", &salario_fixo);

    printf("Digite o valor que ele recebe por carro vendido: ");
    scanf("%f", &valor_por_carro);

    comissao_por_carro = valor_por_carro * 0.05;

    salario_final = salario_fixo + (num_carros_vendidos * valor_por_carro) + (valor_venda * 0.05);

    printf("O salário final do vendedor é: R$ %.2f\n", salario_final);

    return 0;
}
