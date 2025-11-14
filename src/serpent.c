#include <stdlib.h>
#include <stdbool.h>
#include "serpent.h"

S_Serpent S_serpent(C_Coordonnee positionInitialeQueue,
		    unsigned int longueurInitiale,
		    D_Direction directionInitiale,
		    unsigned int largeurTerrain,
		    unsigned int hauteurTerrain) {
  // Initialisation du serpent
  S_Serpent serpent = {LC_listeChainee(), LC_listeChainee(), longueurInitiale, longueurInitiale-1, directionInitiale, largeurTerrain, hauteurTerrain};
  unsigned int x = C_abscisse(positionInitialeQueue); 
  unsigned int y = C_ordonnee(positionInitialeQueue); 
  unsigned int accroissement =  serpent.accroissement;
  C_Coordonnee positionInitialeTete; 
  //Initialisation du serpent en fonction de la coordonnée de départ 
  switch(directionInitiale){
    case D_HAUT : 
      positionInitialeTete = C_coordonnee(x,y-accroissement); 
    break; 
    case D_BAS : 
      positionInitialeTete = C_coordonnee(x, y+accroissement); 
    break; 
    case D_GAUCHE : 
      positionInitialeTete = C_coordonnee(x - accroissement,y); 
    break; 
    case D_DROITE : 
      positionInitialeTete = C_coordonnee(x+accroissement,y); 
    break; 
  };
  // Ajouts des informations tete / queue au serpent  
  LC_ajouter(&serpent.tete, &positionInitialeTete, C_copier); 
  LC_ajouter(&serpent.queue, &positionInitialeQueue,C_copier); 

  return serpent;
}

C_Coordonnee S_positionTete(S_Serpent serpent) {
  return  *((C_Coordonnee*)LC_obtenirElement(serpent.tete));
}

C_Coordonnee S_positionQueue(S_Serpent serpent) {
  return  *((C_Coordonnee*)LC_obtenirElement(serpent.queue));
}

void S_avancer(S_Serpent* pserpent) {
  
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
  return NULL;
}

