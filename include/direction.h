#ifndef __DIRECTION_H__
#define __DIRECTION_H__

typedef enum {
  D_HAUT,
  D_BAS,
  D_GAUCHE,
  D_DROITE
} D_Direction;

D_Direction D_directionOpposee(D_Direction dir);

#endif
