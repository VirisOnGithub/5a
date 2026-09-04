---
color: yellow
---

# TD1

# Exercice 1

## 1.1

Le code exécutable sera exécuté dans la ROM (dans la mémoire FLASH)

## 1.2

La pile est utile :

- Pour l'utilisation des variables locales
- Lors des appels des fonction : paramètres reçus et retournés, adresse de retour
- Pour sauvegarder le contexte du CPU lors des interruptions (ensemble des registres internes au processeur)

Elle utilise la RAM

## 1.3

Le microprocesseur lit l'adresse du startup dans la table des vecteurs d'interruption : il s'agit de l'adresse du vecteur de reset

## 1.4

C'est une entrée : il donne une information binaire (si il est activé ou pas)

## 1.5

Une LED est une sortie : elle permet d'indiquer à l'utilisateur une information

## 1.6

Une grandeur analogique est une grandeur qui varie de manière continue. La fonction représentative est donc toujours une fonction **continue**

Capteurs possibles :

- Capteur de température
- Micro
- Anémomètre

## 1.8

ça dépend de la couleur :

- led rouge/jaune/vert : 1.8V
- led bleue : 2.2V
- led blanche : 3V

## 1.9

### 1.9.a

Le niveau logique 1 permet d'allumer la LED

### 1.9.b

Le niveau logique 0 permet d'allumer la LED

## 1.11

- 0 si on appuie
- Si on appuie pas, on sait pas

Pour résoudre :

- Soit une résistance pull up reliée au courant : 0 si actif, 1 si relâché
- Soit une résistance pull down reliée à la terre : 1 si actif, 0 si relâché

# Exercice 2

| Nom broche  | numéro GPIO |                Remarque                 |
| :---------: | :---------: | :-------------------------------------: |
|     A0      |     26      | GPIO & analog input & **analog output** |
|     A1      |     25      | GPIO & analog input & **analog output** |
|     A2      |     34      |            GPI (only input)             |
|     A3      |     39      |            GPI (only input)             |
|     A4      |     36      |            GPI (only input)             |
|     D2      |     14      |                                         |
|     D3      |     32      |                                         |
|     D4      |     15      |                                         |
|     D5      |     33      |                                         |
|     RX      |   RX (16)   |           peut servir de GPIO           |
|     TX      |   TX (17)   |           peut servir de GPIO           |
|     SCL     |     22      |                                         |
|     SDA     |     23      |                                         |
|     SCL     |     22      |                                         |
|     SDA     |     23      |                                         |
| LED BUILTIN |     13      |                                         |
