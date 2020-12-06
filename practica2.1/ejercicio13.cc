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
   struct timeval *tv;
   int v;
	int tiempo;

   for(int i=0; i < 1000000; ++i){
      v++;
   }

   tiempo = gettimeofday(tv, NULL);

   printf("%d \n", tv->tv_usec);

   return 0;
}
