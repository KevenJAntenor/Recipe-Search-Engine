#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "list.h"

/**
 * Permet de retirer les espaces au debut et a la fin de la chaine\
 * @param chaineDeCaractere la chaine de caractere
 * @return la nouvelle chaine 
*/
char *enleve_espace_deb_fin(char *chaineDeCaractere) ;

/**
 * Permet de retirer les espaces au milieu de la chaine
 * @param chaineDeCaractere la chaine de caractere
 * @return la nouvelle chaine
*/
char *enleve_espace_milieu(char *chaineDeCaractere) ;

/**
 * Traite ce que l'utilisateur entre comme donnee
 * @param critereDeRecherche le critere de recherche que l'utilisateur a entre
*/
void traiter_entree_de_utilisateur(char *critereDeRecherche) ;

/**
 * Permet le lancement de la rechercher
 * @param categories la liste des categories
*/
void lancer_recherche(struct liste_categories *categories) ;