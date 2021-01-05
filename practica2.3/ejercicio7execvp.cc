#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
   
   //Los argumentos se deben introducir sin comillas
   if(argc < 2){
      perror("Numero de argumentos incorrecto");
      return -1;
   }


   if(execvp(argv[1], &argv[1]) == -1){
      perror("Error en execvp\n");
      return -1;
   }

   printf("El comando terminó de ejecutarse\n");


   return 0;
}
