#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
   pid_t id = fork();

   if(id == 0){ // Proceso hijo
      pid_t nid, pid, ppid, gid, sid;

      //sleep(3);

      nid = setsid(); // Creo sesión
      pid = getpid();
      ppid = getppid();
      gid = getpgid(id);
      sid = getsid(id);

      int cambio = chdir("/tmp");

      printf("Información del proceso HIJO\n");
      printf("Identificador de proceso: %d\n", pid);
      printf("Identificador de proceso padre: %d\n", ppid);
      printf("Identificador de grupo de procesos: %d\n", gid);
      printf("Identificador de sesión: %d\n", sid);
   }
   else{
      pid_t pid, ppid, gid, sid;

      sleep(3);

      pid = getpid();
      ppid = getppid();
      gid = getpgid(id);
      sid = getsid(id);

      printf("Información del proceso PADRE\n");
      printf("Identificador de proceso: %d\n", pid);
      printf("Identificador de proceso padre: %d\n", ppid);
      printf("Identificador de grupo de procesos: %d\n", gid);
      printf("Identificador de sesión: %d\n", sid);
   }


   return 0;
}
