#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(){

   for(int i=0; i < 255; ++i){
	std::cout << i << " " << strerror(i) << std::endl;
   }

   return 0;
}
