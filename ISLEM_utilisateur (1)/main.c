#include <stdio.h>
#include <string.h>
#include"utilisateur.h"



int main()
{
    int x;
    int nbr,nbrob,nbrag,nbreh,nbref;
    utilisateur u={"islem","maiti","10833472",7,9,2001,"52206935","1866635","Islem123","electeur","femme","555","ghazela"};
    utilisateur u1={"mayar","mait","10833472",7,9,2001,"52206357","111111","Islem1234","agent","homme","@gmail","ghazelaa"};
    utilisateur u2;
    printf("les operations validées :\n");
   
    ajouter(u);
    ajouter(u1);
   
    modifier("18666",u1);


    u=rechercher_role("electeur");
   

     supprimer("1083");
   
    u=rechercher("111111");
    printf("le calcul statistique est :\n");
   
    printf("\n");
    nbr=nbreelecteur();
    printf("le nbre des électeurs est %d \n " ,nbr);
    printf("\n");
    nbreh=nbreelecteurh();
    printf("le nbre des électeurs hommes est %d \n " ,nbreh);
    nbref=nbreelecteurf();
     printf("le nbre des électeurs femmes est %d \n " ,nbref);
    tauxhf();
    nbreag();
    nbreobservateurs();
    
    return 0;
}
