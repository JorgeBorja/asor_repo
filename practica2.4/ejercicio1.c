#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){

   if(argc != 5){
      perror("Error. Hay que introducir 4 argumentos\n");

      return -1;
   }

   int fd[2];
   pid_t pid;

   if(pipe(fd) == -1){
      perror("Error en pipe");
      return -1;
   }

   pid = fork();

   if(pid == 0){
      close(fd[1]);
      dup2(fd[0], 0);
      close(fd[0]);

      execlp(argv[3], argv[3], argv[4], NULL);

   }
   else{
      close(fd[0]);
      dup2(fd[1], 1);
      close(fd[1]);

      execlp(argv[1], argv[1], argv[2], NULL);

   }


   return 0;
}
