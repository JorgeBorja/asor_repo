#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
   
   //Con system, el argumento debe ir con comillas para que la implementacion sea sencilla
   //Solo se debe introducir un argumento, si se introducen más, no los tiene en cuenta
   if(argc < 2){
      perror("Numero de argumentos incorrecto");
      return -1;
   }


   if(system(argv[1]) == -1){
      perror("Error en system");
      return -1;
   }

   printf("EL comando terminó de ejecutarse\n");


   return 0;
}
