#include <stdio.h>

int main() {
    int anos, meses, dias, idade;

    printf("Digite a idade em anos: ");
    scanf("%d", &anos);
    
    printf("Digite a idade em meses:");
    scanf("%d", &meses);
    
    printf("Digite a idade em dias:");
    scanf("%d", &meses);

    if (anos>=2024 || meses > 12 || dias >=32 || dias <=0){
        printf("Data inválida");
    }else{
        idade = anos * 365 + meses * 30 + dias;

      printf("A idade em dias e: %d\n", idade);
    }

    

    return 0;
}