#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
#include <stdio.h>
typedef struct 
{
 int j;
 int m;
 int a;
}date;

typedef struct
{
    char nom [50];
    char prenom[50];
    char cin[50];
    date d ;
    char tel[50];
    char id[50];
    char mdp[50];
    char role[50];
    char s[50];
    char mail[50];
    char adresse[50]; 
    
} utilisateur;

void ajouter( utilisateur u );

void modifier(  char id[], utilisateur nouv );

void supprimer(char cin[]);
utilisateur rechercher(char id[]);
utilisateur rechercher_role(char role[]);


void nbreobservateurs();
int nbreelecteur();
void nbreag();
int nbreelecteurh();
int nbreelecteurf();
void tauxhf();





#endif // UTILSATEUR_H_INCLUDED

