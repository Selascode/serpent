#include <ncurses.h>
#include <time.h>
#include "interface.h"

I_Interface I_interface(unsigned int largeur, unsigned int hauteur) {
  I_Interface res;
  res.largeur = largeur;
  res.hauteur = hauteur;
  res.ralentissement.tv_sec = 0;
  res.ralentissement.tv_nsec = 500 * 1000000L; // une demi secondes
  initscr(); // initialise ncurse
  clear();   // efface le terminal
  cbreak();  // entree immediate
  noecho();  // on n'affiche pas le caractère de la touche
  keypad(stdscr, TRUE); // activer touches speciales
  nodelay(stdscr, TRUE); // getch() ne bloque pas
  return res;
}

void I_afficherTerrain(void* pinterface,
		       S_Serpent serpent,
		       C_Coordonnee fruit,
		       unsigned int score) {
  int i, j;
  unsigned int largeur = ((I_Interface*)pinterface)->largeur;
  unsigned int hauteur = ((I_Interface*)pinterface)->hauteur;
  C_Coordonnee *pcoordonnee;
  for (i = 0; i <= largeur + 1; i++) {
    mvprintw(0, i, "#");
    mvprintw(hauteur + 1, i, "#");
  }
  for (j = 0; j <= hauteur + 1; j++) {
    mvprintw(j, 0, "#");
    mvprintw(j, largeur + 1, "#");
  }
  pcoordonnee = S_coordonneeDuSerpent(serpent);
  for (i = 0; i < S_longueur(serpent); i++) {
    mvprintw(C_ordonnee(pcoordonnee[i]) + 1, C_abscisse(pcoordonnee[i]) + 1, "O");
  }
  mvprintw(C_ordonnee(fruit)+1, C_abscisse(fruit)+1, "+");
  ((I_Interface*)pinterface)->precedenteCoordonneeQueue = S_positionQueue(serpent);
  mvprintw(hauteur + 3, 0, "Score : %u", score);
}

void I_mettreAJour(void* pinterface,
		   S_Serpent serpent,
		   C_Coordonnee fruit,
		   unsigned int score) {
  C_Coordonnee tete = S_positionTete(serpent);
  C_Coordonnee queue = S_positionQueue(serpent);
  C_Coordonnee precedenteCoordonneeQueue = ((I_Interface*)pinterface)->precedenteCoordonneeQueue;
  mvprintw(C_ordonnee(tete) + 1, C_abscisse(tete) + 1, "O");
  mvprintw(C_ordonnee(fruit)+1, C_abscisse(fruit)+1, "+");
  if (!C_sontEgales(precedenteCoordonneeQueue, queue)) {
    mvprintw(C_ordonnee(precedenteCoordonneeQueue) + 1, C_abscisse(precedenteCoordonneeQueue) + 1, " ");
    ((I_Interface*)pinterface)->precedenteCoordonneeQueue = queue;
  }
  mvprintw(((I_Interface*)pinterface)->hauteur + 3, 0, "Score : %u", score);
  nanosleep(&((I_Interface*)pinterface)->ralentissement,NULL);
}

D_Direction I_obtenirDirection(void* pinterface,
			       D_Direction directionActuelle) {
  int ch = getch();
  switch (ch) {
  case KEY_UP:
    return D_HAUT;
  case KEY_DOWN:
    return D_BAS;
  case KEY_LEFT:
    return D_GAUCHE;
  case KEY_RIGHT:
    return D_DROITE;
  default:
    return directionActuelle;
  }
}

void I_accelerer(void* pinterface) {
  ((I_Interface*)pinterface)->ralentissement.tv_nsec -= 500;
}

void I_fermer(void* pinterface) {
  nodelay(stdscr, FALSE);  
  keypad(stdscr, FALSE);   
  echo();                  
  nocbreak();
  endwin();
}

