# TP3: Recherche

## Description

Le projet est un programme en C qui permet de faire une recherche de recettes dans une banque de donnée. Celle-ci est chargée à partir d'un fichier passer en argument dans une liste chainée. Puis la recherche est effectuée par catégorie et optionnellement avec un mot-clé. Ce projet a été donné lors du TP3 du cours INF3135 en Automne 2022.

## Auteurs

- Andy Edzo Nkily (EDZA23039901)
- Keven Jude Antenor (ANTK08129003)
- Ekoue Andy Scott Messan (MESE65110306)

## Fonctionnement

1- Compiler le projet en exécutant cette commande:

```sh
make
```

2. Exécuter le programme `recherche` avec le fichier contenant la banque de donnée en argument:

```sh
./recherche <nom_fichier_banque>
```

Ajouter l'option `-S <nom_fichier_stats>` pour générer les statistiques de la banque de donnée dans un fichier:

```sh
./recherche <nom_fichier_banque> -S <nom_fichier_stats>
```

3. Suivez les instructions pour effectuer vos recherches ou pour quitter le programme une fois terminer

## Tests

Pour lancer la suite de tests unitaires et d'intégrations, exécuter la commande suivante:

```sh
make test
```

## Dépendances

- [gcc](gcc.gnu.org)
- [bats](github.com/bats-core/bats-core)
- [Cunit](cunit.sourceforge.net)

## Références

- [devdocs](devdocs.io/c)
- [Cunit docs](cunit.sourcefore.net/documentation.html)


