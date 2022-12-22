#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"


#define BUFFER 10000


struct stats {
    unsigned int nb_lignes;
    unsigned int nb_mots_sans_doublons;
    unsigned int nb_mots_avec_doublons;
    char lettre_plus_frequente;
    unsigned int nb_categories;
    unsigned int nb_recettes;
    char *categorie_plus_populaire;
    char *categorie_plus_grand_recettes;
    char *recettes_plus_longues;
};


void generer_stats(char *fichier_entree, char *fichier_stats,struct liste_categories *categories);

void generer_depuis_fichier(char *fichier_entree,struct stats *statistiques);

unsigned int compter_nb_lignes(FILE *fichier);

unsigned int compter_nb_mots_sans_doublons(FILE *fichier);

unsigned int compter_nb_mots_avec_doublons(FILE *fichier);

char trouver_lettre_plus_frequente(FILE *fichier);

void generer_depuis_liste(struct liste_categories *categories,struct stats *statistiques);

unsigned int compter_nb_recettes(struct liste_categories *categories);

void trouver_categorie_plus_grand_recettes(struct liste_categories *categories, char *categorie);

void trouver_recettes_plus_longue(struct liste_categories *categories,char *nom_recette);

void ecrire_statistiques(struct stats statistiques,char *fichier_stats);





