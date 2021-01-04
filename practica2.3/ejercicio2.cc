#include <sched.h>
#include <stdio.h>

int main(){
   int politica, pmax, pmin;
   struct sched_param st;


   politica = sched_getscheduler(0);

   switch(politica){
   case SCHED_OTHER: {
      printf("Política del proceso actual: SCHED_OTHER\n");
   }
   break;
   case SCHED_FIFO: {
      printf("Política del proceso actual: SCHED_FIFO\n");
   }
   break;
   case SCHED_RR: {
      printf("Política del proceso actual: SCHED_RR\n");
   }
   break;
   default: {
      printf("Otra política\n");
   }

   }


   if(sched_getparam(0, &st) == -1){
      perror("Error");
   }

   printf("Prioridad del proceso actual: %d\n", st.sched_priority);


   pmax = sched_get_priority_max(politica);
   printf("Valor máximo de la prioridad: %d\n", pmax);

   pmin = sched_get_priority_min(politica);
   printf("Valor minimo de la prioridad: %d\n", pmin);

   return 0;
}
