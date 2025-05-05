
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "utilities.h"

using namespace std;



/****************************************/
/* Objectif : Affichage de la matrice d'adjacence*/
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
chemins*/
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
- s : sommet origine d'où les plus longs chemins sont calculés*/
/****************************************/
void mooredijkstra(double *c[], double d[], int n, int s)
{
	const double INF = 1e9; // une grande valeur
	double L[n][n];			// matrice des -log(c[i][j])
	bool visite[n];			// sommets visités

	// Étape 1 : construire L[i][j] = -log(c[i][j])
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (c[i][j] > 0)
				L[i][j] = -log(c[i][j]);
			else
				L[i][j] = INF; // pas de lien
		}
	}

	// Étape 2 : initialisation
	for (int i = 0; i < n; ++i)
	{
		d[i] = INF;
		visite[i] = false;
	}
	d[s] = 0;

	// Étape 3 : Dijkstra
	for (int k = 0; k < n; ++k)
	{
		// Trouver le sommet u non visité avec d[u] minimal
		int u = -1;
		double min = INF;
		for (int i = 0; i < n; ++i)
		{
			if (!visite[i] && d[i] < min)
			{
				min = d[i];
				u = i;
			}
		}

		if (u == -1)
			break; // plus de sommet atteignable

		visite[u] = true;

		// Mettre à jour les voisins
		for (int v = 0; v < n; ++v)
		{
			if (!visite[v] && L[u][v] < INF && d[v] > d[u] + L[u][v])
			{
				d[v] = d[u] + L[u][v];
			}
		}
	}

	// Étape 4 : reconversion vers probabilité
	for (int i = 0; i < n; ++i)
	{
		if (d[i] < INF)
			d[i] = exp(-d[i]);
		else
			d[i] = 0; // aucun chemin
	}
}
