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
   @brief cr�er un serpent
   @param positionInitialeQueue coordonn�e de la queue du serpent
   @param longueurInitiale longueur initiale du serpent (>=1)
   @param directionInitiale direction initiale du serpent
   @param largeurTerrain largeur du terrain
   @param hauteurTerrain hauteur du terrain
   @return le serpent cr��
**/
S_Serpent S_serpent(C_Coordonnee positionInitialeQueue,
		    unsigned int longueurInitiale,
		    D_Direction directionInitiale,
		    unsigned int largeurTerrain,
		    unsigned int hauteurTerrain);

/**
   @brief coordonn�es de la t�te du serpent
   @param serpent le serpent
   @return coordonn�e de la t�te du serpent
**/
C_Coordonnee S_positionTete(S_Serpent serpent);

/**
   @brief coordonn�es de la queue du serpent
   @param serpent le serpent
   @return coordonn�e de la queue du serpent
**/
C_Coordonnee S_positionQueue(S_Serpent serpent);

/**
   @brief fait avancer le serpent
   @param pserpent pointeur vers le serpent
   @note le serpent avance dans la direction courante et il peut grandir si l'accroissement est > 0 (d�cr�mente l'accroissement dans ce cas). Si le serpent atteint le bord du terrain, il r�appara�t de l'autre c�t�.
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
   @return 0 si la direction a �t� chang�e, -1 sinon
   @note la nouvelle direction doit �tre diff�rente de la direction courante et ne pas �tre l'oppos�e
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
   @brief teste si une coordonn�e est occup�e par le serpent
   @param serpent le serpent
   @param coord la coordonn�e
   @return true si la coordonn�e est occup�e par le serpent, false sinon
**/
bool S_estUneCoordonneeDuSerpent(S_Serpent serpent, C_Coordonnee coord);

/**
   @brief retourne les coordonn�es du serpent sous forme de tableau dynamique
   @param serpent le serpent
   @return un tableau dynamique contenant les coordonn�es du serpent (de la queue � la t�te)
   @note la m�moire allou�e pour le tableau doit �tre lib�r�e par l'appelant avec free()
   @note la premi�re coordonn�e du tableau est celle de la queue et la derni�re est celle de la t�te
**/
C_Coordonnee* S_coordonneeDuSerpent(S_Serpent serpent);

/**
   @brief lib�re la m�moire allou�e dynamiquement pour le serpent
   @param pserpent pointeur vers le serpent � lib�rer
**/
void S_liberer(S_Serpent* pserpent);
#endif

  
