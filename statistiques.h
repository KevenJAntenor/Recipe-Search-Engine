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


void generer_stats(char *fichier_entree, char *fichier_stats,struct liste_categories categories);

void generer_depuis_fichier(char *fichier_entree,struct stats *statistiques);

unsigned int compter_nb_lignes(FILE *fichier);

unsigned int compter_nb_mots_sans_doublons(FILE *fichier);



