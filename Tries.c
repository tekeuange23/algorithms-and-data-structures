#include "Tries.h"

/************************************************SUR LES TABLEAUX**************************************************************/
void afficheTab(int* tab, int n){
    int i;
    for(i=0; i<n; i++)
        printf("| %d |", tab[i]);
    printf("\n");
}
void permut(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void triBulles(int* t, int dim){
    int i,j;
    for(i=0; i<dim; i++)
        for(j=0; j<dim; j++)
            if(t[j+1] < t[j])
                permut(t+j,t+j+1);
}
void triSelection(int *t, int n){
    int i, j, min;
    for(i=0; i<n-1; ++i) {
        min = i;
        for(j=i+1; j<n; ++j)
            if(t[j] < t[min])
                min = j;
        if(min!=i)
            permut(t+min,t+i);
    }
}
void triPermutation(int* t, int n){
    int ranger[n],          //ce trie n'est pas en place car j'utilise un tableau intermediaire
        pos=0,i,j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(t[j]>t[i])   //si l'element en position i du tableau a N(pos) element inferieur a lui
                pos++;
        ranger[pos] = t[i]; //alors il sera place dans le tableau intermediaire en position N
        pos=0;
    }
    for(i=0; i<n; i++)      //puis on met a jour le tableau initial
        t[i] = ranger[i];
}
void triInsertion(int* t, int n){
    int i,pos,j,x;

    for(i=1; i<n; i++){
        x = t[i];
        pos = i-1;
        /**
        *
            while(t[pos] > x && pos-- > 0){}  //on trouve la position ou on doit inserer l'element ""qui est ds X""
            pos++;

            for(j = i-1; j >= pos; j--)          //on fait glisser les valeurs jusqu'a ceque la case de l'elem soit vide
                t[j+1] = t[j];
            t[pos] = x;                          //on insere l'element
        */
        while(t[pos] > x && pos > -1){
            t[pos+1] = t[pos];      //on fait coulisser les elements superieurs a X vers la droite
            pos--;
        }
        t[pos+1] = x;
    }
}

void fusion(int*t,int p, int q, int r){   //   p <= q < r

    int*tab,        //tableau alternatif
        i= p,       //indice permettant de parcourir le tableau 1
        j= q+1,     //indice permettant de parcourir le tableau 2
        k=0;        //indice permettant de parcourir le tableau TAB

    tab=(int*)malloc((r-p+1)*sizeof(int));

    while(i<=q && j<=r){
        if(t[i]<t[j]){
            tab[k] = t[i];
            i++;
        }
        else{
            tab[k] = t[j];
            j++;
        }
        k++;
    }
    while(i<=q){
        tab[k] = t[i];
        k++;
        i++;
    }
    while(j<=r){
        tab[k] = t[j];
        k++;
        j++;
    }
    for(i=p; i<=r; i++)
        t[i]=tab[i-p];      //recopie des elements trier dans le tableau alternatif dans le tableau final.

    free(tab);
}
void triFusion2(int*t,int deb,int fin){

    if(deb < fin){               // arreter triFusion(x,x)  if(x!=y)
        int mil=(fin+deb)/2;
        triFusion2(t,deb,mil);   //on envoie le moitier gauche du tableau qui se fait decoupee recurssivement
        triFusion2(t,mil+1,fin); //ensuite on envoi la moitier gauche de la MOITIE DROITE RESTANTE;
        fusion(t,deb,mil,fin);
    }
}
void triFusion(int*t,int n){
    if(n>0)
        triFusion2(t,0,n-1);
}

void echanger(int*t,int i,int j){
    int tmp;
    tmp=t[i];
    t[i]=t[j];
    t[j]=tmp;
}
int partition(int*t,int deb,int fin){

    int compt=deb;
    int pivot=t[deb];
    int i;

    for(i=deb+1;i<=fin;i++){
        if(t[i]<pivot){
            compt++;
        echanger(t,compt,i);
        }
    }
    echanger(t,compt,deb);
    return compt;
}
void tri_rapide_bis(int*t,int debut,int fin){

    if(debut<fin){
        int pivot = partition(t,debut,fin);
        tri_rapide_bis(t,debut,pivot-1);
        tri_rapide_bis(t,pivot+1,fin);
    }
}
void tri_rapide(int*t,int n){
    tri_rapide_bis(t,0,n-1);
}

//**************RECHERCHE DICHOTOMOQUE***************
int rechercheDichotomieRec(int* t, int p, int q, int x){
    if( t[(p+q)/2] == x)
        return 1;
    else if(p>q)
        return 0;
    else if(x < t[(p+q)/2])
        return rechercheDichotomieRec(t,p,(p+q)/2-1,x);
    else if(x > t[(p+q)/2])
        return rechercheDichotomieRec(t,(p+q)/2+1,q,x);
}
int rechercheDichotomie(int* t, int dim, int x){
    int test=0,
        g=0, d=dim-1,mil;
    while(!test && g<=d){
        mil = (g+d)/2;
        if(x == t[mil])
            test = 1;
        else if(x < t[mil])
            d=mil-1;
        else
            g=mil+1;
    }
    return test;
}
int rechercheSequentielle(int *tab, int dim, int x){
    int i;
    for(i=0; i<dim; i++)
        if(x == tab[i])
            return 1;
    return 0;
}
/*************************************************SUR LES LISTE CHAINEES SIMPLE************************************************/
/***trie fusion****/
/*
List* fusion(List* gauche, List* droite){
    if(gauche == NULL)
        return copy_lisst(droite);
    if(droite == NULL)
        return copy_list(gauche);
    if(gauche->value <= droite->value)
        return ajoutTete(fusion(gauche->next,droite), gauche->value);
    else
        returnajouteTete(fusion(gauche,droite->next), droite->value);
}
List* copy_list(List* list){
    if (NULL == list)
        return NULL;
    else
        return ajoutTete(copy_list(list->next) , list->value);
}
void decoupe(List *list, List **gauche, List **droite){
    do {
        if (NULL != list) {
            *gauche = cons(list->value, *gauche);
            list = list->next;
        }
        if (NULL != list) {
            *droite = cons(list->value, *droite);
            list = list->next;
        }
    }while (NULL != list);
}
List *tri_fusion(List *list){
    if (NULL == list || NULL == list->next)
        return copy_list(list);
    else{
        //au début, gauche et droite sont vides
        List *gauche = NULL,
             *droite = NULL,
             *gauche_triee,
             *droite_triee,
             *resultat;
        //on decoupe la list en gauche et droite
        decoupe(list, &gauche, &droite);

        //on trie gauche et droite, avant de les libérer
        gauche_triee = tri_fusion(gauche);
        droite_triee = tri_fusion(droite);
        free_list(gauche);
        free_list(droite);

        //on fait la fusion des deux listes triées, avant de leslibérer
        resultat = fusion(gauche_triee, droite_triee);
        free_list(gauche_triee);
        free_list(droite_triee);
        //il ne reste plus qu'à renvoyer le résultat
        return resultat;
    }
}
*/

/**************************************************SUR LES LISTE CHAINEES CIRCULAIRE*******************************************/
/**************************************************SUR LES  PILES**************************************************************/
/**************************************************SUR LES  FILES**************************************************************/
/**************************************************SUR LES LISTE DOUBLEMENT CHAINEES CIRCULAIRE********************************/
/**************************************************SUR LES LISTE DOUBLEMENT CHAINEES SIMPLE************************************/

