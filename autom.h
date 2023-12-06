#include <stdlib.h>
#include <stdio.h>

#ifndef AUTOM_H
    #define   AUTOM_H
#endif
struct Automate{
  //nb d'etat et nb de symbole et la matrice
   int nbE;
   //nb de symbole
   int nSy;
   //nb de transition
   int transition;
  // matrice à 3 dimensions
   int ***mat;
};
typedef struct Automate Automate;


struct Noeud{
  int valeur;
  struct Noeud *suivant;
};
typedef struct Noeud *Noeud;


void creerAutomate (Automate* automate);
void remplirAutomate(Automate* automate);
void afficherAutomate (Automate* automate);
void supprimerAutomate(Automate* automate);
void saisirtransition(Automate* automate);
void libererListe(Noeud tete);
int verifierMot(Automate* automate, Noeud mot);
/*void copierAutomate(Automate* automate);*/
Noeud ajouterEnTete(Noeud tete, int valeur);
void affiche( Noeud tete);
Noeud ajouterEnQueue(Noeud tete, int valeur);
int estVide (Noeud tete);
Noeud supprimerEnTete(Noeud tete);
Noeud saisirListe();
