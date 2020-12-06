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

   char outstr[200];
   time_t hora;
   hora = time(NULL);

   struct tm* pt1;
   pt1 = localtime(&hora);

   strftime(outstr, sizeof(outstr), "%a, %d de %B de %G, %H:%M %n", pt1);

   printf(outstr);

   return 0;
}
