#ifndef DINAMICWHISKY1_H_INCLUDED
#define DINAMICWHISKY1_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct whisky{
    char nomeWhisky[50];
    double precoVenda;
    int idadeWhisky;
    char paisOrigem[50];
    int cod;
    int quantidade; //quantidade no estoque
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct whisky* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT inicio;
}LISTA;

//Protótipos ou chamadas das funções
void menu();
void inicializarLista(LISTA *l);
void exibirWhisky(LISTA *l);
void inserirQtd(LISTA *l, REGISTRO elem);
void inserirIdade(LISTA *l, REGISTRO elem);
void inserirPais(LISTA *l, REGISTRO elem);
PONT buscaCod(LISTA *l, int codBusca);
void excluirWhisky(LISTA *l, int codExcluir);
void reinicializarLista(LISTA *l);




#endif // DINAMICWHISKY1_H_INCLUDED
