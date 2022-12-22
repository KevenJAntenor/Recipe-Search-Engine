#include "list.h"

struct recette *initialiser_recette(char *nom_recette){
   struct recette *new_recette = (struct recette*) malloc(sizeof(struct recette));
   new_recette->nom_recette = nom_recette;
   new_recette->suivant = NULL;
   return new_recette;
}

struct liste_recettes *initialiser_liste_recettes(){
   struct liste_recettes *new_liste_recettes = (struct liste_recettes*) malloc(sizeof(struct liste_recettes));
   new_liste_recettes->nb_recettes = 0;
   new_liste_recettes->recettes = NULL;
   return new_liste_recettes;
}

struct categorie *initialiser_categorie(char *nom_categorie){
   struct categorie *new_categorie = (struct categorie*) malloc(sizeof(struct categorie));
   new_categorie->nom_categorie = nom_categorie;
   new_categorie->suivant = NULL;
   new_categorie->recettes  = initialiser_liste_recettes();
   return new_categorie;
}

struct liste_categories *initialiser_liste_categories(){
   struct liste_categories *new_liste_categories = (struct liste_categories*) malloc(sizeof(struct liste_categories));
   new_liste_categories->nb_categories = 0;
   new_liste_categories->categories = NULL;
   return new_liste_categories;
}

int comparer_recettes(struct recette *recette,struct recette *autre_recette){
   return strcmp(recette->nom_recette,recette->nom_recette);
}

int trouver_position_recette(char *nom_recette, struct liste_recettes *liste_recettes){
   int position = 0;
   if (liste_recettes->nb_recettes == 0){
      return position;
   }
   struct recette *courant = liste_recettes->recettes;
   while(courant != NULL && strcmp(nom_recette,courant->nom_recette) < 0){
      position++;
      courant = courant->suivant;
   }
   return position;
}

void inserer_recette(struct recette *recette, int position, struct liste_recettes *liste_recettes){
   struct recette *courant = liste_recettes->recettes;
   if (position == 0){
      liste_recettes->recettes = recette;
   } else {
      unsigned int i;
      while ( i++ < position){
         courant = courant->suivant;
      }
      recette->suivant = courant->suivant;
      courant->suivant = recette;
   }
}

void ajouter_recette(struct recette *recette, struct liste_recettes *liste_recettes){
   int position = trouver_position_recette(recette->nom_recette,liste_recettes);
   inserer_recette(recette,position,liste_recettes);
   liste_recettes->nb_recettes++;
}


int comparer_categories(struct categorie *categorie,struct categorie *autre_categorie){
   return strcmp(categorie->nom_categorie,autre_categorie->nom_categorie);
}

int trouver_position_categorie(char *nom_categorie, struct liste_categories *liste_categories){
   int position = 0;
   if (liste_categories->nb_categories == 0){
      return position;
   }
   struct categorie *courant = liste_categories->categories;
   while(courant != NULL && strcmp(nom_categorie,courant->nom_categorie) < 0){
      position++;
      courant = courant->suivant;
   }
   return position;
}

void inserer_categorie(struct categorie *categorie, int position, struct liste_categories *liste_categories){
   struct categorie *courant = liste_categories->categories;
   if (position == 0){
      liste_categories->categories = categorie;
   } else {
      unsigned int i;
      while ( i++ < position){
         courant = courant->suivant;
      }
      categorie->suivant = courant->suivant;
      courant->suivant = categorie;
   }
}

void ajouter_categorie(struct categorie *categorie, struct liste_categories *liste_categories){
   int position = trouver_position_categorie(categorie->nom_categorie,liste_categories);
   inserer_categorie(categorie,position,liste_categories);
   liste_categories->nb_categories++;
}

void afficher_categorie(struct categorie *categorie){
   struct recette *courant = categorie->recettes->recettes;
   while(courant != NULL){
      printf("%s\n",courant->nom_recette);
   }
   printf(".\n");
}