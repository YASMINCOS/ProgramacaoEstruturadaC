#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <float.h>


#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50
#define MAX_CHAR 50
#define NUM_ESTADOS 26


struct Produto
{
    char descricao[MAX_CHAR];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    char fabricante[MAX_CHAR];
};


struct Fabricante
{
    char marca[MAX_CHAR];
    char site[MAX_CHAR];
    char telefone[15];
    char uf[3];
};




const char* estados[NUM_ESTADOS] = {
    "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS",
    "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC",
    "SP", "SE", "TO"
};


void le_valida_fabricantes(struct Fabricante fabricantes[], int *numFabricantes);
void le_valida_produtos(struct Produto produtos[], int *numProdutos, struct Fabricante fabricantes[], int numFabricantes);
void listar_marcas(struct Fabricante fabricantes[], int numFabricantes);
void listar_produtos(struct Produto produtos[], int numProdutos);
void listar_produtos_estado(struct Produto produtos[], int numProdutos, char estados[][MAX_CHAR]);


void listar_produtos_marca(struct Produto produtos[], int numProdutos);
void produto_mais_caro_por_estado(struct Produto produtos[], int numProdutos);
void fabricante_mais_barato(struct Produto produtos[], int numProdutos, struct Fabricante fabricantes[], int numFabricantes);
int comparar_valor(const void *a, const void *b);
int comparar_lucro(const void *a, const void *b);
int comparar_percentual(const void *a, const void *b);






int main()
{
    setlocale(LC_ALL, "");
    int opcao;
    int numFabricantes = 0;
    int numProdutos = 0;
    printf("===== Sistema de Cadastro =====\n\n");
    struct Fabricante fabricantes[MAX_FABRICANTES];
    struct Produto produtos[MAX_PRODUTOS];


    le_valida_fabricantes(fabricantes, &numFabricantes);
    le_valida_produtos(produtos, &numProdutos, fabricantes, numFabricantes);


    char estados[NUM_ESTADOS][MAX_CHAR] = {
        "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};


    do
    {
        printf("\nMenu de Relatórios\n");
        printf("- [1] Listar todas as marcas\n");
        printf("- [2] Listar todos os produtos\n");
        printf("- [3] Listar os produtos de um determinado estado\n");
        printf("- [4] Listar os produtos de uma determinada marca\n");
        printf("- [5] Apresentar o(s) estado(s) onde está registrado o produto mais caro\n");
        printf("- [6] Apresentar o(s) fabricante(s) onde está registrado o produto mais barato\n");
        printf("- [7] Listar todos os produtos em ordem crescente de valor\n");
        printf("- [8] Listar todos os produtos em ordem crescente de maior valor do lucro\n");
        printf("- [9] Listar todos os produtos em ordem crescente de percentual de lucro\n");
        printf("- [0] Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);


        switch (opcao)
        {
        case 1:
            listar_marcas(fabricantes, numFabricantes);
            break;
        case 2:
            listar_produtos(produtos, numProdutos);
            break;
        case 3:
            listar_produtos_estado(produtos, numProdutos, estados);
            break;
        case 4:
            listar_produtos_marca(produtos, numProdutos);
            break;
        case 5:
            produto_mais_caro_por_estado(produtos, numProdutos);
            break;
        case 6:
            fabricante_mais_barato(produtos, numProdutos, fabricantes, numFabricantes);
            break;
        case 7:
            qsort(produtos, numProdutos, sizeof(struct Produto), comparar_valor);
            listar_produtos(produtos, numProdutos);
            break;
        case 8:
            qsort(produtos, numProdutos, sizeof(struct Produto), comparar_lucro);
            listar_produtos(produtos, numProdutos);
            break;
        case 9:
            qsort(produtos, numProdutos, sizeof(struct Produto), comparar_percentual);
            listar_produtos(produtos, numProdutos);
            break;
        case 0:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);


    return 0;
}void le_valida_fabricantes(struct Fabricante fabricantes[], int *numFabricantes)
{
    printf("===== Cadastro de Fabricantes =====\n\n");
    int i = 0;
    do {
        printf("Fabricante %d:\n", i + 1);
        printf("Marca: ");
        scanf("%s", fabricantes[i].marca);
        printf("Site: ");
        scanf("%s", fabricantes[i].site);
        printf("Telefone: ");
        scanf("%s", fabricantes[i].telefone);


       
        while (1) {
            printf("UF disponiveis:\nAC\nAL\nAP\nAM\nBA\nCE\nDF\nES\nGO\nMA\nMT\nMS\nMG\nPA\nPB\nPR\nPE\nPI\nRJ\nRN\nRS\nRO\nRR\nSC\nSP\nSE\nTO\nDigite sua UF: ");
            scanf("%s", fabricantes[i].uf);
       
        if (strcmp(fabricantes[i].uf, "AC") != 0 && strcmp(fabricantes[i].uf, "AL") != 0 && strcmp(fabricantes[i].uf, "AP") != 0 && strcmp(fabricantes[i].uf, "AM") != 0 && strcmp(fabricantes[i].uf, "BA") != 0 && strcmp(fabricantes[i].uf, "CE") != 0 && strcmp(fabricantes[i].uf, "DF") != 0 && strcmp(fabricantes[i].uf, "ES") != 0 && strcmp(fabricantes[i].uf, "GO") != 0 && strcmp(fabricantes[i].uf, "MA") != 0 && strcmp(fabricantes[i].uf, "MT") != 0 && strcmp(fabricantes[i].uf, "MS") != 0 && strcmp(fabricantes[i].uf, "MG") != 0 && strcmp(fabricantes[i].uf, "PA") != 0 && strcmp(fabricantes[i].uf, "PB") != 0 && strcmp(fabricantes[i].uf, "PR") != 0 && strcmp(fabricantes[i].uf, "PE") != 0 && strcmp(fabricantes[i].uf, "PI") != 0 && strcmp(fabricantes[i].uf, "RJ") != 0 && strcmp(fabricantes[i].uf, "RN") != 0 && strcmp(fabricantes[i].uf, "RS") != 0 && strcmp(fabricantes[i].uf, "RO") != 0 && strcmp(fabricantes[i].uf, "RR") != 0 && strcmp(fabricantes[i].uf, "SC") != 0 && strcmp(fabricantes[i].uf, "SP") != 0 && strcmp(fabricantes[i].uf, "SE") != 0 && strcmp(fabricantes[i].uf, "TO") != 0) {
            printf("Erro: UF inválida. Por favor digite uma UF válida.\n");
            continue;
        } else {
                break;
            }
        }


        (*numFabricantes)++;
        printf("\n");


        if (*numFabricantes < 2) {
            printf("É necessário cadastrar no mínimo 2 fabricantes.\n");
            i++;
            continue;
        }


        printf("Deseja cadastrar outro fabricante? (Digite 1 para SIM ou 0 para NÃO): ");
        int opcao;
        scanf("%d", &opcao);


        if (opcao == 0) {
            break;
        }


        i++;
    } while (i < MAX_FABRICANTES);
    
    system("clear");
}


void le_valida_produtos(struct Produto produtos[], int *numProdutos, struct Fabricante fabricantes[], int numFabricantes)
{
    printf("===== Cadastro de Produtos =====\n\n");
    int i = 0;
    do {
        printf("Produto %d:\n", i + 1);
        printf("Descrição: ");
        scanf("%s", produtos[i].descricao);
        printf("Peso: ");
        scanf("%f", &produtos[i].peso);
        printf("Valor de Compra: ");
        scanf("%f", &produtos[i].valorCompra);
        printf("Valor de Venda: ");
        scanf("%f", &produtos[i].valorVenda);
        printf("Fabricante (Digite o número correspondente):\n");
        listar_marcas(fabricantes, numFabricantes);
        int opcao;
        scanf("%d", &opcao);
        strcpy(produtos[i].fabricante, fabricantes[opcao - 1].uf);
        (*numProdutos)++;
        printf("\n");


        if (*numProdutos < 5) {
            printf("É necessário cadastrar no mínimo 5 produtos.\n");
            i++;
            continue;
        }


        printf("Deseja cadastrar outro produto? (Digite 1 para SIM ou 0 para NÃO): ");
        scanf("%d", &opcao);


        if (opcao == 0) {
            break;
        }


        i++;
    } while (i < MAX_PRODUTOS);
}




void listar_marcas(struct Fabricante fabricantes[], int numFabricantes)
{
        int i=0;
    printf("===== Marcas Cadastradas =====\n\n");
    for ( i = 0; i < numFabricantes; i++)
    {
        printf("[%d] Marca: %s\n", i + 1, fabricantes[i].marca);
    }
}


void listar_produtos(struct Produto produtos[], int numProdutos)
{
        int i;
    printf("===== Produtos Cadastrados =====\n\n");
    for ( i = 0; i < numProdutos; i++)
    {
        printf("Produto %d:\n", i + 1);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: %.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: %.2f\n", produtos[i].valorVenda);
         float lucroPercentual = ((produtos[i].valorVenda - produtos[i].valorCompra) / produtos[i].valorCompra) * 100;
        printf("Lucro Percentual: %.2f%%\n", lucroPercentual);
        printf("Fabricante: %s\n", produtos[i].fabricante);


        
       


        printf("\n");
    }
}


void listar_produtos_estado(struct Produto produtos[], int numProdutos, char estados[][MAX_CHAR])
{
        int i;
    printf("===== Listar Produtos por Estado =====\n\n");
    printf("Estados disponíveis:\n");
    for ( i = 0; i < NUM_ESTADOS; i++)
    {
        printf("[%d] %s\n", i + 1, estados[i]);
    }


    int opcao;
    printf("Digite o número do estado: ");
    scanf("%d", &opcao);
    opcao--; 


    printf("\nProdutos do estado %s:\n", estados[opcao]);
    int encontrou = 0;
    for ( i = 0; i < numProdutos; i++)
    {
        if (strcmp(produtos[i].fabricante, estados[opcao]) == 0)
        {
            printf("Produto %d:\n", i + 1);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de Compra: %.2f\n", produtos[i].valorCompra);
            printf("Valor de Venda: %.2f\n", produtos[i].valorVenda);
            printf("Fabricante: %s\n", produtos[i].fabricante);
            printf("\n");
            encontrou = 1;
        }
    }


    if (!encontrou)
    {
        printf("Nenhum produto encontrado para o estado %s.\n", estados[opcao]);
    }
}


void listar_produtos_marca(struct Produto produtos[], int numProdutos)
{
        int i;
    printf("===== Listar Produtos por Marca =====\n\n");
    for ( i = 0; i < numProdutos; i++)
    {
        printf("[%d] Marca: %s\n", i + 1, produtos[i].fabricante);
    }


    int opcao;
    printf("Digite o número da marca: ");
    scanf("%d", &opcao);
    opcao--; // Ajusta o índice baseado em 0


    printf("\nProdutos da marca %s:\n", produtos[opcao].fabricante);
    int encontrou = 0;
    for ( i = 0; i < numProdutos; i++)
    {
        if (strcmp(produtos[i].fabricante, produtos[opcao].fabricante) == 0)
        {
            printf("Produto %d:\n", i + 1);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de Compra: %.2f\n", produtos[i].valorCompra);
            printf("Valor de Venda: %.2f\n", produtos[i].valorVenda);
            printf("Fabricante: %s\n", produtos[i].fabricante);
            printf("\n");
            encontrou = 1;
        }
    }


    if (!encontrou)
    {
        printf("Nenhum produto encontrado para a marca %s.\n", produtos[opcao].fabricante);
    }
}




void produto_mais_caro_por_estado(struct Produto produtos[], int numProdutos)
{
        int i, j;
    printf("===== Produto mais Caro por Estado =====\n\n");
    for ( i = 0; i < NUM_ESTADOS; i++)
    {
        printf("Estado: %s\n", estados[i]);
        float maxValor = 0;
        int encontrou = 0;
        for ( j = 0; j < numProdutos; j++)
        {
            if (strcmp(produtos[j].fabricante, estados[i]) == 0)
            {
                if (produtos[j].valorVenda > maxValor)
                {
                    maxValor = produtos[j].valorVenda;
                    encontrou = 1;
                }
            }
        }
        if (encontrou)
        {
            printf("Produto mais caro: %.2f\n", maxValor);
        }
        else
        {
            printf("Nenhum produto encontrado.\n");
        }
        printf("\n");
    }
}




void fabricante_mais_barato(struct Produto produtos[], int numProdutos, struct Fabricante fabricantes[], int numFabricantes)
{
        int i,j;
    printf("===== Fabricante mais Barato =====\n\n");
    float minValor = FLT_MAX;
    int encontrou = 0;
    for ( i = 0; i < numProdutos; i++)
    {
        if (produtos[i].valorCompra < minValor)
        {
            minValor = produtos[i].valorCompra;
            encontrou = 1;
        }
    }
    if (encontrou)
    {
        printf("Fabricante(s) mais barato(s):\n");
        for ( i = 0; i < numProdutos; i++)
        {
            if (produtos[i].valorCompra == minValor)
            {
                for ( j = 0; j < numFabricantes; j++)
                {
                    if (strcmp(produtos[i].fabricante, fabricantes[j].uf) == 0)
                    {
                        printf("Fabricante: %s\n", fabricantes[j].marca);
                        printf("Site: %s\n", fabricantes[j].site);
                        printf("Telefone: %s\n", fabricantes[j].telefone);
                        printf("\n");
                    }
                }
            }
        }
    }
    else
    {
        printf("Nenhum fabricante encontrado.\n");
    }
}




int comparar_valor(const void *a, const void *b)
{
    struct Produto *produtoA = (struct Produto *)a;
    struct Produto *produtoB = (struct Produto *)b;


    if (produtoA->valorVenda < produtoB->valorVenda)
        return -1;
    else if (produtoA->valorVenda > produtoB->valorVenda)
        return 1;
    else
        return 0;
}


int comparar_lucro(const void *a, const void *b)
{
    struct Produto *produtoA = (struct Produto *)a;
    struct Produto *produtoB = (struct Produto *)b;


    if (produtoA->valorLucro < produtoB->valorLucro)
        return -1;
    else if (produtoA->valorLucro > produtoB->valorLucro)
        return 1;
    else
        return 0;
}


int comparar_percentual(const void *a, const void *b)
{
    struct Produto *produtoA = (struct Produto *)a;
    struct Produto *produtoB = (struct Produto *)b;


    if (produtoA->percentualLucro < produtoB->percentualLucro)
        return -1;
    else if (produtoA->percentualLucro > produtoB->percentualLucro)
        return 1;
    else
        return 0;
}




void listar_produtos_valor_lucro_crescente(struct Produto produtos[], int numProdutos) {
    int i, j;
    struct Produto temp;
    int opcao;


    for (i = 0; i < numProdutos - 1; i++) {
        for (j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorLucro > produtos[j + 1].valorLucro) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }


}