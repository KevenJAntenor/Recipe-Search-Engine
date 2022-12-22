#include "main.h"

int main(int argc, char *argv[]){
   verifier_arguments(argc,argv);
   struct liste_categories *categories = lire_fichier(argv[1]);
   printf("%d\n",categories->nb_categories);
   return 0;
}

void verifier_arguments(int argc, char *argv[]){
   verifier_nb_arguments(argc);
   verifier_fichier_banque(argv[1]);
   if (argc == 4){
      verifier_options(argv);
   }
}

void verifier_nb_arguments(int nb_arguments){
   if (nb_arguments != 2 && nb_arguments != 4) {
      stop(ARGS,MSG_ERR_NB_ARGS);
   }
}

void verifier_fichier_banque(char nom_fichier_banque[]) {
   if(!est_fichier(nom_fichier_banque)){
      stop(FICHIER,MSG_FICHIER_INVALIDE) ;
   }
}

void verifier_options(char *arguments[]){
   if (strcmp(arguments[2],"-S") != 0){
      stop(ARGS,MSG_ARGS_INVALIDE);
   } 
}
