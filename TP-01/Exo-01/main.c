#include <stdio.h>
#include <stdlib.h>

// Une fonction iterative pour la recherche sequentielle d'un element x dans un tableau
int rechercheIteSequentielle(int t[], int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (t[i] == x)
        {
            return i;
        }
    }
    return -1;
}

// Une fonction recursive pour la recherche sequentielle d'un element x dans un tableau
int rechercheRecSequentielle(int t[], int x, int n)
{
    if (n < 0)
    {
        return -1;
    }
    if (t[n] == x)
    {
        return n;
    }
    return rechercheRecSequentielle(t, x, n - 1);
}

// Une fonction iterative pour la recherche dichotomique
int rechercheIteDichotomique(int t[], int x, int d, int f)
{
    while (d <= f)
    {
        int milieu = d + (f - d) / 2;
        if (t[milieu] == x)
        {
            return milieu;
        }
        if (t[milieu] > x)
        {
            f = milieu - 1;
        }
        if (t[milieu] < x)
        {
            d = milieu + 1;
        }
    }
    return -1;
}

// Une fonction Recursive pour la recherche dichotomique d'un element x dans un tableau trie
int rechercheRecDichotomique(int t[], int x, int d, int f)
{
    if (d > f)
    {
        return -1;
    }
    int milieu = d + (f - d) / 2;
    if (t[milieu] == x)
    {
        return milieu;
    }
    if (t[milieu] > x)
    {
        return rechercheRecDichotomique(t, x, d, milieu - 1);
    }
    if (t[milieu] < x)
    {
        return rechercheRecDichotomique(t, x, milieu + 1, f);
    }
    return -1;
}

int main()
{
    int T[] = {5, 30, 75, 49, 18, 33}; // les valeurs du tableau sont choisis par moi
    int A[] = {5, 18, 30, 33, 49, 75}; // on est besoin d'un tableau trie lors de la recherche dichotomique
    int n = sizeof(T) / sizeof(T[0]);  // calculer la longueur du tableau
    int d = 0;
    int f = n - 1;
    // L'appel des fonctions en prenons x = 75 et x = 33 comme des exemples
    printf("Recherche Sequentielle Iterative: %d\n", rechercheIteSequentielle(T, 75, n));
    printf("Recherche Sequentielle Recursive: %d\n", rechercheRecSequentielle(T, 75, n - 1));
    printf("Recherche Dichotomique Iterative: %d\n", rechercheIteDichotomique(A, 33, d, f));
    printf("Recherche Dichotomique Recursive: %d\n", rechercheRecDichotomique(A, 33, d, f));
    return 0;
}