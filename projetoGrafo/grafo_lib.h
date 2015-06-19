#ifndef GRAFO_LIB_H_INCLUDED
#define GRAFO_LIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct grafoM GrafoM;
/**< DEFINI��O DAS ESTRUTURAS */
struct grafoM{
    int vertice;
    int aresta;
    int **adj;
};

/**< DEFINI��O DAS FUN��ES */
GrafoM* init (int vert);
int** matrizInit(int linha, int coluna, int valor);
void grafoInsert(GrafoM* grafo, int linha, int coluna);
void grafoRemove(GrafoM* grafo, int linha, int coluna);
void grafoShow(GrafoM* grafo);
void geraArq(GrafoM* grafo);

#endif // GRAFO_LIB_H_INCLUDED
