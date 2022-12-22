#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#ifndef LIST
#include "list.h"
#endif

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

/**
 * Fait une recherche par categorie
 * @param categories la liste des categories
 * @param critereDeREcherche la categorie a chercher 
*/
void rechercher_par_categorie(struct liste_categories *categories, char *critereDeRecherche) ;

/**
 * Fait une recherche par categorie avec un mot cle
 * @param categories la liste des categories
 * @param critereDeREcherche la categorie a chercher et son mot cle
*/
void rechercher_par_categorie_et_mot_cle(struct liste_categories *categories, char *critereDeRecherche) ;

/**
 * Permet de parcourir les recettes
 * @param listeREcette la liste de recettes
 * @param buffer le mot cle
 * @param recherche mot recherche pas trouve ?
*/
void parcourir_recettes(struct liste_recettes *listeRecette, char *buffer, bool recherche) ;

/**
 * Compte le nombred'espaces et le retourne
 * @param chaineDeCaractere la chaine de caracteres
 * @return nombre d'espaces
*/
int compter_nombre_espaces(char *chaineDeCaractere) ;