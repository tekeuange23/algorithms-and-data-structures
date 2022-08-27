#include "Etudiant.h"

struct Etudiant *lire(struct Etudiant *etu)
{
    printf("Entrez successivement: MATRICULE | NOM | PRENOM | NOTES(%d) \n", NN);

    scanf("%d", &((*etu).matricule));
    scanf("%s", etu->name);
    scanf("%s", etu->surname);
    int i;
    for (i = 0; i < NN; i++)
        scanf("%f ", etu->notes + i);
    return etu;
}
void afficherEtu(struct Etudiant *etu)
{
    printf("MATRICULE: %d \n", etu->matricule);
    printf("NAME     : %s \n", etu->name);
    printf("SURNAME  : %s \n", etu->surname);
    printf("NOTES    : ");
    int i;
    for (i = 0; i < NN; i++)
        printf("| %.2f |", (etu->notes)[i]);
    printf("\n");
    printf("MOYENNE  : %.3f \n", moyenne(etu));
}
struct ListEtu *enregistrer(struct ListEtu *list)
{
    struct Etudiant *etu = (struct Etudiant *)malloc(sizeof(struct Etudiant));
    etu = lire(etu);

    struct ListEtu *alt = (struct ListEtu *)malloc(sizeof(struct ListEtu));
    if (alt != NULL)
    {
        alt->e = *etu;
        alt->next = list;
        return alt;
    }
    else
        exit(1);
}
void afficherListEtu(struct ListEtu *list)
{

    if (list == NULL)
        printf("\n");
    else
    {
        afficherEtu(list);
        printf("\n----------------------------------------------------\n\n");
        afficherListEtu(list->next);
    }
}
float moyenne(struct Etudiant *etu)
{
    int i;
    float moy = 0;
    for (i = 0; i < NN; i++)
        moy = moy + (etu->notes)[i];

    return moy / NN;
}
char *lePlusFortEn(struct ListEtu *list, int numMat)
{

    char *nom;
    float note = 0.0;
    if (list == NULL || numMat < 1 || numMat > NN)
        return NULL;
    else
    {
        while (list != NULL)
        {
            if (list->e.notes[numMat - 1] > note)
            {
                note = list->e.notes[numMat - 1];
                nom = list->e.name;
            }
            list = list->next;
        }
        return nom;
    }
}
struct Etudiant *find(struct ListEtu *list, char *nom)
{

    if (list == NULL)
        return NULL;
    else
    {
        while (list != NULL)
        {
            if (nom == list->e.name)
                return list;
            list = list->next;
        }
    }
}