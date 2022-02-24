#ifndef ARVORE_H
#define ARVORE_H

typedef long Chave;
typedef struct Registro
{
    Chave chave;
} Registro;
typedef struct No *Apontador;
typedef struct No
{
    Registro registro;
    Apontador esq, dir;
} NoAB;
typedef Apontador Dicionario;

//Cabeçalhos:
void antecessor(Apontador q, Apontador *r);
void inserir_AB(Registro x, Apontador *p);
void pesquisar_AB(Registro x, Apontador *p);
void inicializar_AB(Apontador *dicionario);
void remover_AB(Registro x, Apontador *p);
void imprimir_AB(Apontador p);
void semear_AB(Apontador *p);
void pesquisa_aleatoria_AB(Apontador *p);
//----------------------------------------
#endif