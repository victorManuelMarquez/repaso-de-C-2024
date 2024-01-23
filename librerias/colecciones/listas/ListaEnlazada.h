#ifndef LISTA_ENLAZADA_H_
#define LISTA_ENLAZADA_H_

#include <stdlib.h>
#include "../Nodo.h"

nodo* crearNodo(int dato)
{
    nodo *nuevo = malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo* eliminarNodo(nodo *actual)
{
    nodo *temporal = actual;
    actual = actual->siguiente;
    free(temporal);
    temporal = NULL;
    return actual->siguiente;
}

nodo* buscarValor(nodo *principal, int valor)
{
    nodo *actual = principal;
    int encontrado = 0;
    while (actual && encontrado == 0)
    {
        if (actual->dato == valor)
            encontrado++;
        else
            actual = actual->siguiente;
    }
    return actual;
}

void insertarAlFinal(nodo *principal, nodo *nuevo)
{
    if (!principal)
    {
        printf("La lista está vacía.\n");
        return;
    }
    nodo *ultimo = principal;
    while (ultimo->siguiente)
        ultimo = ultimo->siguiente;
    ultimo->siguiente = nuevo;
}

void insertarAlInicio(nodo** principal, nodo *nuevo)
{
    if (!principal)
    {
        printf("La lista está vacía.\n");
        return;
    }
    nuevo->siguiente = *principal;
    *principal = nuevo;
    printf("(%p) -> %d\tes ahora el inicio de la lista.\n", *principal, (*principal)->dato);
}


void insertarEn(nodo **principal, int posicion, nodo *nuevo)
{
    if (!principal)
    {
        printf("\nprimer elemento: (%p) -> %d\n", nuevo, nuevo->dato);
        return;
    }
    if (posicion < 1)
    {
        printf("\nNo es posible realizar esta operación.\n");
        return;
    }
    else if (posicion == 1)
    {
        nuevo->siguiente = *principal;
        *principal = nuevo;
        printf("nueva cabecera: (%p) -> %d\n", *principal, (*principal)->dato);
        return;
    }
    int i = 1;
    nodo *temporal = *principal;
    while (i < posicion && temporal->siguiente)
    {
        temporal = temporal->siguiente;
        i++;
    }
    if (i+1 < posicion)
    {
        printf("La posición %d no existe.\n", posicion);
        free(nuevo);
    }
    else
    {
        nuevo->siguiente = temporal->siguiente;
        temporal->siguiente = nuevo;
        printf("%d insertado después de: (%p)->%d.\n", nuevo->dato, temporal, temporal->dato);
    }
}

void ascendente(nodo *principal)
{
    printf("ordenando de menor a mayor...\n");
    int aux = 0;
    nodo *encabezado = principal;
    while (encabezado->siguiente)
    {
        nodo *temporal = principal;
        while (temporal->siguiente)
        {
            if (temporal->dato > temporal->siguiente->dato)
            {
                //printf("\t%d > %d [%p, %p]\n", temporal->dato, temporal->siguiente->dato, temporal, temporal->siguiente);
                aux = temporal->dato;
                temporal->dato = temporal->siguiente->dato;
                temporal->siguiente->dato = aux;
            }
            temporal = temporal->siguiente;
        }
        encabezado = encabezado->siguiente;
    }
    printf("\tordenado!\n");
}

void descendente(nodo *principal)
{
    printf("ordenando de mayor a menor...\n");
    int aux = 0;
    nodo *encabezado = principal;
    while (encabezado->siguiente)
    {
        nodo *temporal = principal;
        while (temporal->siguiente)
        {
            if (temporal->dato < temporal->siguiente->dato)
            {
                //printf("\t%d < %d [%p, %p]\n", temporal->dato, temporal->siguiente->dato, temporal, temporal->siguiente);
                aux = temporal->dato;
                temporal->dato = temporal->siguiente->dato;
                temporal->siguiente->dato = aux;
            }
            temporal = temporal->siguiente;
        }
        encabezado = encabezado->siguiente;
    }
    printf("\tordenado!\n");
}

void mostrarLista(nodo *principal)
{
    if (!principal)
    {
        printf("Lista vacía.\n");
        return;
    }
    printf("Lista enlazada: { ");
    nodo *actual = principal;
    while (actual)
    {
        if (actual->siguiente)
            printf("%d | ", actual->dato);
        else
            printf("%d }", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void limpiarLista(nodo *principal)
{
    while (principal)
    {
        nodo *temporal = principal;
        principal = principal->siguiente;
        printf("free(%p) -> %d\n", temporal, temporal->dato);
        free(temporal);
        temporal = NULL;
    }
}

#endif