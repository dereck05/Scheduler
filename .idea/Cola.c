#include <stdio.h>
#include "Cola.h"


int push;
int pop;

void Inicializar()
{
    push = 0;
    pop = -1;
}

void Push(Process p,Process cola[])
{
    if( push != pop ) // Cola llena
        cola[push] = p;

    if( pop == -1 )
        pop = push; // Ya hay elementos a extraer de la cola

    push = (push+1)%10;
}

Process Pop(Process cola[])
{
    Process toReturn  ; // Valor a devolver si la cola está vacía

    if( pop != -1 ) {
        toReturn = cola[pop];

        pop = (pop + 1) % 10;

        if (pop == push)
            pop = -1; // Si hemos extraido el último indicamos que está vacía
    }

    return toReturn;
}

void printResults(Process cola[]){
    int cont = 0;
    while(cola != NULL){
        Process p = Pop(cola);
        printf("Proceso %d :","%d\n",p.processNumber,p.result);

    }
}