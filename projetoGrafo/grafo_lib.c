#include "grafo_lib.h"

/** \brief  Retorna um novo grafo com vértices e nenhum arco,
 *          ou seja, inicializa o grafo com seu primeiro vertice.
 * \param   int V
 * \return  *Grafo
 *
 */
Grafo* init(int vert)
{
    Grafo* newGrafo = (Grafo*) malloc(sizeof(Grafo));
    newGrafo->vertice = vert;
    newGrafo->aresta = 0;
    newGrafo->adj = matrizInit(vert, vert, 0);
    return newGrafo;
}

/** \brief  aloca espaço na memória para uma matriz com linha e coluna para cada elemento recebe o valor
 *
 * \param   int linha, int coluna, int valor
 * \return  int (matriz)
 *
 */
int **matrizInit(int linha, int coluna, int valor)
{
    int i,j;
    int** matriz = (int**) malloc(linha*sizeof(int));  /**< ALOCA MEMÓRIA PARA TODAS AS LINHAS DA MATRIZ */
    for(i=0;i<linha; i++){
        matriz[i]= (int*) malloc(coluna*sizeof(int));       /**< ALOCA MEMÓRIA PARA TODAS AS COLUNAS DA MATRIZ */
        for(j=0;j<coluna; j++){
            matriz[i][j] = valor;
        }
    }
    return matriz;
}

void grafoInsert(Grafo* grafo, int linha, int coluna)
{
    if(grafo->adj[linha][coluna]==0){
        grafo->adj[linha][coluna] = 1;
        grafo->aresta++;
    }
}

void grafoRemove(Grafo* grafo, int linha, int coluna)
{
    if(grafo->adj[linha][coluna]==1){
        grafo->adj[linha][coluna] = 0;
        grafo->aresta--;
    }
}

void grafoShow(Grafo* grafo)
{
    int col,lin;
    for(lin=0;lin<grafo->vertice; lin++){
        printf("%2d: ",lin);
        for(col=0;col<grafo->aresta; col++){
            if(grafo->adj[lin][col]==1){
                printf(" %2d", col);
            }
        }
        printf("\n");
    }
}
