#include <stdio.h>
#include <stdlib.h>

typedef   struct compte

{
    char nom [20];
    char prenom[20];
    char CIN[20];
    float montant;

} compte;
int main()
{
    compte compt[20];
    compte tem[20];
    compte tab[50];
    printf("\t\t\t\t\t\t^^^^^^^^^^ projet sas ^^^^^^^^^^\t\t\t\t\t\t\n");

    printf("\t\t\t\t\t\t************menu************\t\t\t\t\t\t\n\n");

    int menu,nombredescomptes,count = 0,operation,affichage;

    int i=0, v,j=0,e=0;
    int n=0;
    char ID[20];

    float retrait,depot,chiffre;

    while(menu!=6)
    {

        printf("1-introduire un compte bancaire :\n\n");

        printf("2-introduire plusieurs comptes bancaire \n\n");

        printf("3-operations : retrait/depot \n\n");

        printf("4-affichage:\n\n");

        printf("5-fidelisation:\n\n");

        printf("6-quitter l'application:\n\n");

        printf("veuillez choisir l'operation souhaitee:\t\n");

        scanf("%d",&menu);

        printf("\t\t\t***************************************************\n\n");


        switch(menu)
        {
        case 1:
            printf("veuillez remplir vos informations :\n");

            printf("entrer votre nom :\n");

            scanf("%s",compt[count].nom);

            printf("entrer votre prenom :\n");

            scanf("%s",compt[count].prenom);

            printf("entrer la CIN :\n");

            scanf("%s",compt[count].CIN);

            printf("entrer le montant :\n");

            scanf("%f",&compt[count].montant);

            count++;
            break;

        case 2:
            printf("veuillez remplir vos informations :\n");

            printf("entrer le nombre des comptes que vous voulez creer:\n");

            scanf("%d",&nombredescomptes);

            int total = count + nombredescomptes;

            for(int i=count; i<total; i++)
            {

                printf("entrer le prenom du client[ %d] :\t",i+1);

                scanf("%s",compt[i].prenom);

                printf("entrer le nom du client :");

                scanf("%s",compt[i].nom);

                printf("entrer la CIN du client :");

                scanf("%s",compt[i].CIN);

                printf("entrer le montant du client :");

                scanf("%f",&compt[i].montant);
                count++;
            }
            for(int i=0; i<count; i++)
            {
                printf(" prenom : %s\n",compt[i].prenom);

                printf(" nom :%s\n",compt[i].nom);

                printf(" CIN :%s\n",compt[i].CIN);

                printf("montant :%f\n",compt[i].montant);

            }
            break;

        case 3:

            printf("veuillez choisir l'operation souhaitee :\n1-RETRAIT\n2-depot\n");

            scanf("%d",&operation);

            switch(operation)
            {
            case (1):

              start:
                printf("entrer ID :\t" );

                scanf("%s",ID);
                    int v=0;

                for(i=0; i<count; i++)
                {
                    if( stricmp(ID,compt[i].CIN )==0)
                    {
                        v=1;
                        printf("veuillez entrer le montant retire :\n");

                        scanf("%f",&retrait);

                        if(compt[i].montant >= retrait )
                        {

                            compt[i].montant=compt[i].montant-retrait;

                            printf("votre montant maintenant est :%f \n",compt[i].montant);
                        }
                        else printf("votre solde est insuffisant\n");
                    }
                }
                if(v!=1)
                {
                    printf("votre CIN est invalide \n");
                   goto start;
                }

                break;

            case (2):
                printf("entrer ID :\t" );

                scanf("%s",ID);


                for(i=0; i<count; i++)
                {
                    if( stricmp(ID,compt[i].CIN )==0)
                    {
                        v=1;
                        printf("veuillez entrer le montant depose :\n");

                        scanf("%f",&depot);

                        compt[i].montant+=depot;

                        printf("votre nouveau montant est :%f \n",compt[i].montant);
                    }
                }
                if(v!=1)
                {
                    printf("votre CIN est invalide \n");

                   goto start;
                }
                break;

            default:
                printf("operation invalide \n ");
            }
            break;

        case 4:

            printf("1-affichage par ordre ascendant:\n");

            printf("2-affichage par ordre descendant:\n");

            printf("3-affichage les comptes superieur par ordre ascendant :\n");

            printf("4-affichage les comptes superieur par ordre descendant :\n");

            printf("5-recherche par CIN :\n");

            printf("choisir une methode d'affichage:\t");

            scanf("%d",&affichage);

            switch(affichage)
            {
            case (1):

                for(i=0; i<count; i++)
                {
                    for(j=i+1; j<count; j++)

                        if (compt[i].montant > compt[j].montant )
                        {
                            tem[e] = compt[i] ;

                            compt[i] = compt[j];

                            compt[j] = tem[e] ;
                        }
                }
                for(i=0; i<count; i++)
                {
                    printf(" prenom : %s\n",compt[i].prenom);

                    printf(" nom :%s\n",compt[i].nom);

                    printf(" CIN :%s\n",compt[i].CIN);

                    printf("montant :%f\n",compt[i].montant);
                }
                break;

            case (2):

                for(i=0; i<count; i++)
                {
                    for(j=i+1; j<count; j++)

                        if (compt[i].montant < compt[j].montant )
                        {
                            tem[e] = compt[i] ;

                            compt[i] = compt[j];

                            compt[j] = tem[e] ;
                        }
                }
                for(i=0; i<count; i++)
                {
                    printf(" prenom : %s\n",compt[i].prenom);

                    printf(" nom :%s\n",compt[i].nom);

                    printf(" CIN :%s\n",compt[i].CIN);

                    printf("montant :%f\n",compt[i].montant);
                }
                break;

            case (3):

                for(i=0; i<count; i++)
                {
                    for(j=i+1; j<count; j++)

                        if (compt[i].montant > compt[j].montant )
                        {
                            tem[e] = compt[i] ;

                            compt[i] = compt[j];

                            compt[j] = tem[e] ;
                        }
                }
                for(i=0; i<count; i++)
                {
                    printf(" prenom : %s\n",compt[i].prenom);

                    printf(" nom :%s\n",compt[i].nom);

                    printf(" CIN :%s\n",compt[i].CIN);

                    printf("montant :%f\n",compt[i].montant);
                }
                printf("introduire un chiffre:\n");

                scanf("%f",&chiffre);

                for(i=0; i<count; i++)
                {
                    if(compt[i].montant >= chiffre)
                    {

                        printf("les comptes affiches par ordre ascendant et superieur au chiffre:\n");

                        printf(" prenom : %s\n",compt[i].prenom);

                        printf(" nom :%s\n",compt[i].nom);

                        printf(" CIN :%s\n",compt[i].CIN);

                        printf("montant :%f\n",compt[i].montant);

                    }
                }break;
            case (4):

                for(i=0; i<count; i++)
                {
                    for(j=i+1; j<count; j++)

                        if (compt[i].montant < compt[j].montant )
                        {
                            tem[e] = compt[i] ;

                            compt[i] = compt[j];

                            compt[j] = tem[e] ;
                        }
                }
                for(i=0; i<count; i++)
                {
                    printf(" prenom : %s\n",compt[i].prenom);

                    printf(" nom :%s\n",compt[i].nom);

                    printf(" CIN :%s\n",compt[i].CIN);

                    printf("montant :%f\n",compt[i].montant);
                }
                printf("introduire un chiffre:\n");

                scanf("%f",&chiffre);

                for(i=0; i<count; i++)
                {
                    if(compt[i].montant >= chiffre)
                    {

                        printf("les comptes affiches par ordre descendant et superieur au chiffre:\n");

                        printf(" prenom : %s\n",compt[i].prenom);

                        printf(" nom :%s\n",compt[i].nom);

                        printf(" CIN :%s\n",compt[i].CIN);

                        printf("montant :%f\n",compt[i].montant);
                    }
                }break;
            case 5:


                 printf("entrer ID :\n ");

                    scanf("%s",ID);

                    int found=0;


                    for(i=0; i<count; i++)
                    {
                        if( stricmp(ID,compt[i].CIN )==0)
                        {

                            found=1;
                            n=i;
                        }
                    }


                if (found==1)
                {
                    printf(" prenom : %s\n",compt[n].prenom);

                    printf(" nom :%s\n",compt[n].nom);

                    printf(" CIN :%s\n",compt[n].CIN);

                    printf("montant :%f\n",compt[n].montant);

                }

                else printf("votre CIN est invalide \n");

                break;

                }break;

            break;

            case 5:

                for(i=0; i<count; i++)
                {
                    for(j=i+1; j<count; j++)

                        if (compt[i].montant < compt[j].montant )
                        {
                            tem[e] = compt[i] ;

                            compt[i] = compt[j];

                            compt[j] = tem[e] ;
                        }}

                for(i=0; i<3; i++)
                {
                    compt[i].montant+=(compt[i].montant*1.3)/100;

                    printf(" prenom : %s\n",compt[i].prenom);

                    printf(" nom :%s\n",compt[i].nom);

                    printf(" CIN :%s\n",compt[i].CIN);

                    printf("montant :%f\n",compt[i].montant);
                } break;

            case 6:

                   printf("vous avez quitter l'application \n");

    }}
    return 0;
}
