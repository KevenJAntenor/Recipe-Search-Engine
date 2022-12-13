#include "erreur.h"

void stop(enum codes code, char message[]){
   fprintf(stderr,"%s\n",message);
   exit(code);
}
