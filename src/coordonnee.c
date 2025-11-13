#include <stdlib.h>
#include "coordonnee.h"

C_Coordonnee C_coordonnee(unsigned int x, unsigned int y) {
  C_Coordonnee coord;
  coord.x = x;
  coord.y = y;
  return coord;
}

unsigned int C_abscisse(C_Coordonnee coord) {
  return coord.x;
}

unsigned int C_ordonnee(C_Coordonnee coord) {
  return coord.y;
}

C_Coordonnee C_coordonneeVoisine(C_Coordonnee positionActuelle,
				 D_Direction direction,
				 unsigned int largeurTerrain,
				 unsigned int hauteurTerrain) {
  unsigned int x = C_abscisse(positionActuelle);
  unsigned int y = C_ordonnee(positionActuelle);
  switch (direction) {
  case D_HAUT:
    y = (y == 0) ? hauteurTerrain - 1 : y - 1;
    break;
  case D_BAS:
    y = (y + 1) % hauteurTerrain;
    break;
  case D_GAUCHE:
    x = (x == 0) ? largeurTerrain - 1 : x - 1;
    break;
  case D_DROITE:
    x = (x + 1) % largeurTerrain;
    break;
  }
  return C_coordonnee(x, y);
}

bool C_sontEgales(C_Coordonnee coord1, C_Coordonnee coord2) {
  return (coord1.x == coord2.x) && (coord1.y == coord2.y);
}

void* C_copier(void* pcoord) {
  if (pcoord == NULL) {
    return NULL;
  }
  C_Coordonnee* original = (C_Coordonnee*)pcoord;
  C_Coordonnee* copie = (C_Coordonnee*)malloc(sizeof(C_Coordonnee));
  if (copie != NULL) {
    copie->x = original->x;
    copie->y = original->y;
  }
  return copie;
}

void C_liberer(void* pcoord) {
  free(pcoord);
}

int C_comparer(const void* pcoord1, const void* pcoord2) {
  if (pcoord1 == NULL || pcoord2 == NULL) {
    return 1; // Consider NULL not equal to anything
  }
  C_Coordonnee coord1 = *(C_Coordonnee*)pcoord1;
  C_Coordonnee coord2 = *(C_Coordonnee*)pcoord2;
  return C_sontEgales(coord1, coord2) ? 0 : 1;
}	   
