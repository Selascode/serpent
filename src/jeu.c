#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "coordonnee.h"

static C_Coordonnee J_nelleCoordonneeFruit(unsigned int largeurTerrain,
					 unsigned int hauteurTerrain,
					 S_Serpent serpent) {
  return C_coordonnee(0,0);
}

unsigned int J_jouer(void* pinterface,
		     void (*afficherTerrain)(void* pinterface,
					     S_Serpent serpent,
					     C_Coordonnee coordFruit,
					     unsigned int score),
		     void (*mettreAJour)(void* pinterface,
					 S_Serpent serpent,
					 C_Coordonnee coordFruit,
					 unsigned int score),
		     D_Direction (*obtenirDirection)(void* pinterface,
						     D_Direction directionActuelle),
		     void (*accelerer) (void* pinterface),
		     unsigned int largeurTerrain,
		     unsigned int hauteurTerrain,
		     unsigned int longueurInitialeSerpent,
		     D_Direction directionInitialeSerpent) {
  return 0;
}
