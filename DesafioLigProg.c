#include <stdio.h> //biblioteca para executar os inputs e outputs
#include <string.h> //biblioteca para manipulação de strings

void menu(); //declaração da função menu
void inserir(); //declaração da função inserir
void listar(); //declaração da função listar
void buscar(); //declaração da função buscar
void excluir(); //declaração da função excluir

int option; //variavel que armazena a escolha do user
int i = 0; //variavel que armazena a quantidade de produtos inseridos

typedef struct { //declarando a struct 
    int codigo;
    char nome[100];
    float preco;
    int quantidade;
} Lista;
Lista Produto[100]; // criando sem variaveis de produto

int main() {
    Produto[0].codigo = -1; //improviso para corrigir erro em que nao era possivel criar produto com codigo 0
    int w = 1; //variavel usada para loop no while
    while( w == 1 ) {
        menu();
        switch (option) { //cada case de 'option' inicia uma funcao diferente
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
            w++; //incrementa 'w'' e sai do loop
            break;
        default:
            printf("Opção inexistente\n\n");
            break;
        }
    }
    return 0;
}
void menu() {
    printf("=== Menu de Opcoes ===\n1. Inserir produto\n2. Listar todos os produtos\n3. Buscar produto por nome\n4. Excluir produto por nome\n5. Sair\n\nEscolha uma opcao: ");
    scanf("%d", &option); //le a opcao escolida pelo user
    printf("\n");
}
void inserir() {
    int tratcode; //variavel onde sera tratado o codigo inserido pelo user
    int b = 1; //variavel para loop
    int nomeduplicado = 1; //variavel para identificacao de nome duplicado
    char name [100];  //variavel onde sera tratado o nome inserido pelo user
    while (b == 1) {
        printf("Digite um codigo numerico para o produto: ");
        scanf("%d", &tratcode); //recebe o código digitado pelo usuário
        for(int k = 0; k<=i; k++) { //compara o codigo inserido com os codigos ja existentes ate a posicao i
            if (Produto[k].codigo == tratcode) {
                while (tratcode == Produto[k].codigo) { //loop para quando o código inserido pelo usuário for igual a algum código do array
                    printf("\nCodigo ja existente. Insira outro!\n\n");
                    printf("Digite um codigo numerico para o produto: ");
                    scanf("%d",&tratcode); //recebe outro valor de código
                    k = 0; //reinicia a busca no array
                }
            }
            b++; //incrementa b e sai do loop

        }
    }
    Produto[i].codigo = tratcode; //atribui o código ao produto
    while (nomeduplicado) {
        printf("Digite o nome do produto: ");
        scanf("%s", name);//recebe o nome digitado pelo user
        nomeduplicado = 0;//variavel para loop
        for (int m = 0; m <= i; m++) {//compara os nomes já inseridos
            if (strcmp(Produto[m].nome, name) == 0) {
                printf("\nNome ja existente. Insira outro.\n");
                nomeduplicado = 1;//quando variavel receber 1 parada de código
                break;        }
        }
    }
    strcpy(Produto[i].nome, name);

    while (1) { //loop infinito ate a entrada ser valida
        printf("Digite o preco do produto: ");
        if (scanf("%f", &Produto[i].preco) == 1) { //scanf retornando 1 = entrada valida
            break; //sai do loop
        } else {
            printf("Insira um número.\n");
            while (getchar() != '\n'); //limpa o buffer de entrada
        }
    }

    while (1) { //loop infinito ate a entrada ser valida
        printf("Digite a quantidade em estoque: ");
        if (scanf("%d", &Produto[i].quantidade) == 1) { //scanf retornando 1= entrada valida
            break; //sai do loo
        } else {
            printf("Inteiro válido.\n");
            while (getchar() != '\n'); //limpa o buffer de entrada
        }
    }

    printf("\nproduto inserido com sucesso!\n");
    i++;
}
void listar() {
    if((i) != 0) { //printa separadamente a lista de todos os produtos
        printf("Sua lista de produtos:\n\n");
        for(int c = 0; c<i; c++) {
            printf("=======Produto: %s=======\n",Produto[c].nome);
            printf("codigo: %d\n",Produto[c].codigo);
            printf("nome: %s\n",Produto[c].nome);
            printf("preco: %.2f\n",Produto[c].preco);
            printf("quantidade: %d\n",Produto[c].quantidade);
            printf("\n");
        }
    }
    else {
        printf("Nao ha produtos na sua lista\n"); //caso nao haja produtos na lista
    }
}
void buscar() {
    char busca[100];
    printf("Qual produto esta procurando? ");
    scanf("%s",&busca);
    int found = 0;
    for(int t = 0; t<=i; t++) { //busca ate o indice i um produto com o mesmo nome
        int CompBusc =  strcmp(busca,Produto[t].nome); //'compbusc' recebe o retorno da funcao strcmp
        if(CompBusc == 0) {
            found++; //um sinal de que achou um produto de nome igual
            printf("Codigo: %d\n",Produto[t].codigo);
            printf("Nome: %s\n",Produto[t].nome);
            printf("Preco: %.2f\n",Produto[t].preco);
            printf("Quantidade: %d\n\n",Produto[t].quantidade);
        }
    }
    if(found==0) { //caso nao ache o produto de mesmo nome
        printf("\n%s nao e um produto em sua lista.\n\n", busca);
    }
}
void excluir() { 
    char excluir[100]; //criando uma string de char com 100 caracteres
    int found = 0; //variavel de sinal
    printf("Qual produto deseja excluir? ");
    scanf("%s", excluir); //input do user

    for(int l = 0; l<=i; l++) {
        int CompExc = strcmp(excluir,Produto[l].nome); //'CompExc' recebe o retorno da funcao strcmp'

        if(CompExc == 0) {
            found++; //um sinal e que achou um produto de nome igual
            for(int j = l; j < i-1; j++) {
                Produto[j] = Produto[j+1]; //leva o produto que tem o mesmo nome ate a ultima posicao de i
            }
            printf("Produto excluido\n\n");
            i--;// decrementa i, excluindo o ultimo produto

        }
    }
    if(found==0) {
        printf("\n%s nao e um produto em sua lista.\n\n",excluir); //caso nao ache o produto de mesmo nome
    }

}