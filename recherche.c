#include "recherche.h"

void rechercher_par_categorie(){

}

void rechercher_par_categorie_et_mot_cle(){

}

void rechercher(){

}

char *enleve_espace_deb_fin(char *chaineDeCaractere){
  char *finDeLaChaine;
  while(isspace(*chaineDeCaractere)) chaineDeCaractere ++;
  if(*chaineDeCaractere == 0) return chaineDeCaractere;
  finDeLaChaine = chaineDeCaractere + strlen(chaineDeCaractere) - 1;
  while(finDeLaChaine > chaineDeCaractere && isspace(*finDeLaChaine)) finDeLaChaine --;
  *(finDeLaChaine+1) = 0;
  return chaineDeCaractere;
}

char *enleve_espace_milieu(char *chaineDeCaractere){
    int i = 0 , j = 0; char buffer[150] = "";
    while(i < strlen(chaineDeCaractere)){
        if(chaineDeCaractere[i] != ' ' || (chaineDeCaractere[i] == ' ' && chaineDeCaractere[i+1] != ' ')){
            buffer[j] = chaineDeCaractere[i] ;
            j++ ;
        } 
        i++;
    } buffer[j] = '\0' ; strcpy(chaineDeCaractere,buffer) ;
    return chaineDeCaractere ;
}

void traiter_entree_de_utilisateur(char *critereDeRecherche){
    char *critere ;
    strcpy(critere,enleve_espace_milieu(enleve_espace_deb_fin(critereDeRecherche))) ;
    for(int i = 0; i < strlen(critere); i++) critere[i] = tolower(critere[i]) ;
}

void lancer_recherche(struct liste_categories *categories){
    char critereDeRecherche[150] = "" ; 
    do{
        print("Entrez votre critère de recherche(ou sinon 'q' pour quitter) :") ;
        scanf("%s",&critereDeRecherche) ;
        traiter_entree_de_utilisateur(critereDeRecherche) ;
    }while(strcmp(critereDeRecherche,"q") == 0) ;
    
}