#include <stdio.h>
#include <stdlib.h>

typedef struct Arbol
{
    int dato;
    struct Arbol *izq, *der;
} Rama;

Rama* nuevaRama(int dato);

Rama* crearRama(Rama* origen, int dato);

void mostrar_en_preorden(Rama* principal);

void mostrar_en_orden(Rama* principal);

void mostrar_en_postorden(Rama* principal);

void limpiar(Rama *principal);

int main(void)
{
    Rama *arbol = NULL;
    int total = 8;
    for (int i=1; i<=total; i++)
    {
        if (arbol == NULL)
            arbol = crearRama(arbol, i);
        else
            crearRama(arbol, i);
    }
    mostrar_en_preorden(arbol);
    printf("\n");
    mostrar_en_orden(arbol);
    printf("\n");
    mostrar_en_postorden(arbol);
    printf("\n");
    limpiar(arbol);
    return 0;
}

Rama* nuevaRama(int dato)
{
    Rama *nueva = malloc(sizeof(Rama));
    nueva->dato = dato;
    nueva->izq = nueva->der = NULL;
    return nueva;
}

Rama* crearRama(Rama* origen, int dato)
{
    if (origen == NULL) return nuevaRama(dato);
    if (dato < origen->dato)
        origen->izq = crearRama(origen->izq, dato);
    else if (dato > origen->dato)
        origen->der = crearRama(origen->der, dato);
    return origen;
}

void mostrar_en_preorden(Rama* principal)
{
    if (principal != NULL)
    {
        printf("\n(%d)", principal->dato);
        mostrar_en_preorden(principal->izq);
        mostrar_en_preorden(principal->der);
    }
}

void mostrar_en_orden(Rama* principal)
{
    if (principal != NULL)
    {
        mostrar_en_orden(principal->izq);
        printf("(%d)\t", principal->dato);
        mostrar_en_orden(principal->der);
    }
}

void mostrar_en_postorden(Rama* principal)
{
    if (principal != NULL)
    {
        mostrar_en_postorden(principal->izq);
        mostrar_en_postorden(principal->der);
        printf("(%d)\t", principal->dato);
    }
}

void limpiar(Rama *principal)
{
    if (principal != NULL)
    {
        limpiar(principal->izq);
        limpiar(principal->der);
        free(principal);
    }
}