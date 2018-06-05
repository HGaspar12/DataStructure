#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //biblioteca para utilização de acentuação da lingua portuguesa
#include "StaticWhisky1.h"

int main(){


    LISTA lista;
    WHISKY wh;

    int busca;
    int estq;
    int exclui;
    int option;

    char novo[] = "";
    char op;

    inicializarLista(&lista);

    wh.cod = 1;
    strcpy(wh.nomeWhisky , "Jack Daniels");
    wh.idadeWhisky = 12;
    wh.quantidade = 3;
    inserirWhisky(&lista, wh);

    wh.cod = 2;
    strcpy(wh.nomeWhisky , "Jack Daniels Honey");
    wh.idadeWhisky = 5;
    wh.quantidade = 4;
    inserirWhisky(&lista, wh);

    wh.cod = 3;
    strcpy(wh.nomeWhisky , "Red Label");
    wh.idadeWhisky = 5;
    wh.quantidade = 8;
    inserirWhisky(&lista, wh);

    wh.cod = 4;
    strcpy(wh.nomeWhisky , "Buchanans");
    wh.idadeWhisky = 10;
    wh.quantidade = 8;
    inserirWhisky(&lista, wh);

    wh.cod = 6;
    strcpy(wh.nomeWhisky , "White Horse");
    wh.idadeWhisky= 5;
    wh.quantidade = 6;
    inserirWhisky(&lista, wh);

    wh.cod = 7;
    strcpy(wh.nomeWhisky , "Old Par");
    wh.idadeWhisky = 3;
    wh.quantidade = 2;
    inserirWhisky(&lista, wh);

    void sistema (){
     system("pause");
     system("cls");
     return;
    }

    void menu() {
        printf("Whisky Menu");
        printf("\n [1] -  Inserir");
        printf("\n [2] -  Exibir");
        printf("\n [3] -  Busca Sequencial ");
        printf("\n [4] -  Busca Binaria");
        printf("\n [5] -  Alterar o Estoque");
        printf("\n [6] -  Excluir ");
        printf("\n [7] -  Reinicializar lista");
        printf("\n [8] -  Total de bebidas");
        printf("\n [0] -  Sair");
        return;
    }

    do{
     menu();
     printf("\n");
     printf("Digite uma opcao: \n");
     scanf("%d", &option);

    if (option == 1){

            printf("Inserindo Whikies\n");

            printf("\nCodigo do Whisky: ");
            scanf("%d", &wh,fflush(stdin));
            fflush(stdin);

            printf("\nNome do Whisky: ");
            scanf("%s", novo);

            strcpy(wh.nomeWhisky, novo);
            fflush(stdin);

            printf("\nIdade do Whisky: ");
            scanf("%d", &wh.idadeWhisky);
            fflush(stdin);

            printf("\nQuantidade em estoque: ");
            scanf("%d", &wh.quantidade);
            fflush(stdin);

            inserirWhisky(&lista, wh);
            char novo[] = "";
     }
    else if (option == 2){
            printf("\n Exibindo lista: \n");
            exibirWhisky(&lista);
     }
    else if(option == 3){
                printf("\n Busca sequencial: \n");
                printf("\nCodigo do produto: ");
                scanf("%d", &busca);
                fflush(stdin);
                buscaSequencial(&lista, busca);
     }
    else if(option == 4){
                printf("\n Busca binaria: \n");

                printf("\nCodigo do produto para busca: ");
                scanf("%d", &busca);
                fflush(stdin);
               exibirBusca(&lista, 0, lista.nroElem - 1, busca);

     }

    else if(option == 5){
            printf("\n Alterando estoque: \n");

            printf("\n Codigo do Whisky: ");
            scanf("%d", &busca);
            fflush(stdin);
            printf("\n Nova quantidade em estoque: ");
            scanf("%d", &estq);
            fflush(stdin);
            alterar(&lista, busca, estq);
     }

    else if(option == 6){
        printf("\n Excluindo");
        printf("\n Codigo do Whiky:\n ");
        scanf("%d", &exclui);
        fflush(stdin);
        excluirWhisky(&lista, exclui);
     }
    else if(option == 7){
        printf("Reinicializando");
        reinicializarLista(&lista);
     }
    else if(option == 8){
        printf("\nTotal de Whisky no sistema: %d\n",tamanhoLista(&lista));
    }
    else if(option == 0){
        exit (0);
    }
     else{
        printf("DIGITE A SUA OPCAO \n");
     }
    sistema();
    } while (option != 9);

    return 0;
}
