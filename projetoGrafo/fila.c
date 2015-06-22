#include "fila.h"

void filaInit(int N)
{
    fila = (int*) malloc(N * sizeof(int));
    ini = fim = 0;
}
int filaEmpty(void)
{
    return ini == fim;
}
void filaPut(int v)
{
    fila[fim++] = v;
}
int filaGet(void)
{
    return fila[ini++];
}
void filaFree(void)
{
    free( fila);
}
