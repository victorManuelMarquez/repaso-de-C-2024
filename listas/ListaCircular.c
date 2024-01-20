#include <stdio.h>
#include <stdlib.h>

typedef struct Enlace
{
    char * dato;
    struct Enlace *siguiente;
} Nodo;

int main(void)
{
    Nodo *inicio = NULL;
    int total = 5;
    for (int i=0; i<total; i++)
    {
        Nodo *nuevo = malloc(sizeof(Nodo));
        char *valor = malloc(100 * sizeof(char));
        printf("Ingrese un dato: ");
        scanf("%s", valor);
        nuevo->dato = valor;
        if (inicio == NULL)
        {
            nuevo->siguiente = nuevo;
            inicio = nuevo;
        }
        else
        {
            Nodo *actual = inicio;
            while (actual->siguiente != inicio)
                actual = actual->siguiente;
            nuevo->siguiente = inicio;
            actual->siguiente = nuevo;
        }
    }

    Nodo *actual = inicio;
    while (actual != NULL)
    {
        printf("%s <-> ", actual->dato);
        actual = actual->siguiente;
        if (actual == inicio)
            actual = NULL;
    }

    printf("\n>>>");
    while (inicio != NULL)
    {
        if (inicio->siguiente != inicio)
        {
            Nodo *actual, *ultimo;
            actual = ultimo = inicio;
            while (ultimo->siguiente != inicio)
                ultimo = ultimo->siguiente;
            inicio = inicio->siguiente;
            ultimo->siguiente = inicio;
            printf("\nfree(%s)", actual->dato);
            free(actual->dato);
            free(actual);
        }
        else
        {
            printf("\nfree(%s)", inicio->dato);
            free(inicio->dato);
            free(inicio);
            inicio = NULL;
        }
    }
    printf("\n<<<\n");
    return 0;
}