#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

   mode_t mascara = umask(0027);

   int fd = open("ejercicio7.txt", O_RDWR | O_CREAT | O_TRUNC, 0645);

   return 0;
}
