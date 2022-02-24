#ifndef HLE_H
#define HLE_H
#define M 19997

typedef struct no
{
    int chave;
    struct no *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} ListaHLE;

void inicializa_lista_HLE(ListaHLE *l);
void inserir_lista_HLE(ListaHLE *l, int valor);
int buscar_lista_HLE(ListaHLE *l, int valor);
int imprimir_lista_HLE(ListaHLE *l, int indice);
void inicializa_tabela_HLE(ListaHLE t[]);
void inserir_tabela_HLE(ListaHLE t[], int valor);
void buscar_tabela_HLE(ListaHLE t[], int valor);
void imprimir_tabela_HLE(ListaHLE t[]);
void semear_tabela_HLE(ListaHLE t[]);
void pesquisa_aleatoria_HLE(ListaHLE t[]);
int gerarHashHLE(int chave);

#endif // !HLE_H