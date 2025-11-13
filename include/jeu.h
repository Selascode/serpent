#ifndef __JEU_H__
#define __JEU_H__

#include "direction.h"
#include "serpent.h"

/**
   @brief lance une partie de serpent
   @param pinterface pointeur vers une structure de gestion de l'interface (peut être NULL si non utilisé)
   @param afficherTerrain fonction d'affichage du terrain
   @param mettreAJour fonction de mise à jour de l'affichage du terrain
   @param obtenirDirection fonction d'obtention de la direction du serpent
   @param ralentir fonction de ralentissement du jeu (par exemple en attendant un certain temps ou un appui sur une touche)
   @param largeurTerrain largeur du terrain de jeu
   @param hauteurTerrain hauteur du terrain de jeu
   @param longueurInitialeSerpent longueur initiale du serpent
   @param directionInitialeSerpent direction initiale du serpent
   @return le score final (longueur du serpent - longueurInitialeSerpent)
   @note On considère que le terrain est torique (le serpent réapparaît de l'autre côté lorsqu'il sort du terrain) et que les coordonnées commencent en (0,0) en haut à gauche
**/
unsigned int J_jouer(void* pinterface,
		     void (*afficherTerrain)(void* pinterface,
					     S_Serpent serpent,
					     C_Coordonnee fruit,
					     unsigned int score),
		     void (*mettreAJour)(void* pinterface,
					 S_Serpent serpent,
					 C_Coordonnee fruit,
					 unsigned int score),
		     D_Direction (*obtenirDirection)(void* pinterface,
						     D_Direction directionActuelle),
		     void (*accelerer) (void* pinterface),
		     unsigned int largeurTerrain,
		     unsigned int hauteurTerrain,
		     unsigned int longueurInitialeSerpent,
		     D_Direction directionInitialeSerpent);
#endif
