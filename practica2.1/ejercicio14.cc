#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>

int main(){
   
   time_t hora;
   hora = time(NULL);

   struct tm* pt1 = localtime(&hora);

   printf("%d \n", pt1->tm_year + 1900);

   return 0;
}
