#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "FonctionsMathematiques.h"
#include "Tries.h"
#include "Structures.h"

#define NN 6

struct Etudiant
{
    int matricule;
    char name[20];
    char surname[20];
    float notes[NN];
};
// typedef struct Etudiant ETU;

struct ListEtu
{
    struct Etudiant e;
    struct ListEtudiant *next;
};
// typedef struct ListEtudiant ListEtu;

struct Etudiant *lire(struct Etudiant *etu);
void afficherEtu(struct Etudiant *etu);
struct ListEtu *enregistrer(struct ListEtu *list);
void afficherListEtu(struct ListEtu *list);
float moyenne(struct Etudiant *etu);
char *lePlusFortEn(struct ListEtu *list, int numMat);
struct Etudiant *find(struct ListEtu *list, char *nom);

#endif // ETUDIANT_H_INCLUDED
