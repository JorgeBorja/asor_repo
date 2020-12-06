#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   
   uid_t id;

   id = getuid();

   return 0;
}
