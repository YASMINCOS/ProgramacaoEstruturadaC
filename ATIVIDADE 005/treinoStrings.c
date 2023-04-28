#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    char nomeCompleto[50];
    
    printf("Digite o nome completo: ");
    fgets(nomeCompleto, sizeof(nomeCompleto), stdin);
    
    if (nomeCompleto[strlen(nomeCompleto) - 1] == '\n') {
        nomeCompleto[strlen(nomeCompleto) - 1] = '\0';
    }
    
    formatarReferencia(nomeCompleto);
    
    return 0;
}

void formatarReferencia(char nomeCompleto[]) {
     char sobrenome[50];
     char iniciais[20] = "";
     char* ultimoEspaco = strrchr(nomeCompleto, ' ');
     char* palavrasExtraidas = strtok(nomeCompleto, " ");
    
    
    if (ultimoEspaco != NULL) {
        strcpy(sobrenome, ultimoEspaco + 1);
    }

   
   
    while (palavrasExtraidas != NULL) {
        char inicial = palavrasExtraidas[0];
        if (inicial >= 'a' && inicial <= 'z') {
            inicial = toupper(inicial);
        }
        strncat(iniciais, &inicial, 1);
        palavrasExtraidas = strtok(NULL, " ");
    }
    
    for (int i = 0; sobrenome[i] != '\0'; i++) {
        sobrenome[i] = toupper(sobrenome[i]);
    }
    for (int i = 0; iniciais[i] != '\0'; i++) {
        iniciais[i] = toupper(iniciais[i]);
    }
    
    printf("%s %c. %s.\n", sobrenome, iniciais[0], iniciais + 1);
}