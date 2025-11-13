#include <stdlib.h>
#include <stdbool.h>
#include "serpent.h"

S_Serpent S_serpent(C_Coordonnee positionInitialeQueue,
		    unsigned int longueurInitiale,
		    D_Direction directionInitiale,
		    unsigned int largeurTerrain,
		    unsigned int hauteurTerrain) {
  S_Serpent serpent = {LC_listeChainee(), LC_listeChainee(), 0, 0, D_HAUT, 1, 1};

  return serpent;
}

C_Coordonnee S_positionTete(S_Serpent serpent) {
  return  C_coordonnee(0,0);
}

C_Coordonnee S_positionQueue(S_Serpent serpent) {
  return  C_coordonnee(0,0);
}

void S_avancer(S_Serpent* pserpent) {
  C_Coordonnee coordTete = *pserpent.positionInitialeQueue
}

D_Direction S_direction(S_Serpent serpent) {
  return D_HAUT;
}

int S_changerDirection(S_Serpent* pserpent, D_Direction nouvelleDirection) {

  return 0;
}

void S_accroissement(S_Serpent* pserpent, unsigned int longueur) {

}

unsigned int S_longueur(S_Serpent serpent) {
  return 0;
}

bool S_seMord(S_Serpent serpent) {
  return true;
}

bool S_estUneCoordonneeDuSerpent(S_Serpent serpent, C_Coordonnee coord) {
  return true;
}

C_Coordonnee* S_coordonneeDuSerpent(S_Serpent serpent) {
  return NULL;
}



void S_liberer(S_Serpent* pserpent) {
  
}

