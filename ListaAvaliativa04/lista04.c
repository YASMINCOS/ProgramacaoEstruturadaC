//Yasmin Vitoria Costa
//Yan Soares Guimaraes 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <float.h>


#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50
#define MAX_CHAR 50
#define NUM_ESTADOS 27


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

void listar_produtos_marca(struct Produto produtos[], struct Fabricante fabricantes[],int numProdutos, int numFabricantes);
void produto_mais_caro_por_estado(struct Produto produtos[], int numProdutos);
void fabricante_mais_barato(struct Produto produtos[], int numProdutos, struct Fabricante fabricantes[], int numFabricantes);

void ordenar_produtos_alfabeticamente(struct Produto produtos[], int numProdutos);
void ordenar_marcas_alfabeticamente(struct Fabricante fabricantes[], int numFabricantes);

void selection_sort_percentual_lucro(struct Produto produtos[], int numProdutos);
void selection_sort_lucro(struct Produto produtos[], int numProdutos);
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
    struct Fabricante* fabricantes = malloc(MAX_FABRICANTES * sizeof(struct Fabricante));
    struct Produto* produtos = malloc(MAX_PRODUTOS * sizeof(struct Produto));


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
       printf("- [A] Listar todos os produtos em ordem alfabética crescente A-Z\n");
        printf("- [Z] Listar todas as marcas em ordem alfabética decrescente Z-A\n");
        printf("- [0] Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

char opcao;
scanf(" %c", &opcao);

switch (opcao)
{
    case '1':
        listar_marcas(fabricantes, numFabricantes);
        break;
    case '2':
        listar_produtos(produtos, numProdutos);
        break;
    case '3':
        listar_produtos_estado(produtos, numProdutos, estados);
        break;
    case '4':
        listar_produtos_marca(produtos, fabricantes, numProdutos, numFabricantes);
        break;
    case '5':
        produto_mais_caro_por_estado(produtos, numProdutos);
        break;
    case '6':
        fabricante_mais_barato(produtos, numProdutos, fabricantes, numFabricantes);
        break;
    case '7':
        qsort(produtos, numProdutos, sizeof(struct Produto), comparar_valor);
        listar_produtos(produtos, numProdutos);
        break;
    case '8':
        selection_sort_lucro(produtos, numProdutos);
        
        break;
    case '9':
       selection_sort_percentual_lucro(produtos, numProdutos);
        break;
    case 'A':
    case 'a':
        ordenar_produtos_alfabeticamente(produtos, numProdutos);
        listar_produtos(produtos, numProdutos);
        break; 
    case 'Z':
    case 'z':
        ordenar_marcas_alfabeticamente(fabricantes, numFabricantes);
        listar_marcas(fabricantes, numFabricantes);
        break;
    case '0':
        printf("Saindo do sistema...\n");
        break;
    default:
        printf("Opção inválida!\n");
        break;
}

    } while (opcao != 0);
 free(fabricantes);
  free(produtos);

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

int le_valida_peso(float *peso) {
    do {
        printf("Peso (em gramas): ");
        scanf("%f", peso);
        
        if (*peso < 50 || *peso > 50000) {
            printf("Erro: Peso deve estar entre 50g e 50kg.\n");
        }
        else {
            return 1;
        }
    } while (1);
}

int le_valida_valor_compra(float *valorCompra) {
    float valor;
    do {
        printf("Valor de Compra: ");
        scanf("%f", &valor);
        
        if (valor < 0.5 || valor > 8000) {
            printf("Erro: Valor de Compra deve estar entre R$ 0,50 e R$ 8.000,00.\n");
        }
        else {
            *valorCompra = valor;
            return 1;
        }
        while (getchar() != '\n');
    } while (1);
}

int le_valida_valor_venda(float *valorVenda) {
    float valor;
    do {
        printf("Valor de Venda: ");
        scanf("%f", &valor);
        
        if (valor < 1 || valor > 10000) {
            printf("Erro: Valor de Venda deve estar entre R$ 1,00 e R$ 10.000,00.\n");
        }
        else {
            *valorVenda = valor;
            return 1;
        }
        while (getchar() != '\n');
    } while (1);
}

int le_valida_uf(char *uf) {
    do {
        printf("UF: ");
        scanf("%s", uf);
        
        const char* estados[26] = {
            "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS",
            "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC",
            "SP", "SE", "TO"
        };
        
        int numEstados = sizeof(estados) / sizeof(estados[0]);
        for (int i = 0; i < numEstados; i++) {
            if (strcmp(uf, estados[i]) == 0) {
                return 1;
            }
        }
        
        printf("Erro: UF inválida.\n");
    } while (1);
}

void le_valida_produtos(struct Produto produtos[], int *numProdutos, struct Fabricante fabricantes[], int numFabricantes)
{
    printf("===== Cadastro de Produtos =====\n\n");
    int i = 0;
    do {
        printf("Produto %d:\n", i + 1);
        printf("Descrição: ");
        scanf("%s", produtos[i].descricao);

    
        le_valida_peso(&produtos[i].peso);

  
        le_valida_valor_compra(&produtos[i].valorCompra);

        le_valida_valor_venda(&produtos[i].valorVenda);

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
}void selection_sort_lucro(struct Produto produtos[], int numProdutos) {
    int i, j;
    struct Produto temp;

    for (i = 0; i < numProdutos - 1; i++) {
        for (j = 0; j < numProdutos - 1 - i; j++) {
            float lucro1 = produtos[j].valorVenda - produtos[j].valorCompra;
            float lucro2 = produtos[j + 1].valorVenda - produtos[j + 1].valorCompra;

            if (lucro1 > lucro2) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("===== Produtos em Ordem Crescente de Lucro =====\n\n");
    listar_produtos(produtos, numProdutos);
}


void selection_sort_percentual_lucro(struct Produto produtos[], int numProdutos) {
    int i, j;
    struct Produto temp;

    for (i = 0; i < numProdutos - 1; i++) {
        for (j = 0; j < numProdutos - 1 - i; j++) {
            float percentualLucro1 = ((produtos[j].valorVenda - produtos[j].valorCompra) / produtos[j].valorCompra) * 100;
            float percentualLucro2 = ((produtos[j + 1].valorVenda - produtos[j + 1].valorCompra) / produtos[j + 1].valorCompra) * 100;

            if (percentualLucro1 > percentualLucro2) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("===== Produtos em Ordem Crescente de Lucro Percentual =====\n\n");
    listar_produtos(produtos, numProdutos);
}
void listar_produtos(struct Produto produtos[], int numProdutos) {
    int i;

    printf("+----+----------------+----------------+---------------------+------------------+-----------------+-------------------+\n");
    printf("| ID |   Descrição    |      Peso      |       Compra        |      Venda       |      Lucro      | Lucro Percentual  |\n");
    printf("+----+----------------+----------------+---------------------+------------------+-----------------+-------------------+\n");

    for (i = 0; i < numProdutos; i++) {
        float lucro = produtos[i].valorVenda - produtos[i].valorCompra;
        float lucroPercentual = ((produtos[i].valorVenda - produtos[i].valorCompra) / produtos[i].valorCompra) * 100;

        printf("| %2d | %-14s | %10.2f     | %13.2f       | %13.2f    | %11.2f      | %16.2f%%   |\n",
               i + 1,
               produtos[i].descricao,
               produtos[i].peso,
               produtos[i].valorCompra,
               produtos[i].valorVenda,
               lucro,
               lucroPercentual);
    }

    printf("+----+----------------+----------------+---------------------+------------------+-----------------+-------------------+\n");
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

void listar_produtos_marca(struct Produto produtos[], struct Fabricante fabricantes[],int numProdutos,int numFabricantes)
{
    printf("===== Listar Produtos por Marca =====\n\n");
    int i, opcao;
    
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    
    printf("Marcas disponíveis:\n");
    for ( i = 0; i < numFabricantes; i++)
    {
        printf("[%d] Marca: %s\n", i + 1, fabricantes[i].marca);
    }
    
    printf("Digite o número correspondente à marca que deseja listar os produtos: ");
    scanf("%d", &opcao);
    
    if (opcao < 1 || opcao > numProdutos) {
        printf("Opção inválida.\n");
        return;
    }
    
    char marcaSelecionada[MAX_CHAR];
    strcpy(marcaSelecionada, produtos[opcao - 1].fabricante);
    
    printf("Produtos da marca %s:\n", marcaSelecionada);
    for (i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante, marcaSelecionada) == 0) {
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
void ordenar_produtos_alfabeticamente(struct Produto produtos[], int numProdutos)
{
    int i, j, minlet;
    struct Produto temp;

    for (i = 0; i < numProdutos - 1; i++)
    {
        minlet = i;
        for (j = i + 1; j < numProdutos; j++)
        {
            if (strcmp(produtos[j].descricao, produtos[minlet].descricao) < 0)
            {
                minlet = j;
            }
        }
        if (minlet != i)
        {
            temp = produtos[i];
            produtos[i] = produtos[minlet];
            produtos[minlet] = temp;
        }
    }
}
void ordenar_marcas_alfabeticamente(struct Fabricante fabricantes[], int numFabricantes)
{
    int i, j, maxlet;
    struct Fabricante temp;

    for (i = 0; i < numFabricantes - 1; i++)
    {
        maxlet = i;
        for (j = i + 1; j < numFabricantes; j++)
        {
            if (strcmp(fabricantes[j].marca, fabricantes[maxlet].marca) > 0)
            {
                maxlet = j;
            }
        }
        if (maxlet != i)
        {
            temp = fabricantes[i];
            fabricantes[i] = fabricantes[maxlet];
            fabricantes[maxlet] = temp;
        }
    }
}
