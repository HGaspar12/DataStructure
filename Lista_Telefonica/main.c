// Trabalho de implementação de uma Lista Estática Sequencial, em uma LISTA TELEFÔNICA
//Aluno: Henrique Gaspar ra:120143

#include <stdlib.h>
#include <stdio.h>
#include "lista_linear_sequencial.h"

int main(){
  LISTA l;
  REGISTRO r;

  inicializar_lista(&l);

  r.NOME = "Tamara";
  r.TELEFONE = "3302-7101";
  r.ENDERECO = "Rua dos Professores";
  inserir_ElemLista(&l, r);

  r.NOME = "Henrique";
  r.TELEFONE = "4002-8922";
  r.ENDERECO = "Rua dos Universitários";
  inserir_ElemLista(&l, r);

  r.NOME = "Della Mura";
  r.TELEFONE = "1010-1597";
  r.ENDERECO = "Rua dos Muros";
  inserir_ElemLista(&l, r);

  r.NOME = "Steve Jobs(empregos)";
  r.TELEFONE = "7576-1315";
  r.ENDERECO = "Ceu";
  inserir_ElemLista(&l, r);

  r.NOME = "Bill Gates";
  r.TELEFONE= "4685-8256";
  r.ENDERECO = "Rua dos Portoes";
  inserir_ElemLista(&l, r);

  printf("Não Ordenado:");
  exibir_Lista(&l);
  ordenar_Nomes(&l);
  printf("\nOrdenado:");
  exibir_Lista(&l);


  return 0;
}
