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

  // Initialisation 
  C_Coordonnee coordTete, nelleCoordonnee; 
  LC_ListeChainee nelleTete = LC_listeChainee();

  coordTete = S_positionTete(*pserpent); 
  nelleCoordonnee = C_coordonneeVoisine(coordTete, S_direction(*pserpent), pserpent->largeurTerrain,pserpent->hauteurTerrain);
 
  LC_ajouter(&nelleTete,&nelleCoordonnee,C_copier);
  LC_fixerListeSuivante(&pserpent->tete, nelleTete); 
  pserpent->tete=nelleTete;

  if (pserpent->accroissement == 0 ) {
    LC_supprimerTete(&pserpent->queue,C_liberer); 
  }else{
    pserpent->accroissement = pserpent->accroissement+1; 
    pserpent->longueur = pserpent->longueur+1; 
  }
}

D_Direction S_direction(S_Serpent serpent) {
  return serpent.direction;
}

int S_changerDirection(S_Serpent* pserpent, D_Direction nouvelleDirection) {
  int aChange = -1; 
  D_Direction directionCourante = S_direction(*pserpent);
  D_Direction directionOpposee = D_directionOpposee(directionCourante); 
  if((directionCourante!= nouvelleDirection)&&(directionCourante!= directionOpposee)){
    pserpent->direction = nouvelleDirection;
    aChange = 0; 
  }

  return aChange;
}

void S_accroissement(S_Serpent* pserpent, unsigned int longueur) {
  pserpent->longueur = pserpent->longueur + longueur; 
  

}

unsigned int S_longueur(S_Serpent serpent) {
  return serpent.longueur;
}

bool S_seMord(S_Serpent serpent) {
  return false;
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

