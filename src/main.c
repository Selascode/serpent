#include <stdlib.h>
#include <stdio.h>
#include "jeu.h"
#include "interface.h"

int main(int argc, char* argv[]) {
  unsigned int largeur = atoi(argv[1]);
  unsigned int hauteur = atoi(argv[2]);
  unsigned int longueur = atoi(argv[3]);

  I_Interface interface = I_interface(largeur, hauteur);
  
  unsigned int score = J_jouer(&interface,
			       I_afficherTerrain,
			       I_mettreAJour,
			       I_obtenirDirection,
			       I_accelerer,
			       largeur,
			       hauteur,
			       longueur,
			       D_DROITE);
  I_fermer(&interface);
  printf("Votre score %d\n", score);
  return 0;
}
