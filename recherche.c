#include "recherche.h"

void rechercher_par_categorie(struct liste_categories *categories, char *critereDeRecherche){
    struct categorie *temp = categories->categories ; int i = 0 ; bool recherche = true ;
    while(i < categories->nb_categories && recherche ){
        if(strstr(critereDeRecherche,temp->nom_categorie) != NULL) {
            afficher_categorie(temp) ;
            recherche = false ;
        }
        temp = temp->suivant ;
        i++ ;
    }
    if(recherche) printf("\nCategorie inexistante.\n") ;
}

void parcourir_recettes(struct liste_recettes *listeRecette, char *buffer, bool recherche){
    struct recette *temp = listeRecette->recettes ; int i = 0;
    while(i< listeRecette->nb_recettes && recherche){
        if(strstr(buffer,temp->nom_recette) != NULL){
            printf("%s.\n",temp->nom_recette) ;
            recherche = false ;
        }
        temp = temp->suivant ; 
        i++ ;
    }
}

void rechercher_par_categorie_et_mot_cle(struct liste_categories *categories, char *critereDeRecherche){
    struct categorie *temp = categories->categories ; int i = 0 ; bool rechercheC = true, rechercheR = true ; char *buffer = strtok(critereDeRecherche," ");
    while(i < categories->nb_categories && rechercheC ){
        if(strstr(buffer,temp->nom_categorie) != NULL) {
            buffer = strtok(NULL," ") ; rechercheC = false ;
            parcourir_recettes(temp->recettes,buffer,&rechercheR) ;
        }
        temp = temp->suivant ;
        i++ ;
    }
    if(rechercheC) printf("\nCategorie inexistante.\n") ; if(rechercheR) printf("\nAucun resultat trouve.\n") ;
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

int compter_nombre_espaces(char *chaineDeCaractere){
    int i = 0 , nb = 0 ; 
    while(i < strlen(chaineDeCaractere)){
        if(chaineDeCaractere[i] == ' '){
            nb++ ;
        }
    }
    return nb ;
}

void traiter_entree_de_utilisateur(char *critereDeRecherche){
    char *critere ; int i = 0 ;
    strcpy(critere,enleve_espace_milieu(enleve_espace_deb_fin(critereDeRecherche))) ;
    while(i < strlen(critere)) {
        critere[i] = tolower(critere[i]) ;
        i++ ;
    } 
    strcpy(critereDeRecherche,critere) ;
}


void lancer_recherche(struct liste_categories *categories){
    char critereDeRecherche[150] = "" ; 
    do{
        printf("Entrez votre critère de recherche(ou sinon 'q' pour quitter) :") ;
        scanf("%s",(char *)&critereDeRecherche) ;
        traiter_entree_de_utilisateur((char *)&critereDeRecherche) ;
        if(compter_nombre_espaces(critereDeRecherche) >= 0 && compter_nombre_espaces(critereDeRecherche) < 2){
            if(compter_nombre_espaces(critereDeRecherche) == 0) rechercher_par_categorie(categories,critereDeRecherche) ;
            else(rechercher_par_categorie_et_mot_cle(categories,critereDeRecherche)) ;
        }else printf("\nRecherche Invalide.\n") ;
    }while(strcmp(critereDeRecherche,"q") != 0) ;  
}