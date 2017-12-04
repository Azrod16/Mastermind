#include<stdio.h>
#include<windows.h>
#include<string.h>
#include"choix_reponse.h"

/********************************************************************/
/* INPUT : l'adresse du debut du vecteur de reponse                 */
/* PROCESS : l'utilisateur encode la combinaison de couleur que le
    deuxième joueur doit découvrir                                  */
/* OUTPUT : /                                                       */
/********************************************************************/

void choix_reponse(char *Pr)
{
    short i,j,n=4;
    char a,v[4]={"§§§§"},couleurA[9]={"RVBNbMrJ"};
    system("cls");
    printf("--Mode 2 joueurs--\n");
    code_couleur();
    printf("Joueur 1 :\n\t( Mettez vous a l'abri du regard du deuxieme joueur )\n\tEntrez la combinaison a decouvrir  :\n\n");
    printf("Couleur 1 : ");
    fflush(stdin);
    scanf("%c",&v[0]);
    while(strchr(couleurA,v[0])==NULL)
    {
        fflush(stdin);
        printf("Entrez une lettre correspondante au code couleur impose !! : ");
        scanf("%c",&v[0]);
    }
    for(i=1;i<4;i++)
    {
        printf("Couleur %d : ",i+1);
        fflush(stdin);
        scanf("%c",&a);
        while(strchr(couleurA,v[0])==NULL)
        {
            fflush(stdin);
            printf("Entrez une lettre correspondante au code couleur impose !! : ");
            scanf("%c",&a);
        }
        for(j=0;j<4;j++)
        {
            while(a==v[j])
            {
                printf("Vous ne pouvez pas entrez deux couleurs identiques !!! \n");
                printf("Entrez une nouvelle couleur : ");
                fflush(stdin);
                scanf("%c",&a);
                while(strchr(couleurA,v[0])==NULL)
                {
                    fflush(stdin);
                    printf("Entrez une lettre correspondante au code couleur impose !! : ");
                    scanf("%c",&a);
                }
                j=0;
            }
        }
        v[i]=a;
    }
    printf("\n\nCode a decouvrir :\n");
    affichage(&v[0]);
    system("pause");
    for(i=0;i<4;i++,Pr++)
    {
        *Pr=v[i];
    }
}

/********************************************************************/
/* INPUT : l'adresse du debut du vecteur de reponse                 */
/* PROCESS : l'ordinateur choisit aléatoirement 4 chiffres
        différents                                                  */
/* OUTPUT : /                                                       */
/********************************************************************/

void ia_reponse(char *pv)
{
    srand(time(NULL));
    char v[5]={"§§§§"},a;
    short i,j;
    system("cls");
    printf("--Mode 1 joueur--\n");
    code_couleur();
    rand_(&v[0]);
    for(i=1;i<4;i++)
    {
        rand_(&a);
        for(j=0;j<4;j++)
        {
            while(a==v[j])
            {
                rand_(&a);
                j=0;
            }
        }
        v[i]=a;
    }
    for(j=0;j<4;j++,pv++)
    {
        *pv=v[j];
    }
}

/********************************************************************/
/* INPUT : l'adresse du chiffre choisi par l'odinateur              */
/* PROCESS : convertit le chiffre en un code couleur                */
/* OUTPUT : /                                                       */
/********************************************************************/

void rand_(char *pr)
{
    short i;
    i=rand()%8;
    switch(i)
    {
        case 0:*pr='R';
            break;
        case 1:*pr='V';
            break;
        case 2:*pr='B';
            break;
        case 3:*pr='N';
            break;
        case 4:*pr='b';
            break;
        case 5:*pr='J';
            break;
        case 6:*pr='M';
            break;
        case 7:*pr='r';
            break;
    }

}
