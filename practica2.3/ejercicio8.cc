#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
   
   if(argc < 2){
      perror("Numero de argumentos incorrecto");
      return -1;
   }

   pid_t id = fork();
   
   if(id == 0){ //Hijo
      pid_t pid, ppid;
      pid_t sid = setsid(); // Creo sesión

      sleep(3);

      pid = getpid();
      ppid = getppid();

      printf("Flujo del proceso hijo\n");
      printf("PID: %d\n", pid);
      printf("PPID: %d\n", ppid);

      int fd1 = open("/tmp/daemon.out", O_CREAT | O_RDWR, 0777);
      int fd2 = open("/tmp/daemon.err", O_CREAT | O_RDWR, 0777);
      int fd3 = open("/dev/null", O_CREAT | O_RDWR, 0777);

      dup2(fd1, 1);
      dup2(fd2, 2);
      dup2(fd3, 0);

      if(execvp(argv[1], &argv[1]) == -1){
         perror("Error en system");
         return -1;
      }

      close(fd1);
      close(fd2);
      close(fd3);

   }
   else{
      pid_t pid, ppid;

      printf("Flujo del proceso padre\n");
      printf("PID: %d\n", pid);
      printf("PPID: %d\n", ppid);
   }

   return 0;
}
