//
//  structure.h
//  
//
//  Created by ALEXANDRE Dorian on 27/04/2020.
//

#ifndef structure_h
#define structure_h

struct mot
{
    int nbr_lettre;
    char* mot[50];
    
};

struct dico
{
    struct mot* mots;
    int taille;

};

#endif /* structure_h */
