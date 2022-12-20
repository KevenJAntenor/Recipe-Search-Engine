#include "list_test.h"




/* Test function definitions */
void test_recette(void){
    char *nom_recette = "bouillon de poisson";
    struct recette *une_recette = initialiser_recette(nom_recette);
    CU_ASSERT_EQUAL(0,strcmp(nom_recette,une_recette->nom_recette));
    CU_ASSERT_EQUAL(une_recette->suivant,NULL);
    free(une_recette);
}
