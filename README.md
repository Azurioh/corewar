# Corewar - Projet de fin de 1ère année

## Qu'est ce que le Corewar ?

Le [**Corewar**](https://fr.wikipedia.org/wiki/Core_War) est un **jeu de programmation** dans lequel des programmes s'affrontent dans une **arène virtuelle**. Les programmes sont écrits dans un langage **assembleur spécifique**, et sont ensuite compilés en un **fichier binaire**. 

Ces programmes sont ensuite chargés dans l'arène virtuelle, et s'exécutent en parallèle. Le **but du jeu** est de faire en sorte que **son programme soit le dernier à s'exécuter**.

Le projet Corewar **traitera uniquement de l'arène virtuelle**, et non de la compilation des programmes.

## Comment lancer le Corewar ?

Dans un premier temps, il faut compiler le projet. Pour ce faire, il suffit de **cloner le dépot actuel** et de lancer la commande `make` à la racine du projet. Cela générera un exécutable nommé `corewar`. 

Voici les commandes à rentrer dans un terminal pour réaliser ces opérations :

```bash
git clone git@github.com:Azurioh/corewar.git
cd corewar
make
```

<br>

Maintenant, pour lancer le Corewar, il suffit de lancer l'exécutable que nous venons de générer.

```bash
./corewar champs/abel.cor champs/tylor.cor
```

**Attention** : L'exécutable `corewar` prend en paramètre **2 fichiers binaire** représentant les programmes à exécuter. Il est possible de trouver des fichiers binaires dans le dossier `champs`.

## Un bonus ?

Nous avons implémenté une **interface graphique** pour le Corewar. Cela vous permettra de visualiser l'état de la mémoir en temps réel. Cette partie comporte encore quelques bugs, par manque de temps pour la réaliser.

Pour lancer le Corewar en mode visualisation, il faut compiler à nouveau le projet en utilisant cette fois si la commande :

```bash
make bonus
```

Une fois que vous avez compilé le projet, vous pouvez lancer le Corewar en mode visualisation de la même manière qu'en temps normal, mais cette fois si avec le nouvel exécutable `:

```bash
./corewar_bonus champs/abel.cor champs/tylor.cor
```

## Résultats :

- Preliminary **(2 / 2)** :
- Virtual Machine - Basics **(4 / 5)** :
- Virtual Machine - Algorithm app. **(3 / 3)** :
- Virtual Machine - Scheduling **(2 / 2)** :

### Total : 11 / 12

---


### Crédits : [Alan CUNIN](https://www.linkedin.com/in/alancunin/) et [Mattéo MILLIN](https://www.linkedin.com/in/matteo-milin/)