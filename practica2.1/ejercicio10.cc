#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

int main(){
   
   uid_t id, idE;
   struct passwd * pwd;

   id = getuid();
   idE = geteuid();

   pwd = getpwuid(id);

   printf("ID real del usuario: %d\n", id);
   printf("ID efectivo del usuario: %d\n", idE);

   printf("Nombre de usuario: %s\n", pwd->pw_name);
   printf("Directorio home: %s\n", pwd->pw_dir);
   printf("Descripcion del usuario: %s\n", pwd->pw_gecos);

   return 0;
}
