#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(){

   /*la diferencia entre st_mtime y st_ctime es que el primero es la ultima vez que ha sido modificado y el otro es el ultimo cambio de estado */

   struct stat st;

   int func = stat("ejercicio7.txt", &st);

   printf("Major number and minor number: (%li,%li)\n", major(st.st_dev), minor(st.st_dev));

   printf("i-node number: %i\n", st.st_ino);

   printf("File type: ");

   switch(st.st_mode & S_IFMT){
   case S_IFLNK: printf("Symlink\n"); break;
   case S_IFREG: printf("Regular file\n"); break;
   case S_IFDIR: printf("Directory\n"); break;
   default: printf("Other\n"); break;
   }

   printf("Last access: %s\n", ctime(&st.st_atime));

   return 0;
}
