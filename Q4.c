#include <stdio.h>
#include <stdlib.h>

// Structure pour les transitions
typedef struct {
    int etat_initial;
    int etat_final;
} Transition;

// Structure pour les automates
typedef struct {
    int nbE;
    int nSy;
    int transition;
    int ***mat;
} Automate;

// Fonction pour rendre un automate complet
void completeAutomate(Automate *automate) {
    // Ajout de l'état phi (nouvel état pour les transitions manquantes)
    int phi_state = automate->nbE;
    automate->nbE++;

    // Réallouer la mémoire pour la matrice avec l'état phi
    automate->mat = realloc(automate->mat, automate->nbE * sizeof(int**));
    for (int i = 0; i < automate->nbE; i++) {
        automate->mat[i] = realloc(automate->mat[i], automate->nSy * sizeof(int*));
        for (int j = 0; j < automate->nSy; j++) {
            automate->mat[i][j] = realloc(automate->mat[i][j], automate->nbE * sizeof(int));
        }
    }

    // Ajouter des transitions manquantes vers l'état phi
    for (int i = 0; i < automate->nbE - 1; i++) {
        for (int j = 0; j < automate->nSy; j++) {
            int transition_trouve = 0;

            for (int k = 0; k < automate->nbE; k++) {
                if (automate->mat[i][j][k] == 1) {
                    transition_trouve = 1;
                    break;
                }
            }

            if (!transition_trouve) {
                // Ajouter la transition manquante vers l'état phi
                automate->mat[i][j][phi_state] = 1;
            }
        }
    }
}
