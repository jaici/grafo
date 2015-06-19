#include "grafo_lib.h"

int main()
{
    GrafoM* teste;

    teste = init(7);//inicia com numero máximo de grafo
    grafoInsert(teste,1,2);
    grafoInsert(teste,1,4);
    grafoInsert(teste,3,4);
    grafoInsert(teste,2,4);
    grafoInsert(teste,3,2);
    grafoInsert(teste,5,6);
    grafoShow(teste);
    geraArq(teste);
    return 0;
}
