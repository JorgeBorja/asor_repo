#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv){
   int fd, entrada;

   fd = open(argv[1], O_CREAT | O_WRONLY, 0777);

   if(fd == -1){
      perror("Error en open()");
      return 1;
   }

   entrada = dup2(fd, 1);

   if(entrada == -1){
      perror("Error en dup2()");
      return 1;
   }

   printf("La salida estandar ha sido modificada correctamente\n");
   printf("Saludos\n");
   close(fd);

   return 0;
}
