#ifndef GRAFO_LIB_H_INCLUDED
#define GRAFO_LIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct grafo Grafo;
/**< DEFINIÇÃO DAS ESTRUTURAS */
struct grafo{
    int vertice;
    int aresta;
    int **adj;
};

/**< DEFINIÇÃO DAS FUNÇÕES */
Grafo* init (int vert);
int** matrizInit(int linha, int coluna, int valor);
void grafoInsert(Grafo* grafo, int linha, int coluna);
void grafoRemove(Grafo* grafo, int linha, int coluna);
void grafoShow(Grafo* grafo);


#endif // GRAFO_LIB_H_INCLUDED
