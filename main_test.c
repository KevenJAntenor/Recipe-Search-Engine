#include "main_test.h"

int main(void)
{
    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add the test functions to the suite */
    CU_pSuite pSuite = CU_add_suite("Test du module des listes chaines", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "test_recette", test_recette)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run the tests and show the run summary */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    /* Clean up the test registry and return */
    CU_cleanup_registry();
    return CU_get_error();
}
