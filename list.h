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

// Méthodes des recettes

/**
 * Initialise une recette en mémoire
 * @param nom_recette Le nom de la recette
 * @return struct recette* : une recette
 */
struct recette *initialiser_recette(char *nom_recette);

/**
 * Compare deux recettes selon l'ordre lexicographique de leurs noms
 * @param recette la recette comparante
 * @param autre_recette la recette comparée
 * @return un nombre inferieur à 0 si plus petit, supérieur à 0 si
 * plus grand sinon 0 si égal
 */
int comparer_recettes(struct recette *recette,struct recette *autre_recette);


// Méthodes des listes de recettes

/**
 * Initialise en mémoire une liste chanée de recettes
 * @return struct liste_recettes* : une liste chainée de recettes vide
*/
struct liste_recettes *initialiser_liste_recettes(void);

/**
 * Ajoute une recette dans une liste de recettes
 * @param recette la recette à ajouter
 * @param liste_recettes la liste de recettes
*/
void ajouter_recette(struct recette *recette, struct liste_recettes *liste_recettes);

/**
 * Trouve la position ou ajouter une recette
 * @param nom_recette le nom de la recette a ajouter
 * @param liste_recettes la liste de recettes
*/
int trouver_position_recette(char *nom_recette, struct liste_recettes *liste_recettes);


// Méthodes des catégories

/**
 * Initialise une categorie en mémoire
 * @param nom_categorie Le nom de la categorie
 * @return struct categorie* : une categorie vide
 */
struct categorie *initialiser_categorie(char *nom_categorie);

/**
 * Compare deux categories selon l'ordre lexicographique de leurs noms
 * @param recette la categorie comparante
 * @param autre_recette la categorie comparée
 * @return un nombre inferieur à 0 si plus petit, supérieur à 0 si
 * plus grand sinon 0 si égal
 */
int comparer_categories(struct categorie *categorie, struct categorie *autre_categorie);

/**
 * Initialise en mémoire une liste chanée de catégories
 * @return struct liste_recettes* : une liste chainée de recettes vide
*/
struct liste_categories *initialiser_liste_categories();

/**
 * Ajoute une categorie dans une liste de categories
 * @param categorie la categorie à ajouter
 * @param liste_categories la liste des categories
*/
void ajouter_categorie(struct categorie *categorie, struct liste_categories *liste_categories);

/**
 * Inserer une recette dans une liste a une position donnee
 * @param recette recette a ajouter
 * @param position poisition ou ajouter
 * @param liste_recettes la liste de recettes ou ajouter la recette
*/
void inserer_recette(struct recette *recette, int position, struct liste_recettes *liste_recettes);

/**
 * Trouve la position ou ajouter une categorie
 * @param nom_categorie le nom de la categorie a ajouter
 * @param liste_categories la liste des categories
*/
int trouver_position_categorie(char *nom_categorie, struct liste_categories *liste_categories);


/**
 * Inserer une categorie dans une liste a une position donnee
 * @param categorie categorie a ajouter
 * @param position poisition ou ajouter
 * @param liste_categories la liste de catefories ou ajouter la recette
*/
void inserer_categorie(struct categorie *categorie, int position, struct liste_categories *liste_categories);