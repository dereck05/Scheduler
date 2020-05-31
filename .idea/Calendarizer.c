#include <stdio.h>
#include "Calendarizer.h"
#include "Cola.h"




void FCFS(Calendar calendar){
    Process cola[calendar.numberProcess]; // arreglo de procesos
    Process finished[calendar.numberProcess]; // procesos que terminaron
    int cont = 0;
    Inicializar(cola);
    Inicializar(finished);
    while(cont< calendar.numberProcess){        //llenamos cola de procesos
        Process proceso;
        proceso.processNumber = cont+1;
        proceso.iteration = 1;
        proceso.lastTaylor = 1;
        proceso.result = 1;
        proceso.jobDone = 0;
        Push(proceso,cola);
        cont = cont+1;
    }

    while(cola != NULL){
        Process p = Pop(cola);      //saca proceso de cola

        if(p.jobDone <= calendar.job){ //si el trabajo hecho por el proceso es menor al maximo pedido
            long double x,sum,last;
            x = 1;
            last=p.lastTaylor;
            sum = p.result;
            int actual=(p.jobDone*50)+1;
            int limit = calendar.quantum*50+(p.jobDone*50);
            for(int i = actual;i <= limit;i++) //cede el control de acuerdo al quantum
            {
                last*=((x*x)*(2*i-1)*(2*i-1))/((2*i)*(2*i+1));
                sum+=last;
            }
            p.lastTaylor = last;
            p.result = sum;
            p.jobDone= p.jobDone+1;

            Push(p,cola);
            Pop(cola);
        }
        else{
            Push(p,finished);   // si el proceso termino su trabajo

        }


    }
    printResults(finished);



}