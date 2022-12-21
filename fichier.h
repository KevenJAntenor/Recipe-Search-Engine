#ifndef UNTITLED_FICHIER_H
#define UNTITLED_FICHIER_H

// Inclusions avec < >

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

// INclusions avec ""
#include "list.h"

// Declaration des fonctions publiques

/**
 * Cree une recette
 * @param nomRecette nom de la recette
 * @return struct recette* : une recette
*/
struct recette *creerRecette(char *nomRecette) ;

/**
 * Cree une categorie
 * @param nomCategorie nom de la categorie
 * @return struct categorie * : la categorie
*/
struct categorie *creerCategorie(char *nomCategorie) ;

/**
 * Permet de vider un tableau
 * @param tabAVider
 */
void viderTab(char *tabAVider) ;

/**
 * Verifie si fichier bien ouvert
 * @param fichier
 */
void ouvrirFichier(FILE *fichier);

/**
 * Ferme le fichier et verifie s'il est bien ferme
 * @param lefichier
 */
void fermerFichier(FILE *leFichier) ;

/**
 * Genere la liste des categories
 * @param nom_fichier nom du fichier
 * @return struct liste_categories * : la liste des categories
*/
struct liste_categories *lire_fichier(char *nom_fichier) ;

#endif
