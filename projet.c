
#include <stdio.h>
#include <stdbool.h>

struct Node{
	int val;
	struct Node *nxt;
};

typedef struct Node * Node;

Node ajouterEnTete(Node tete, int valeur){
	Node nouveauNoeud=malloc(sizeof(Node));
	nouveauNoeud->val=valeur;
	nouveauNoeud->suivant=tete;
	tete=nouveauNoeud;
	return tete;
}


int **2DmatriceAEF(int nb_etat, int nb_symbole){
	int **m= malloc(nb_etat*sizeof(int*)); 
	for (int i; i<nb_etat; i++){
        	m[i]=malloc(nb_symbol*sizeof(int)) 
        	for (int j; int<nb_symbole;j++){
            		m[i][j]=-1
        		}
    		}
        
    	}
    	
int ***3DmatriceAEF(int d1, int d2, int d3){
   	int ***m=malloc(d1*sizeof(int**));
	for (int i; i<d1; i++){
        	m[i]=malloc(d2*sizeof(int*));
        	for (int j; j<d2;j++){
            		m[j]=malloc(d3*sizeof(int));
            		for (int k; k<d3; k++){
                		m[i][j][k]=-1;
            			}
        		}
    		}
    	return m;
    	
    	
void affiche(int ***m, int d1, int d2, int d3){
for (int i=0; i<d1; i++){
	for (int j=0; j<d1; j++){
		for (int k=0; k<d1; k++){
			printf("m[%d][%d][%d]=%d\n",i,j,k,m[i][j][k]);
			}
		}
	}
}
   

    
int saisir(){
	int nb_etat;
	int nb_symbole;
	int etat_depart;
	int etat_final;
	bool booleen;
	printf("Quel est l'état de départ?");
	scanf("%d",&etat_depart);
	printf("Quel est l'état d'arrivé?");
	scanf("%d",&etat_final);
	printf("Combien y a t'il d'état ?");
	scanf("%d",&nb_etat);
	printf("Combien y a t'il de symbole?");
	scanf("%d",&nb_symbole);
	int m=3DmatriceAEF(nb_etat,nb_symbole,nb_etat);
	for (int i; i<nb_etat; i++){
		for (int j; j<nb_symbole; j++){
			for (int k; k<nb_etat; k++){
				printf("Est ce que l'état %d permet d'aller à l'état %d grâce au symbole %d ?",i,j,k)
				scanf("%d",&booleen)
				if (booleen=true){
					m[i][j][k]=1};
				else {
					m[i][j][k]=-1};
				}
			}
		}
	}
}




int main{
    return 0;
}

