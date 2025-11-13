#ifndef __COORDONNEE_H__
#define __COORDONNEE_H__

#include <stdbool.h>
#include "direction.h"

/**
   @brief structure représentant une coordonnée d'un écran de jeu avec un terrain de jeu rectangulairetorique (la coordonnée voisine d'un bord est de l'autre côté du terrain)
   (0,0) étant le coin supérieur gauche de l'écran
**/
typedef struct {
    unsigned int x;
    unsigned int y;
} C_Coordonnee;

/**
   @brief créer une coordonnée
   @param x abscisse
   @param y ordonnée
   @return la coordonnée créée
**/
C_Coordonnee C_coordonnee(unsigned int x, unsigned int y);

/**
   @brief obtenir l'abscisse d'une coordonnée
   @param coord la coordonnée
   @return l'abscisse
**/
unsigned int C_abscisse(C_Coordonnee coord);

/**
   @brief obtenir l'ordonnée d'une coordonnée
   @param coord la coordonnée
   @return l'ordonnée
**/
unsigned int C_ordonnee(C_Coordonnee coord);

/**
   @brief obtenir la coordonnée voisine dans une direction donnée
   @param coord la coordonnée
   @param direction la direction
   @param largeurTerrain la largeur du terrain de jeu
   @param hauteurTerrain la hauteur du terrain de jeu
   @return la coordonnée voisine
**/
C_Coordonnee C_coordonneeVoisine(C_Coordonnee coord,
				 D_Direction direction,
				 unsigned int largeurTerrain,
				 unsigned int hauteurTerrain);

/**
   @brief tester l'égalité de deux coordonnées
   @param coord1 la première coordonnée
   @param coord2 la deuxième coordonnée
   @return true si les coordonnées sont égales, false sinon
**/
bool C_sontEgales(C_Coordonnee coord1, C_Coordonnee coord2);

/**
   @brief réalise une copie (allocation dynamique) d'une coordonnée compatible avec les fonctions de gestion mémoire génériques des sdd
   @param coord la coordonnée
   @return un pointeur vers la copie de la coordonnée
**/
void* C_copier(void* pcoord);

/**
   @brief libère une coordonnée allouée dynamiquement
   @param pcoord pointeur vers la coordonnée à libérer
**/
void C_liberer(void* pcoord);

/**
   @brief compare deux coordonnées pour les fonctions de gestion mémoire génériques des sdd
   @param pcoord1 pointeur vers la première coordonnée
   @param pcoord2 pointeur vers la deuxième coordonnée
   @return 0 si les coordonnées sont égales, 1 sinon
**/
int C_comparer(const void* pcoord1, const void* pcoord2);

#endif
