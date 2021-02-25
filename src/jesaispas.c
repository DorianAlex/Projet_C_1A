//
//  jesaispas.c
//  
//
//  Created by ALEXANDRE Dorian on 27/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"

#define TAILLE_MAX 1000 // Tableau de taille 1000
#define buffer 50

//---------------------------------------------------------------------------------------


void dodo(struct dico *d, int a, int b, int * tableau, float * pourcentage)
{
    int compteur =0;
    
    while (compteur <= (*d).taille+1 && (*d).mots[compteur].nbr_lettre != 0)
    {
        tableau[(d*).mots[compteur].nbr_lettre +1] += 1;
        compteur++;
    }
    int i=0;
    while(i<=b)
    {
        pourcentage[i+1]=(float)tableau[i+1]*100/compteur;
        i++;
    }
}


//---------------------------------------------------------------------------------------


void ouv_dico(struct dico *d)
{
    int compteur=0;
    FILE* dico = NULL;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    int nombreMots=0;
    dico = fopen("dic/french-sans-accents-latin1.txt", "r+");
    
    if (dico != NULL)
          {
              while (fgets(chaine, TAILLE_MAX, dico) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
                               {
                                   int i=0;
                                   
                                   (*d).mots[compteur].nbr_lettre=strlen(chaine)-1;
                                   
                                   while (chaine[i] != '\0')
                                   {
                                       if (chaine[i]='\n')
                                       {
                                           chaine[i]='\0';
                                           break;
                                       }
                                       i++;
                                   }
                                   strcpy((*d).mots[compteur].mot,chaine);
                                   i++;
                               }
          }
    fclose(dico);
}


//---------------------------------------------------------------------------------------


void taille (struct dico *d, int *min, int *max,float *m)
{
    float somme=0;
    float moyenne =0;
    *min=100;
    *max=0;
    
    int compteur=0;
     while (compteur <= (*d).taille && (*d).mot[compteur].nbr_lettre != 0)
     {
         somme=somme+(*d).mots[compteur].nbr_lettre;
         
         if((*d).mots[compteur].nbr_lettre<*min)
         {
             *min=(*d).mots[compteur].nbr_lettre;
             compteur++;
         }
         if((*d).mots[compteur].nbr_lettre>*man)
                 {
                     *man=(*d).mots[compteur].nbr_lettre;
                     compteur++;
                 }
         else
         {
             compteur++;
         }
     }
    
    moyenne=somme/(compteur);
    *m=moyenne;
}
