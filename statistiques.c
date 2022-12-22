#include "statistiques.h"

void generer_stats(char *fichier_entree, char *fichier_stats,struct liste_categories *categories){
    struct stats statistiques;
    initialiser_statistiques(&statistiques);
    generer_depuis_fichier(fichier_entree,&statistiques);
    generer_depuis_liste(categories, &statistiques);
    ecrire_statistiques(statistiques,fichier_stats);
}

void initialiser_statistiques(struct stats *statistiques){
    statistiques->nb_lignes = 0;
    statistiques->nb_mots_sans_doublons = 0;
    statistiques->nb_mots_avec_doublons = 0;
    statistiques->lettre_plus_frequente = 'A';
    statistiques->nb_categories = 0;
    statistiques->nb_recettes = 0;
    statistiques->categorie_plus_populaire = "";
    statistiques->categorie_plus_grand_recettes = "";
    statistiques->recettes_plus_longues = "";
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

void ecrire_statistiques(struct stats statistiques,char *fichier_stats){
    FILE *fp = fopen(fichier_stats,"w");
    char str[5000] = "";
    sprintf(str,"Nombre de lignes dans le fichier d'entrée: %i\nNombre de mots sans doublons: %i\nNombre de mots avec doublons: %i\nLettre la plus fréquente: %c\nNombre de catégories: %i\nNombre de recettes: %i\nCatégorie la plus populaire: %s\nCatégorie qui a le plus grand nombre de recettes: %s\nRecette la plus longue (en termes de nombre de caractères): %s",
    statistiques.nb_lignes,
    statistiques.nb_mots_sans_doublons,
    statistiques.nb_mots_avec_doublons,
    statistiques.lettre_plus_frequente,
    statistiques.nb_categories,
    statistiques.nb_recettes,
    statistiques.categorie_plus_populaire,
    statistiques.categorie_plus_grand_recettes,
    statistiques.recettes_plus_longues);
    fputs(str,fp);
    fclose(fp);

}