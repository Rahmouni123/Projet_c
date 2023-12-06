#include <stdio.h>
#include <stdlib.h>

#include "autom.h"


/*struct Noeud{
  int valeur;
  struct Noeud *suivant;
};
typedef struct Noeud *Noeud;*/

//ajouter en tete de liste
Noeud ajouterEnTete(Noeud tete, int valeur){
  Noeud newNoeud = malloc(sizeof(Noeud));
  if(newNoeud == NULL){
      fprintf(stderr, "Echec de l'Allocation\n");
  }
  newNoeud->valeur= valeur;
  newNoeud->suivant=tete;
  tete=newNoeud;
  return tete;
}
// afficher les élément de la liste
void affiche( Noeud tete){
  for (Noeud p= tete; p!=NULL; p=p->suivant)
  {printf("%d\n", p->valeur );}
}
//ajouter en queue

Noeud ajouterEnQueue(Noeud tete, int valeur){
  Noeud newNoeud = malloc(sizeof(Noeud));
  if(newNoeud == NULL){
    fprintf(stderr, "Echec de l'Allocation\n");}
  newNoeud->valeur= valeur;
  newNoeud->suivant= NULL;

    if( tete==NULL){
        return tete= newNoeud;
    }
 else{
   Noeud tmp= tete;
   while (tmp->suivant != NULL){
     tmp = tmp->suivant;
    }
   tmp->suivant= newNoeud;
   return tete;
    }
}
//verifier si la liste est vide
int estVide (Noeud tete){
  return (tete == NULL)? 1:0;
}
//supprimer en element en queue
Noeud supprimerEnQueue(Noeud tete){
  //si la liste est vide
    if (tete == NULL){
      return NULL;
    }
  //si la liste a une valeur
    if(tete->suivant == NULL){
      free(tete);
      return NULL;
    }
    //si la liste contient plus de deux elements
    Noeud tmp = tete;
    Noeud temp = tete;

    while (tete->suivant != NULL) {
      temp= tmp;
      tmp= tmp->suivant;
      }
      temp->suivant = NULL;
      free(tmp);
    return tete;

}

//supprimer un element en fin de liste
Noeud supprimerEnTete(Noeud tete){
   if(tete != NULL)
   {Noeud aRenvoyer = malloc(sizeof(Noeud));
   aRenvoyer= tete->suivant;
   free(tete);
   return aRenvoyer;}
   else{
     return NULL;
   }
}

// Fonction pour saisir dynamiquement la liste depuis l'utilisateur
Noeud saisirListe() {
    Noeud tete = NULL;
    int symbole;

    printf("Saisissez les symboles (entrez -1 pour terminer) :\n");

    while (1) {
        printf("Symbole : ");
        scanf("%d", &symbole);

        if (symbole == -1) {
            break;
        }

        tete = ajouterEnQueue(tete, symbole);
    }

    return tete;
}

//liberer la mémoire
/*void libererListe(Noeud tete) {
    Noeud courant = tete;
    while (courant != NULL) {
        Noeud temp = courant;
        courant = courant->suivant;
        free(temp);
    }
}*/

/*int main(int argc, char const *argv[]) {
  Noeud tete= NULL;
  tete= ajouterEnTete(tete, 5);
  tete= ajouterEnTete(tete, 9);
  tete= ajouterEnQueue(tete,10);
  affiche(tete);
  free(tete);
  tete = NULL;
  return 0;
}*/
