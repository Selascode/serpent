#ifndef __SERPENT_H__
#define __SERPENT_H__

#include "listeChainee.h"
#include "coordonnee.h"
#include "direction.h"

typedef struct {
  LC_ListeChainee tete;
  LC_ListeChainee queue;
  unsigned int longueur;
  unsigned int accroissement;
  D_Direction direction;
  unsigned int largeurTerrain;
  unsigned int hauteurTerrain;
} S_Serpent;

/**
   @brief créer un serpent
   @param positionInitialeQueue coordonnée de la queue du serpent
   @param longueurInitiale longueur initiale du serpent (>=1)
   @param directionInitiale direction initiale du serpent
   @param largeurTerrain largeur du terrain
   @param hauteurTerrain hauteur du terrain
   @return le serpent créé
**/
S_Serpent S_serpent(C_Coordonnee positionInitialeQueue,
		    unsigned int longueurInitiale,
		    D_Direction directionInitiale,
		    unsigned int largeurTerrain,
		    unsigned int hauteurTerrain);

/**
   @brief coordonnées de la tête du serpent
   @param serpent le serpent
   @return coordonnée de la tête du serpent
**/
C_Coordonnee S_positionTete(S_Serpent serpent);

/**
   @brief coordonnées de la queue du serpent
   @param serpent le serpent
   @return coordonnée de la queue du serpent
**/
C_Coordonnee S_positionQueue(S_Serpent serpent);

/**
   @brief fait avancer le serpent
   @param pserpent pointeur vers le serpent
   @note le serpent avance dans la direction courante et il peut grandir si l'accroissement est > 0 (décrémente l'accroissement dans ce cas). Si le serpent atteint le bord du terrain, il réapparaît de l'autre côté.
**/
void S_avancer(S_Serpent* pserpent);

/**
   @brief retourne la direction courante du serpent
   @param serpent le serpent
   @return la direction courante du serpent
**/
D_Direction S_direction(S_Serpent serpent);

/**
   @brief change la direction du serpent
   @param pserpent pointeur vers le serpent
   @param nouvelleDirection nouvelle direction du serpent
   @return 0 si la direction a été changée, -1 sinon
   @note la nouvelle direction doit être différente de la direction courante et ne pas être l'opposée
**/
int S_changerDirection(S_Serpent* pserpent, D_Direction nouvelleDirection);

/**
   @brief fait grandir le serpent
   @param pserpent pointeur vers le serpent
   @param longueur nombre d'avancements pendant lesquels le serpent grandit
**/
void S_accroissement(S_Serpent* pserpent, unsigned int longueur);

/**
   @brief retourne la longueur du serpent
   @param serpent le serpent
   @return la longueur du serpent
**/
unsigned int S_longueur(S_Serpent serpent);

/**
   @brief teste si le serpent se mord la queue
   @param serpent le serpent
   @return true si le serpent se mord la queue, false sinon
**/
bool S_seMord(S_Serpent serpent);

/**
   @brief teste si une coordonnée est occupée par le serpent
   @param serpent le serpent
   @param coord la coordonnée
   @return true si la coordonnée est occupée par le serpent, false sinon
**/
bool S_estUneCoordonneeDuSerpent(S_Serpent serpent, C_Coordonnee coord);

/**
   @brief retourne les coordonnées du serpent sous forme de tableau dynamique
   @param serpent le serpent
   @return un tableau dynamique contenant les coordonnées du serpent (de la queue à la tête)
   @note la mémoire allouée pour le tableau doit être libérée par l'appelant avec free()
   @note la première coordonnée du tableau est celle de la queue et la dernière est celle de la tête
**/
C_Coordonnee* S_coordonneeDuSerpent(S_Serpent serpent);

/**
   @brief libère la mémoire allouée dynamiquement pour le serpent
   @param pserpent pointeur vers le serpent à libérer
**/
void S_liberer(S_Serpent* pserpent);
#endif

  
