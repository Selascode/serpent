#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "coordonnee.h"

static C_Coordonnee J_nelleCoordonneeFruit(unsigned int largeurTerrain,
					 unsigned int hauteurTerrain,
					 S_Serpent serpent) {
  return C_coordonnee(0,0);
}

unsigned int J_jouer(void* pinterface,
		     void (*afficherTerrain)(void* pinterface,
					     S_Serpent serpent,
					     C_Coordonnee coordFruit,
					     unsigned int score),
		     void (*mettreAJour)(void* pinterface,
					 S_Serpent serpent,
					 C_Coordonnee coordFruit,
					 unsigned int score),
		     D_Direction (*obtenirDirection)(void* pinterface,
						     D_Direction directionActuelle),
		     void (*accelerer) (void* pinterface),
		     unsigned int largeurTerrain,
		     unsigned int hauteurTerrain,
		     unsigned int longueurInitialeSerpent,
		     D_Direction directionInitialeSerpent) {

				
				D_Direction nelleDirection;
				unsigned int score = 0;
				S_Serpent serp = S_serpent(C_coordonnee( (largeurTerrain / 2), (hauteurTerrain / 2)), 
										   longueurInitialeSerpent,directionInitialeSerpent,
										   largeurTerrain,hauteurTerrain); 
				C_Coordonnee coordFruit = J_nelleCoordonneeFruit(largeurTerrain,hauteurTerrain,serp); 
				afficherTerrain(pinterface,serp,coordFruit,score); 
				while (! S_seMord(serp)){
					nelleDirection = obtenirDirection(pinterface,S_direction(serp)); 
					if ((nelleDirection != S_direction(serp)) && (nelleDirection != D_directionOpposee(S_direction(serp)))) {
						S_changerDirection(&serp, nelleDirection); 
					}
					S_avancer(&serp);
					if (C_sontEgales(S_positionTete(serp), coordFruit)){
						score++;
						S_accroissement(&serp,1); 
						coordFruit = J_nelleCoordonneeFruit(largeurTerrain, hauteurTerrain,serp); 
						accelerer(pinterface); 
					}
					mettreAJour(pinterface,serp,coordFruit,score); 
				}



  return 0;
}
