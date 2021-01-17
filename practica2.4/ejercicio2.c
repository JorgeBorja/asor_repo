#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){

   if(argc > 1){
      perror("Error. Hay que introducir 1 argumento\n");

      return -1;
   }

   int p_h[2], h_p[2];
   pid_t pid;

   if(pipe(p_h) == -1){
      perror("Error al crear la tubería\n");
      return -1;
   }

   if(pipe(h_p) == -1){
      perror("Error al crear la tubería\n");
      return -1;
   }

   pid = fork();

   if(pid == 0){
      close(p_h[1]);
      close(h_p[0]);

      char mensajeRec[1000];
      char mensajeEnv[1];
      mensajeEnv[0] = 'l';

      int i = 0;
      while(i < 10){
         if(read(p_h[0], mensajeRec, sizeof(mensajeRec)) == -1){
            perror("Error en read()\n");
            return -1;
         }

         printf("Mensaje recibido por el hijo: %s\n", mensajeRec);
         sleep(1);

         if(i == 9){
            mensajeEnv[0] = 'q';
         }

         if(write(h_p[1], mensajeEnv, 1) == -1){
            perror("Error en write()\n");
            return -1;
         }

         i++;
      }


      close(p_h[0]);
      close(h_p[1]);

   }
   else{
      close(p_h[0]);
      close(h_p[1]);

      char mensajeRecibido[1], msg[1000];
      mensajeRecibido[0] = 'l';
      int bytes;

      while(mensajeRecibido[0] != 'q'){
         bytes = read(0, msg, sizeof(msg));
         if(bytes == -1){
            perror("Error en read()\n");
            return -1;
         }


         if(write(p_h[1], msg, bytes) == -1){
            perror("Error en write()\n");
            return -1;
         }


         if(read(h_p[0], mensajeRecibido, 1) == -1){
            perror("Error en read()");
            return -1;
         }
      }

      
      close(p_h[1]);
      close(h_p[0]);
   }


   return 0;
}
