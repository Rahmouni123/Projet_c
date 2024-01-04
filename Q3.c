#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure pour les transitions
typedef struct {
    int initial_state;
    int final_state;
} Transition;

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
