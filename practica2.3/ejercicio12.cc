#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

volatile int intCont = 0;
volatile int stpCont = 0;

void handler(int n){
   if(n == SIGINT){
      intCont += 1;
   }

   if(n == SIGTSTP){
      stpCont += 1;
   }

}

int main(int argc, char *argv[]){

   struct sigaction action;

   sigaction(SIGINT, NULL, &action);
   action.sa_handler = handler;
   sigaction(SIGINT, &action, NULL);

   sigaction(SIGTSTP, NULL, &action);
   action.sa_handler = handler;
   sigaction(SIGTSTP, &action, NULL);

   sigset_t sig;
   sigemptyset(&sig);

   while(intCont + stpCont < 10){
      sigsuspend(&sig);
   }

   printf("Señales SIGINT: %d\n", intCont);
   printf("Señales SIGTSTP: %d\n", stpCont);

   return 0;
}
