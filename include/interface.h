#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "serpent.h"
#include "coordonnee.h"
#include "direction.h"

typedef struct {
  unsigned int largeur;
  unsigned int hauteur;
  struct timespec ralentissement;
  C_Coordonnee precedenteCoordonneeQueue;
} I_Interface;

I_Interface I_interface(unsigned int largeur, unsigned int hauteur);

void I_afficherTerrain(void* pinterface,
		       S_Serpent serpent,
		       C_Coordonnee fruit,
		       unsigned int score);

void I_mettreAJour(void* pinterface,
		   S_Serpent serpent,
		   C_Coordonnee fruit,
		   unsigned int score);

D_Direction I_obtenirDirection(void* pinterface,
			       D_Direction directionActuelle);

void I_accelerer(void* pinterface);

void I_fermer(void *pinterface);
#endif
