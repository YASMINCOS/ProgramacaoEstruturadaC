#include <stdio.h>

int main() {
    int num1, num2;

    
    printf("----------------------\n");
    printf("Verificador de maior \n");
    printf("-----------------------\n");

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    if (num1 > num2) {
        printf("%d é maior que %d", num1, num2);
    } else if (num2 > num1) {
        printf("%d é maior que %d", num2, num1);
    } else {
        printf("%d e %d são iguais", num1, num2);
    }

    return 0;
}
