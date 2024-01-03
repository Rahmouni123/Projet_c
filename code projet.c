#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct {
    int initial_state;
    int final_state;
    // Ajoutez d'autres champs nécessaires ici
} Transition;

typedef struct {
    int state_count;
    char* alphabet;
    Transition* transitions;
} Automaton;

int is_transition_valid(Automaton* automaton, char letter, int current_state) {
    for (int i = 0; i < automaton->state_count; i++) {
        if (automaton->transitions[i].initial_state == current_state &&
            automaton->transitions[i].alphabet == letter) {
            return automaton->transitions[i].final_state;
        }
    }
    return -1; // Transition invalide
}

int is_word_recognized_rec(Automaton* automaton, char* word, int current_state) {
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

int is_word_recognized(Automaton* automaton, char* word) {
    int initial_state = automaton->transitions[0].initial_state;
    return is_word_recognized_rec(automaton, word, initial_state);
}

int is_complete(Automaton* automaton) {
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

Automaton* completing(Automaton* automaton) {
    Automaton* new_automaton = malloc(sizeof(Automaton));
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

int main() {
    // Utilisez ces fonctions comme des exemples
    Automaton* automaton = /* Initialiser votre automate ici */;
    char* word = /* Initialiser votre mot ici */;

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

    Automaton* completed_automaton = completing(automaton);
    
    // Libérez la mémoire à la fin
    free(automaton->transitions);
    free(automaton);
    free(completed_automaton->transitions);
    free(completed_automaton);

    return 0;
}
