#include <stdio.h>
#include "Calendarizer.h"
#include "Cola.h"




void FCFS(Calendar calendar){
    Process cola[calendar.numberProcess]; // arreglo de procesos
    int cont = 0;
    Inicializar(cola);
    while(cont< calendar.numberProcess){        //llenamos cola de procesos
        Process proceso;
        proceso.processNumber = cont+1;
        Push(proceso,cola);
        cont = cont+1;

    }





}