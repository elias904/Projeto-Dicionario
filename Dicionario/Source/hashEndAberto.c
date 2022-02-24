#include "../Headers/hashEndAberto.h"
#include <stdio.h>
#include <stdlib.h>

// inicializa tabela com valor de matricula = -1
void inicializarHEA(ListaHEA t[]) 
{
    for (int i = 0; i < M; i++)
       t[i].chave = -1;
}

void inserirHEA(int chave, ListaHEA t[])
{
    int indice = gerarHash(chave);
    while (t[indice].chave != -1)
    {
        indice = gerarHash(indice + 1);
    }
    t[indice].chave = chave;
}

void buscarHEA(int chave, ListaHEA t[])
{
    int indice = gerarHash(chave);
    while (t[indice].chave != -1)
    {
        if (t[indice].chave == chave)
        {
            printf("\nValor %d encontrado na posicao %d\n", chave, indice);
            return;
        }else{
            indice = gerarHash(indice + 1);
        }
    }
    printf("\nValor nao encontrado!");
}

void imprimirHEA(ListaHEA t[]){
    for (int i = 0; i < M; i++){
        if(t[i].chave != -1){
            printf("%d: %d\n", i, t[i].chave);
        }
    }
}

void semearHEA(ListaHEA t[]){
    for(int i = 0; i < 10000; i++){
        inserirHEA(rand() % 100000, t);
    }
}

void pesquisaAleatoriaHEA(ListaHEA t[]){
    for(int i = 0; i < 1000000; i++){
    buscarHEA(rand() % 100000, t);
    }
}

int gerarHash(int chave)
{
    return chave % M;
}
