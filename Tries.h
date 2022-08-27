#ifndef TRIES_H_INCLUDED
#define TRIES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FonctionsMathematiques.h"
#include "Structures.h"
#include "Etudiant.h"


/*********************SUR LES TABLEAUX***************************************************/
void afficheTab(int* tab, int n);
void permut(int *a, int *b);

void triBulles(int *t, int dim);
void triSelection(int *t, int n);
void triPermutation(int* t, int n);
void triFusion(int*t,int n);


//**************RECHERCHE DICHOTOMOQUE***************
int rechercheDichotomieRec(int* t, int p, int q, int x);
int rechercheDichotomie(int* t, int dim, int x);

int rechercheSequentielle(int *tab, int dim, int x);
/*********************SUR LES LISTE CHAINEES SIMPLE***************************************/
//void triSelectionList(List** list);
//List* permut(List *l2, List *l1);
/***trie fusion****/
/*
List* fusion(List* gauche, List* droite);
List* copy_list(List* list);
void decoupe(List *liste, List **gauche, List **droite);
List* tri_fusion(List *liste);
*/
/**************************************************SUR LES LISTE CHAINEES CIRCULAIRE*******************************************/
/**************************************************SUR LES LISTE PILES*********************************************************/
/**************************************************SUR LES LISTE FILES*********************************************************/
/**************************************************SUR LES LISTE DOUBLEMENT CHAINEES CIRCULAIRE********************************/
/**************************************************SUR LES LISTE DOUBLEMENT CHAINEES SIMPLE************************************/




#endif // TRIES_H_INCLUDED
