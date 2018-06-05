#ifndef STATICWHISKY1_H_INCLUDED
#define STATICWHISKY1_H_INCLUDED
#define MAX 100
#define INVALIDO -1;

typedef int TIPOCHAVE;

typedef struct{ //struct que guarda os registros do programa
    TIPOCHAVE cod;
    char nomeWhisky[50];
    int idadeWhisky;
    int quantidade;
}WHISKY;

typedef struct{
    WHISKY W[MAX];
    int nroElem;
}LISTA;

//Protótipos ou chamadas das funções

void inicializarLista(LISTA *l);
int tamanhoLista(LISTA *l);
void exibirWhisky(LISTA *l);
void inserirWhisky(LISTA *l, WHISKY wh);
int buscaBin(LISTA *l, int esq, int dir, int cod);
int buscaSequencial(LISTA *l, int busca);
void excluirWhisky(LISTA *l, int excluir);
void reinicializarLista(LISTA *l);
void alterar(LISTA *l, int ch, int estq);


#endif // STATICWHISKY1_H_INCLUDED
