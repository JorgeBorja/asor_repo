#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
   pid_t id, pid, gid, sid;
   struct rlimit rlim;
   char dir[100];

   id = getpid();
   pid = getppid();
   gid = getpgid(id);
   sid = getsid(id);

   if(getrlimit(RLIMIT_NOFILE, &rlim) == -1){
      perror("Error en getrlimit");
   }

   if(getcwd(dir, 1000) == NULL){
      perror("Error en getcwd");
   }

   printf("Identificador de proceso: %d\n", id);
   printf("Identificador de proceso padre: %d\n", pid);
   printf("Identificador de grupo de procesos: %d\n", gid);
   printf("Identificador de sesión: %d\n", sid);
   printf("Número máximo de ficheros que puede abrir el proceso: %d\n", rlim.rlim_max);
   printf("Directorio de trabajo actual: %s\n", dir);


   return 0;
}
