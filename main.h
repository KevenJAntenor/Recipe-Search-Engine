#include <stdio.h>

#include "erreur.h"

#define MSG_ERR_NB_ARGS "Nombre d'arguments invalide"


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

