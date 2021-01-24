#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


int main(int argc, char **argv){

   if(argc != 3){
      perror("Error, hay que introducir 3 argumentos\n");
      return -1;
   }

   struct addrinfo *res, *rp;
   int bytes, enviados, error;
   char buffer[2] = "";
   struct sockaddr_storage dirHost;

   memset(&hints, 0, sizeof(struct addrinfo));

   hints.ai_flags = AI_PASSIVE;
   hints.ai_family = AF_UNSPEC;
   hints.ai_socktype = SOCK_DGRAM;

   hints.ai_protocol = 0;
   hints.ai_canonname = NULL;
   hints.ai_addr = NULL;
   hints.ai_next = NULL;


   if (getaddrinfo(argv[1], argv[2], &hints, &res) != 0) {
      perror("Error en getaddrinfo()\n");
      return -1;
   }

   for (rp = res; rp != NULL; rp = rp->ai_next){

       sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
       if (sd == -1) {
           perror("Error en socket()\n");
           continue;
       }
        
       error = bind(sd, rp->ai_addr, rp->ai_addrlen);
       if (error == 0) {
           break;
       }
        
       close(sd);        
   }

   if (rp == NULL) {
       perror("Error\n");
       return -1;
   }
    
   freeaddrinfo(res);


   while(buffer[0] != 'q'){
        bytes = recvfrom(sd, buffer, sizeof(buffer), 0, (struct sockaddr *) &dirHost, &dirHostLength);
        if (bytes == -1) {
            continue;
        }
        
        error = getnameinfo((struct sockaddr *) &dirHost, dirHostLength, host, NI_MAXHOST, port, NI_MAXSERV, NI_NUMERICHOST);
        if (error != 0) {
            perror("Error en getnameinfo()\n");
            return -1;
        }

        printf("%d bytes recibidos %s:%s\n", bytes, host, port);

        if (buffer[0] == 't' || buffer[0] == 'd') {

                
            strftime(envio, MAX_ENVIO, "%I:%M:%S %p", valor);                
            
            enviados = sendto(sd, envio, strlen(envio), 0, (struct sockaddr *) &dirHost, dirHostLength);
            
        }
        else if (buffer[0] == 'q')
        {
            printf("Finalizando el proceso\n");
            break;
        }
        
    }

    close(sd);


   return 0;
}
