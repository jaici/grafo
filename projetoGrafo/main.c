#include "grafo_lib.h"
#define SIZE 10
int main()
{
    GrafoM* testeMatriz;
    testeMatriz = init(SIZE);//inicia com numero máximo de grafo
    grafoInsert(testeMatriz,0,1);
    grafoInsert(testeMatriz,1,2);
    grafoInsert(testeMatriz,1,4);
    grafoInsert(testeMatriz,2,3);
    grafoInsert(testeMatriz,2,4);
    grafoInsert(testeMatriz,2,9);
    grafoInsert(testeMatriz,3,4);
    grafoInsert(testeMatriz,4,5);
    grafoInsert(testeMatriz,4,6);
    grafoInsert(testeMatriz,4,7);
    grafoInsert(testeMatriz,5,6);
    grafoInsert(testeMatriz,7,8);
    grafoInsert(testeMatriz,7,9);
    grafoShow(testeMatriz);
    geraArq(testeMatriz);
printf("\n###################\nBusca de profundidade\n#####################\n");
    DIGRAPHbfs(testeMatriz,0);

    liberaMem(testeMatriz,SIZE);

    /**NÃO ESTÁ FUNCIONANDO LISTA ENCADEADA*/
    return 0;
}
