#include "statistiques.h"

void generer_stats(char *fichier_entree, char *fichier_stats,struct liste_categories categories){
    struct stats statistiques;
    generer_depuis_fichier(fichier_entree,&statistiques);
    gnerer_depuis_liste(categories, &statistiques);
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


void gnerer_depuis_liste(struct liste_categories categories,struct stats *statistiques){
    
}