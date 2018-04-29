#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "lista_linear_sequencial.h"

void inicializar_lista(LISTA *l){
  l->nroElem = 0;
}

int tamanho(LISTA *l){
  return l->nroElem;
}

void exibir_Lista(LISTA *l){
  for(int i=0; i < l->nroElem; i++){
    printf("Lista Telefônica");
    printf("Nome:%s | ", l->A[i].NOME);
    printf("Telefone:%s | ", l->A[i].TELEFONE);
    printf("Endereco:%s\n", l->A[i].ENDERECO);
  }
}

int inserir_ElemLista(LISTA *l, REGISTRO a){
  if(l->nroElem == 50){
    return -1;
  }

  l->A[l->nroElem] = a;
  l->nroElem = l->nroElem+1;
}


int busca_Sequencial()LISTA *l, char* c){
    int i = 0;
    while(i < l->nroElem){
        if(strcmp(c, l->A[i].NOME) == 0 || strcmp(c, l->A[i].TELEFONE) == 0 || strcmp(c, l->A[i].ENDERECO) == 0){
            printf("Nome:%s | ", l->A[i].NOME);
            printf("Telefone:%s | ", l->A[i].TELEFONE);
            printf("Endereco:%s\n", l->A[i].ENDERECO);
            return i;
        }
        else i++;
    }
    return -1;
}

bool excluir_ElemLista(LISTA *l, char* c){
    int pos, j;
    pos = busca_Sequencial(l, c);

    if(pos == -1) return false;

    for(j = pos; j < l->nroElem-1; j++){
        l->A[j] = l->A[j+1];
    }

     l->nroElem--;
     return true;
}

void ordenar_Nomes(LISTA* l){//recursao ´para ordenar os itens sejam ordenados
    REGISTRO aux;
    for (int x = 0; x < l->nroElem-1; x++){
        if(strncmp(l->A[x].NOME, l->A[x+1].NOME, 1) > 0){
            aux = l->A[x];
            l->A[x] = l->A[x+1];
            l->A[x+1] = aux;

            ordenar_Nomes(l);
        }
    }
}

void atualizar_Lista(LISTA* l){
    l->nroElem = 0;
}
