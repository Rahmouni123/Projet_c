#ifndef H_HEAD_H
#define H_HEAD_H


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



/*La fonction qui sert à importer un AEF à partir d'un fichier*/
Automate import_automate(char *chemin);

/* La fonction qui fait le miroir d'un automate saisi depuis depuis un fichier texte*/
Automate miror(Automate a);

#endif