#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "code.h"


/*La fonction qui sert à importer un AEF à partir d'un fichier*/
Automate import_automate(char *Fichier){

    //Déclaration des variables locales
    Automate a;
    FILE *fichier;
    char nomFichier[] = "/home/cytech/Desktop/Yasmine/Import file/f.txt";
    char caractere;
 
    //Instructions
    /*Ouverture du fichier en mode lecture*/
    fichier = fopen(nomFichier, "r");
 
    /*Vérification si le fichier est ouvert avec succès*/
    if (fichier != NULL) {
        /*Lecture et affichage du contenu du fichier caractère par caractère*/
        while ((caractere = fgetc(fichier)) != EOF) {
            printf("%c", caractere);
        }
        /* Fermeture du fichier après utilisation*/
        fclose(fichier);
    } else {
        /*Affichage d'un message si l'ouverture a échoué*/
        printf("Impossible d'ouvrir le fichier.\n");
    }
 
    //La fonction retourne
    return a;
 
}


/* La fonction qui fait le miroir d'un automate saisi depuis depuis un fichier texte*/
Automate miror(Automate a){

    
};


/* Le main pour faire les testes ici*/
int main(){

    // Vars 
    Automate a_test;
    char chemin [] = "/home/cytech/Desktop/Yasmine/Import file/f.txt";

    // Appels de fonctions
    a_test = import_automate(chemin);


}