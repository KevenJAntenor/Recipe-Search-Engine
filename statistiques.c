#include "statistiques.h"

void generer_stats(char *fichier_entree, char *fichier_stats,struct liste_categories *categories){
    struct stats statistiques;
    generer_depuis_fichier(fichier_entree,&statistiques);
    generer_depuis_liste(categories, &statistiques);
}

void generer_depuis_fichier(char *fichier_entree,struct stats *statistiques){
    FILE *fichier = fopen(fichier_entree,"r");
    statistiques->nb_lignes = compter_nb_lignes(fichier);
    statistiques->nb_mots_sans_doublons = compter_nb_mots_sans_doublons(fichier);
    statistiques->nb_mots_avec_doublons = compter_nb_mots_avec_doublons(fichier);
    statistiques->lettre_plus_frequente = trouver_lettre_plus_frequente(fichier);
    fclose(fichier);
}

unsigned int compter_nb_lignes(FILE *fichier){
    fseek(fichier,0,SEEK_SET);
    unsigned int nb_lignes;
    char ligne[BUFFER];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        nb_lignes++;
    }
    
    return nb_lignes;
}

unsigned int compter_nb_mots_sans_doublons(FILE *fichier){
    return 0;
}

unsigned int compter_nb_mots_avec_doublons(FILE *fichier){
    return 0;
}

char trouver_lettre_plus_frequente(FILE *fichier){
   return 'A';
}


void generer_depuis_liste(struct liste_categories *categories,struct stats *statistiques){
    statistiques->nb_categories = categories->nb_categories;
    statistiques->nb_recettes = compter_nb_recettes(categories);
    trouver_categorie_plus_grand_recettes(categories,statistiques->categorie_plus_grand_recettes);
    statistiques->categorie_plus_populaire = statistiques->categorie_plus_grand_recettes;
    trouver_recettes_plus_longue(categories,statistiques->recettes_plus_longues);
}

unsigned int compter_nb_recettes(struct liste_categories *categories){
    struct categorie *courant = categories->categories;
    unsigned int cpt = 0;
    while (courant != NULL){
        cpt = cpt + courant->recettes->nb_recettes;
        courant = courant->suivant;
    }
    return cpt;
}


void trouver_categorie_plus_grand_recettes(struct liste_categories *categories, char *categorie){
    unsigned int max = 0;
    struct categorie *courant = categories->categories;
    while (courant != NULL){
        if (courant->recettes->nb_recettes > max){
            max = courant->recettes->nb_recettes;
            categorie = courant->nom_categorie;
        }
        courant = courant->suivant;
    }
}

void trouver_recettes_plus_longue(struct liste_categories *categories,char *nom_recette){
   unsigned int max = 0;
   struct categorie *courant_categorie = categories->categories;
   struct recette *courant_recette;
   while (courant_categorie != NULL){
       courant_recette = courant_categorie->recettes->recettes;
       while(courant_recette != NULL){
           if (max < strlen(courant_recette->nom_recette)){
               max = strlen(courant_recette->nom_recette);
               nom_recette = courant_recette->nom_recette;
           }
           courant_recette = courant_recette->suivant;
       }
       courant_categorie = courant_categorie->suivant;
   }
}