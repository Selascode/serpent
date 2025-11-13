#include "direction.h"

D_Direction D_directionOpposee(D_Direction direction) {
  switch (direction) {
  case D_HAUT:
    return D_BAS;
  case D_BAS:
    return D_HAUT;
  case D_GAUCHE:
    return D_DROITE;
  case D_DROITE:
    return D_GAUCHE;
  default:
    return direction; 
  }
}

