#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FonctionsMathematiques.h"
#include "Tries.h"
#include "Etudiant.h"

/************************************************LISTES SIMPLEMENT CHAINEE*****************************************************/
struct list
{

    int value;
    int length;
    struct list *next;
};
typedef struct list List;

List *ajoutTete(List *list, int elem);
List *supprimerTete(List *list);
int length(List *list);
int get(int indice, List *list);
List *concat(List *A, List *B);
List *filter(List *list);
void free_list(List *l);
void affiche(List *list);

//***************************Maillon*****************************/
struct Maillon
{

    int val;
    struct Maillon *suiv;
};
typedef struct Maillon Maillon;
typedef Maillon *Liste;

Maillon *creerMaillon(int info, Liste suiv);
void insereMaillonTete(Liste *pl, Maillon *pm);
void insereMaillonQueue(Liste *pl, Maillon *pm);
void insereMaillonI(Liste *pl, Maillon *pm, int pos);
void deleteMaillonTete(Liste *pl);
void deleteMaillonQueue(Liste *pl);
void deleteMaillonI(Liste *pl, int pos);
void deleteListe(Liste *pl);
Liste cloneListe(Liste l);

int longueur(Liste l);
void afficheMaillon(Maillon M, int aLaLigne);
void afficheListe(Liste l);
/************************************************LISTES SIMPLEMENT CHAINEE CIRCULAIRE******************************************/
struct Cellule
{
    int value;
    struct cellule *next;
};
typedef struct Cellule Cellule;
typedef Cellule *ListCirc;

Cellule *creerCellule(int val);
void AjoutTeteListCirc(ListCirc *L, Cellule *C);
void AjouteQueueListCirc(ListCirc *l, Cellule *c);
void Afficher(ListCirc l);
void AfficherRec(ListCirc l);
void AfficherBetement(ListCirc l); // debogage
/************************************************LES PILES Sur les tableaux*********************************************************************/
typedef struct Pile
{
    int s;
    int taille;
    int *tab;
} Pile;

Pile *creerPile(int taille);
int pileVide(Pile p);
int pilePleine(Pile p);
int nbreElementPile(Pile p);
void afficherPile(Pile p);
void empiler(Pile *p, int x);
void depiler(Pile *p);

int depiler2(Pile *p);
Pile *reversePile(Pile p);
void reversePile2(Pile *p);
void retourner(Pile *p, int n);
Pile *clonerPile(Pile p);
void freePile(Pile *p);
/************************************************LES FILES Sur les tableaux*********************************************************************/
typedef struct File
{
    int t;
    int q;
    int taille;
    int *tab;
} File;

File *creerFile(int taille);
int fileVide(File f);
int filePleine(File f);
int fileCircPleine(File f);
int incrementationQueue(File f);
int incrementationTete(File f);
int nbreElementFile(File f);

void afficherFile(File f);
void enfiler(File *f, int x);
void defiler(File *f);

/************************************************LISTES DOUBLEMENT CHAINEE SIMPLE**********************************************/
/************************************************LISTES DOUBLEMENT CHAINEE CIRCULAIRE******************************************/
/************************************************TABLE DE HACHAGE**************************************************************/
typedef struct MaillonH
{
    char *key;
    int value;
    struct MaillonH *next;
} MaillonH;
typedef MaillonH *ChaineH;
typedef struct TableH
{
    ChaineH *pc; // pointeur sur la cette chainage
    int taille
} TableH; // on ne va jamais utiliser une TableH**
          // je n'est par consequent pas besoin de definir(typedef) une TableH*

int Xor(char *ch);               // transforme la cles en un entier quelconque
int Or(char *ch);                // transforme la cles en un entier quelconque
int hachage(TableH t, char *ch); // transforme la cles en un entier compris entre 0--TAILLE
TableH *creerTableH();           /************* TableH[i].pc  est un MaillonH* *************/
TableH *creerTableH2();          /************* TableH->pc[i]  est un MaillonH* *************/

MaillonH *creerMaillonH(char *cles, int valeur);
void insereMaillonHQueue(ChaineH *chain, MaillonH *m); // insere un mai;llon en queue d'une chaine
void insereMaillonTableH(TableH *t, MaillonH *m);      // insere un maillon dans une Table de Hachage

void afficheMaillonH(MaillonH m);
void afficheChaineH(ChaineH c);
void afficheTableH(TableH *t);

// FONCTION DE RECHERCHES BETES ; complexite en O(TAILLE)
MaillonH *recherceChaineH(ChaineH chain, char *cles); // good
int isDefault(MaillonH m);
MaillonH *Default();
MaillonH *rechercheTableH(TableH *t, char *cles);
// bonne fonction de recherche : complexite en O(1)
MaillonH *rechercheTableHachage(TableH *t, char *cles);

/************************************************ARBRE BINAIRE*****************************************************************/
typedef struct Noeud
{
    int value;
    struct Noeud *fg; // fils gauche
    struct Noeud *fd; // fils droit
} Noeud;
typedef Noeud *Arbre;

Noeud *creerNoeud(int valeur);
Noeud *creerNode(int valeur, Noeud *fg, Noeud *fd);
int nbreDeNoeud(Arbre a);
int hauteur(Arbre a);
int plusGrand(Arbre a);
int rechercheArbre(Arbre a, Noeud n);
/************************************************ARBRE BINAIRE DE Recherche*/
int minABR(Arbre a);
int maxABR(Arbre a);
int estDeRecherche(Arbre a);
int rechercheABR(Arbre a, Noeud n);
int rechercheABR2(Arbre a, Noeud n);
void affichePrefixe(Arbre a);
void afficheInfixe(Arbre a);
void addNodeRec(Arbre *a, Noeud *n);
int successeur(Arbre a, int x);
void addNode(Arbre *a, Noeud *n);
void clearTree(Arbre *a);
void clearTree2(Arbre *a);
/************************************************ARBRE BINAIRE: LES TAS(HEAP)*/
typedef struct Arbre
{
    int capacite;
    int taille;
    int *tab;
} Tas;
int fg(int i);
int fd(int i);
int pere(int i);
Tas *createTas(int capacite);
void pushNode(Tas *tas, int n);
void reorganiserTas(Tas *tas);
void TasRealloc(Tas *tas);

void entasser(Tas *tas, int i);
void construireTas(Tas *tas);
void triTas(Tas *tas);

void afficherTas(Tas tas);
void freeTas(Tas *tas);

#ifdef __cplusplus
extern "C"
{
#endif
////////////////////prototypes c
#ifdef __cplusplus
}
#endif

#endif // STRUCTURES_H_INCLUDED
