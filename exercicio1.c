#include <stdio.h>

int main() {
    float custo, frete, despesas, venda, lucro;

    printf("Digite o custo da mercadoria: R$");
    scanf("%f", &custo);

    printf("Digite o valor do frete: R$");
    scanf("%f", &frete);

    printf("Digite o valor das despesas eventuais: R$");
    scanf("%f", &despesas);

    venda = custo + frete + despesas;

    printf("Digite o valor de venda da mercadoria: R$");
    scanf("%f", &venda);

    lucro = (venda - custo - frete - despesas) / (custo + frete + despesas) * 100;

    printf("A percentagem de lucro da mercadoria é: %.2f%%\n", lucro);

    return 0;
}