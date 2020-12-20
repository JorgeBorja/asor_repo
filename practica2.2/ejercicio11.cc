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
   struct stat st;
   char simbolico[200];
   char rigido[200];

   int func = stat(argv[1], &st);

   if((st.st_mode & S_IFMT) == S_IFREG){
      //Ponemos el nombre correcto y creamos el enlace simbolico
      strcpy(simbolico, argv[1]);
      strcat(simbolico, ".sym");

      int sym = symlink(argv[1], simbolico);

      if(sym == -1){
	  perror("Error en symlink()");
	  return 1;
      }

      //Ponemos el nombre correcto y creamos en enlace rigido
      strcpy(rigido, argv[1]);
      strcat(rigido, ".hard");

      int rig = link(argv[1], rigido);

      if(rig == -1){
	  perror("Error en link()");
	  return 1;
      }


   }

   return 0;
}
