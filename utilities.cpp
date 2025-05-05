
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "utilities.h"

using namespace std;



/****************************************/
/* Objectif : Affichage de la matrice d'adjacence
/****************************************/
void affichage(double *c[], int n)
{
	cout << "c = " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (n-1); j++)
			cout << setprecision(2) << c[i][j] << "\t";
		cout << setprecision(2) << c[i][n-1] << endl;		
	}

	cout << endl;
}


/****************************************/
/* Objectif : Affichage du tableau des plus longs
chemins
/****************************************/
void affichage(double d[], int n)
{
	cout << "d = " << endl;
	for(int i = 0; i < n-1; i++)
		cout << d[i] << "\t";
	
	cout << d[n-1] << endl << endl;		
}



/****************************************/
/* Objectif : Algorithme de calcul des plus longs chemins
dans un graphe dont les arcs ont des valeurs dans [0,1].
Le coût d'un chemin est le produit des coûts des arcs le composant.
- c : matrice de longueur de chaque arc
- d : tableau des plus longs chemins chemins
- pere : tableau donnant pour chaque sommet i son prédecesseur
pred[i] dans le plus long chemin.
- n : nombre de sommets du graphe
- s : sommet origine d'où les plus longs chemins sont calculés
/****************************************/
void mooredijkstra(double *c[], double d[], int n, int s)
{
	// A faire
}
