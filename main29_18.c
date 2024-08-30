#include <stdio.h>  //biblioteca para executar os inputs e outputs
#include <string.h> //biblioteca para manipulação de strings

void menu();    // declaração da função menu
void inserir(); // declaração da função inserir
void listar();  // declaração da função listar
void buscar();  // declaração da função buscar
void excluir(); // declaração da função excluir

char option; // variavel que armazena a escolha do user
int i = 0;   // variavel global que armazena a quantidade de produtos inseridos

typedef struct
{                   // Definição da struct para a lista de produtos
    int codigo;     // variavel que armazena os codigos de cada produto
    char nome[100]; // variavel que armazena o nome de cada produto
    float preco;    // variavel que armazena o preço de cada produto
    int quantidade; // variavel que armazena a quantidade de cada produto
} Lista;
Lista Produto[100]; // criando 100 "produtos" dentro da struct lista

void main()
{
    int b = 1;
    while (b == 1)
    { // criação do loop while usando a variavel b como parametro
        menu();
        switch (option)
        { // switch case usando o valor da variavel "option" como parametro
        case '1':
            inserir(); // chama a função inserir
            break;
        case '2':
            listar(); // chama a função listar
            break;
        case '3':
            buscar(); // chama a função buscar
            break;
        case '4':
            excluir(); // chama a função excluir
            break;
        case '5':
            printf("Saindo do programa");
            b++; // incrementa b para b=2 e fecha a main
        default:
            printf("Opção inexistente"); // alternativa para escolhas diferentes de 1,2,3,4 ou 5
            break;
        }
    }
}
void menu()
{ // função que exibe o menu
    printf("=== Menu de Opcoes ===\n1. Inserir produto\n2. Listar todos os produtos\n3. Buscar produto por nome\n4. Excluir produto por nome\n5. Sair\n\nEscolha uma opcao: ");
    scanf("%c", &option); // armazena a escolha do usuario
    printf("\n");
}
void inserir()
{                 // função para inserção de um novo produto
    int code = 0; // variavel que armazena temporariamente o codigo para verificação
    int nomeduplicado = 1;
    char name[100];

    int b = 1;
    while (b == 1)
    {
        printf("Digite um codigo numerico para o produto: ");
        scanf("%d", &code);
        for (int k = 0; k <= i; k++)
        {
            if (Produto[k].codigo == code)
            {
                while (code == Produto[k].codigo)
                {
                    printf("\nCodigo ja existente. Insira outro!\n\n");
                    printf("Digite um codigo numerico para o produto: ");
                    int tentativa = code;
                    scanf("%d", &code);
                    if (code < tentativa)
                    {
                        k = 0;
                    }
                }
            }
            b++;
        }
    }
    Produto[i].codigo = code;
    while (nomeduplicado)
    {
        printf("Digite o nome do produto: ");
        scanf("%s", name);
        nomeduplicado = 0;
        for (int m = 0; m <= i; m++)
        {
            if (strcmp(Produto[m].nome, name) == 0)
            {
                printf("\nNome ja existente. Insira outro.\n");
                nomeduplicado = 1;
                break;
            }
        }
    }
    strcpy(Produto[i].nome, name);

    while (1)
    {
        printf("Digite o preco do produto: ");
        if (scanf("%f", &Produto[i].preco) == 1)
        {
            break;
        }
        else
        {
            printf("\nInsira um numero.\n");
            while (getchar() != '\n')
                ;
        }
    }

    while (1)
    {
        printf("Digite a quantidade em estoque: ");
        if (scanf("%d", &Produto[i].quantidade) == 1)
        {
            break;
        }
        else
        {
            printf("\nInsira um numero.\n");
            while (getchar() != '\n')
                ; // Limpa o buffer de entrada
        }
    }

    printf("\nproduto inserido com sucesso!\n");
    i++;
}
void listar()
{
    if ((i) != 0)
    {
        printf("Sua lista de produtos:\n\n");
        for (int c = 0; c < i; c++)
        {
            printf("=======Produto: %s=======\n", Produto[c].nome);
            printf("codigo: %d\n", Produto[c].codigo);
            printf("nome: %s\n", Produto[c].nome);
            printf("preco: %.2f\n", Produto[c].preco);
            printf("quantidade: %d\n", Produto[c].quantidade);
            printf("\n");
        }
    }
    else
    {
        printf("Nao ha produtos na sua lista\n");
    }
}
void buscar()
{
    char busca[100];
    printf("Qual produto esta procurando? ");
    scanf("%s", &busca);
    int found = 0;
    for (int t = 0; t <= i; t++)
    {
        int CompBusc = strcmp(busca, Produto[t].nome);
        if (CompBusc == 0)
        {
            found++;
            printf("Codigo: %d\n", Produto[t].codigo);
            printf("Nome: %s\n", Produto[t].nome);
            printf("Preco: %.2f\n", Produto[t].preco);
            printf("Quantidade: %d\n\n", Produto[t].quantidade);
        }
    }
    if (found == 0)
    {
        printf("\n%s nao e um produto em sua lista.\n\n", busca);
    }
}
void excluir()
{
    char excluir[100];
    int found = 0;
    printf("Qual produto deseja excluir? ");
    scanf("%s", excluir);

    for (int l = 0; l <= i; l++)
    {
        int CompExc = strcmp(excluir, Produto[l].nome);

        if (CompExc == 0)
        {
            found++;
            for (int j = l; j < i - 1; j++)
            {
                Produto[j] = Produto[j + 1];
            }
            i--;
        }
    }
    if (found == 0)
    {
        printf("\n%s nao e um produto em sua lista.\n\n", excluir);
    }
    printf("Produto excluido\n\n");
}
