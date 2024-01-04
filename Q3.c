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
