#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv){

   if(argc != 2){
      perror("Error, hay que introducir 2 argumentos\n");
      return -1;
   }

   char hbuf[1025], sbuf[32];

   struct addrinfo *res, *rp;

   if(getaddrinfo(argv[1], NULL, NULL, &res) != 0){
      perror("Error en getaddrinfo()\n");
      return -1;
   }

   for(rp = res; rp != NULL; rp = rp->ai_next){  
      if(getnameinfo(rp->ai_addr, rp->ai_addrlen, hbuf, sizeof(hbuf), sbuf, sizeof(sbuf), NI_NUMERICHOST) == 0){
         printf("%s\t", hbuf); 
         printf("%d\t", rp->ai_family);
         printf("%d\n", rp->ai_socktype);
      }
      else{
         perror("Error getnameinfo");
      }
   }

   return 0;
}
