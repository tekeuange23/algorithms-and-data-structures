#ifndef FONCTIONSMATHEMATIQUES_H_INCLUDED
#define FONCTIONSMATHEMATIQUES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <conio.h>
#include "Tries.h"
#include "Structures.h"
#include "Etudiant.h"


void afficher(int *t, int dim);
int nombrePremier(int n);
void estPremier(int n);
void racineCarre(float *nbre);
void unic(int *dynamic, int stati[], int dim);

int puissance(int x, int n);     //complexite: O(N)
int puissance_DPR(int x, int n); //complexite: O(log(N))

int fibbonaci(int n);
int* create_and_init_memo(int n);
int fibbonaci_memorisation(int n, int* memo);
int fibbonaci_tabulation(int n, int* tab);


/**********************************RENDU DE MONNAIE**********************************************/
/**/    typedef struct piece{
/**/        int valeur;   //densite
/**/        int qte;      //quantite
/**/    }Piece;
/**/    Piece create_piece(int value, int qty);
/**/    void show_piece(Piece p);
/**/    Piece choisie_candidat_prometteur(Piece* candidateS, int dim, int montant);
/**/
/**/
/**/
/**/
/**/
/**/
/**/
/************************************************************************************************/













#endif // FONCTIONSMATHEMATIQUES_H_INCLUDED
