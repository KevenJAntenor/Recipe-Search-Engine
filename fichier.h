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
 * Verifie si le fichier existe
 * @param nomDuFichier le nom du fichier
 * @return est fichier ou pas
*/
bool est_fichier(char *nomDuFichier) ;

/**
 * Manipule une ligne du fichier
 * @param liste_categorie la liste de categories
 * @param ligne la ligne du fichier
*/
void manipuler_ligne(struct liste_categories *liste_categorie , char *ligne) ;

/**
 * Remplit la liste de categories
 * @param liste_categorie la liste de categories
 * @param nomRecette le nom de la recette
 * @param nomCategorie le nom de la categorie
*/
void remplir_liste_categorie(struct liste_categories *liste_categorie, char *nomRecette , char *nomCategorie) ;

/**
 * Trouve le nom de la recette
 * @param ligne la ligne du fichier
 * @param nomRecette le nom de la recette
 * @return nom de la recette
*/
char *trouver_nom_recette(char *ligne, char *nomRecette) ;

/**
 * Trouver le nom de la categorie
 * @param ligne la ligne du fichier
 * @param nomCategorie le nom de la categorie
 * @return nom de la categorie
*/
char *trouver_nom_categorie(char *ligne, int index, char *nomCategorie) ;

/**
 * Genere la liste des categories
 * @param nom_fichier nom du fichier
 * @return struct liste_categories * : la liste des categories
*/
struct liste_categories *lire_fichier(char *nom_fichier) ;