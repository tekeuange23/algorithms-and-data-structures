#include "FonctionsMathematiques.h"

int main()
{

    /*  ************** LISTE
        List* l = NULL;
        for(i=0;)
        ajoutTete(Liste,10);
        */
    /*  ************** MAILLON
        Liste list = NULL;
        int i;
        for(i=10; i>0; i--){
            Maillon* M = creerMaillon(--i,NULL);
            afficheMaillon(*M,1);
            insereMaillonTete(&list,M);
        }
        afficheListe(list);

        //inserer en position i
        printf("3\n");
        insereMaillonI(&list,creerMaillon(1200,NULL),3);
        afficheListe(list);

        printf("1\n");
        insereMaillonI(&list,creerMaillon(1200,NULL),1);
        afficheListe(list);

        printf("taille+1\n");
        insereMaillonI(&list,creerMaillon(1200,NULL),1+longueur(list));
        afficheListe(list);

        printf("queue\n");
        insereMaillonQueue(&list,(creerMaillon(1200,NULL)));
        afficheListe(list);

        //suppression
        printf("supression\ntete\n");
        deleteMaillonTete(&list);
        afficheListe(list);

        printf("queue\n");
        deleteMaillonQueue(&list);
        afficheListe(list);

        printf("3\n");
        deleteMaillonI(&list,3);
        afficheListe(list);
        */
    /*  ************** LISTCIRC

        ListCirc list = NULL;
        int i;
        for(i=4; i>0; i--){
            AjoutTeteListCirc(&list,creerCellule(i));
            printf("OK\n");
        }
        //AjouteQueueListCirc(&list,creerCellule(5));
        printf("OK\n");

        //AfficherBetement(list);
        AfficherRec(list);
        */
    /*  ************** ETUDIANTS
    struct ListEtu *le = NULL;
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("Student %d \n", i + 1);
        le = enregistrer(le);
        printf("\n End Student %d \n", i + 1);
    }
    afficherListEtu(le);
    for (i = 1; i <= NN; i++)
        printf("le meilleur etudiant en la matiere  %d  est  %s  \n", i, lePlusFortEn(le, i));
    afficherEtu(find(le, lePlusFortEn(le, 4)));
    */
    /*  ************** TRIE
        int tab[10] = {9,6,4,1,2,7,8,0,5,3};
        afficheTab(tab,10);
        //triSelection(&tab,10);   printf("Tri Selecton-->>");   afficheTab(tab,10);
        //triBulles(&tab,10);      printf("Tri Bulles-->>");     afficheTab(tab,10);
        //triPermutation(&tab,10); printf("Tri Permutation-->>");afficheTab(tab,10);
        //triInsertion(tab,10);    printf("Tri Insertion-->>");  afficheTab(tab,10);
        triFusion(tab,10);       printf("Tri Fusion-->>");     afficheTab(tab,10);
        /////////////////////////////////////////////////////////////////////
            //int i ;
            //for(i=-10; i<21; i++)
            //    printf((rechercheDichotomie(tab,10,i) == 0 ? "%d pas trouve \n" : "%d trouve \n"),i);
            //    printf((rechercheDichotomieRec(tab,0,9,i) ? "%d trouve \n" : "%d pas trouve \n"),i);
        printf("%d == %d ",puissance(2,5),puissance_DPR(2,5));
        /////////////////////////////////////////////////////////////////////

    */
    /*  ************** PROGRAMMANTION DYNAMIQUE
           printf("\n__________DYNAMIC PROGRAMMING__________\n");

        int n=0;
        int* T = create_and_init_memo(n);
        //printf("fibbo-recu = %d\n",fibbonaci(n));
        //printf("fibbo-memo = %d\n",fibbonaci_memorisation(n,T));
        //printf("fibbo-tabu = %d\n",fibbonaci_tabulation(n,T));
        int i;
        for(i=0; i<=-1; i++){
                printf("\t\t:%d  ",T[i]);
            if(i%5 == 0)
                printf("\n");
        }




        //  **************        ALGORITHME GLOUTON
        Piece tp[4] = {             //candidats potentiel a la solution;
            create_piece(50,1),
            create_piece(20,3),
            create_piece(2,6),
            create_piece(1,1)
        };

        show_piece(tp[1]);


    */
    /*  ************** TABLE HACHAGE
        TableH* tab = creerTableH(16);

        insereMaillonTableH(tab,creerMaillonH("ANGE ",12));
        insereMaillonTableH(tab,creerMaillonH("     ",61));
        insereMaillonTableH(tab,creerMaillonH("Francois ",19));
        insereMaillonTableH(tab,creerMaillonH("Franka",21));
        insereMaillonTableH(tab,creerMaillonH("Kamga",45));
        insereMaillonTableH(tab,creerMaillonH("Lemo",91));
        insereMaillonTableH(tab,creerMaillonH("Zele ",40));
        insereMaillonTableH(tab,creerMaillonH("NKAMNANG STEPHANE",12));
        insereMaillonTableH(tab,creerMaillonH("TENE TEKEU ANGE",61));
        insereMaillonTableH(tab,creerMaillonH("MOUAFFO ADRIEN",19));
        insereMaillonTableH(tab,creerMaillonH("MOUAFFO WINNIE",21));
        insereMaillonTableH(tab,creerMaillonH("ZELE TASSOFO",45));
        insereMaillonTableH(tab,creerMaillonH("LEMOFOUET ULICH",91));
        insereMaillonTableH(tab,creerMaillonH("NEGOU DUREL",40));
        insereMaillonTableH(tab,creerMaillonH("MAFANI DJOH-DJOH",40));
        insereMaillonTableH(tab,creerMaillonH("FOLEFACk WILLY,40",21));
        insereMaillonTableH(tab,creerMaillonH("EKONDO ANGE",40));
        insereMaillonTableH(tab,creerMaillonH("NGAMENI JEAN CLAUDE",40));
        insereMaillonTableH(tab,creerMaillonH("RAISSA",40));
        insereMaillonTableH(tab,creerMaillonH("OWONA OWONO",40));
        insereMaillonTableH(tab,creerMaillonH("HILLARY CLINTON",40));
        insereMaillonTableH(tab,creerMaillonH("BEN SIMMOMS",40));
        afficheTableH(tab);

        printf("\n");
        afficheMaillonH(  *(rechercheTableHachage(tab,"RAISSA"))  );
        printf("\n");
        afficheMaillonH(  *(rechercheTableHachage(tab,"LEMOFOUET ULICH"))  );
        printf("\n");
        afficheMaillonH(  *(rechercheTableHachage(tab,"maman est partir ou village"))  );
        printf("\n");
        afficheMaillonH(  *(rechercheTableHachage(tab,"Francois"))  );
        printf("\n");
        afficheMaillonH(  *(rechercheTableHachage(tab,"NHASD DDD FIJFSI"))  );
        printf("\n\n");

        */
    /* *************** ARBRE BINAIRE

        Noeud *u = creerNoeud(30),      //arbre simple
              *t = creerNode(29,u,NULL),
              *s = creerNoeud(28),
              *r = creerNode(27,t,NULL),
              *q = creerNoeud(26),
              *p = creerNoeud(25),
              *o = creerNoeud(24),
              *n = creerNode(23,r,s),
              *m = creerNoeud(22),
              *l = creerNode(21,q,NULL),
              *k = creerNoeud(200),
              *j = creerNoeud(19),
              *i = creerNode(18,o,p),
              *h = creerNoeud(17),
              *g = creerNode(16,NULL,n),
              *f = creerNode(15,l,m),
              *e = creerNode(14,j,k),
              *d = creerNode(13,h,i),
              *c = creerNode(12,f,g),
              *b = creerNode(11,d,e),
              *a = creerNode(10,b,c);

        Noeud *O = creerNoeud(155),     //arbre de recherche
              *N = creerNode(160,O,NULL),
              *M = creerNoeud(140),
              *L = creerNoeud(209),
              *K = creerNode(150,M,N),
              *J = creerNoeud(90),
              *I = creerNoeud(9),
              *H = creerNoeud(5),
              *G = creerNode(205,NULL,L),
              *F = creerNode(100,J,K),
              *E = creerNoeud(15),
              *D = creerNode(8,H,I),
              *C = creerNode(200,F,G),
              *B = creerNode(10,D,E),
              *A = creerNode(20,B,C);
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        printf("nbre noeud == %d \n",nbreDeNoeud(a));
        printf("hauteur == %d \n",hauteur(a));
        printf("MAX == %d \n",plusGrand(a));
        int v=45,y=11;
        printf( (rechercheArbre(a,*(creerNoeud(v)))) ? "l\'element %d existe\n " : "l\'element %d n\'existe pas\n",v );
        if(   rechercheArbre(a,*(creerNoeud(y)))    )
            printf("l\'element %d existe\n",y);
        else
            printf("l\'element %d n\'existe pas\n",y);
        printf( (estDeRecherche(a)) ? "a est de recherche \n " : "a n\'est pas de recherche \n" );
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        printf( "\n\n" );

        printf( (estDeRecherche(A)) ? "A est de recherche \n " : "A n\'est pas de recherche \n" );
        int vv = 155;
        printf( (rechercheABR(A,*(creerNoeud (vv)))) ?"l\'element %d existe\n " : "l\'element %d n\'existe pas\n",vv );

        addNode(&A,creerNoeud(2));
        addNode(&A,creerNoeud(80));
        afficheInfixe(A);
        vv= 200;
        printf("Le successeur de %d esr %d \n",vv,successeur(A,vv) );
        printf("Le successeur de %d  \n",minABR(A->fd->fd) );

        clearTree(&A); printf("____free____\n");
        afficheInfixe(A);
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        */
    /* *************** ARBRE BINAIRE : les TAS
        Tas *tas = createTas(15);
        pushNode(tas,12);
        pushNode(tas,11);
        printf("OK\n");
        pushNode(tas,14);
        printf("OK\n");
        pushNode(tas,8);
        pushNode(tas,13);
        pushNode(tas,7);
        pushNode(tas,18);
        pushNode(tas,6);
        pushNode(tas,1);
        pushNode(tas,10);
        pushNode(tas,3);

        afficherTas(*tas);
        construireTas(tas);
        afficherTas(*tas);

        */
    /* *************** PILES & FILES
        int i;
        Pile* p = creerPile(5);
        for(i=10; i<15; i++)
            empiler(p,i);

                                        printf("\nPile Init          ->     ");    afficherPile(*p);
        Pile* r = reversePile(*p);      printf("\nInit rever         ->     ");    afficherPile(*r);
        Pile* c = clonerPile(*p);       printf("\nInit cloner        ->     ");    afficherPile(*c);
        retourner(p,3);                 printf("\nPile Init retourn 3->     ");    afficherPile(*p);
        reversePile2(p);                printf("\nRetourner new init ->     ");    afficherPile(*p);
                                        printf("\nclone              ->     ");    afficherPile(*c);

                                        printf("\n\n\n");


        printf("\t\t\n\nFILES\n\n");
        File* f = creerFile(10);
        printf( fileVide(*f) ? "--File vide\n" : "--File non vide\n");
        for(i=111; i<=125; i++)
            enfiler(f,i);
        afficherFile(*f);
        for(i=1;i<=7;i++)
            defiler(f);
        afficherFile(*f);
        for(i=991; i<=994; i++)
            enfiler(f,i);
        afficherFile(*f);



        */

    return 0;
}
