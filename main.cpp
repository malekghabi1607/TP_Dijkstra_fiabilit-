
#include <iostream>
#include "utilities.h"

using namespace std;

int main()
{
    const int n = 5;
    int s = 2;

    double **c = new double *[n];
    for (int i = 0; i < n; i++)
        c[i] = new double[n];

    double valeurs[n][n] = {
        {0.0, 0.1, 0.2, 0.2, 0.3},
        {0.1, 0.0, 0.2, 0.6, 0.3},
        {0.2, 0.2, 0.0, 0.8, 0.8},
        {0.2, 0.6, 0.8, 0.0, 0.9},
        {0.3, 0.3, 0.8, 0.9, 0.0}};

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            c[i][j] = valeurs[i][j];

    double d[n];

    mooredijkstra(c, d, n, s);

    affichage(d, n);

    for (int i = 0; i < n; i++)
        delete[] c[i];
    delete[] c;

    return 0;
}