#include "fichier.h"

struct recette *creerRecette(char *nomRecette){
   struct recette *uneRecette = initialiser_recette(nomRecette);
   return uneRecette ;
}

struct categorie *creerCategorie(char *nomCategorie){
   struct categorie *uneCategorie = initialiser_categorie(nomCategorie);
   return uneCategorie ;
}

void ouvrirFichier(FILE *fichier){
   if(fichier == NULL) {
      printf("Erreur %s\n", strerror(errno));
      exit(1);
   }
}

bool est_fichier(char *nomDuFichier){
   FILE *fichier = fopen(nomDuFichier,"r");
   if(fichier == NULL) return false ;
   else { fclose(fichier) ; return true ;} ;
}

void fermerFichier(FILE *leFichier){
   if(fclose(leFichier) == EOF){
      printf("Erreur lors de la fermeture du fichier.\n") ;
      exit(1) ;
   }
}

void viderTab(char *tabAVider){
   int i = 0 ;
   while(i < strlen(tabAVider)){
      if(tabAVider[i] != 0){
            tabAVider[i] = '\0' ;
        }
      i++ ;
   }
}

char *trouver_nom_recette(char *ligne, char *nomRecette){
   int k = 0 , index = 0;
   while(ligne[index] != '['){
      nomRecette[k] = ligne[index] ;
      k++; index++;
   }
   return nomRecette ;
}

char *trouver_nom_categorie(char *ligne, int index, char nomCategorie[50]){
   int j = 0 ; index++;
   while(ligne[index] != ']'){
      nomCategorie[j] = ligne[index] ;
      index++;j++;
   }
   return nomCategorie ;
}

void remplir_liste_categorie(struct liste_categories *liste_categorie, char *nomRecette , char *nomCategorie){
   struct recette *recette = creerRecette(nomRecette) ;
   struct categorie *categorie = creerCategorie(nomCategorie) , *temp = liste_categorie->categories ; 
   int i = 0 ;
   while(i < liste_categorie->nb_categories){
      if(comparer_categories(categorie,temp) != 0){
         ajouter_recette(recette,(categorie->recettes)) ; 
         ajouter_categorie(categorie,liste_categorie) ;
      }
      temp = temp->suivant ;
      i++ ;
   }
}

void manipuler_ligne(struct liste_categories *liste_categorie , char *ligne){
   int i = 0 ;
   char nomRecette[100] = "" , nomCategorie[50] = "" ;
   while(ligne[i] != '\0' && ligne[i] != '\n'){
      strcpy(nomRecette,trouver_nom_recette(ligne,(char *)&nomRecette)) ;
      if(ligne[i] == '['){
         strcpy(nomCategorie,trouver_nom_categorie(ligne,i,nomCategorie)) ;
         remplir_liste_categorie(liste_categorie,nomRecette,nomCategorie) ;
      } 
      viderTab((char *)&nomCategorie) ; viderTab((char *)&nomRecette) ;
      i++;
   }
}

struct liste_categories *lire_fichier(char *nom_fichier) {
   FILE *leFichier = fopen(nom_fichier,"r") ; char ligne[1000] = "", nomRecette[100] = "" , nomCategorie[50] = "" ;
   struct liste_categories *liste_categorie = initialiser_liste_categories();
   ouvrirFichier(leFichier) ;
   while(fgets(ligne,1000,leFichier) != NULL){
      manipuler_ligne(liste_categorie,ligne) ;
   }
   fermerFichier(leFichier) ;
   return liste_categorie ;
}

