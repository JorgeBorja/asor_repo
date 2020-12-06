#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   
   printf("ENLACES: %ld \n", pathconf("ejercicio6.cc", _PC_LINK_MAX));
   printf("RUTA: %ld \n", pathconf("ejercicio6.cc", _PC_PATH_MAX));
   printf("FICHERO: %ld \n", pathconf("ejercicio6.cc", _PC_NAME_MAX));

   return 0;
}
