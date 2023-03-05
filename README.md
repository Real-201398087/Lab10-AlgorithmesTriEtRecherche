# Lab 10 - Algorithmes de Tri

## Description
Dans ce laboratoire, nous allons mettre à l'essaie 3 algorithmes de tri : 
- tri à bulle
- tri par sélection
- tri par insertion

Voici les détails d'implémentation de ces 3 types de tri.

## Tri à bulle
- Il consiste à faire remonter le plus petit élément du tableau (comme une bulle d'air remonte à la surface) en comparant les éléments successifs. C'est-à-dire qu'on va comparer le 1er et le 2e élément du tableau, conserver le plus petit et puis les échanger s'ils sont désordonnés les uns par rapport aux autres. On recommence cette opération jusqu'à la fin du tableau.
- Cet algorithme est très critiqué en raison de sa lenteur d'exécution. Il a non seulement beaucoup d’itérations, mais beaucoup d’échanges d’éléments.
- Vous devez passer en paramètre le tableau d’objets à trier ainsi que sa dimension.

**Pseudo-code**
```
POUR i DE 0 A n-1  //n étant la size du tableau
    POUR j DE i+1 A n
        SI tab(i) > tab(j)
            Permute(tab(i), tab(j))
```


## Tri par sélection 
- Il consiste à rechercher la position du plus petit élément que l'on va déplacer à sa position finale (1ère du tableau au début), puis rechercher la position du 2e plus petit que l'on va déplacer à la 2e position, jusqu'à ce que le tableau soit tout trié.
- Le tri par sélection est intéressant lorsque les éléments sont faciles à comparer mais coûteux à déplacer. Ainsi, le nombre de comparaisons sera toujours supérieur ou égal à ce qui est nécessaire pour effectuer un tri par insertion ou un tri à bulles. Par contre, le nombre d'échanges sera en moyenne très inférieur.

**Pseudo-code**
```
POUR i DE 0 A n-1  //n étant la size du tableau
    posMin ← i
    POUR j DE i+1 A n
        SI tab(j) < tab(posMin)
            posMin ←  j
    SI i != posMin
        permute (tab(i), tab(posMin))
```

## Tri par insertion
- Le tri par insertion est le tri le plus efficace sur des listes de petite taille.
- Le principe de ce tri est très simple : c’est le tri que toute personne utilise naturellement quand elle a des dossiers (ou n’importe quoi d’autre) à classer. On prend un dossier et on le met à sa place parmi les dossiers déjà triés. Puis on recommence avec le suivant.
- Ce tri considère le tableau en deux zones. Une zone ordonnée et une zone non ordonnée. La taille de ces zones augmente et diminue à chaque tour.

**Pseudo-code**
```
POUR i DE 1 A n		//n étant la size du tableau
    temp ←  tab(i)
    POUR j DE i-1 A 0 PAR -1
        SI temp > tab(j)
            termine
        SINON 
            tab(j+1) ← tab(j)
        FIN SI
    FIN POUR
    tab(j+1) ← temp
FIN POUR
```

## Énoncé du laboratoire
Maintenant que nous avons un aperçu du fonctionnement des algorithme de tri, c'est le temps de les programmer.  Pour ce laboratoire, nous allons ré-utiliser le sujet du laboratoire 2 soit le fichier .csv des casernes de pompiers.  Nous utiliserons les données de ce fichier pour pratiquer les algos de tri et au prochain cours les algos de recherche.  

Tout d'abord, nous allons "convertir" ce lab 2 en objet.  Il vous faudra donc créer une classe `Caserne` qui représentera une ligne du fichier csv.  Cette classe doit pouvoir contenir les informations du fichier CSV, donc un attribut par colonne.

Ensuite, on devra lire le fichier .csv, créer un objet caserne par ligne que l'on met dans un tableau statique de 68 entrées (soit le nombre de caserne dans le fichier).   
