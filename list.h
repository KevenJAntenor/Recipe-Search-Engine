#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct recette {
   char *nom_recette;
   struct recette *suivant;
};

struct liste_recettes {
   struct recette *recettes;
   unsigned int nb_recettes;
};


struct categorie {
   char *nom_categorie;
   struct categorie *suivant;
   struct liste_recettes *recettes;
};

struct liste_categories {
   unsigned int nb_categories;
   struct categorie *categories;
};


int compare_recette(struct recette *recette1,struct recette *recette2);

int compare_categorie(struct categorie *categorie1, struct categorie *categorie2);

struct categorie *initialiser_categorie(char *nom_recette);

struct categorie *initiliser_recette(char *nom_categorie);

struct liste_categories *initialiser_liste_categories();

struct liste_recettes *initialiser_liste_recettes();

void ajouter_recette(struct recette *recette, struct liste_recettes *liste_recettes);

void ajouter_categorie(struct categorie *categorie, struct liste_categories *liste_categories);
