/*Escreva um programa que leia um número inteiro, maior ou igual a zero, do usuário.
Imprima o enésimo termo da sequência de Fibonacci. Essa sequência começa no termo de
ordem zero, e, a partir do segundo termo, seu valor é dado pela soma dos dois termos
anteriores. Alguns termos dessa sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34.*/

#include <stdio.h>

void fibonacci(int n) {

    if (n < 0) {
        printf("Erro: o valor de n deve ser maior ou igual a zero.\n");
    } else if (n == 0) {
        printf("A sequencia de Fibonacci de ordem zero eh: 0\n");
    } else {
        int i, t1 = 0, t2 = 1, proximo_termo;
        printf("A sequencia de Fibonacci ate a ordem %d eh: ", n);
        printf("0, 1");
        for (i = 3; i <= n; i++) {
            proximo_termo = t1 + t2;
            printf(", %d", proximo_termo);
            t1 = t2;
            t2 = proximo_termo;
        }
        printf("\nO enesimo termo da sequencia de Fibonacci de ordem %d eh: %d\n", n, t2);
    }
}

int main() {

    printf("------------------------\n");
    printf("Sequencia de Fibonacci:\n");
    printf("------------------------\n");

    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}
