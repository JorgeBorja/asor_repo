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
   int fd, cerrojo;

   fd = open(argv[1], O_CREAT | O_WRONLY, 0777);

   if(fd == -1){
      perror("Error en open()");
      return 1;
   }

   cerrojo = lockf(fd, F_TLOCK, 0);

   if(cerrojo == -1){
      printf("El fichero esta bloqueado\n");

      return 0;
   }
   else{
      printf("Se ha bloqueado el fichero\n");

      time_t hora = time(NULL);
      struct tm* pt1 = localtime(&hora);
      char horaActual[255];

      strftime(horaActual, 255, "%A, %d de %B de %Y, %H:%I", pt1);

      write(fd, horaActual, strlen(horaActual));

      sleep(30);

      cerrojo = lockf(fd, F_ULOCK, 0);

      printf("Se ha desbloqueado el fichero\n");

   }

   close(fd);

   return 0;
}
