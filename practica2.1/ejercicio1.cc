#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
   int error;

   error = setuid(0);

   if(error == -1){
      perror("setuid");
   }

   return 1;
}
