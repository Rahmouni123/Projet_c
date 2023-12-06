#include <stdio.h>
#include <stdlib.h>

#include "liste.c"



int main(int argc, char const *argv[]) {
  Automate monAutomate;
  Noeud mot= NULL;

  mot= saisirListe();
  creerAutomate(&monAutomate);
  saisirtransition(&monAutomate);
  afficherAutomate(&monAutomate);
  verifierMot(&monAutomate, mot);
  libererListe(mot);
  supprimerAutomate(&monAutomate);
  return 0;
}
