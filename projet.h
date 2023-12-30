#define PROJET_H_INCLUDED
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
int matricule;
char nom[20],prenom[25];
float cotisation;
FILE *fp;

void ajoutMem();
void recherMem();
void modifyMem();
void supprimeMem();
void menu();
void secret();
void afficheMem();

void secret(){
    system("cls"); 
    char passwd[20];
    int i, j = 0;
    char c;
    char mon[20] = "zidane";
    int choix;
        printf("\n\t\t\t\t\tveuillez entrer le mot de passe : ");
        while((c = getch()) != '\r'){
            if(c == '\b'){
                if(i > 0){
                j--;
                printf("\b \b");
                }
            }else{
                passwd[j++] = c;
                printf("*");
            }
        }
        passwd[j] = '\0';
        printf("\n\n\n\n\t\t\t\t\t\t\tLOAGING");
        for(i = 0; i<=50; i+=10){
                usleep(1);
                if(i >= 3){
                    printf(".");
                }
        }
        printf("\n"); 
        if(strcmp(passwd,mon)){
            system("cls");
            system(" color 0F");
            printf("\n\t\t\t\t\t\t\t\tMot De Passe Incorrect!!!!\t\t\t\t\t\t\n\n");
            printf("\a");
            printf("\t\t\t\t\t\t\t\tQuel est votre choix ? \n\n\t\t\t\t\t\t\t\t 1.Ressayez\n\n\t\t\t\t\t\t\t\t 2.Quittez\n");
            printf("\n\t\t\t\t\t\t\tvotre choix : ");
            scanf("%d",&choix);
            system(" color 04");
            if(choix == 1){
                system("cls");
                secret();
            }else{
                system("cls");
                exit(0);
            }
        }else{
          system("cls");
          menu();
        }
}
void menu(){
    int choix,choose;
    back:
    system("color 06");
        printf("\n\n\t\t\t\t\t\t\xB2\xB2\xB2GESTION DES MEMBRES D'UNE REUNION\xB2\xB2\xB2\n");
        printf("\t\t\t\t\t\t\t1. Ajouter un membre\n");
        printf("\t\t\t\t\t\t\t2. Rechercher un membre\n");
        printf("\t\t\t\t\t\t\t3. Modifier les donnees d'un membre\n");
        printf("\t\t\t\t\t\t\t4. Supprimer un membre\n");
        printf("\t\t\t\t\t\t\t5. Afficher tout les membres\n");
        printf("\t\t\t\t\t\t\t0. Fin du programme\n");
        printf("\t\t\t\t\t\tVotre choix : ");scanf("%d",&choix);
        switch(choix){
        case 1:{ajoutMem();break;}
        case 2:{recherMem();break;}
        case 3:{modifyMem();break;}
        case 4:{supprimeMem();break;}
        case 5:{afficheMem();break;}
        case 0:{printf("\n\n\t\t\t\tQuittez .....");usleep(5);system("cls"); break;}

        }
    system("color 0F ");
}
void ajoutMem(){
    int matricul,trouve = 0,choose;
    fp = fopen("etoile.txt","a+");
    if(fp == NULL){
        printf("impossible d'ouvrir le fichier\n");
        exit(1);
    }
    printf("entrer le matricule du membre a ajouter : ");scanf("%d",&matricul);
    while(!feof(fp)){
     fscanf(fp,"%d\n%s\n%s\n%f\n",&matricule,nom,prenom,&cotisation);
     if(matricul == matricule){
        trouve =1;
        break;
     }
    }
    if(trouve == 1){
        printf("le membre existe deja!!!\n");
    }
    else{
        printf("donner votre matricule : ");scanf("%d",&matricule);
        printf("donner votre nom : ");scanf("%s",nom);
        printf("donner votre prenom : ");scanf("%s",prenom);
        printf("donner le montant de votre cotisation : ");scanf("%f",&cotisation);
        fprintf(fp,"%d\n%s\n%s\n%f\n",matricule,nom,prenom,cotisation);

    }
    fclose(fp);
    printf("\tL'etudiant est ajouter");
    printf("\n\n\t\t\t1. Menu\n\n\t\t\t2. Exit\n\n\t\t Quel est votre choix ? :");
    scanf("%d",&choose);
    if(choose == 1){
        system("cls");
        menu();
    }else{
        exit(0);
    }
}
void recherMem(){
    int matricul, trouve = 0,choose;
    fp = fopen("etoile.txt","r");
    if(fp == NULL){
        printf("impossible d'ouvrir le fichier\n");
        exit(1);
    }
    printf("entrer le matricule du membre a rechercher : "); scanf("%d",&matricul);
    while(!feof(fp)){ 
        fscanf(fp,"%d\n%s\n%s\n%f\n",&matricule,nom,prenom,&cotisation); 
        if(matricul == matricule){
            trouve = 1;
            printf("voici les information du membre que vous rechercher : \n");
            printf("NOM\tPRENOM\tMATRICULE\tCOTISATION\n");
            printf("%s\t%s\t%d\t%f\n",nom,prenom,matricule,cotisation);
        }
    }
    if(trouve == 0){
        printf("le membre n'existe pas!!!\n");
    }
    fclose(fp);
    printf("\n\n\t\t\t1. Menu\n\n\t\t\t2. Exit\n\n\t\t Quel est votre choix ? :");
    scanf("%d",&choose);
    if(choose == 1){
        system("cls");
        menu();
    }else{
        exit(0);
    }
}
void afficheMem(){
    int choose;
    fp = fopen("etoile.txt","r");
    if(fp == NULL){
        printf("impossible d'ouvrir le fichier\n");
        exit(1);
    } 
    system("cls");
    printf("NOM\tPRENOM\tMATRICULE\tCOTISATION\n"); 
    while(!feof(fp)){
       fscanf(fp,"%d\n%s\n%s\n%f\n",&matricule,nom,prenom,&cotisation);
       printf("%s\t%s\t%d\t\t%.0f\n",nom,prenom,matricule,cotisation); 
    }
    fclose(fp);
    printf("\n\n\t\t\t1. Menu\n\n\t\t\t2. Exit\n\n\t\t Quel est votre choix ? :");
    scanf("%d",&choose);
    if(choose == 1){
        system("cls");
        menu();
    }else{
        exit(0);
    }
}
void modifyMem(){
    int matricul, tr = 0,num,choose;
    FILE *tp;
    fp = fopen("etoile.txt","r");
    if(fp == NULL){
        printf("impossible d'ouvrir le fichier\n");
        exit(1);
    } 
    tp = fopen("reunion.txt","w");
    if(tp == NULL){
        printf("impossible d'ouvrir le fichier\n");
        exit(1);
    } 
    printf("Donner le matricule du membres a modifier : ");scanf("%d",&matricul);
    while(!feof(fp)){
       fscanf(fp,"%d\n%s\n%s\n%f\n",&matricule,nom,prenom,&cotisation);
       if(matricul == matricule){
            tr = 1;
            printf("Que voulez vous modifier sur ce membre?\n ");
            printf("\t1. Le nom\n");
            printf("\t2. Le prenom\n");
            printf("\t3. Le matricule\n");
            printf("\t4. Le montant de sa cotisation\n");
            printf("votre choix : " );scanf("%d",&num);
            switch(num){
                case 1:{printf("Donner le nouveau nom :");scanf("%s",nom);break; }
                case 2:{printf("Donner le nouveau prenom :");scanf("%s",prenom);break; }
                case 3:{printf("Donner le nouveau matricule :");scanf("%d",&matricule);break; }
                case 4:{printf("Donner le nouveau montant :");scanf("%d",&cotisation);break; }
                case 5:{printf("Rien");break;}
            }
       }
       fprintf(tp,"%d\n%s\n%s\n%f\n",matricule,nom,prenom,cotisation);
    }
    fclose(fp);fclose(tp);
    remove("etoile.txt");
    rename("reunion.txt","etoile.txt");
    if(tr == 0){
        printf("l'etudiant n'existe pas\n");
    }else{
        printf("l'etudiant est modifier\n");
    }
    printf("\n\n\t\t\t1. Menu\n\n\t\t\t2. Exit\n\n\t\t Quel est votre choix ? :");
    scanf("%d",&choose);
    if(choose == 1){
        system("cls");
        menu();
    }else{
        exit(0);
    }
    
}
void supprimeMem(){
  int matricul, tr = 0,num,choose;
    FILE *tp;
    fp = fopen("etoile.txt","r");
    if(fp == NULL){
        printf("impossible d'ouvrir le fichier\n");
        exit(1);
    } 
    tp = fopen("reunion.txt","w");
    if(tp == NULL){
        printf("impossible d'ouvrir le fichier\n");
        exit(1);
    } 
    printf("Donner le matricule du membres a modifier : ");scanf("%d",&matricul);
    while(!feof(fp)){
       fscanf(fp,"%d\n%s\n%s\n%f\n",&matricule,nom,prenom,&cotisation);
       if(matricul != matricule){
        fprintf(tp,"%d\n%s\n%s\n%f\n",matricule,nom,prenom,cotisation);
       }else{
         tr = 1;
       } 
    }
    fclose(fp);fclose(tp);
    remove("etoile.txt");
    rename("reunion.txt","etoile.txt");
    if(tr == 0){
        printf("l'etudiant n'existe pas\n");
    }else{
        printf("l'etudiant est supprimer\n");
    } 
    printf("\n\n\t\t\t1. Menu\n\n\t\t\t2. Exit\n\n\t\t Quel est votre choix ? :");
    scanf("%d",&choose);
    if(choose == 1){
        system("cls");
        menu();
    }else{
        exit(0);
    } 
}