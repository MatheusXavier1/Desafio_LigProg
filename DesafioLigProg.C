#include <stdio.h> //biblioteca para executar os inputs e outputs
#include <string.h> //biblioteca para manipulação de strings

void menu(); //declaração da função menu
void inserir(); //declaração da função inserir
void listar(); //declaração da função listar
void buscar(); //declaração da função buscar
void excluir(); //declaração da função excluir

int option; //variavel que armazena a escolha do user
int i = 0; //variavel que armazena a quantidade de produtos inseridos

typedef struct{
    int codigo;
    char nome[100];
    float preco;
    int quantidade;
}Lista;
Lista Produto[100];

void main(){
    int w = 1;
    while( w == 1 ){
        menu();
        switch (option){
        case 1:
            inserir();
            break;
        case 2:
            listar();
            break;
        case 3:
            buscar();
            break;
        case 4:
            excluir();
            break;
        case 5:
            printf("Saindo do programa");
            w++;
            break;
        default:
            printf("Opção inexistente");
            break;
        }
    }
}
void menu(){
    printf("=== Menu de Opcoes ===\n1. Inserir produto\n2. Listar todos os produtos\n3. Buscar produto por nome\n4. Excluir produto por nome\n5. Sair\n\nEscolha uma opcao: ");
    scanf("%d", &option);
    printf("\n");
}
void inserir(){
    int code;
    int b = 1;
    while(b == 1){
    printf("Digite o codigo do produto: ");
    scanf("%d", &code);
    for(int k = 0; k<=i;k++){
        if(Produto[k].codigo == code){ //analiza se o código inserido já existe
            while(code == Produto[k].codigo){ //repete até o código inserido ser diferente
            printf("Codigo ja existente. Insira outro\n\n");
            printf("Digite o codigo do produto: ");
            int tentativa = code;
            scanf("%d",&code);
            if(code < tentativa){
                k = 0;
            }
            }
        }
        b++;
    }
    }
    Produto[i].codigo = code;
    printf("Digite o nome do produto: ");
    scanf("%s",Produto[i].nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &Produto[i].preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d",&Produto[i].quantidade);
    printf("\n");
    printf("Produto inserido com sucesso!\n\n");
    i++;

}
void listar(){
    if((i) != 0){            
        printf("Sua lista de produtos:\n\n");
        for(int c = 0; c<i; c++){
            printf("=======Produto: %s=======\n",Produto[c].nome);
            printf("codigo: %d\n",Produto[c].codigo);
            printf("nome: %s\n",Produto[c].nome);
            printf("preco: %.2f\n",Produto[c].preco);
            printf("quantidade: %d\n",Produto[c].quantidade);
            printf("\n");
        }
    }
    else{
        printf("Nao ha produtos na sua lista\n");
    }
}
void buscar(){
    char busca[100];
    printf("Qual produto esta procurando? ");
    scanf("%s",&busca);
    for(int t = 0; t<=i;t++){
        int CompBusc =  strcmp(busca,Produto[t].nome);
        if(CompBusc == 0){
            printf("Codigo: %d\n",Produto[t].codigo);
            printf("Nome: %s\n",Produto[t].nome);
            printf("Preco: %.2f\n",Produto[t].preco);
            printf("Quantidade: %d\n\n",Produto[t].quantidade);
        }
    }
}
void excluir(){
    char excluir[100];

    printf("Qual produto deseja excluir? ");
    scanf("%s", excluir);

    for(int l = 0; l<=i;l++){
        int CompExc = strcmp(excluir,Produto[l].nome);

        if(CompExc == 0){
            for(int j = l; j < i-1; j++){
                Produto[j] = Produto[j+1];
            }
        }
    }
    i--;
    printf("Produto excluido\n\n");
}
