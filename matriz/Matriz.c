#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargar(int f, int c, int matrix[f][c]);

void mostrar(int f, int c, int matrix[f][c]);

void diagonalPrincipal(int f, int c, int matrix[f][c]);

void diagonalSecundaria(int f, int c, int matrix[f][c]);

int main(void)
{
    srand(time(NULL));
    int f = (rand() % 8) + 2, c = (rand() % f) + f;
    int matrix[f][c];
    cargar(f, c, matrix);
    mostrar(f, c, matrix);

    f = 6, c = 6;
    int cuadrado[f][c];
    cargar(f, c, cuadrado);
    mostrar(f, c, cuadrado);

    diagonalPrincipal(f, c, cuadrado);
    diagonalSecundaria(f, c, cuadrado);

    int x, y, z;
    x = y = z = 3;
    int cubo[x][y][z];
    for (int i=0; i<x; i++)
    {
        printf("\nNivel %d", i + 1);
        for (int j=0; j<y; j++)
        {
            printf("\n\tFila %d ->\t| ", j+1);
            for (int k=0; k<z; k++)
            {
                cubo[i][j][k] = (rand() % 9) + 1;
                printf("%d | ", cubo[i][j][k]);
            }
        }
    }
    printf("\n");
    return 0;
}

void cargar(int f, int c, int matrix[f][c])
{
    for (int i=0; i<f; i++)
    {
        for (int j=0; j<c; j++)
            matrix[i][j] = (rand() % 9) + 1;
        printf("\n");
    }
}

void mostrar(int f, int c, int matrix[f][c])
{
    for (int i=0; i<f; i++)
    {
        for (int j=0; j<c; j++)
            printf("%d | ", matrix[i][j]);
        printf("\n");
    }
}

void diagonalPrincipal(int f, int c, int matrix[f][c])
{
    if (f == c)
    {
        printf("Diagonal principal: ");
        int j = 0;
        for (int i=0; i<f; i++)
        {
            if (i == j) printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
    }
}

void diagonalSecundaria(int f, int c, int matrix[f][c])
{
    if (f == c)
    {
        printf("Diagonal secundaria: ");
        for (int i=0; i<c; i++)
        {
            f--;
            printf("%d ", matrix[f][i]);
        }
        printf("\n");
    }
}