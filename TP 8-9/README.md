# README
## TP 8-9 de programmation C
### Table des matières
- [README](#readme)
  - [TP 8-9 de programmation C](#tp-8-9-de-programmation-c)
    - [Table des matières](#table-des-matières)
      - [Compiler](#compiler)
      - [Lancer l'exécutable](#lancer-lexécutable)
        - [Chiffrement d'un message](#chiffrement-dun-message)
        - [Démineur](#démineur)
      - [Supprimer les fichiers en .exe et .o](#supprimer-les-fichiers-en-exe-et-o)
      - [Documentation Doxygen](#documentation-doxygen)
      - [Sauvegarde des fichiers sources](#sauvegarde-des-fichiers-sources)
      - [Restauration de la dernière sauvegarde](#restauration-de-la-dernière-sauvegarde)
      - [Ouvrir la documentation Doxygen](#ouvrir-la-documentation-doxygen)
    - [Crédits](#crédits)

#### Compiler
***
Pour compiler :
```sh
make
```
Cela créera aussi l'éxecutable.
#### Lancer l'exécutable
***
Il existe différentes options dans cet exécutable :
##### Chiffrement d'un message
```sh
./bin/TP8-9 -c <nom_methode> -m <"message">
```
Il existe 3 méthodes de chiffrement ici : cesar, vigenere et scytale.
Si le message est une phrase (comportant donc des espaces) il faut absolument mettre les guillemets ("message").
Si vous choisissez le code César, il faut saisir ceci :
```sh
./bin/TP8-9 -c <nom_methode> -m <"message"> -d <decalage>
```
Le décalage doit être un entier.
Si vous choisissez le code Vigenère, il faut saisir ceci :
```sh
./bin/TP8-9 -c <nom_methode> -m <"message"> -k <cle>
```
La clé est un mot.
Pour le code de Scytale, utilisez que les arguments -c et -m.
##### Démineur
Pour jouer au démineur, il faut saisir ceci :
```sh
./bin/TP8-9 -demineur
```
#### Supprimer les fichiers en .exe et .o
***
Pour supprimer les fichiers en .exe et .o :
```sh
make clean
```
#### Documentation Doxygen
***
En lançant cette commande :
```sh
make doc
```
La documentation Doxygen sera créée ou mise à jour si elle existe déjà.
#### Sauvegarde des fichiers sources
***
Pour sauvegarder vos fichiers sources, il suffit de faire ceci :
```sh
make save
```
#### Restauration de la dernière sauvegarde
***
Pour récupérer la toute dernière sauvegarde, utilisez cette commande :
```sh
make restore
```
#### Ouvrir la documentation Doxygen
***
Pour ouvrir la documentation Doxygen :
```sh
make doxy
```
### Crédits
***
Auteur : Ugo Latry (<latryugo@cy-tech.fr>)