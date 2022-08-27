#include "Structures.h"

/************************************************LISTES SIMPLEMENT CHAINEE*****************************************************/
List *ajoutTete(List *list, int elem)
{
    List *l = (List *)malloc(sizeof(List));
    l->value = elem;
    l->next = list;
    return l;
}
List *supprimerTete(List *list)
{
    if (list == NULL)
        return list;
    List *l = list->next;
    free(list);
    return l;
}
int length(List *list)
{
    if (list == NULL)
        return 0;
    else
        return 1 + length(list);
}
int get(int indice, List *list)
{
    if (indice > 0 && indice < 1 + length(list) && list != NULL)
    {
        if (indice == 1)
            return list->value;
        else
            return get(--indice, list->next);
    }
    else
    {
        printf("Probleme d'indice ou de liste");
        exit(1);
    }
}

//***************************Maillon*****************************/
Maillon *creerMaillon(int info, Liste suiv)
{
    Maillon *m = (Maillon *)malloc(1 * sizeof(Maillon));
    m->val = info;
    m->suiv = suiv;
    return m;
}
void insereMaillonTete(Liste *pl, Maillon *pm)
{
    if (pm != NULL)
    {
        pm->suiv = *pl;
        *pl = pm;
    }
}
void insereMaillonQueue(Liste *pl, Maillon *pm)
{
    if (*pl == NULL)
        *pl = pm;
    else
        insereMaillonQueue(&((*pl)->suiv), pm);
}
void insereMaillonI(Liste *pl, Maillon *pm, int pos)
{
    if (pos < 1 || pos > longueur(*pl) + 2)
        return;
    else if (pos == 1)
        insereMaillonTete(pl, pm);
    else if (pos == 2)
    {
        pm->suiv = (*pl)->suiv;
        (*pl)->suiv = pm;
        return;
    }
    insereMaillonI(&((*pl)->suiv), pm, --pos);
}

void deleteMaillonTete(Liste *pl)
{
    if (*pl != NULL)
    {
        Liste alt = *pl;
        *pl = alt->suiv;
        free(alt);
    }
}
void deleteMaillonQueue(Liste *pl)
{
    if (*pl == NULL)
        return;
    else if ((*pl)->suiv == NULL)
    {
        Maillon *alt = *pl;
        *pl = NULL;
        free(alt);
        return;
    }
    deleteMaillonQueue(&((*pl)->suiv));
}
void deleteMaillonI(Liste *pl, int pos)
{
    if (pos < 1 && pos > longueur(*pl) + 1)
        return;
    else if (pos == 1)
        deleteMaillonTete(pl);
    else if (pos == 2 && (*pl) != NULL)
    {
        Maillon *alt = (*pl)->suiv;
        (*pl)->suiv = alt->suiv;
        free(alt);
        return;
    }
    deleteMaillonI(&((*pl)->suiv), --pos);
}
void deleteListe(Liste *pl)
{
    int i;
    for (i = 1; i <= longueur(*pl); i++)
        deleteMaillonTete(pl);
}
Liste cloneListe(Liste l)
{
    Liste l1 = l,
          clone = NULL;
    while (l1 != NULL)
    {
        Maillon *m = creerMaillon(l1->val, NULL);
        insereMaillonQueue(clone, m);
        free(m);
        l1 = l1->suiv;
    }
}

int longueur(Liste l)
{
    if (l == NULL)
        return 0;
    else
        return 1 + longueur(l->suiv);
}
void afficheMaillon(Maillon M, int aLaLigne)
{
    if (aLaLigne)
        printf("| %d |\n", M.val);
    else
        printf("| %d |", M.val);
}
void afficheListe(Liste l)
{
    while (l != NULL)
    {
        afficheMaillon(*l, 0);
        l = l->suiv;
    }
    printf("\n");
}

/************************************************LISTES SIMPLEMENT CHAINEE CIRCULAIRE******************************************/
Cellule *creerCellule(int val)
{
    Cellule *c = (Cellule *)malloc(sizeof(Cellule));
    c->value = val;
    c->next = NULL;
    return c;
}
void AjoutTeteListCirc(ListCirc *L, Cellule *C)
{

    Cellule *l1 = *L;
    if (l1 != NULL)
    {

        while (l1 != *L)
            l1 = l1->next;
        C->next = *L;
        l1 = C;
        *L = l1;
    }
    else
    {
        C->next = C;
        (*L) = C->next;
    }
}
void AjouteQueueListCirc(ListCirc *l, Cellule *c)
{

    if (*l == NULL)
        AjouteQueueListCirc(l, c);
    else
    {

        ListCirc l1 = (*l)->next;
        while (l1 != (*l))
            l1 = l1->next;
        c->next = l1;
        l1 = c;
    }
}
void Afficher(ListCirc l)
{
    ListCirc l1 = l;

    printf("| %d |", l1->value);
    l1 = l1->next;

    while (l1 != l)
    {
        printf("| %d |", l1->value);
        l1 = l1->next;
    }
    printf("\n");
}
void AfficherRec(ListCirc l)
{
    // if(l != NULL){
    printf("| %d |", l->value);
    if (l->next != l)
        AfficherRec(l->next);
    printf("\n");
}
void AfficherBetement(ListCirc l)
{
    ListCirc l1 = l;
    while (l1 != NULL)
    {
        printf("| %d |", l1->value);
        l1 = l1->next;
    }
}

/************************************************LES PILES Sur les tableaux*********************************************************************/
Pile *creerPile(int taille)
{
    Pile *p = (Pile *)malloc(sizeof(Pile));
    p->s = -1;
    p->taille = taille;
    p->tab = (int *)malloc(taille * sizeof(int));
    return p;
}
int pileVide(Pile p)
{
    return (p.s == -1);
}
int pilePleine(Pile p)
{
    return (p.s + 1 == p.taille);
}
int nbreElementPile(Pile p)
{
    return p.s + 1;
}

void afficherPile(Pile p)
{
    int i;
    for (i = p.s; i > -1; i--)
        printf("| %d |", p.tab[i]);

    printf(pilePleine(p) ? "->END\n" : "\n");
}
void empiler(Pile *p, int x)
{

    if (!pilePleine(*p))
        p->tab[++p->s] = x;
    else
        printf("Empiler :: pile pleine...!\n");
}
void depiler(Pile *p)
{

    if (!pileVide(*p))
        // return p->tab[p->s --];
        p->s--;
    else
        printf("Depiler :: Pile vide...!");
}

int depiler2(Pile *p)
{

    if (!pileVide(*p))
        return p->tab[p->s--];
}
Pile *reversePile(Pile p)
{

    Pile *acc = creerPile(p.taille);

    while (!pileVide(p))
        empiler(acc, depiler2(&p));

    return acc;
}
void reversePile2(Pile *p)
{
    Pile *acc = creerPile(p->taille);

    while (!pileVide(*p))
    {
        empiler(acc, depiler2(p));
    }

    acc = reversePile(*acc);

    while (!pileVide(*acc))
        empiler(p, depiler2(acc));

    freePile(acc);
}
void retourner(Pile *p, int n)
{

    Pile *acc = creerPile(n); // l'accumulateur qui va revoir les N premiers elements

    while (!pileVide(*p) && n > 0)
    {
        empiler(acc, depiler2(p));
        n--;
    }
    acc = reversePile(*acc);
    while (!pileVide(*acc))
        empiler(p, depiler2(acc));

    freePile(acc);
}
Pile *clonerPile(Pile p)
{

    Pile *clone = creerPile(p.taille);

    while (!pileVide(p))
        empiler(clone, depiler2(&p));

    return reversePile(*clone);
}
void freePile(Pile *p)
{
    free(p->tab);
    free(p);
    p = NULL;
}

/************************************************LES FILES Sur les tableaux*********************************************************************/
File *creerFile(int taille)
{
    File *f = (File *)malloc(sizeof(File));
    f->t = 0;
    f->q = 0;
    f->taille = taille;
    f->tab = (int *)malloc((1 + taille) * sizeof(int));
    int i;
    for (i = 0; i < taille; i++)
        f->tab[i] = 0;
    return f;
}
int fileVide(File f)
{
    return (f.t == f.q);
}
int filePleine(File f)
{
    return (f.q == f.taille);
}
int fileCircPleine(File f)
{
    return (incrementationQueue(f) == f.t);
}
int incrementationQueue(File f)
{
    if (f.q == f.taille)
        return 0;
    else
        return (f.q + 1);
}
int incrementationTete(File f)
{
    if (f.t == f.taille - 1)
        return 0;
    else
        return (f.t + 1);
}
int nbreElementFile(File f)
{
    if (f.t == f.q)
        return 0;
    else if (f.t < f.q)
        return f.q - f.t;
    else
        return f.taille - f.t + f.q;
}

void afficherFile(File f)
{

    int i;
    if (fileVide(f))
        return;
    else if (f.t < f.q)
    {
        for (i = f.t; i < f.q; i++)
            printf("| %d |", f.tab[i]);
        printf(fileCircPleine(f) ? "->END\n" : "\n");
    }
    else
    {
        for (i = f.t; i < f.taille; i++)
            printf("/ %d /", f.tab[i]);
        for (i = 0; i < f.q; i++)
            printf("/ %d /", f.tab[i]);
        printf(fileCircPleine(f) ? "->END\n" : "\n");
    }
}
void enfiler(File *f, int x)
{

    if (!fileCircPleine(*f))
    {
        if (f->q == f->taille)
            f->q = incrementationQueue(*f); // si la queue pointe sur la dernierre case du tableau qu'on n'utilise pas

        f->tab[f->q] = x;
        f->q = incrementationQueue(*f);
    }
    else
        printf("Enfiler :: File pleine...!\n");
}
void defiler(File *f)
{
    if (!fileVide(*f) && f->t != f->taille)
    {
        // return f->tab[f->t++]
        f->tab[f->t] = 0;
        f->t = incrementationTete(*f);
    }
    else
        printf("Defiler :: File vide...!\n");
}

/************************************************TABLE DE HACHAGE**************************************************************/
/////////////////HACHAGE////////////////////
int Xor(char *ch)
{
    int i, r = 0;
    for (i = 0; ch[i] != '\0'; i++)
        r = r ^ ch[i];
    return r;
}
int Or(char *ch)
{
    int i, r = 0;
    for (i = 0; ch[i] != '\0'; i++)
        r = r + ch[i];
    return r;
}
int hachage(TableH t, char *ch)
{
    return ((Xor(ch) + Or(ch) + strlen(ch)) % t.taille);
}
TableH *creerTableH(int taille)
{
    int i;
    TableH *tab = (TableH *)malloc(sizeof(TableH));

    tab->pc = (ChaineH *)malloc(taille * sizeof(ChaineH));
    for (i = 0; i < taille; i++)
        tab->pc[i] = NULL;
    tab->taille = taille;
}
/////////////////INSERTION//////////////////
MaillonH *creerMaillonH(char *cles, int valeur)
{
    MaillonH *m = (MaillonH *)malloc(sizeof(MaillonH *));
    m->key = cles;
    m->value = valeur;
    m->next = NULL;
    return m;
}
void insereMaillonHQueue(ChaineH *chain, MaillonH *m)
{
    if (*chain == NULL)
        *chain = m;
    else
        insereMaillonHQueue(&((*chain)->next), m);
}
void insereMaillonTableH(TableH *t, MaillonH *m)
{
    int index = hachage(*t, m->key);
    insereMaillonHQueue(&(t->pc[index]), m);
}
/////////////////AFFICHAGE//////////////////
void afficheMaillonH(MaillonH m)
{
    printf("-| %s :: %d |-", m.key, m.value);
}
void afficheChaineH(ChaineH c)
{
    while (c != NULL)
    {
        afficheMaillonH(*c);
        c = c->next;
    }
}
void afficheTableH(TableH *t)
{
    int i;
    for (i = 0; i < t->taille; i++)
    {
        printf("%d ->", i);
        afficheChaineH(t->pc[i]);
        printf("\n");
    }
}
/////////////////RECHERCHE//////////////////
MaillonH *recherceChaineH(ChaineH chain, char *cles)
{
    if (chain == NULL)
        return Default();
    else if (chain->key == cles)
        return chain;
    else
        recherceChaineH(chain->next, cles);
}
int isDefault(MaillonH m)
{
    return (m.key == "0000" && m.value == 0);
}
MaillonH *Default()
{
    return creerMaillonH("0000", 0);
}
MaillonH *rechercheTableHachage(TableH *t, char *cles)
{
    int index = hachage(*t, cles);

    return recherceChaineH(t->pc[index], cles);
}

/************************************************ARBRE BINAIRE*****************************************************************/
Noeud *creerNoeud(int valeur)
{
    Noeud *n = (Noeud *)malloc(sizeof(Noeud));
    n->value = valeur;
    n->fg = NULL;
    n->fd = NULL;
    return n;
}
Noeud *creerNode(int valeur, Noeud *fg, Noeud *fd)
{
    Noeud *n = (Noeud *)malloc(sizeof(Noeud));
    n->value = valeur;
    n->fg = fg;
    n->fd = fd;
    return n;
}
int nbreDeNoeud(Arbre a)
{
    if (a == NULL)
        return 0;
    else
        return 1 + nbreDeNoeud(a->fd) + nbreDeNoeud(a->fg);
}
int hauteur(Arbre a)
{
    int x, y;
    if (a == NULL)
        return 0;
    else if (a->fg != NULL || a->fd != NULL)
        return 1 + (((x = hauteur(a->fg)) > (y = hauteur(a->fd))) ? x : y);
}
int plusGrand(Arbre a)
{
    int x, y, m, MAX;

    if (a == NULL) // pointe sur NULL
        return;
    else
        MAX = a->value;

    return (x = MAX > (m = plusGrand(a->fg)) ? MAX : m) > (y = plusGrand(a->fd)) ? x : y;
    // on trouve le max du sous arbre qauche que l'on met dans X
    // on trouve le max du sous arbre droit  que l'on met dans Y
    // puis on compare les deux vsleurs
}
int rechercheArbre(Arbre a, Noeud n)
{
    if (a == NULL)
        return 0;
    else if (a->value == n.value)
        return 1;
    else
        return (rechercheArbre(a->fg, n)) + (rechercheArbre(a->fd, n));
}
/************************************************ARBRE BINAIRE DE RECHERCHE*/
int minABR(Arbre a)
{

    Noeud *a1 = NULL;
    while (a)
    {
        a1 = a;
        a = a->fg;
    }
    if (a1)
        return a1->value;
}
int maxABR(Arbre a)
{

    Noeud *a1 = NULL;
    while (a)
    {
        a1 = a;
        a = a->fd;
    }
    if (a1)
        return a1->value;
}
int estDeRecherche(Arbre a)
{
    if (a == NULL)
        return 1;
    if (a->fg != NULL)
        return (a->value > a->fg->value) ? 1 : 0;
    if (a->fd != NULL)
        return (a->value < a->fd->value) ? 1 : 0;
    return (estDeRecherche(a->fg)) && (estDeRecherche(a->fd));
}
int rechercheABR(Arbre a, Noeud n)
{
    if (a == NULL)
        return 0;
    else if (a->value == n.value)
        return 1;
    else if (n.value < a->value)
        rechercheABR(a->fg, n);
    else
        rechercheABR(a->fd, n);
}
int rechercheABR2(Arbre a, Noeud n)
{
    while (a)
    {
        if (n.value == a->value)
            return 1;
        else if (n.value < a->value)
            a = a->fg;
        else
            a = a->fd;
    }
    return 0;
}
void affichePrefixe(Arbre a)
{
    if (a != NULL)
    {
        printf("%d \n", a->value);
        affichePrefixe(a->fg);
        affichePrefixe(a->fd);
    }
}
void afficheInfixe(Arbre a)
{
    if (a != NULL)
    {
        afficheInfixe(a->fg);
        printf("%d \n", a->value);
        afficheInfixe(a->fd);
    }
}
void afficheInfixe2(Arbre a)
{

    if (a == NULL)
        return; // ce return nous permet de remonter au PERE

    if (a->fg != NULL)
        afficheInfixe2(a->fg);

    printf("%d \n", a->value);

    if (a->fd != NULL)
        afficheInfixe2(a->fd);
}
void afficheSuffixe(Arbre a)
{
    if (a != NULL)
    {
        afficheSuffixe(a->fg);
        afficheSuffixe(a->fd);
        printf("%d \n", a->value);
    }
}
void addNodeRec(Arbre *a, Noeud *n)
{
    if (*a == NULL)
    {
        *a = n;
        return;
    }
    else if (n->value < (*a)->value)
        addNodeRec(&((*a)->fg), n);
    else
        addNodeRec(&((*a)->fg), n);
}
void addNode(Arbre *a, Noeud *n)
{

    Arbre a1 = *a,
          a2;

    if (a1 != NULL)
    {
        do
        {
            a2 = a1;
            if (n->value < a1->value)
            {
                a1 = a1->fg;
                if (a1 == NULL)
                    a2->fg = n;
            }
            else
            {
                a1 = a1->fd;
                if (a1 == NULL)
                    a2->fd = n;
            }
        } while (a1 != NULL);
    }
    else
        a1->value = n;
}
int successeur(Arbre a, int x)
{
    int succ = -99999;
    Arbre gauche = a;
    while (a && succ == -99999)
    {

        if (x == a->value)
        {
            if (a->fd)
                succ = minABR(a->fd);
            else
                succ = gauche->value;
            break;
        }
        else if (x < a->value)
        {
            gauche = a;
            a = a->fg;
        }
        else
            a = a->fg;
    }
    return succ;
}
void clearTree(Arbre *a)
{
    if ((*a) != NULL)
    {
        clearTree(&((*a)->fg));
        clearTree(&((*a)->fd));
        free(*a);
        *a = NULL;
    }
}
void clearTree2(Arbre *a)
{
    Arbre a1 = *a;
    if (a1 == NULL)
        return;
    if (a1->fg != NULL)
        clearTree2(&a1->fg);
    if (a1->fd != NULL)
        clearTree2(&a1->fd);
    free(a1);
    *a = NULL;
}

/************************************************ARBRE BINAIRE: LES TAS(Tas)*/
int fg(int i)
{
    return 2 * i + 1;
}
int fd(int i)
{
    return 2 * i + 2;
}
int pere(int i)
{
    if (i % 2 == 0)
        return (i / 2 - 1);
    else
        return (i / 2);
}

Tas *createTas(int capacite)
{

    Tas *tas = (Tas *)malloc(sizeof(Tas));
    if (!tas)
        return NULL;
    tas->tab = (int *)malloc(capacite * sizeof(Tas));
    if (!tas->tab)
        return NULL;
    tas->capacite = capacite;
    tas->taille = 0;
    return tas;
}
void pushNode(Tas *tas, int n)
{

    if (tas->taille >= tas->capacite - 1)
        TasRealloc(tas);
    tas->tab[++tas->taille] = n; // j'avance j'ajoute
    reorganiserTas(tas);
}
void reorganiserTas(Tas *tas)
{
    int size = tas->taille,
        capa = tas->capacite;
    while (size > 0)
    { // ie    pere(size) > -1
        if (tas->tab[pere(size)] < tas->tab[size])
            permut(tas->tab + pere(size), tas->tab + size);
        size = pere(size);
    }
}
void TasRealloc(Tas *tas)
{
    int new_size = 2 * tas->capacite;
    tas->tab = realloc(tas->tab, new_size * sizeof(int));
    tas->capacite = new_size;
}

void entasser(Tas *tas, int i)
{
    int g = fg(i),
        d = fd(i),
        max = i;
    if (g <= tas->taille && tas->tab[max] < tas->tab[g])
        max = g;
    if (d <= tas->taille && tas->tab[max] < tas->tab[d])
        max = d;
    if (max != i)
        permut(&max, &i);
    entasser(tas, max);
}
void construireTas(Tas *tas)
{
    int i;
    tas->capacite = tas->taille;

    for (i = tas->taille / 2; i > 0; i--)
        entasser(tas, i);
}
void triTas(Tas *tas)
{
    int i;
    for (i = tas->taille; i < 1; i--)
    {
        permut(tas->tab + i, tas->tab + 0); // on met le maximun du tableau a la derniere case
        tas->capacite--;
        entasser(tas, 0); // puis on met l maximux du tableau restant a la position 0
    }
}

void afficherTas(Tas tas)
{
    int i;
    for (i = 0; i < tas.taille; i++)
        printf("| %d |", tas.tab[i]);
    printf("\n");
}
void freeTas(Tas *tas)
{
    free(tas->tab);
    free(tas);
}
