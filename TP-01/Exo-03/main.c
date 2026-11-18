#include <stdio.h>
#include <time.h>

int f1(int n)
{
    int u0 = 1, u1 = 1, Un;
    if (n <= 1)
        return 1;
    for (int i = 2; i <= n; i++)
    {
        Un = u1 + u0;
        u0 = u1;
        u1 = Un;
    }
    return Un;
}

int f2(int n)
{
    if (n <= 1)
        return 1;
    return f2(n - 1) + f2(n - 2);
}

int main()
{
    int n;
    clock_t T1, T2;
    double temp;
    int resultat;
    printf("Fibonacci iterative (f1):\n\n");
    for (n = 20; n <= 40; n += 10)
    {
        T1 = clock();
        resultat = f1(n);
        T2 = clock();
        temp = (double)(T2 - T1) / CLOCKS_PER_SEC;
        printf("n = %d\n", n);
        printf("Resultat = %d\n", resultat);
        printf("Temps = %.6f seconde(s)\n\n", temp);
    }
    printf("Fibonacci recursive (f2):\n\n");
    for (n = 20; n <= 40; n += 10)
    {
        T1 = clock();
        resultat = f2(n);
        T2 = clock();
        temp = (double)(T2 - T1) / CLOCKS_PER_SEC;
        printf("n = %d\n", n);
        printf("Resultat = %d\n", resultat);
        printf("Temps = %.6f seconde(s)\n\n", temp);
    }
    return 0;
}
