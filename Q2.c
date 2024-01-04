// Fonction qui vérifier un mot
int verifierMot( Automate* automate, Noeud mot){
  int etatcourant = 0; // État initial
  //int i = 0;
  Noeud courant = mot;


  while (courant !=NULL){

    int symbole = courant -> valeur;
    if( symbole< 0 || symbole >= automate->nSy){
        printf("Erreur : Symbole non reconnu.\n");
        libererListe(mot);
        return 0;
    }
    int etatsuivant = -1;
    // Chercher une transition depuis l'état courant avce le symbole donné
    for (int j = 0; j < automate->nbE; j++) {
      if (automate->mat[etatcourant][symbole][j] == 1){
          etatsuivant = j;
          break;
      }

    }
    if (etatsuivant == -1) {
      //aucune transistions
      return 0; // mot non reconnu
    }
    etatcourant = etatsuivant;
    //++i;
    courant= courant -> suivant;
  }
  for (int k = 0; k < automate->nbE; k++) {
      if (etatcourant == automate->nbE-1){
        printf("mot reconnu\n");

        return 1; //mot reconnu
      }
  }
  printf("mot non reconnu \n");
  libererListe(mot);
  return 0; //mot non reconnu
}
