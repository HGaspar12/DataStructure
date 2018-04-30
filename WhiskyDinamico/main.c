#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "WhiskyDinamico.h"

int main(){

    LISTA lista;
    REGISTRO elem;

    PONT aux = NULL;
    int option=0;


    inicializarLista(&lista);
/*
    elem.cod = 1;
    strcpy(elem.nomeWhisky , "Jack Daniels");
    strcpy(elem.paisOrigem, "Estados Unidos");
    elem.idadeWhisky = 12;
    elem.quantidade = 3;
    inserirQtd(&lista, elem);
    exibirWhisky(&lista);

    elem.cod = 2;
    strcpy(elem.nomeWhisky , "Jack Daniels Honey");
    elem.idadeWhisky = 5;
    elem.quantidade = 4;
    inserirQtd(&lista, elem);
    inserirIdade(&lista, elem);

    elem.cod = 3;
    strcpy(elem.nomeWhisky , "Red Label");
    elem.idadeWhisky = 5;
    elem.quantidade = 8;
    inserirQtd(&lista, elem);

    elem.cod = 4;
    strcpy(elem.nomeWhisky , "Buchanans");
    elem.idadeWhisky = 10;
    elem.quantidade = 8;
    inserirQtd(&lista, elem);
*/

    menu();
    scanf("%i", &option);


    elem = (const REGISTRO){"Johnnie Walker",1500.00,25,"Inglaterra",1,5};
    if(option==1)inserirIdade(&lista, elem);

    else if(option==2){
        inserirQtd(&lista, elem);
    }
    else if(option==3){
        inserirPais(&lista, elem);
    }


    elem = (const REGISTRO){"Jack Daniels",150.00,5,"Estados Unidos",5,15};
    if(option==1){
        inserirIdade(&lista, elem);
    }
    else if(option==2){
        inserirQtd(&lista, elem);
    }
    else if(option==3){
        inserirPais(&lista, elem);
    }

    system("cls");
    if(option==1) puts("Estoque ordenado por Idade:\n");
    else if(option==2) puts("Estoque ordenado por Quantidade no estoque:\n");
    else if(option==3) puts("Estoque ordenado por Pais:\n");
    exibirWhisky(&lista);

puts("-------------------------------------------------------------------------------------------------------------\n");
aux = buscarCod(&lista, elem.cod);

if(buscarCod(&lista, elem.cod)!=NULL){
    printf("Busca por codigo:\n\nO elemento esta na lista:\n\n");
    printf("Nome:%s - Preco de venda:%.2lf - Idade:%i - Pais:%s - Codigo:%i - Quantidade em estoque:%i\n\n", aux->reg.nomeWhisky,aux->reg.precoVenda,aux->reg.idadeWhisky,aux->reg.paisOrigem,aux->reg.cod,aux->reg.quantidade);
}
else{
    printf("O elemento %d nao esta na lista\n", elem.cod);
}

puts("-------------------------------------------------------------------------------------------------------------\n");
printf("Exclusao por codigo:\n\n");
excluirWhisky(&lista, elem.cod=5);

puts("-------------------------------------------------------------------------------------------------------------\n");
printf("Reexibicao do estoque:\n\n");
if(option==1) puts("Estoque ordenado por Idade:\n");
else if(option==2) puts("Estoque ordenado por Quantidade no estoque:\n");
else if(option==3) puts("Estoque ordenado por Pais:\n");
exibirWhisky(&lista);

reinicializarLista(&lista);
return 0;
}

