#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ListaEnlazada.h"

int generarPositivo(int max);

int generarNegativo(int min);

int main(void)
{
    srand(time(NULL));
    nodo *principal = NULL;
    printf("Iniciando...\n");

    int total = generarPositivo(9) + 1;
    printf("generando una lista de %d elementos.\n", total);
    for (int i=1; i<=total; i++)
    {
        if (rand() % 2 > 0)
            insertarEn(&principal, i, crearNodo(generarPositivo(100)));
        else
            insertarEn(&principal, i, crearNodo(generarNegativo(-100)));
    }

    insertarAlInicio(&principal, crearNodo(generarNegativo(0)));
    total++;

    insertarEn(&principal, total * total, crearNodo(generarNegativo(0)));

    insertarEn(&principal, 1, crearNodo(generarPositivo(0)));

    mostrarLista(principal);

    ascendente(principal);

    mostrarLista(principal);

    descendente(principal);

    mostrarLista(principal);

    limpiarLista(principal);

    printf("Fin del programa.\n");
    return 0;
}

int generarPositivo(int max)
{
    if (max > 0) return (rand() % max) + 1;
    else return (rand() % 1000) + 1;
}

int generarNegativo(int min)
{
    return generarPositivo(min * -1) * -1;
}