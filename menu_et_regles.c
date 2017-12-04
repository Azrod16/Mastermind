#include<stdio.h>
#include<windows.h>
#include"menu_et_regles.h"

/********************************************************************/
/* INPUT : /                                                        */
/* PROCESS : Un menu est affiché a l'ecran et un numéro est
demandé à l'utilisateur pour connaitre le choix de l'utilisateur    */
/* OUTPUT : /                                                       */
/********************************************************************/

void menu()
{
    system("cls");
    printf("----------------------\n");
    printf("|     MASTERMIND     |\n");
    printf("----------------------\n\n");
    printf("1 pour afficher les regles\n");
    printf("2 pour jouer\n");
    printf("3 pour quitter\n");
    printf("Faites votre choix (1-2-3) : ");
    selection();
}

/********************************************************************/
/* INPUT : le choix de l'utilisateur pour naviguer dans le menu     */
/* PROCESS : renvoie à la fonction choisie par l'utilisateur        */
/* OUTPUT : /                                                       */
/********************************************************************/

void selection()
{
    short choix;
    fflush(stdin);
    scanf("%hd",&choix);
    while(choix<1||choix>3)
    {
        fflush(stdin);
        printf("Entrez un chiffre entre 1 et 3 ");
        scanf("%hd",&choix);
    }
    switch(choix)
    {
        case 1: regles();
        break;
        case 2: jouer();
        break;
        default: quitter();
    }
}

/********************************************************************/
/* INPUT : /                                                        */
/* PROCESS : affiche les regles du jeu à l'écran                    */
/* OUTPUT : /                                                       */
/********************************************************************/

void regles()
{
    system("cls");
    printf("\nREGLES :\n");
    printf("\tLe but est de trouver une combinaison de 4 chiffres en un maximum\n\tde 10 coups");
    printf("\n\tA chaque essai, vous serez informe sur le nombre de couleurs\n\ttrouve mal places et le nombre de couleurs trouves a la bonne place\n");
    code_couleur();
    system("pause");
    menu();
}

/********************************************************************/
/* INPUT : /                                                        */
/* PROCESS : affiche un message de fin et quitte le programme       */
/* OUTPUT : /                                                       */
/********************************************************************/

void quitter()
{
    system("cls");
    printf("Merci et a bientot");
}

/********************************************************************/
/* INPUT : /                                                        */
/* PROCESS : affiche le code couleur à l'écran                    */
/* OUTPUT : /                                                       */
/********************************************************************/

void code_couleur()
{
    printf("\n\tVoici le code couleur a respecter : \n\n");
    color(0,12);
    printf("\t\t  R  ");
    color(0,0);
    printf("a\n");
    color(0,10);
    printf("\t\t  V  ");
    color(0,0);
    printf("a\n");
    color(0,9);
    printf("\t\t  B  ");
    color(0,0);
    printf("a\n");
    color(15,0);
    printf("\t\t  N  ");
    color(0,0);
    printf("a\n");
    color(0,15);
    printf("\t\t  b  ");
    color(0,0);
    printf("a\n");
    color(0,14);
    printf("\t\t  J  ");
    color(0,0);
    printf("a\n");
    color(0,5);
    printf("\t\t  M  ");
    color(0,0);
    printf("a\n");
    color(0,13);
    printf("\t\t  r  ");
    color(0,0);
    printf("a\n\n");
    color(15,0);
}
