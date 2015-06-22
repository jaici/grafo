#include "grafo_lib.h"

/** \brief  Retorna um novo grafo com vértices e nenhum arco,
 *          ou seja, inicializa o grafo com seu primeiro vertice.
 * \param   int V
 * \return  *Grafo
 *
 */
GrafoM* init(int vert)
{
    GrafoM* newGrafo = (GrafoM*) malloc(sizeof(GrafoM));
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

/** \brief  insere os vertices e suas arestas, ou seja, realiza ligacao entre dois vertices
 *  \param   GrafoM* grafo, int linha, int coluna
 */
void grafoInsert(GrafoM* grafo, int linha, int coluna)
{
    if(grafo->adj[linha][coluna]==0){
        grafo->adj[linha][coluna] = 1;
        grafo->aresta++;
    }
}

/** \brief  remove um vertice com sua aresta, ou seja, remove uma ligação entre dois vertives
 *  \param   GrafoM* grafo, int linha, int coluna
 */
void grafoRemove(GrafoM* grafo, int linha, int coluna)
{
    if(grafo->adj[linha][coluna]==1){
        grafo->adj[linha][coluna] = 0;
        grafo->aresta--;
    }
}
/** \brief  exibe os vertices e suas ligacoes com os outros vertices
 *  \param   GrafoM* grafo
 */
void grafoShow(GrafoM* grafo)
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
/** \brief  gera arquivo no formato para ser importado pelo programa graphviz.
 *  \param   GrafoM* grafo
 */
void geraArq(GrafoM* grafo)
{
    int col,lin;
    FILE* fp = fopen("graphviz.dot","w");
    fprintf(fp,"digraph G {\r\n");

    for(lin=0;lin<grafo->vertice; lin++){
        for(col=0;col<grafo->aresta; col++){
            if(grafo->adj[lin][col]==1){
                fprintf(fp," %2d -> %2d\r\n", lin,col);
            }
        }
    }
    fprintf(fp,"}");
}
/** \brief  liberar memória alocada
 *  \param  GrafoM* grafo
 */
void liberaMem(GrafoM* grafo, int tam)
{
    int i;
    for(i=0; i<tam; i++){       /**Questionar o professor sobre liberar memória*/
        free(grafo->adj[i]);
    }
    free(grafo);
}

/** \brief  Cria novo nó que liga dois vertices
 *  \param  int v2, No* n
 *  \return No*
 */
No* novoNo(int v2,No* prox)
{
    No* newNo = (No*) malloc(sizeof(No));
    newNo->vertice2 = v2;
    newNo->prox = prox;
    return newNo;
}
/** \brief  Inicializa grafo de lista
 *  \param  int v
 *  \return GrafoL*
 */
 /*
 GrafoL* grafoLinit(int v)
 {
    int c;
    GrafoL* newGrafo = (GrafoL*) malloc(sizeof(GrafoL));
    newGrafo->vertice = v;
    newGrafo->aresta = 0;
    newGrafo->adj = (No*) malloc(v*sizeof(No));
    for(c=0; c < v; c++){
        newGrafo->adj[c] = NULL;
    }
    return newGrafo;
 }

void grafoLInsert(GrafoL* grafo, int v1, int v2)
{
    No* a;
    for(a=grafo->adj[v1];a!= NULL; a=a->prox){
        if(a->vertice2 == v2) return;
    }
    grafo->adj[v1] = novoNo(v2,grafo->adj[v1]);
    grafo->aresta++;
}*/

void DIGRAPHbfs(GrafoM* G, int s)
{
    int v1, v2;
    conta = 0;
    for (v1 = 0; v1 < G->vertice; v1++)
        lbl[v1] = -1;
    filaInit( G->vertice);
    lbl[s] = conta++;
    filaPut(s);
    printf(" %d \n", s);
    while (!filaEmpty()) {
        v1 = filaGet();
        for (v2 = 0; v2 < G->vertice; v2++){
            if (G->adj[v1][v2] == 1 && lbl[v2] == -1) {
            printf(" %d ", v2);
                lbl[v2] = conta++;
                filaPut(v2);
            }
        }
        printf("\n");
    }
    filaFree();
}
