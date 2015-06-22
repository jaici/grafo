#ifndef GRAFO_LIB_H_INCLUDED
#define GRAFO_LIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct grafoM GrafoM;
typedef struct grafoL GrafoL;
typedef struct no No;

#define maxV 1000
int conta, lbl[maxV];

/**< DEFINIÇÃO DAS ESTRUTURAS */
struct grafoM{
    int vertice;
    int aresta;
    int **adj;
};

struct grafoL{
    int vertice;
    int aresta;
    No *adj;
};

struct no {
    int vertice2;
    No *prox;
};


/**< DEFINICAO DAS FUNCOES USANDO MATRIZ*/
GrafoM* init (int vert);
int** matrizInit(int linha, int coluna, int valor);
void grafoInsert(GrafoM* grafo, int linha, int coluna);
void grafoRemove(GrafoM* grafo, int linha, int coluna);
void grafoShow(GrafoM* grafo);
void geraArq(GrafoM* grafo);
void liberaMem(GrafoM* grafo, int tam);
/**< DEFINICAO DAS FUNCOES USANDO LISTA */
/*No* novoNo(int v2,No* prox);
GrafoL* grafoLinit(int v);
void grafoLInsert(GrafoL* grafo, int v1, int v2);
*/

void DIGRAPHbfs(GrafoM* G, int s);
#endif // GRAFO_LIB_H_INCLUDED
