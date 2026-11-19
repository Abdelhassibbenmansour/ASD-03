#include <stdio.h>
#include <stdlib.h>

// Une fonction qui échange deux éléments d'un tableau.
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Une fonction qui affiche le contenu d'un tableau
void afficher(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Une fonction qui trie un tableau en utilisant la méthode du tri gnome
void triGnome(int A[], int n)
{
    int i = 0;
    while (i < n)
    {
        if (i == 0)
            i++;
        if (A[i] >= A[i - 1])
            i++;
        else
        {
            swap(A, i, i - 1);
            i--;
        }
    }
}

int main()
{
    int liste[] = {4, 2, 3, 5, 1};
    int n = sizeof(liste) / sizeof(liste[0]);
    triGnome(liste, n);
    printf("Tableau trie : ");
    afficher(liste, n);
    return;
}