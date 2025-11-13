#include<stdlib.h>
#include<CUnit/Basic.h>
#include "coordonnee.h"

int init_suite_success(void) { 
  return 0; 
}

int clean_suite_success(void) { 
  return 0; 
}

void test_abscisse(void) {
  unsigned int resultatAttendu = 1;
  unsigned int resultatObtenu = C_abscisse(C_coordonnee(1,2));
  CU_ASSERT_EQUAL(resultatObtenu, resultatAttendu);
}

void test_ordonnee(void) {
  unsigned int resultatAttendu = 2;
  unsigned int resultatObtenu = C_ordonnee(C_coordonnee(1,2));
  CU_ASSERT_EQUAL(resultatObtenu, resultatAttendu);
}

void test_coordonnee_voisine(void) {
  C_Coordonnee c = C_coordonnee(1,1);
  C_Coordonnee haut = C_coordonneeVoisine(c, D_HAUT, 5, 5);
  C_Coordonnee bas = C_coordonneeVoisine(c, D_BAS, 5, 5);
  C_Coordonnee gauche = C_coordonneeVoisine(c, D_GAUCHE, 5, 5);
  C_Coordonnee droite = C_coordonneeVoisine(c, D_DROITE, 5, 5);
  CU_ASSERT_TRUE(C_sontEgales(haut, C_coordonnee(1,0)));
  CU_ASSERT_TRUE(C_sontEgales(bas, C_coordonnee(1,2)));
  CU_ASSERT_TRUE(C_sontEgales(gauche, C_coordonnee(0,1)));
  CU_ASSERT_TRUE(C_sontEgales(droite, C_coordonnee(2,1)));

  C_Coordonnee c_bord_haut = C_coordonnee(2,0);
  C_Coordonnee haut_bord = C_coordonneeVoisine(c_bord_haut, D_HAUT, 5, 5);
  CU_ASSERT_TRUE(C_sontEgales(haut_bord, C_coordonnee(2,4)));

  C_Coordonnee c_bord_bas = C_coordonnee(2,4);
  C_Coordonnee bas_bord = C_coordonneeVoisine(c_bord_bas, D_BAS, 5, 5);
  CU_ASSERT_TRUE(C_sontEgales(bas_bord, C_coordonnee(2,0)));

  C_Coordonnee c_bord_gauche = C_coordonnee(0,2);
  C_Coordonnee gauche_bord = C_coordonneeVoisine(c_bord_gauche, D_GAUCHE, 5, 5);
  CU_ASSERT_TRUE(C_sontEgales(gauche_bord, C_coordonnee(4,2)));

  C_Coordonnee c_bord_droite = C_coordonnee(4,2);
  C_Coordonnee droite_bord = C_coordonneeVoisine(c_bord_droite, D_DROITE, 5, 5);
  CU_ASSERT_TRUE(C_sontEgales(droite_bord, C_coordonnee(0,2)));
}

void test_sontEgales(void) {
  C_Coordonnee c1 = C_coordonnee(1,2);
  C_Coordonnee c2 = C_coordonnee(1,2);
  C_Coordonnee c3 = C_coordonnee(2,3);
  CU_ASSERT_TRUE(C_sontEgales(c1, c2));
  CU_ASSERT_FALSE(C_sontEgales(c1, c3));
}

void test_copier(void) {
  C_Coordonnee c1 = C_coordonnee(1,2);
  C_Coordonnee *pc2 = C_copier(&c1);
  CU_ASSERT_TRUE(C_sontEgales(c1, *pc2));
  C_liberer(pc2);
}

void test_comparer(void) {
  C_Coordonnee c1 = C_coordonnee(1,2);
  C_Coordonnee c2 = C_coordonnee(1,2);
  C_Coordonnee c3 = C_coordonnee(2,3);
  C_Coordonnee *pc1 = C_copier(&c1);
  C_Coordonnee *pc2 = C_copier(&c2);
  C_Coordonnee *pc3 = C_copier(&c3);
  CU_ASSERT_EQUAL(C_comparer(pc1, pc2), 0);
  CU_ASSERT_NOT_EQUAL(C_comparer(pc1, pc3), 0);
  C_liberer(pc1);
  C_liberer(pc2);
  C_liberer(pc3);
}
 
int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : coordonnee", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "abscisse", test_abscisse))
      || (NULL == CU_add_test(pSuite, "ordonnee", test_ordonnee))
      || (NULL == CU_add_test(pSuite, "coordonneeVoisine", test_coordonnee_voisine))
      || (NULL == CU_add_test(pSuite, "sontEgales", test_sontEgales))
      || (NULL == CU_add_test(pSuite, "copier", test_copier))
      || (NULL == CU_add_test(pSuite, "comparer", test_comparer))
      ) 
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}


