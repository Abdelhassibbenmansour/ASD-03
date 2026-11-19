#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Une fonction qui trouve la plus grandes valeurs dans un tableau
int maxx(int t[], int n)
{
    int max = t[0];
    for (int i = 0; i < n; i++)
    {
        if (max < t[i])
        {
            max = t[i];
        }
    }
    return max;
}

// Une fonction qui tri un tableau par dénombrement
void countingSort(int t[], int n)
{
    int max = maxx(t, n);
    int newTab[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        newTab[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        newTab[t[i]]++;
    }
    int k = 0;
    for (int i = 0; i < max + 1; i++)
    {
        while (newTab[i] > 0)
        {
            t[k] = i;
            k++;
            newTab[i]--;
        }
    }
}

// Une fonction qui affiche le contenu d'un tableau
void afficher(int t[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", t[i]);
    printf("\n");
}

int main()
{
    int T1[] = {5, 11, 8, 2, 14, 21, 9, 1};
    int n1 = 8;
    clock_t T1_time, T2_time;
    double temps;
    T1_time = clock();
    countingSort(T1, n1);
    T2_time = clock();
    temps = (double)(T2_time - T1_time) / CLOCKS_PER_SEC;
    printf("Tableau 1 apres tri: ");
    afficher(T1, n1);
    printf("Temps: %.6f seconde(s)\n\n", temps);
    return 0;
}