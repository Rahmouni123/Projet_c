#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Structure pour les transitions
typedef struct {
    int initial_state;
    int final_state;
} Transition;

// Structure pour les automates
typedef struct {
    int state_count;
    char *alphabet;
    Transition *transitions;
} Automaton;

// Structure pour les listes de symboles
struct Noeud {
    int valeur;
    struct Noeud *suivant;
};
typedef struct Noeud *Noeud;

typedef struct {
    int nbE;
    int nSy;
    int transition;
    int ***mat;
} Automate;

// Fonctions du premier code

int is_transition_valid(Automaton *automaton, char letter, int current_state) {
    for (int i = 0; i < automaton->state_count; i++) {
        if (automaton->transitions[i].initial_state == current_state &&
            automaton->transitions[i].alphabet == letter) {
            return automaton->transitions[i].final_state;
        }
    }
    return -1; // Transition invalide
}

int is_word_recognized_rec(Automaton *automaton, char *word, int current_state) {
    if (word[0] == '\0') {
        return current_state == automaton->transitions[0].final_state;
    } else {
        int next_state = is_transition_valid(automaton, word[0], current_state);
        if (next_state != -1) {
            return is_word_recognized_rec(automaton, word + 1, next_state);
        } else {
            return 0; // Mot non reconnu
        }
    }
}

int is_word_recognized(Automaton *automaton, char *word) {
    int initial_state = automaton->transitions[0].initial_state;
    return is_word_recognized_rec(automaton, word, initial_state);
}

int is_complete(Automaton *automaton) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char letter = automaton->alphabet[i];
        for (int j = 0; j < automaton->state_count; j++) {
            if (is_transition_valid(automaton, letter, j) == -1) {
                return 0; // Automate non complet
            }
        }
    }
    return 1; // Automate complet
}

Automaton *completing(Automaton *automaton) {
    Automaton *new_automaton = malloc(sizeof(Automaton));
    new_automaton->state_count = automaton->state_count + 1;
    new_automaton->alphabet = automaton->alphabet;
    new_automaton->transitions = malloc(new_automaton->state_count * ALPHABET_SIZE * sizeof(Transition));

    // Copiez les transitions existantes
    memcpy(new_automaton->transitions, automaton->transitions, automaton->state_count * ALPHABET_SIZE * sizeof(Transition));

    // Ajoutez la transition vers l'état phi
    new_automaton->transitions[new_automaton->state_count - 1].initial_state = new_automaton->state_count - 1;
    new_automaton->transitions[new_automaton->state_count - 1].final_state = new_automaton->state_count - 1;

    return new_automaton;
}

void creerAutomate (Automate*automate){
  int i,j;

  printf("Quel est le nombre d'état?\n" );
  scanf("%d", &(automate->nbE));

  printf("Quel est le nombre de symboles?\n" );
  scanf("%d", &(automate->nSy));

  printf("Quel est le nombre de transistions ?");
  scanf("%d", &(automate->transition));

  //alloction de la memoire pour les lignes
  automate->mat=(int***)calloc(automate->nbE,sizeof(int));

   //alloction de la memoire pour les colones
    for ( i = 0; i < automate->nbE; i++) {

     automate->mat[i]=(int**)calloc(automate->nbE,sizeof(int));
     }

          for ( i = 0; i < automate->nbE; i++) {

                    for (j = 0; j < automate->nSy; j++) {
                      automate->mat[i][j]=(int*)calloc(automate->nSy,sizeof(int));
                              }
                    }

  };

//remplir les champs de l'automate
void remplirAutomate(Automate*automate){
  int i, j,z;

  for ( i = 0; i <automate->nbE; i++) {
      for (j=0;j <automate->nSy; j++) {
          for (z = 0; z < automate->nbE; z++) {
          printf("valeur de mat[q%d][a%d][q%d]\n", i,j,z);
          scanf("%d", &(automate->mat[i][j][z]));
                        }
       }
  }


};
//afficher l'Automate
void afficherAutomate (Automate*automate){
  int i,j,z;
  for( i=0; i< automate->nbE; i++) {

    for( j=0;j<automate->nSy; j++){
       for(z=0; z< automate->nSy; z++){
          if( automate->mat[i][j][z] == 1){
          printf("[Q%d][A%d][Q%d]=[%d]\t", i,j,z, automate->mat[i][j][z] );
             }
         }
    }
      printf("\n");
  }

};

void saisirtransition(Automate*automate){
    int i, from, to, symbole;

    printf("Saisie des transition:\n");
    for ( i = 0; i < automate->transition; i++) {
      printf("Transition %d: \n",i+1 );

      printf(" Etat de départ:");
      scanf("%d", &from );

      printf("Symbole: \n");
      scanf("%d", &symbole);

      printf("Etat d'arrivée:\n");
      scanf("%d", &to);
      // vérifications du nombre des états et symbole
      if (from >=0 && from < automate->nbE && to >=0 && to < automate->nbE &&
      symbole >=0 && symbole < automate->nSy) {
        automate->mat[from][symbole][to]= 1;

      }
      else {
         printf("Erreur: Etat ou symbole hors des limites\n");
         -- i; //retour à la transition précédente
      }
    }


};

//liberer mémoire de la liste
void libererListe(Noeud tete) {
    Noeud courant = tete;
    while (courant != NULL) {
        Noeud temp = courant;
        courant = courant->suivant;
        free(temp);
    }
}

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


//liberation de la mémoire
 void supprimerAutomate(Automate*automate){
   int i,j;
  for (i = 0; i < automate->nbE; i++) {
    for (j = 0; j< automate->nSy; j++) {
        free(automate->mat[i][j]);
    }
    free(automate->mat[i]);
   }
   //free(automate->mat);
};


int main() {
    Automaton *automaton = /* Initialiser votre automate ici */;
    char *word = /* Initialiser votre mot ici */;

    if (is_complete(automaton)) {
        printf("L'automate est complet.\n");
    } else {
        printf("L'automate n'est pas complet.\n");
    }

    if (is_word_recognized(automaton, word)) {
        printf("Le mot est reconnu par l'automate.\n");
    } else {
        printf("Le mot n'est pas reconnu par l'automate.\n");
    }

    Automaton *completed_automaton = completing(automaton);

    free(automaton->transitions);
    free(automaton);
    free(completed_automaton->transitions);
    free(completed_automaton);

    return 0;
}
