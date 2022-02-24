#ifndef HEA_H
#define HEA_H
#define M 19997

typedef struct {
    int chave;
} ListaHEA;

void inicializarHEA(ListaHEA t[]) ;
void inserirHEA(int chave, ListaHEA t[]);
void buscarHEA(int chave, ListaHEA t[]);
void imprimirHEA(ListaHEA t[]);
void semearHEA(ListaHEA t[]);
void pesquisaAleatoriaHEA(ListaHEA t[]);
int gerarHash(int chave);

#endif // !HEA_H