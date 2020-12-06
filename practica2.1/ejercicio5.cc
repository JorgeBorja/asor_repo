//#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main(int argc, char **argv){

   struct utsname buf;

   int error;

   error = uname(&buf);

   if(error == -1){
      perror("UNAME");

      return -1;
   }
   
   printf("SYSNAME: %s\n", buf.sysname);
   printf("NODENAME: %s\n", buf.nodename);
   printf("RELEASE: %s\n", buf.release);
   printf("VERSION: %s\n", buf.version);
   printf("MACHINE: %s\n", buf.machine);

   return 0;
}
