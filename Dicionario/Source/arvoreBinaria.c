#include <stdio.h>
#include <stdlib.h>
#include "../Headers/arvoreBinaria.h"

void inserir_AB(Registro x, Apontador *p)
{
    if (*p == NULL)
    {
        *p = (Apontador)malloc(sizeof(NoAB));
        (*p)->registro = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
        return;
    }
    if (x.chave < (*p)->registro.chave)
    {
        inserir_AB(x, &(*p)->esq);
        return;
    }
    else if (x.chave > (*p)->registro.chave)
        inserir_AB(x, &(*p)->dir);
    else
    {
        return;
    }
}

void imprimir_AB(Apontador p)
{
    if (p != NULL)
    {
        imprimir_AB(p->esq);
        printf("%ld\n", p->registro.chave);
        imprimir_AB(p->dir);
    }
}

//Retorna o Indice da chave procurada procurada
void pesquisar_AB(Registro x, Apontador *p)
{
    if (*p == NULL)
    {
        printf("Erro : Registro nao esta presente na arvore\n");
        return;
    }
    if (x.chave < (*p)->registro.chave)
    {
        pesquisar_AB(x, &(*p)->esq);
    }
    else if (x.chave > (*p)->registro.chave)
        pesquisar_AB(x, &(*p)->dir);
    else
    {
        printf("Chave encontrada: %ld\n", (*p)->registro.chave);
    }
}

void inicializar_AB(Apontador *dicionario)
{
    *dicionario = NULL;
    //printf("%ld", (*dicionario)->registro.chave);
}

void remover_AB(Registro x, Apontador *p)
{
    Apontador aux;
    if (*p == NULL)
    {
        return;
    }
    else if (x.chave < (*p)->registro.chave)
    {
        remover_AB(x, &(*p)->esq);
        return;
    }
    else if (x.chave > (*p)->registro.chave)
    {
        remover_AB(x, &(*p)->dir);
        return;
    }
    else if ((*p)->dir == NULL)
    {
        aux = *p;
        *p = (*p)->esq;
        free(aux);
    }
    else if ((*p)->esq == NULL)
    {
        aux = *p;
        *p = (*p)->dir;
        free(aux);
    }
    else
    {
        antecessor(*p, &(*p)->esq);
    }
}

void antecessor(Apontador q, Apontador *r)
{
    if ((*r)->dir != NULL)
    {
        antecessor(q, &(*r)->dir);
        return;
    }
    else
    {
        q->registro = (*r)->registro;
        q = *r;
        *r = (*r)->esq;
        free(q);
    }
}

void semear_AB(Apontador *p)
{
    Registro x;
    for (int i = 0; i < 10000; i++)
    {
        x.chave = rand() % 100000;
        inserir_AB(x, p);
    }
}

void pesquisa_aleatoria_AB(Apontador *p){
    Registro x;
    for(int i = 0; i < 1000000; i++){
        x.chave = rand() % 100000;
        pesquisar_AB(x, p);
    }
}