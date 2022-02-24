#include "../Headers/hashListaEncad.h"
#include <stdio.h>
#include <stdlib.h>

void inicializa_lista_HLE(ListaHLE *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void inserir_lista_HLE(ListaHLE *l, int valor)
{
    No *novo = malloc(sizeof(No));
    novo->chave = valor;
    novo->proximo = l->inicio;
    l->inicio = novo;
}

int buscar_lista_HLE(ListaHLE *l, int valor)
{
    No *aux = l->inicio;
    while (aux && aux->chave != valor)
    {
        aux = aux->proximo;
    }
    if (aux)
    {
        return aux->chave;
    }
    else
    {
        return 0;
    }
}

int imprimir_lista_HLE(ListaHLE *l, int indice)
{
    No *aux = l->inicio;

    if (aux)
    {
        printf("%d : ", indice);
        while (aux)
        {
            printf("%d\t", aux->chave);
            aux = aux->proximo;
        }
        printf("\n");
    }
}

void inicializa_tabela_HLE(ListaHLE t[])
{
    for (int i = 0; i < M; i++)
    {
        inicializa_lista_HLE(&t[i]);
    }
}

void inserir_tabela_HLE(ListaHLE t[], int valor)
{
    int indice = gerarHashHLE(valor);
    inserir_lista_HLE(&t[indice], valor);
}

void buscar_tabela_HLE(ListaHLE t[], int valor)
{
    int indice = gerarHashHLE(valor);
    int chave = buscar_lista_HLE(&t[indice], valor);
    if (chave)
        printf("\nChave %d encontrada na posicao %d\n", chave, indice);
    else
        printf("Chave nao encontrada\n");
}

void imprimir_tabela_HLE(ListaHLE t[])
{
    for (int i = 0; i < M; i++)
    {
        imprimir_lista_HLE(&t[i], i);
    }
}

void semear_tabela_HLE(ListaHLE t[])
{
    for (int i = 0; i < 10000; i++)
    {
        inserir_tabela_HLE(t, rand() % 100000);
    }
}

void pesquisa_aleatoria_HLE(ListaHLE t[])
{
    for (int i = 0; i < 1000000; i++)
    {
        buscar_tabela_HLE(t, rand() % 100000);
    }
}

int gerarHashHLE(int chave)
{
    int indice = chave % M;
    return indice;
}