#include <stdio.h>

int main() {
    float salarioAtual, percentualReajuste, novoSalario;

    printf("Digite o salario atual: ");
    scanf("%f", &salarioAtual);

    printf("Digite o percentual de reajuste: ");
    scanf("%f", &percentualReajuste);

    novoSalario = salarioAtual + salarioAtual * percentualReajuste / 100;

    if (novoSalario == salarioAtual){
        printf ("não houve aumento");
    }else if(novoSalario < salarioAtual){
        
        printf ("ocorreu uma redução");
    }else{
        printf("O novo salario e: %.2f\n", novoSalario);

    }


    return 0;
}
