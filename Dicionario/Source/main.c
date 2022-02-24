#include <stdio.h>
#include <time.h>
#include "../Headers/hashEndAberto.h"
#include "../Headers/hashListaEncad.h"
#include "../Headers/arvoreBinaria.h"

void MenuArvoreBinaria();
void MenuHashListaEncad();
void MenuHashEndAberto();

clock_t t;

int main()
{
    int op;

    do
    {
        printf("Escolha um tipo de Dicionario:\n");
        printf("1 - Arvore Binaria\n");
        printf("2 - Hash com solucao de colisao por listas lineares\n");
        printf("3 - Hash com sulucao de colisao por enderecamento aberto\n");
        printf("0 - Sair");
        printf("\n\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("Saindo...");
            break;
        case 1:
            MenuArvoreBinaria();
            break;
        case 2:
            MenuHashListaEncad();
            break;
        case 3:
            MenuHashEndAberto();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }

    } while (op);
    return 0;
}

void MenuHashListaEncad()
{
    int op, chave;
    ListaHLE tabelaHLE[M];
    inicializa_tabela_HLE(tabelaHLE);

    do
    {
        printf("\n1 - Popular Tabela\n");
        printf("2 - Pesquisar\n");
        printf("3 - Imprimir\n");
        printf("4 - Fazer 1 milhao pesquisas aleatorias\n");
        printf("0 - Voltar\n");
        printf("\n\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            /* code */
            break;
        case 1:
            t = clock();
            semear_tabela_HLE(tabelaHLE);
            t = clock() - t;
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            break;
        case 2:
            printf("\nDigite o valor que deseja pesquisar: ");
            scanf("%d", &chave);
            t = clock();
            buscar_tabela_HLE(tabelaHLE, chave);
            t = clock() - t;
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            break;
        case 3:
            t = clock();
            imprimir_tabela_HLE(tabelaHLE);
            t = clock() - t;
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            break;
        case 4:
            t = clock();
            pesquisa_aleatoria_HLE(tabelaHLE);
            t = (clock() - t);
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            printf("tempo medio de execucao: %lfms\n", (((double)t) / (CLOCKS_PER_SEC / 1000)) / 1000000);
            break;
        default:
            break;
        }
    } while (op);
}

void MenuHashEndAberto()
{
    int op, chave;
    ListaHEA tabelaHEA[M];
    inicializarHEA(tabelaHEA);

    do
    {
        printf("\n1 - Popular Tabela\n");
        printf("2 - Pesquisar\n");
        printf("3 - Imprimir\n");
        printf("4 - Fazer 1 milhao pesquisas aleatorias\n");
        printf("0 - Voltar\n");
        printf("\n\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            /* code */
            break;
        case 1:
            t = clock();
            semearHEA(tabelaHEA);
            t = clock() - t;
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            break;
        case 2:
            printf("\nDigite o valor que deseja pesquisar: ");
            scanf("%d", &chave);
            t = clock();
            buscarHEA(chave, tabelaHEA);
            t = clock() - t;
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            break;
        case 3:
            t = clock();
            imprimirHEA(tabelaHEA);
            t = clock() - t;
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            break;
        case 4:
            t = clock();
            pesquisaAleatoriaHEA(tabelaHEA);
            t = (clock() - t);
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            printf("tempo medio de execucao: %lfms\n", (((double)t) / (CLOCKS_PER_SEC / 1000)) / 1000000);
            break;
        default:
            break;
        }
    } while (op);
}
void MenuArvoreBinaria()
{
    int op;
    Registro x;
    Dicionario tabelaAB;
    inicializar_AB(&tabelaAB);

    do
    {
        printf("\n1 - Popular Tabela\n");
        printf("2 - Pesquisar\n");
        printf("3 - Imprimir\n");
        printf("4 - Fazer 1 milhao pesquisas aleatorias\n");
        printf("5 - Remover\n");
        printf("0 - Voltar\n");
        printf("\n\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            /* code */
            break;
        case 1:
            t = clock();
            semear_AB(&tabelaAB);
            t = clock() - t;
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            break;
        case 2:
            printf("\nDigite o valor que deseja pesquisar: ");
            scanf("%ld", &x.chave);
            t = clock();
            pesquisar_AB(x, &tabelaAB);
            t = clock() - t;
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            break;
        case 3:
            t = clock();
            imprimir_AB(tabelaAB);
            t = clock() - t;
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            break;
        case 4:
            t = clock();
            pesquisa_aleatoria_AB(&tabelaAB);
            t = (clock() - t);
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            printf("tempo medio de execucao: %lfms\n", (((double)t) / (CLOCKS_PER_SEC / 1000)) / 1000000);
            break;
        case 5:
            printf("\nDigite o valor que deseja remover: ");
            scanf("%ld", &x.chave);
            t = clock();
            remover_AB(x, &tabelaAB);
            t = (clock() - t);
            printf("tempo de execucao: %lfms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
            break;
        default:
            break;
        }
    } while (op);
}