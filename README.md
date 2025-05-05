# Dijkstra - Fiabilité

> 🧠 Implémentation d'un algorithme basé sur Dijkstra pour trouver les **chemins les plus fiables** (au lieu des plus courts) dans un graphe pondéré.

---

## 📌 Objectif

Ce projet implémente une version modifiée de l'algorithme de Dijkstra qui permet de trouver, à partir d’un sommet source, les **chemins de fiabilité maximale** vers les autres sommets d’un graphe.

- Les arêtes du graphe ont des **valeurs entre 0 et 1**, représentant des **probabilités de fiabilité**.
- Le **chemin le plus fiable** maximise le **produit des probabilités** des arêtes empruntées.

---

## 💡 Astuce utilisée

- Le produit des probabilités est transformé en **somme de `-log(p)`** pour pouvoir utiliser l’algorithme classique de Dijkstra (qui minimise des sommes).
- À la fin de l’algorithme, les probabilités sont retrouvées avec `exp(-x)`.

---

## 📁 Fichiers

- `main.cpp` : fichier principal avec un exemple de test.
- `utilities.cpp` : implémentation de l’algorithme `mooredijkstra`.
- `utilities.h` : déclarations des fonctions.

---

## ▶️ Compilation & Exécution

### 1. Compilation

```bash
g++ main.cpp utilities.cpp -o dijkstra -lm

```


### 2. Exécution

```bash
./dijkstra

```


## 🧪 Exemple de sortie

```bash
c = 
0	0.5	0.3	0.6
0.5	0	0	1
0.3	0	0	0.1
0.6	1	0.1	0

d = 
0	0.6	0.3	0.6
```
