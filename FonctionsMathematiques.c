#include "FonctionsMathematiques.h"

void afficher(int *t, int dim){

    int i;
    for(i=0; i<dim; i++)
        printf("| %d |",t[i]);
    printf("\n");
}
int nombrePremier(int n){
    int i=3;
    int test=1;

    if (n<=1 || n%2==0 && n!=2)
        test=0;
    else
        while (i <= n/2 && test == 1){
            printf("%d ",i);
            if(n%i == 0)
                test=0;
            i = i+2;
        }
    return test;
}
void estPremier(int n){
    if(nombrePremier(n) == 1)
        printf("%d est un nombre premier! \n", n);
    else
        printf("%d n\'est pas un nombre premier! \n", n);
}
void racineCarre(float *nbre){

    float i=0;
    while(i*i<*nbre)
        i=i+0.1;

    *nbre=i;
}
void unic(int *dynamic, int stati[], int dim){

    dynamic=(int*)malloc(dim*sizeof(int));
    //selection
    int i,j=1;
    dynamic[0]=stati[0];
    for(i=1; i<dim; i++)
        if( !rechercheSequentielle(dynamic,j,stati[i]) ){       //on selectionne un element de la liste static et
            dynamic[j]=stati[i];
            j++;                                    //on regarde s'il est dans la liste dynamic
    }                                           //si c'est pas le cas, on l'insere dans cette derniere
}


/** LA RECURSIVITE
  *
**/
int puissance(int x, int n){
    if(n == 0)
        return 1;
    else
        return x*puissance(x,n-1);
}
int puissance_DPR(int x, int n){
    if(n == 0)
        return 1;
    else if (n%2 == 0){
        int a = puissance_DPR(x,n/2);
        return a*a;
    }
    else
        return x*puissance_DPR(x,n-1);
}
int fibbonaci(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibbonaci(n-1) + fibbonaci(n-2);
}


/** PROGRAMMATION DYNAMIQUE
  *
**/
int* create_and_init_memo(int n){                   //creation de la liste de memorisation

    int* memo = (int*)malloc((n+1)*sizeof(int));    //create
    int i;
    for(i=0; i<n+1; i++)                            //initialise
        memo[i]=-1;
    return memo;                                    //then return
}
int fibbonaci_memorisation(int n, int* memo){
    if(n == 0)              //si  u0
        memo[0] = 0;
    else if(n == 1)         //si  u1
        memo[1] = 1;
    else if(memo[n]==-1)    //si n n'est pas dans memo
        memo[n] = fibbonaci_memorisation(n-2, memo)  +  fibbonaci_memorisation(n-1, memo) ;

    return memo[n];
}
int fibbonaci_tabulation(int n, int* tab){
    tab[0] = 0;
    tab[1] = 1;

    int i;
    for(i=2; i<n+1; i++)
        tab[i] = tab[i-1] + tab[i-2];

    return tab[n];
}


/**********************************RENDU DE MONNAIE**********************************************/
/**
Piece create_piece(int value, int qty){
    //Piece* p = (Piece*)malloc(1*sizeof(Piece));
    Piece p;
    p.valeur = value;
    p.qte = qty;

    return p;
}

int candidat_vide(Piece* candidateS, int dim){

    int i,
        vide=0;
    for(i=0; i<dim; i++)
        vide = vide || (candidateS[i].qte != 0);
    return vide;
}
Piece choisie_candidat_prometteur(Piece* candidateS, int dim, int montant){

    //recherche d'un maximun dans un tableau qui doit etre inferieur au $montant
    int i;
    Piece max = create_piece(0,0);

    for(i=0; i<dim; i++){
        if(candidateS[i].valeur < montant   &&  candidateS[i].valeur > max.valeur){
            max = candidateS[i];
            max.qte = 1;
            candidateS[i].qte --;
        }
    }
    return max;
}

Piece* vorace(Piece* candidateS, int dim, int m5ontant){                 //montant a rembourser

    Piece* solution = (Piece*)malloc(dim*sizeof(Piece));                // creation de la solution S0
    int i;  for(i=0; i<dim; i++)    solution[i] = create_piece(0,0);    //initialisation

    int S_pas_solution = 0;
    while(!S_pas_solution  &&  candidat_vide(candidateS, dim)){
        Piece x = choisie_candidat_prometteur(candidateS, dim, montant);
        montant = montant - x.valeur;
    }
}
void show_piece(Piece p){
    printf("--------------------------\n");
    printf("| valeur = %d\n",p.valeur);
    printf("| qte = %d\n",p.qte);
    printf("--------------------------\n");
}

*/














