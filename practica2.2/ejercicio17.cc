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
#include <dirent.h>

int main(int argc, char **argv){
   int fd, cerrojo;
   DIR *dir;
   struct dirent *entry;
   struct stat st;
   char ruta[PATH_MAX];
   int suma = 0;

   dir = opendir(argv[1]);

   if(dir == NULL){
      perror("La ruta del directorio no es valida\n");
      return 0;
   }

   while((entry = readdir(dir)) != NULL){
      lstat(entry->d_name, &st);

      switch(st.st_mode & S_IFMT){
      case S_IFREG: {
	 printf("%s", entry->d_name);
	 suma += st.st_size;
      } 
      break;
      case S_IFDIR: printf("%s/", entry->d_name); break;
      case S_IFLNK: {
	 readlink(entry->d_name, ruta, sizeof(ruta)-1);
	 printf("%s -> %s", entry->d_name, ruta);
	 suma += st.st_size;
      } break;
      default: printf("Other\n"); break;
      }

      if(access(entry->d_name, X_OK == 0)){
         printf("%s*\n", entry->d_name);
      }
      else{
	 printf("\n");
      }

   }

   closedir(dir);   

   printf("Tamaño total: %.2f KB\n", ((float)suma/1024));

   return 0;
}
