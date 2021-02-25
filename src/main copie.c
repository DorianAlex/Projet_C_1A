#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//#include "load_dic.h"
//#include "jesaispas.h"
//#include "structure.h"

#define TAILLE_MAX 1000 // Tableau de taille 1000
#define buffer 50

struct mot
{
    int nbr_lettre;
    char* mot[buffer];
    
};

struct dico
{
    struct mot* mots;
    int taille;

};

void dodo(struct dico *d, int a, int b, int * tableau, float * pourcentage);
void ouv_dico(struct dico *d);
void taille (struct dico *d, int *min, int *max,float *m);


int main( int argc, char* argv[] )
{
    struct dico d;
    d.taille=340000;
    int a;
    int b;
    float moy=0;
    struct mot essais;
    d.mots=malloc(d.taille * sizeof(essais));
    
    
    ouv_dico(&d);
    
    taille(&d,&a,&b,&moy);
    
    printf("taille minimum des mots : %-d\n",a);
    printf("taille maximum des mots : %-d\n",b);
    printf("taille moyenne des mots : %-f\n",moy);
    int *tableau=NULL;
    float *pourcentage=NULL;
    tableau=malloc((b+1)*sizeof(float));
    pourcentage=malloc((b+1)*sizeof(float));
    int i=0;
    int j=0;
    
    while(i<=b+1)
    {
        tableau[i]=0;
        pourcentage[i]=0;
        i++;
    }
    
    dodo(&d,a,b,tableau,pourcentage);
    int k=1;
    
    while(k<=b)
    {
        printf("taille %5d : %7d mots (%6.*f%%)  ",k,tableau[k+1],3,pourcentage[k+1]);
        float a=0;
        while (a<pourcentage[k+1])
        {
            printf("#");
            a+=0.2;
        }
        printf("\n");
        k++;
    }
   

    free(d.mots);
    return 0;
}

//---------------------------------------------------------------------------------------


void dodo(struct dico *d, int a, int b, int * tableau, float * pourcentage)
{
    int compteur =0;
    
    while (compteur <= (*d).taille+1 && (*d).mots[compteur].nbr_lettre != 0)
    {
        tableau[(*d).mots[compteur].nbr_lettre +1] += 1;
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
    char chaine[buffer] = ""; // Chaîne vide de taille TAILLE_MAX
    int nombreMots=0;
    dico = fopen("dic/french-sans-accents-latin1.txt", "r+");
    
    if (dico != NULL)
          {
              while (fgets(chaine, TAILLE_MAX, dico) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
                               {
                                   int i=0;
                                   
                                   (*d).mots[compteur].nbr_lettre=strlen(chaine)-1;
                                   
                                   while (chaine[i] != ('\0'))
                                   {
                                       if (chaine[i]== ('\n'))
                                       {
                                           chaine[i]= ('\0');
                                           break;
                                       }
                                       i++;
                                   }
                                   strcpy((*d).mots[compteur].mot,chaine);
                                   i++;
                                   compteur++;
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
     while (compteur <= (*d).taille && (*d).mots[compteur].nbr_lettre != 0)
     {
         somme=somme+(*d).mots[compteur].nbr_lettre;
         
         if((*d).mots[compteur].nbr_lettre<*min)
         {
             *min=(*d).mots[compteur].nbr_lettre;
             compteur++;
         }
         if((*d).mots[compteur].nbr_lettre>*max)
                 {
                     *max=(*d).mots[compteur].nbr_lettre;
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
