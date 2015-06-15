#ifndef GRAFO_LIB_H_INCLUDED
#define GRAFO_LIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct grafo Grafo;
/**< DEFINI��O DAS ESTRUTURAS */
struct grafo{
    int vertice;
    int aresta;
    int **adj;
};

/**< DEFINI��O DAS FUN��ES */
Grafo* init (int vert);
int** matrizInit(int linha, int coluna, int valor);
void grafoInsert(Grafo* grafo, int linha, int coluna);
void grafoRemove(Grafo* grafo, int linha, int coluna);
void grafoShow(Grafo* grafo);


#endif // GRAFO_LIB_H_INCLUDED
