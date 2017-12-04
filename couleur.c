#include<windows.h>

/********************************************************************/
/* INPUT : La valeur correspondante a la couleur du texte et du fond*/
/* PROCESS : change la couleur de la console                        */
/* OUTPUT : /                                                       */
/********************************************************************/

void color(int couleurDuTexte,int couleurDeFond);

void color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
