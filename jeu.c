#include<windows.h>
#include<stdio.h>
#include<string.h>
#include"jeu.h"
#define NBR_ESSAI 10

/********************************************************************/
/* INPUT : /                                                        */
/* PROCESS : l'utilisateur entre des combinaisons et le programme
    affiche des informations sur les combinaisons entrées           */
/* OUTPUT : /                                                       */
/********************************************************************/

void jouer()
{
    short choix,i,j,bonne=0,mal=0,essai=0;
    char a,couleur[5]={""},reponse[5]={""},couleurA[9]={"RVBNbMrJ"};        //initialiser la chaîne reponse pour avoir le \0 directement
    choix=mode_de_jeu();
    if(choix==2)
        choix_reponse(&reponse[0]);
    else
        ia_reponse(&reponse[0]);
    system("cls");
    printf("--Mode %hd joueur(s)--\n",choix);
    code_couleur();
    printf("JOUEUR 1 : ");
    printf("\n_\t_\t_\t_\n");
    while(bonne<4&&essai<NBR_ESSAI)
    {
        mal=0;
        bonne=0;
        printf("\nIl vous reste %hd essais\n\n",10-essai);
        couleur[0]='§';
        couleur[1]='§';
        couleur[2]='§';
        couleur[3]='§';
        for(i=0;i<4;i++)
        {
                printf("Couleur %d/4 : ",i+1);
                fflush(stdin);
                scanf("%c",&a);
                while(strchr(couleurA,a)==NULL)
                {
                    fflush(stdin);
                    printf("Entrez une lettre correspondante au code couleur impose !! : ");
                    scanf("%c",&a);
                }
                for(j=0;j<4;j++)
                {
                    while(a==couleur[j])
                    {
                        printf("Vous ne pouvez pas entrez deux couleurs identiques !!! \n");
                        printf("Entrez une nouvelle couleur %d/4 : ",i+1);
                        fflush(stdin);
                        scanf("%c",&a);
                        while(strchr(couleurA,a)==NULL)
                        {
                            fflush(stdin);
                            printf("Entrez une lettre correspondante au code couleur impose !! : ");
                            scanf("%c",&a);
                        }
                        j=0;
                    }
                }
                couleur[i]=a;
            if(couleur[i]==reponse[0]||couleur[i]==reponse[1]||couleur[i]==reponse[2]||couleur[i]==reponse[3])
            {
                if(couleur[i]==reponse[i])
                    bonne++;
                else
                    mal++;
            }
        }
        printf("\n");
        affichage(&couleur[0]);
        printf("\n%hd mal place \n%hd bonnes\n",mal,bonne);
        essai++;
    }
    resultat(bonne,essai,&reponse[0]);
    menu();

}

/********************************************************************/
/* INPUT : /                                                        */
/* PROCESS : l'utilisateur va choisir s'il veut jouer contre
    l'ordinateur ou contre un deuxième joueur                       */
/* OUTPUT : le choix de l'utilisateur                               */
/********************************************************************/

short mode_de_jeu()
{
    short choix;
    system("cls");
    printf("Voulez-vous jouer contre l'ordinateur ou a deux joueurs ?\n\n");
    printf("Ordinateur (-1-)\n");
    printf("Deux joueurs (-2-)\n\n");
    scanf("%hd",&choix);
    while(choix!=1&&choix!=2)
    {
        printf("\nEntrez 1 ou 2\n");
        scanf("%hd",&choix);
    }
    return choix;
}

/********************************************************************/
/* INPUT : le caractere à afficher                                  */
/* PROCESS : en fonction de la lettre entrée on va changer la couleur
    de la console                                                   */
/* OUTPUT : /                                                       */
/********************************************************************/

void conversion(char c)
{
    switch(c)
    {
        case 'R' :color(0,12);
            break;
        case 'V' :color(0,10);
            break;
        case 'B' :color(0,9);
            break;
        case 'N' :color(15,0);
            break;
        case 'b' :color(0,15);
            break;
        case 'J' :color(0,14);
            break;
        case 'M' :color(0,5);
            break;
        case 'r' :color(0,13);
            break;
        case 'a' :color(0,0);
            break;
        default:color(15,0);
    }
}

/********************************************************************/
/* INPUT : le nombre d'essai et les solution du jeu                 */
/* PROCESS : vérifie si l'utilisateur a trouvé la combinaison       */
/* OUTPUT : /                                                       */
/********************************************************************/

void resultat(short bonne,short essai,char* reponse)
{
    if(bonne==4)
        printf("\n\nBravo, vous avez trouvez le code couleur en %d essai(s)\n",essai);
    else
    {
        printf("\n\nDommage vous avez perdu!\n");
        printf("La solution etait : \n");
        affichage(reponse);
    }
    system("pause");
}

void affichage(char *reponse)
{
    short i;
    for(i=0;i<4;i++,reponse++)
    {
        conversion('z');
        printf(" | ");
        conversion(*reponse);
        printf("    ");
    }
    conversion('z');
    printf(" |");
    conversion('a');
    printf("a\n");
    conversion('z');
}
