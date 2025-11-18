#include <stdlib.h>
#include <stdbool.h>
#include "serpent.h"

S_Serpent S_serpent(C_Coordonnee positionInitialeQueue,
		    unsigned int longueurInitiale,
		    D_Direction directionInitiale,
		    unsigned int largeurTerrain,
		    unsigned int hauteurTerrain) {
  // Initialisation du serpent
  LC_ListeChainee lc = LC_listeChainee(); 
  LC_ajouter(&lc, &positionInitialeQueue,C_copier);
  
  S_Serpent serpent = {lc,lc, 1, longueurInitiale-1, directionInitiale, largeurTerrain, hauteurTerrain};
  while(serpent.accroissement >=1){
    S_avancer(&serpent);
  }
  return serpent;
}

C_Coordonnee S_positionTete(S_Serpent serpent) {
  return  *((C_Coordonnee*)LC_obtenirElement(serpent.tete));
}

C_Coordonnee S_positionQueue(S_Serpent serpent) {
  return  *((C_Coordonnee*)LC_obtenirElement(serpent.queue));
}

void S_avancer(S_Serpent* pserpent) {

  // Initialisation des coordonnées de la t^te initiale /  Nouvelle
  // Initialisation de la liste chainne assocciee à la tête
  C_Coordonnee coordTete, nelleCoordonnee; 
  LC_ListeChainee nelleTete = LC_listeChainee();
  coordTete = S_positionTete(*pserpent); 
  //Ajout de la coordonnée voisine à la tête actuelle
  nelleCoordonnee = C_coordonneeVoisine(coordTete, S_direction(*pserpent), pserpent->largeurTerrain,pserpent->hauteurTerrain);
  
  //Rattachement de la nouvelle tête au serpent
  LC_ajouter(&nelleTete,&nelleCoordonnee,C_copier);
  LC_fixerListeSuivante(&pserpent->tete, nelleTete); 
  pserpent->tete=nelleTete;

  if (pserpent->accroissement == 0 ) {
    LC_supprimerTete(&pserpent->queue,C_liberer); 
  }else{
    pserpent->accroissement--; 
    pserpent->longueur++; 
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
  pserpent->longueur += longueur; 
  pserpent->accroissement = longueur; 
}

unsigned int S_longueur(S_Serpent serpent) {
  return serpent.longueur;
}

bool S_seMord(S_Serpent serpent) {
  C_Coordonnee teteActuelle =  S_positionTete(serpent);
  return S_estUneCoordonneeDuSerpent(serpent,teteActuelle);
}

bool S_estUneCoordonneeDuSerpent(S_Serpent serpent, C_Coordonnee coord) {
  // Objectif : Parcourt de tous les éléments de la LC (queue)
  // Et vérificatopn de l'égalité 
  
  
  //Récupération de la liste chainee (queue)
  bool estCoord = false; 
  C_Coordonnee coordCourante; 
  LC_ListeChainee queue = serpent.queue; 
  while(!LC_estVide(queue) && (!estCoord)){
    coordCourante = *((C_Coordonnee*)LC_obtenirElement(queue)); 
    estCoord = C_sontEgales(coord,coordCourante); 
    queue = LC_obtenirListeSuivante(queue);
  }
  return estCoord;
}
//@brief retourne les coordonn�es du serpent sous forme de tableau dynamique
C_Coordonnee* S_coordonneeDuSerpent(S_Serpent serpent) {
  unsigned int i = 0 ; 
  LC_ListeChainee queue = serpent.queue; 
  C_Coordonnee* coordonnees = (C_Coordonnee*)malloc(serpent.longueur * sizeof(C_Coordonnee));
  C_Coordonnee coordCourante; 
  while(!LC_estVide(queue)){
    coordCourante = *((C_Coordonnee*)LC_obtenirElement(queue));
    coordonnees[i] = coordCourante; 
    queue = LC_obtenirListeSuivante(queue);
    i++; 
  }
  return coordonnees;
}



void S_liberer(S_Serpent* pserpent) {
  // Suppression des pointeurs sur la tête et ceux de la queue 
  while(!LC_estVide(pserpent->queue)){
    LC_supprimerTete(&pserpent->queue, C_liberer); 
  }
  pserpent->tete = NULL; 
  pserpent->queue = NULL; 
  pserpent->longueur = 0;
  pserpent->accroissement = 0;

}

