#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char *argv[]){
   
   sigset_t blk_set;

   sigemptyset(&blk_set);
   sigaddset(&blk_set, SIGINT);
   sigaddset(&blk_set, SIGTSTP);

   sigprocmask(SIG_BLOCK, &blk_set, NULL);

   //char *sleepsec = getenv("SLEEP_SECS");
   //int s = atoi(sleepsec);
   //sleep(s);
   sleep(5);

   sigset_t pendientes;
  
   sigpending(&pendientes);

   if(sigismember(&pendientes, SIGINT) == 1){
      printf("Se ha recibido la señal SIGINT\n");
   }

   if(sigismember(&pendientes, SIGTSTP) == 1){
      printf("Se ha recibido la señal SIGTSTP\n");

      sigprocmask(SIG_UNBLOCK, &blk_set, NULL);
   }

   printf("Exito\n");


   return 0;
}
