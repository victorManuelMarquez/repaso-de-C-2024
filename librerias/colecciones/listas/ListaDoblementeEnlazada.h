#ifndef LISTA_DOBLEMENTE_ENLAZADA_
#define LISTA_DOBLEMENTE_ENLAZADA_

#include "../Eslabon.h"

void insertarAlFinal(eslabon *principal, eslabon *nuevo);

eslabon* crearNodo(int dato)
{
    eslabon *nuevo = malloc(sizeof(eslabon));
    nuevo->dato = dato;
    nuevo->anterior = nuevo->siguiente = NULL;
    return nuevo;
}

eslabon* generarNodos(int cantidad)
{
    eslabon *principal = NULL;
    for (int i=0; i<cantidad; i++)
    {
        eslabon *nuevo = crearNodo(rand() % 1001);
        if (principal)
        {
            insertarAlFinal(principal, nuevo);
        }
        else
        {
            principal = nuevo;
        }
    }
    return principal;
}

void mostrar(eslabon *principal)
{
    if (!principal)
    {
        printf("La lista está vacía.\n");
        return;
    }
    eslabon *actual = principal;
    while (actual)
    {
        printf("%p -> %d\n", actual, actual->dato);
        actual = actual->siguiente;
    }
}

void ordenNatural(eslabon *principal)
{
    if (!principal)
    {
        printf("La lista no existe!.\n");
        return;
    }
    eslabon *p = principal;
    while (p->siguiente)
    {
        eslabon *sig = p->siguiente;
        while (sig)
        {
            if (p->dato > sig->dato)
            {
                int valor = p->dato;
                p->dato = sig->dato;
                sig->dato = valor;
            }
            sig = sig->siguiente;
        }
        p = p->siguiente;
    }
    printf("Lista ordenada ascendentemente.\n");
}

void ordenInverso(eslabon *principal)
{
    if (!principal)
    {
        printf("La lista no existe!.\n");
        return;
    }
    for (eslabon *p = principal; p->siguiente; p = p->siguiente)
    {
        for (eslabon *aux = p->siguiente; aux; aux = aux->siguiente)
        {
            if (p->dato < aux->dato)
            {
                int valor = aux->dato;
                aux->dato = p->dato;
                p->dato = valor;
            }
        }
    }
    printf("Lista ordenada descendentemente.\n");
}

void insertarAlInicio(eslabon **principal, eslabon *nuevo)
{
    if (principal)
    {
        printf("El nodo ya existe!\n");
        free(nuevo);
        return;
    }
    nuevo->siguiente = *principal;
    ((eslabon*) principal)->anterior = nuevo;
    *principal = nuevo;
    printf("(%p -> %d) insertado al inicio.\n", nuevo, nuevo->dato);
}

void insertarAlFinal(eslabon *principal, eslabon *nuevo)
{
    if (!principal)
    {
        printf("No existe el nodo.\n");
        free(nuevo);
        return;
    }
    while (principal->siguiente)
    {
        principal = principal->siguiente;
    }
    nuevo->anterior = principal;
    principal->siguiente = nuevo;
}

void insertarDespuesDe(eslabon *nodo, eslabon *nuevo)
{
    if (!nodo)
    {
        printf("El nodo no existe!\n");
        free(nuevo);
        return;
    }
    nuevo->siguiente = nodo->siguiente;
    nuevo->anterior = nodo;
    nodo->siguiente = nuevo;
    printf("se insertó %d después de %d.\n", nuevo->dato, nuevo->anterior->dato);
}

eslabon* eliminar(eslabon *nodo)
{
    if (!nodo)
    {
        printf("Nodo vacío.\n");
        return nodo;
    }
    eslabon *temporal = nodo;
    nodo->anterior = NULL;
    nodo = nodo->siguiente;
    printf("free(%d)\n", temporal->dato);
    free(temporal);
    temporal = NULL;
    return nodo;
}

eslabon* vaciar(eslabon *principal)
{
    while (principal)
    {
        principal = eliminar(principal);
    }
    return principal;
}

#endif