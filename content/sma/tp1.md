---
color: purple
---

# TP1

## Exercice 2

### Q4.1

Les groupes sont mixtes au début, dont il faut garantir que personne ne bouge : 

On imagine le pire cas : je suis un homme, dans les 9 autres groupes il y a 1 femme (pour la mixité), et dans mon groupe, je suis tout seul avec 66 femmes. Pour que je ne parte pas, il faut donc que mon seuil de tolérance soit de $\frac{66}{67}$, soit $98.5\%$.

## Exercice 6

### 1.1

Il y a 421 moutons dans ma simulation. (345 loups)

### 1.2

Il y a 265 moutons (15 loups, 166 herbes)

### 2

Avec 10 moutons au départ, les loups disparaissent rapidement par manque de nourriture, et donc les moutons finissent par être seuls et grandir exponentiellement.

![](/images/sma-tp1-1.png)

### 3.4

On voit qu'après 100 pas de simulation, il y a environ 550 moutons pour 300 loups. Ce n'est pas surprenant : Avec plus de moutons, les loups ont plus de nourriture et donc peuvent mieux se reproduire.

## Exercice 8

### 2.1 

![](/images/sma-tp1-2.png)

### 3.1

![](/images/sma-tp1-3.png)

## Exercice 9

### 1.6

Il y a 3 variables : 

- Le nombre de voitures
- L'accélération
- La décélération

## Exercice 10

### 2

L'arrière-plan s'est changé en jaune.

### 3

Les `turtles` sont les sprites des animations, donc on s'attend à ce que les voitures se colorent toutes en marron, et c'est ce qu'il se passe.

### 4.3

L'arrière-plan est jaune, les voitures sont roses, et l'emplacement initial des voitures est blanc.

### 5 

- `color` => avant-plan
- `pcolor` => arrière-plan

### 5.1

En s'adressant aux `turtles`

```netlogo
set color blue
set pcolor red
```

### 5.2 

En appuyant sur setup, les couleurs reviennent à la normale.

## Exercice 11

### 3

- Numéro : 10 (C'est variable selon comment la voiture à été placé au Setup)
- Couleur : 15
- Forme : "car"

### 6.3

La tuile sur laquelle j'ai cliqué se color en rouge

### 6.4

La tuile concernée se colore en jaune

## Exercice 12

### 3.1

Il ne se passe rien.

### 4.2 

Des flèches de couleurs aléatoires apparaissent à des endroits aléatoires dans la vue.

## Exercice 14

### Q3

Les flèches se déplacent et tournent aléatoirement. Quand on rappuie sur le bouton `Go`, les flèches s'arrêtent.

## Exercice 15

### 2.1 

```netlogo
to move-turtles
  ask turtles [
    left random 45
    forward 1
  ]
end
```

## Exercice 17

### 2

Les tortues "mangent" désormais l'herbe quand elles passent dessus.

## Exercice 19

### 4

Lorsque l'interrupteur `montre-energie?` est actif, un label est placé sur chaque tortue qui indique son énergie.

## Exercice 20

### 2

Désormais, les tortues peuvent se reproduire et mourir, l'herbe peut repousser.

## Exercice 21

### 6

![](/images/sma-tp1-4.png)

## Conclusion

::download-button
---
url: "/netlogo/tp1.nlogox"
filename: "tp1.nlogox"
---
::
