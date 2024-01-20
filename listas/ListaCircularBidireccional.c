#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento
{
    char *dato;
    struct Elemento *anterior;
    struct Elemento *siguiente;
} Nodo;

int main(void)
{
    Nodo *inicio = NULL;

    int total = 6;
    for (int i=0; i<total; i++)
    {
        Nodo *nuevo = malloc(sizeof(Nodo));
        char *valor = malloc(100 * sizeof(char));
        printf("Ingrese un dato: ");
        scanf("%s", valor);
        nuevo->dato = valor;
        nuevo->anterior = nuevo;
        nuevo->siguiente = nuevo;
        if (inicio == NULL)
            inicio = nuevo;
        else
        {
            Nodo *ultimo = inicio->anterior;
            nuevo->anterior = ultimo;
            nuevo->siguiente = inicio;
            ultimo->siguiente = nuevo;
            inicio->anterior = nuevo;
        }
    }

    printf("contenido: {");
    Nodo *actual = inicio;
    while (actual != NULL)
    {
        printf(" < %s > ", actual->dato);
        actual = actual->siguiente;
        if (actual->siguiente->anterior == inicio)
            actual = NULL;
    }
    printf("}\n");

    printf("limpiando en orden inverso: {");
    while (inicio != NULL)
    {
        if (inicio->anterior != inicio)
        {
            Nodo *ultimo = inicio->anterior;
            inicio->anterior = ultimo->anterior;
            ultimo->anterior->siguiente = inicio;
            printf("free(%s) ", ultimo->dato);
            free(ultimo->dato);
            free(ultimo);
        }
        else
        {
            printf("free (%s)}\n", inicio->dato);
            free(inicio->dato);
            free(inicio);
            inicio = NULL;
        }
    }
    return 0;
}