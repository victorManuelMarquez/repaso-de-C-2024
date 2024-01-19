#include <stdio.h>
#include <stdlib.h>

typedef struct Enlace
{
    char * dato;
    struct Enlace *anterior;
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

        printf("Ingrese un valor: ");
        scanf("%[^\n]%*c", valor);

        nuevo->dato = valor;
        nuevo->anterior = NULL;
        nuevo->siguiente = NULL;

        if (inicio == NULL)
            inicio = nuevo;
        else
        {
            Nodo *ultimo = inicio;
            while (ultimo->siguiente != NULL)
            {
                ultimo = ultimo->siguiente;
            }
            nuevo->anterior = ultimo;
            ultimo->siguiente = nuevo;
        }
    }

    // muestro la lista
    if (inicio != NULL)
    {
        printf("Lista en orden normal: [");
        Nodo *actual = inicio;
        do
        {
            printf(" %s ", actual->dato);
            actual = actual->siguiente;
        } while (actual != NULL);
        printf("]\n");
    }

    // muestro en orden inverso
    if (inicio != NULL)
    {
        Nodo *actual = inicio;
        // voy al último nodo
        while (actual->siguiente != NULL)
            actual = actual->siguiente;
        printf("Lista en orden inverso: [");
        // itero desde el último nodo hasta el primero
        do
        {
            printf(" %s ", actual->dato);
            actual = actual->anterior;
        } while (actual != NULL);
        printf("]\n");
    }

    // vacio la lista
    while (inicio->siguiente != NULL)
    {
        Nodo *temporal = inicio;
        inicio = inicio->siguiente;
        inicio->anterior = NULL;
        free(temporal->dato);
        free(temporal);
    }

    // libero el dato del último nodo
    free(inicio->dato);
    free(inicio); // libero la lista
    inicio = NULL;
    return 0;
}