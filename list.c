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
   new_categorie->recettes = initialiser_liste_recettes();
}

struct liste_categories *initialiser_liste_categories(){
   struct liste_categories *new_liste_categories = (struct liste_categories*) malloc(sizeof(struct liste_categories));
   new_liste_categories->nb_categories = 0;
   new_liste_categories->categories = NULL;
   return new_liste_categories;
}
