# Simulation de la commande `cp`

Ce projet implémente une simulation de la commande Unix `cp`, permettant de copier le contenu de fichiers vers d'autres fichiers ou vers un répertoire.

## Compilation

Pour compiler le programme, exécutez la commande suivante :

```bash
gcc cp.c -o cp
```

## Utilisation

Le programme prend en charge deux scénarios d'utilisation :

### 1. Copier le contenu d'un fichier vers un autre fichier

**Commande :**
```bash
./cp fichier_source fichier_cible
```

**Exemple :**
```bash
./cp monfichier1 monfichier2
```

Cette commande copie le contenu de `monfichier1` dans `monfichier2`. Si `monfichier2` n'existe pas, il sera créé.

### 2. Copier plusieurs fichiers vers un répertoire

**Commande :**
```bash
./cp fichier1 fichier2 fichier3 répertoire
```

**Exemple :**
```bash
./cp monfichier1 monfichier2 monfichier3 rep
```

Cette commande copie le contenu de `monfichier1`, `monfichier2`, et `monfichier3` dans le répertoire `rep`. Si les fichiers n'existent pas dans `rep`, ils seront créés.

