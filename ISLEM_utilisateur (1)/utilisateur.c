#include<string.h>
#include "utilisateur.h"

void ajouter(utilisateur u )
{    
    int x=0;
    FILE * f=fopen("utilisateur.txt", "a");
    if(f!=NULL)
    {
       if((strlen(u.nom)!=0)&&(strlen(u.prenom)!=0)&&(strlen(u.cin)==8)&&((strlen(u.tel)==8)||(strlen(u.mail)!=0))&&(strlen(u.id)!=0)&&(strlen(u.mdp)!=0))
       {
        fprintf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,u.d.j,u.d.m,u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse);
       
        fclose(f);
         printf("\n l'ajout avec succes\n")  ;
       } 
       else 
             printf("\n Echec d'ajouter \n");
    }
    
}

    void modifier(char id[], utilisateur nouv )
{
    int tr=0;
    utilisateur u;
    FILE * f=fopen("utilisateur.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,&u.d.j,&u.d.m,&u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse)!=EOF)
        {
            
            if(strcmp(u.id,id)==0)
            {
                fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",nouv.nom,nouv.prenom,nouv.cin,nouv.d.j,nouv.d.m,nouv.d.a,nouv.tel,nouv.id,nouv.mdp,nouv.role,nouv.s,nouv.mail,nouv.adresse);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,u.d.j,u.d.m,u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse);

        }
    }
    fclose(f);
    fclose(f2);
    remove("utilisateur.txt");
    rename("nouv.txt", "utilisateur.txt");
   

}

void supprimer(char cin[])
{
    int tr=0;
    utilisateur u;
    FILE * f=fopen("utilisateur.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,&u.d.j,&u.d.m,&u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse)!=EOF)
        {
            
            if(strcmp(u.cin,cin)==0)
            
                tr=1;
            else
                fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,u.d.j,u.d.m,u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse);
        }
    }
     if(tr==1)
        printf("\n Suppression avec succés\n");
    else printf("\n Echec Suppression\n");

    fclose(f);
    fclose(f2);
    remove("utilisateur.txt");
    rename("nouv.txt", "utilisateur.txt");
  
}

utilisateur rechercher(char id[])
{
    utilisateur u;
    int tr=0;
    FILE * f=fopen("utilisateur.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,&u.d.j,&u.d.m,&u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse)!=EOF)
        {
          
            if(strcmp(u.id,id)==0)
                tr=1;
        }
    }
   
    fclose(f);
     if(tr==0)
        printf("\n L'utilisateur que vous cherchez est introuvable\n");
   
    return u;

}
utilisateur rechercher_role(char role[])
{
    utilisateur u;
    int tr=0;
    FILE * f=fopen("utilisateur.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,&u.d.j,&u.d.m,&u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse)!=EOF)
        {
          
            if(strcmp(u.role,role)==0)
                tr=1;
        }
    }
   
    fclose(f);
     if(tr==0)
        printf("\n Rôle introuvable\n");
   
    return u;

}
//fonction satatistique
/*nbre des electeurs , pour le calcul ctt*/

int nbreelecteur()
{
    utilisateur u;
    int nbre=0;
    FILE * f=fopen("utilisateur.txt", "r");
    if(f!=NULL)
    {
        while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,&u.d.j,&u.d.m,&u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse)!=EOF)
        {   
           
           if(strcmp(u.role,"electeur")==0)
             {
                nbre++;
             }
            
        }
    }
    fclose(f);
   return nbre;
}
/*nbre des electeurs homme, pour le calcul */

int nbreelecteurh()
{
    utilisateur u;
    int nbreh=0;
    FILE * f=fopen("utilisateur.txt", "r");
    if(f!=NULL)
    {
       while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,&u.d.j,&u.d.m,&u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse)!=EOF)
        {   
           
           if((strcmp(u.role,"electeur")==0) &&(strcmp(u.s,"homme")==0))
                nbreh++;
        }
    }
    fclose(f);
    return nbreh;
   
}
/*nbre des electeurs femmes, pour le calcul ctt*/
int nbreelecteurf()
{
    utilisateur u;
    int nbref=0;
    FILE * f=fopen("utilisateur.txt", "r");
    if(f!=NULL)
    {
       while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,&u.d.j,&u.d.m,&u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse)!=EOF)
        {   
           
           if((strcmp(u.role,"electeur")==0) &&(strcmp(u.s,"femme")==0))
                nbref++;
        }
    }
    fclose(f);
    return nbref;
}
/*le taux, a afficher  */
void tauxhf()
 {
    float x,y;
    int nbref,nbreh,nbr;
    nbr =nbreelecteur();
    nbreh=nbreelecteurh();
    nbref= nbreelecteurf();
    x=(float)(nbreh*100/nbr);
    y=(float)((nbref*100)/nbr);
    printf("\n");
    printf("le taux de des electeurs hommes est  %.2f pourcent \n",x);
    printf("\n");
    printf("le taux de des electeurs femmes est  %.2f pourcent \n",y);
 }

/*nbre des observateurs, a afficher*/
void nbreobservateurs()
{
    utilisateur u;
    int nbrob=0;
    
    FILE * f=fopen("utilisateur.txt", "r");
    if(f!=NULL)
    {
        while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,&u.d.j,&u.d.m,&u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse)!=EOF)
        {   
           
           if(strcmp(u.role,"observateur")==0)
             {
                nbrob++;
             }
            
        }
}
    fclose(f);
    printf("le nbre des observateurs est %d \n " , nbrob);
}
/*nbre des agent du bureau, a afficher*/
void nbreag()
{
    utilisateur u;
    int nbrag=0;
    
    FILE * f=fopen("utilisateur.txt", "r");
    if(f!=NULL)
    {
        while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s \n",u.nom,u.prenom,u.cin,&u.d.j,&u.d.m,&u.d.a,u.tel,u.id,u.mdp,u.role,u.s,u.mail,u.adresse)!=EOF)
        {   
           
           if(strcmp(u.role,"agent")==0)
             {
                nbrag++;
             }
            
         }
     }
    fclose(f);
    printf("le nbre des agents du bureaux est %d \n " ,nbrag);
}


