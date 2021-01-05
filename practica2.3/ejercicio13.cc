#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

int stop = 0;

void handler(int n){
   if(n == SIGUSR1){
      stop = 1;
   }

}

int main(int argc, char *argv[]){

   if(argc < 2){
      perror("Error, hay que introducir un argumento");
      return -1;
   }

   int segundos = atoi(argv[1]);
   int i = 0;

   sigset_t mask;
   sigemptyset(&mask);
   sigaddset(&mask, SIGUSR1);
   sigprocmask(SIG_UNBLOCK, &mask, NULL);
   struct sigaction accion;

   sigaction(SIGUSR1, NULL, &accion);
   accion.sa_handler = handler;
   sigaction(SIGUSR1, &accion, NULL);


   while(i < segundos && stop == 0){
      i += 1;

      sleep(1);
   }

   if(stop == 0) {
      printf("Borrando el ejecutable...\n");
      unlink(argv[0]);
   }

   return 0;
}
