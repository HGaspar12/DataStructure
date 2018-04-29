typedef struct{
  char* TELEFONE; //Aqui eu utilizo ponteiro pra char para tornar
  char* NOME;  //o tamanho de cada item de tamanho qualquer
  char* ENDERECO;
}REGISTRO;

typedef struct{
  REGISTRO A[50];
  int nroElem;
}LISTA;


void inicializar_lista(LISTA *l);
int tamanho(LISTA *l);
void exibir_Lista(LISTA *l);
int inserir_ElemLista(LISTA *l, REGISTRO a);
int busca_Sequencial(LISTA *l, char* c);
_Bool excluir_ElemLista(LISTA *l, char* c);
void atualizar_Lista(LISTA* l);
void ordenar_Nomes(LISTA* l);
