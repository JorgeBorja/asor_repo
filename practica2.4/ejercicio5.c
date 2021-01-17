#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>


int main(int argc, char **argv){

   if(argc > 1){
      perror("Error. Hay que introducir 1 argumento\n");

      return -1;
   }

   int fd, fd2;

   fd = open("tuberia", O_RDONLY | O_NONBLOCK);

   if(fd == -1){
      perror("Error al abrir la tuberia\n");
      return -1;
   }

   fd2 = open("tuberia2", O_RDONLY | O_NONBLOCK);

   if(fd2 == -1){
      perror("Error al abrir la tuberia 2\n");
      return -1;
   }

   char buf[256];
   fd_set conjunto;
   int seleccionado = 0, actual, max, tubactual;

   while(seleccionado != -1){
      if (fd > fd2) {
         max = fd + 1;
      }
      else {
         max = fd2 + 1;
      }

      FD_ZERO(&conjunto);
      FD_SET(fd, &conjunto);
      FD_SET(fd2, &conjunto);

      seleccionado = select(max, &conjunto, NULL, NULL, NULL);


      if(seleccionado > 0){
         if(FD_ISSET(fd, &conjunto)){
            tubactual = 1;
            actual = fd;
         }
         else if(FD_ISSET(fd2, &conjunto)){
       	    tubactual = 2;
       	    actual = fd2;
         }


         ssize_t tam = 256;
    
         while(tam == 256){
            tam = read(actual, buf, 256);
            buf[tam] = '\0';
            printf("Tuberia %i: %s", tubactual, buf);
         }

         if(tubactual == 1){
            close(fd);
            fd = open("tuberia", O_RDONLY | O_NONBLOCK);
         }
         else if(tubactual == 2){
            close(fd2);
       	    fd2 = open("tuberia2", O_RDONLY | O_NONBLOCK);
         }

      }

   }

   close(fd);
   close(fd2);


   return 0;
}
