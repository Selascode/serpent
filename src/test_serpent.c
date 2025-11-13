#include <stdlib.h>
#include <CUnit/Basic.h>
#include "serpent.h"

int init_suite_success(void) { 
  return 0; 
}

int clean_suite_success(void) { 
  return 0; 
}

void test_coordonnee_tete_queue_initiales(void) {
  S_Serpent serpent = S_serpent(C_coordonnee(5,5), 3, D_DROITE, 10, 10);
  C_Coordonnee posTeteAttendu = C_coordonnee(7,5);
  C_Coordonnee posQueueAttendu = C_coordonnee(5,5);
  CU_ASSERT_TRUE(C_sontEgales(S_positionTete(serpent), posTeteAttendu));
  CU_ASSERT_TRUE(C_sontEgales(S_positionQueue(serpent), posQueueAttendu));
  S_liberer(&serpent);
}

void test_coordonnee_tete_queue_apres_avancer(void) {
  S_Serpent serpent = S_serpent(C_coordonnee(5,5), 3, D_DROITE, 10, 10);
  S_avancer(&serpent);
  C_Coordonnee posTeteAttendu = C_coordonnee(8,5);
  C_Coordonnee posQueueAttendu = C_coordonnee(6,5);
  CU_ASSERT_TRUE(C_sontEgales(S_positionTete(serpent), posTeteAttendu));
  CU_ASSERT_TRUE(C_sontEgales(S_positionQueue(serpent), posQueueAttendu));
  S_liberer(&serpent);
}

void test_coordonnee_tete_queue_apres_changement_de_direction_et_avancer(void) {
  S_Serpent serpent = S_serpent(C_coordonnee(5,5), 3, D_DROITE, 10, 10);
  S_avancer(&serpent);
  S_changerDirection(&serpent, D_BAS);
  S_avancer(&serpent);
  C_Coordonnee posTeteAttendu = C_coordonnee(8,6);
  C_Coordonnee posQueueAttendu = C_coordonnee(7,5);
  CU_ASSERT_TRUE(C_sontEgales(S_positionTete(serpent), posTeteAttendu));
  CU_ASSERT_TRUE(C_sontEgales(S_positionQueue(serpent), posQueueAttendu));
  S_changerDirection(&serpent, D_GAUCHE);
  S_avancer(&serpent);
  posTeteAttendu = C_coordonnee(7,6);
  posQueueAttendu = C_coordonnee(8,5);
  CU_ASSERT_TRUE(C_sontEgales(S_positionTete(serpent), posTeteAttendu));
  S_changerDirection(&serpent, D_HAUT);
  S_avancer(&serpent);
  posTeteAttendu = C_coordonnee(7,5);
  posQueueAttendu = C_coordonnee(8,6);
  CU_ASSERT_TRUE(C_sontEgales(S_positionTete(serpent), posTeteAttendu));
  S_changerDirection(&serpent, D_DROITE);
  S_avancer(&serpent);
  posTeteAttendu = C_coordonnee(8,5);
  posQueueAttendu = C_coordonnee(7,6);
  CU_ASSERT_TRUE(C_sontEgales(S_positionTete(serpent), posTeteAttendu));
  S_liberer(&serpent);
}

void test_coordonnee_tete_queue_apres_accroissement(void) {
  S_Serpent serpent = S_serpent(C_coordonnee(5,5), 3, D_DROITE, 10, 10);
  S_accroissement(&serpent,1);
  S_avancer(&serpent);
  C_Coordonnee posTeteAttendu = C_coordonnee(8,5);
  C_Coordonnee posQueueAttendu = C_coordonnee(5,5);
  CU_ASSERT_TRUE(C_sontEgales(S_positionTete(serpent), posTeteAttendu));
  CU_ASSERT_TRUE(C_sontEgales(S_positionQueue(serpent), posQueueAttendu));
}

void test_longueur(void) {
  S_Serpent serpent = S_serpent(C_coordonnee(5,5), 3, D_DROITE, 10, 10);
  CU_ASSERT_EQUAL(S_longueur(serpent), 3);
  S_accroissement(&serpent,1);
  S_avancer(&serpent);
  CU_ASSERT_EQUAL(S_longueur(serpent), 4);
  S_accroissement(&serpent,2);
  S_avancer(&serpent);
  CU_ASSERT_EQUAL(S_longueur(serpent), 5);
  S_avancer(&serpent);
  CU_ASSERT_EQUAL(S_longueur(serpent), 6);
  S_avancer(&serpent);
  CU_ASSERT_EQUAL(S_longueur(serpent), 6);
  S_liberer(&serpent);
}

void test_se_mord(void) {
  S_Serpent serpent = S_serpent(C_coordonnee(5,5), 5, D_DROITE, 10, 10);
  S_accroissement(&serpent,1);
  S_avancer(&serpent);
  S_accroissement(&serpent,1);
  S_changerDirection(&serpent, D_BAS);
  S_avancer(&serpent);
  S_changerDirection(&serpent, D_GAUCHE);
  S_avancer(&serpent);
  S_changerDirection(&serpent, D_HAUT);
  S_avancer(&serpent);
  CU_ASSERT_TRUE(S_seMord(serpent));
  S_liberer(&serpent);
}

void test_est_une_coordonnee(void) {
  S_Serpent serpent = S_serpent(C_coordonnee(5,5), 3, D_DROITE, 10, 10);
  C_Coordonnee pos1 = C_coordonnee(6,5);
  C_Coordonnee pos2 = C_coordonnee(7,5);
  C_Coordonnee pos3 = C_coordonnee(8,5);
  CU_ASSERT_TRUE(S_estUneCoordonneeDuSerpent(serpent, pos1));
  CU_ASSERT_TRUE(S_estUneCoordonneeDuSerpent(serpent, pos2));
  CU_ASSERT_FALSE(S_estUneCoordonneeDuSerpent(serpent, pos3));
  S_liberer(&serpent);
}

void test_coordonnee(void) {
  S_Serpent serpent = S_serpent(C_coordonnee(5,5), 3, D_DROITE, 10, 10);
  C_Coordonnee* coordonnees = S_coordonneeDuSerpent(serpent);
  if (coordonnees != NULL) {
    CU_ASSERT_TRUE(C_sontEgales(coordonnees[2], C_coordonnee(7,5)));
    CU_ASSERT_TRUE(C_sontEgales(coordonnees[1], C_coordonnee(6,5)));
    CU_ASSERT_TRUE(C_sontEgales(coordonnees[0], C_coordonnee(5,5)));
    free(coordonnees);
  } else {
    CU_FAIL("S_coordonneeDuSerpent returned NULL");
  }
}
  

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : serpent", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "Coordonnées tete queue initiales", test_coordonnee_tete_queue_initiales))
      || (NULL == CU_add_test(pSuite, "Coordonnées tete queue après avancer", test_coordonnee_tete_queue_apres_avancer))
      || (NULL == CU_add_test(pSuite, "Coordonnées tete queue après changement de direction et avancer", test_coordonnee_tete_queue_apres_changement_de_direction_et_avancer))
      || (NULL == CU_add_test(pSuite, "Coordonnées tete queue après accroissement", test_coordonnee_tete_queue_apres_accroissement))
      || (NULL == CU_add_test(pSuite, "Longueur du serpent", test_longueur))
      || (NULL == CU_add_test(pSuite, "Se mord la queue", test_se_mord))
      || (NULL == CU_add_test(pSuite, "Est une coordonnée du serpent", test_est_une_coordonnee))
      || (NULL == CU_add_test(pSuite, "Coordonnées du serpent", test_coordonnee))
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


