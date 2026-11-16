#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Une fonction qui creé une liste chainée
Node *creerListe(int t[], int n)
{
    Node *tete = NULL;
    Node *p = NULL;
    Node *q = NULL;
    for (int i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        if (p == NULL)
        {
            printf("Erreur d'allocation memoire\n");
            return tete;
        }
        p->data = t[i];
        p->next = NULL;
        if (tete == NULL)
        {
            tete = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
    return tete;
}

// Une fonction qui affiche le contenu d'une liste chainée
void afficherListe(Node *tete)
{
    Node *p = tete;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// Une fonction iterative qui recherche un element x a partir d'une liste chainée
int rechercheIteListe(Node *tete, int x)
{
    Node *p = tete;
    int i = 0;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return i;
        }
        p = p->next;
        i++;
    }
    return -1;
}

// Une fonction recursive qui recherche un element x a partir d'une liste chainée
int rechercheRecListe(Node *tete, int x, int i)
{
    if (tete == NULL)
    {
        return -1;
    }
    if (tete->data == x)
    {
        return i;
    }
    return rechercheRecListe(tete->next, x, i + 1);
}

int main()
{
    int T[] = {5, 30, 75, 49, 18, 33}; // les valeurs du tableau sont choisis par moi
    int n = sizeof(T) / sizeof(T[0]);
    Node *tete = creerListe(T, n);
    afficherListe(tete);
    printf("Recherche iterative : %d\n", rechercheIteListe(tete, 48));
    printf("Recherche recursive : %d\n", rechercheRecListe(tete, 18, 0));
}