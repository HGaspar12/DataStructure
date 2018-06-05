#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DinamicWhisky1.h"

//Menu Escolha dos Procedimentos pelo Usuário
void menu(){
    printf("\n ******** Controle de Estoque de Whisky ********* \n");
    printf("\n Utilizando Lista Simplesmente Encadeada Dinamica \n");
    printf("\n *** Como Deseja Ordenar os Produtos? *** \n");
    printf("\n [1] - Ordenar por Idade \n");
    printf("\n [2] - Ordenar por Pais \n");
    printf("\n [3] - Ordenar por Quantidade \n");
}
//==== Inicializando a Lista ==============
void inicializarLista(LISTA *l){
    l->inicio=NULL;
}
//==== Exibir itens do Estoque ============
void exibirWhisky(LISTA *l){
    PONT aux = l->inicio;

    while(aux!=NULL){ //Enquanto não for vazio, vai exibir o estoque
        printf("\n Codigo: %i \n", aux->reg.cod);
        printf("\n Nome do Whisky: %s \n");
        printf("\n Preco de Venda: %.2lf \n",aux->reg.precoVenda);
        printf("\n Idade do Whisky: %i \n");
        printf("\n Pais de Origem: %s \n");
        printf("\n Quantidade em Estoque: %i \n");

        aux=aux->prox;
    }
}
//==== Inserindo Quantidade Ordenadamente ==========
void inserirQtd(LISTA *l, REGISTRO elem){
    PONT atual = NULL;//atriuido null pra nao alocar lixo
    PONT novo = NULL;
    PONT ant = NULL;
    novo = (PONT) malloc(sizeof(ELEMENTO)); //alocando memoria

    if(novo==NULL){
        printf("\n Nao inseriu \n");
    }

    novo->reg=elem;
    novo->prox=NULL;

    atual=l->inicio;

    while(atual!=NULL && atual->reg.quantidade<elem.quantidade){
        ant=atual;
        atual = atual->prox;
    }
    novo->prox=atual;

    if(ant==NULL){
        l->inicio=novo;
    }
    else{
        ant->prox=novo;
    }
}
//==== Inserindo Idade Ordenadamente =========
void inserirIdade(LISTA *l, REGISTRO elem){

    PONT atual = NULL;
    PONT novo = NULL;
    PONT ant = NULL;
    novo = (PONT) malloc(sizeof(ELEMENTO));

    if(novo==NULL){
        printf("\n Nao inseriu \n");
    }

    novo->reg=elem;
    novo->prox=NULL;

    atual=l->inicio;

    while(atual!=NULL && atual->reg.idadeWhisky<elem.idadeWhisky){
        ant=atual;
        atual = atual->prox;
    }
    novo->prox=atual;

    if(ant==NULL){
        l->inicio=novo;
    }
    else{
        ant->prox=novo;
    }
}
//==== Inserindo o País de Origem Ordenadamente
void inserirPais(LISTA *l, REGISTRO elem){

    PONT atual = NULL;
    PONT novo = NULL;
    PONT ant = NULL;
    novo = (PONT) malloc(sizeof(ELEMENTO));

    if(novo==NULL){
        printf("\n Nao inseriu \n");
    }

    novo->reg=elem;
    novo->prox=NULL;

    atual=l->inicio;

    while(atual!=NULL && strcmp(atual->reg.paisOrigem,elem.paisOrigem)<0){
        ant=atual;
        atual = atual->prox;
    }
    novo->prox=atual;

    if(ant==NULL){
        l->inicio=novo;
    }
    else{
        ant->prox=novo;
    }
}
// Buscando pelo codigo do Whisky
    PONT buscarCod(LISTA *l, int codBusca){

    PONT aux= l->inicio;

    while(aux!=NULL && aux->reg.cod<codBusca){
        aux=aux->prox;
    }
    if(aux!=NULL && aux->reg.cod==codBusca){
        return aux;
    }
    else{
        return NULL;
    }
}
//==== Excluir o Whisky pelo Codigo
void excluirWhisky(LISTA *l, int codExcluir){
    PONT atual= l->inicio;
    PONT ant=NULL;

    while(atual!=NULL && atual->reg.cod<codExcluir){
        ant = atual;
        atual = atual->prox;
    }
    if(atual==NULL){//se o codigo for invalido ele aparece mensagem de erro
        printf("\n Nao conseguiu excluir\n");
    }
    else{
        if(atual->reg.cod!=codExcluir){
        printf("\nO produto nao foi excluido pois seu codigo nao se encontra cadastrado no estoque\n");
    }
    else{
        if(ant==NULL){
            l->inicio=atual->prox;
        }
        else{
                ant->prox=atual->prox;
        }
        free(atual); //libera memoria
        printf("\n O Whisky com o codigo %d foi excluido \n", codExcluir);
    }
    }
}
//==== Reinicializando a lista ===============
void reinicializarLista(LISTA *l){
    PONT aux=l->inicio;

    while(aux!=NULL){
        l->inicio=l->inicio->prox;
        free(aux);
        aux=l->inicio;
    }
}
