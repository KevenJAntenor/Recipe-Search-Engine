#include "main.h"

int main(int argc, char *argv[]){
   verifier_arguments(argc,argv);
   return 0;
}

void verifier_arguments(int argc, char *argv[]){
   verifier_nb_arguments(argc);
}

void verifier_nb_arguments(int nb_arguments){
   if (nb_arguments != 3 && nb_arguments != 5) {
      stop(ARGS,MSG_ERR_NB_ARGS);
   }
}

