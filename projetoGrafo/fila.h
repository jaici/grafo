#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int *fila,ini, fim;

void filaInit(int N);
int filaEmpty(void);
void filaPut(int v);
int filaGet(void);
void filaFree(void);
#endif // FILA_H_INCLUDED
