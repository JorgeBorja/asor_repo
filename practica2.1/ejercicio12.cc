#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <time.h>

int main(){
   
   time_t hora;

   hora = time(NULL);

   printf("%d \n", hora);

   return 0;
}
