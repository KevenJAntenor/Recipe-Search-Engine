#include <stdio.h>
#include <stdlib.h>


// codes d'erreurs
enum codes {
   ARGS = 1,
   FICHIER = 2,
};

/** stop le programme avec un code de sortie en laissant
 * un message dans la sortie d'erreur
 */
void stop(enum codes code, char message[]);
