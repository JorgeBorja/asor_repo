#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   
   uid_t id, idE;

   id = getuid();
   idE = geteuid();

   printf("ID real del usuario: %d\n", id);
   printf("ID efectivo del usuario: %d\n", idE);

   return 0;
}
