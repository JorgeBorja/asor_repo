#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char **argv){

   if(argc != 2){
      perror("Error. Hay que introducir 2 argumentos\n");

      return -1;
   }

   int fd;

   fd = open("tuberia", O_WRONLY);

   if(fd == -1){
      perror("Error al abrir la tuberia\n");
      return -1;
   }

   if(write(fd, argv[1], strlen(argv[1])) == -1){
      perror("Error en write()\n");
      return -1;
   }

   close(fd);


   return 0;
}
