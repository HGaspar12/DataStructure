#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StaticWhisky1.h" //importa a biblioteca.h

//======= Inicializando Lista =========================
void inicializarLista(LISTA *l){
    l->nroElem=0;
}
//======= Tamanho da Lista ============================
int tamanhoLista(LISTA *l){
    return (l->nroElem);
}
//======= Exibindo Wiskies ============================
void exibirWhisky(LISTA *l){
    int i;
    for(i=0; i<l->nroElem; i++){
            printf("Bebida %i\n", i+1);
            printf("\n Codigo: %d", i, l->W[i].cod);
            printf("\n Nome do Whisky: %s", i, l->W[i].nomeWhisky); //%s refere-se à string a ser printada
            printf("\n Idade do Whisky: %d", i, l->W[i].idadeWhisky);
            printf("\n Estoque: %d", i, l->W[i].quantidade);
    }
}
//====== Inserindo Whiskies ===========================
void inserirWhisky(LISTA *l, WHISKY wh){
    int j;
    if(l->nroElem >= MAX){ //se o numero de elementos forem maior que o maximo e imprime "lista cheia"
        printf("\n Lista Cheia");
        return;
    }
    for(j=l->nroElem; j>0 && wh.cod<l->W[j-1].cod; j--){
        l->W[j]=wh;
    }
    l->W[j]=wh;
    l->nroElem = l->nroElem+1;
}
//======================================================
void exibirBusca(LISTA *l, int esq, int dir, int code){
    int meio;

    if(l->nroElem == 0)
        printf("\nLista vazia !!\n");

    do
    {
        meio = (int) ((esq + dir) / 2);
        if (l->W[meio].cod > code)
            dir = meio - 1;

        else if (l->W[meio].cod < code)
            esq = meio + 1;

        else{
            printf("Bebida %i \n", meio+1);

            printf("\n (%d) Codigo: %d", meio, l->W[meio].cod);
            printf("\n (%d) Nome whisky: %s", meio,l->W[meio].nomeWhisky);
            printf("\n (%d) Idade: %d", meio,l->W[meio].idadeWhisky);
            printf("\n (%d) Estoque: %d\n\n",meio, l->W[meio].quantidade);
            return;
        }
    }while(esq < l->nroElem && dir >= 0 && esq <= dir);

    printf("\nBebida nao esta na lista\n");
}


//===== Exibindo Busca ================================
int buscaBin(LISTA *l, int esq, int dir, int code){
    int meio;
    if(l->nroElem == 0){
        INVALIDO;
    }

    do{
        meio = (int) ((esq + dir) / 2);
        if (l->W[meio].cod > code)
            dir = meio - 1;

        else if (l->W[meio].cod < code)
            esq = meio + 1;

        else
            return(meio);
    }while(esq < l->nroElem && dir >= 0 && esq <= dir);
    INVALIDO;
}
//===== Busca Sequencial ===============================
int buscaSequencial(LISTA *l, int busca){
    int i;

    if(l->nroElem == 0){
        INVALIDO;
    }

    for(i=0; i<l->nroElem && busca!= l->W[i].cod && busca >l->W[i].cod; i++);

    printf("Bebida %i \n", busca+1);
    printf("\n (%d) Codigo: %d", busca, l->W[i].cod);
    printf("\n (%d) Nome do Whisky: %s", busca,l->W[i].nomeWhisky);
    printf("\n (%d) Idade do Whisky: %d", busca,l->W[i].idadeWhisky);
    printf("\n (%d) Estoque: %d\n\n",busca, l->W[i].quantidade);

    if(i<l->nroElem && busca == l->W[i].cod){
        return (i);
    }

    else INVALIDO;
}
//====== Excluindo Whisky ===============================================
void excluirWhisky(LISTA *l, int excluir){
    int pos = buscaSequencial(l, excluir);

    if (pos == -1){
        printf ("Whisky nao Excluido");
    }
    else{
        for(pos = 0; pos+1<l->nroElem; pos++);
            l->W[pos]=l->W[pos+1];
            l->nroElem= l->nroElem-1;
    printf ("Whisky Excluido", excluir);
    }
}
//====== Alterando ==================================
void alterar(LISTA *l, int ind , int estq){
    int i = buscaBin(l, 0, l->nroElem - 1, ind);

    if (i == -1){
        printf("\n Elemento nao esta na lista"); //como é invalido ira retornar a lista vazia
    }
    else{
        l->W[i].quantidade = estq;
        printf("\n Numero do estoque do cod %d alterado\n", ind);
    }
}
//====== Reinicializando a Lista ===========================
void reinicializarLista(LISTA *l){
    l->nroElem = 0;
}
