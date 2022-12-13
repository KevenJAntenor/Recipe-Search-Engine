#include <stdio.h>
#include <string.h>

#include "erreur.h"

#define MSG_ERR_NB_ARGS "Nombre d'arguments invalide"
#define MSG_ARGS_INVALIDE "Arguments invalides"


int main(int argc, char *argv[]);

/**
 * Vérifie les arguments et stoppent le programme à la moindre
 * invalidité
 * @param argc: nombre d'arguments
 * @param argv: pointeur vers le tableau des arguments
 */
void verifier_arguments(int argc, char *argv[]);


/**
 * Vérifie le nombre d'arguments
 * @param nb_arguments: nombre d'arguments
 */
void verifier_nb_arguments(int nb_arguments);


/**
 * Verifie si le fichier de banque de donnee existe
 * @param nom_fichier_banque[]: nom du fichier
 */
void verifier_fichier_banque(char nom_fichier_banque[]);

/**
 * Verifie les options 
 * @param nb_arguments: nombre d'arguments
 * @param arguments: tableau d'arguments
 */
void verifier_options(char *arguments[]);
