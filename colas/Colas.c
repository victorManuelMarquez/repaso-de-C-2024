#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento
{
    char *dato;
    struct Elemento *siguiente;
} Nodo;

typedef struct Lista
{
    int cantidad;
    Nodo *primero;
} Cola;

const int TOTAL = 5;

int main(void)
{
    // declaro e inicio la cola
    Cola *cola = malloc(sizeof(Cola));
    cola->cantidad = 0;
    cola->primero = NULL;

    for (int i=0; i<TOTAL; i++)
    {
        // declaro y asigno en memoria un puntero
        char *dato = malloc(50 * sizeof(char)); // admite una cadena de hasta 50 caracteres
        printf("Ingrese una dato para la cola (%d/%d): ", i+1, TOTAL);
        scanf("%[^\n]%*c", dato);
        Nodo *nuevo = malloc(sizeof(Nodo));
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
        if (cola->primero == NULL)
            cola->primero = nuevo;
        else
        {
            // asigno un puntero al primer elemento
            Nodo *ultimo = cola->primero;
            // el bucle invocará n nodos hasta dar con el último
            while (ultimo->siguiente != NULL)
            {
                ultimo = ultimo->siguiente; // reasigno el nodo con el que le sigue
            }
            ultimo->siguiente = nuevo; // asigno el nuevo nodo al último en la cola
        }
        cola->cantidad++;
    }

    Nodo *actual = cola->primero;
    for (int i=0; i<cola->cantidad; i++)
    {
        if (actual->siguiente != NULL)
            printf("%s | ", actual->dato);
        else
            printf("%s\n", actual->dato);
        actual = actual->siguiente;
    }

    while (cola->cantidad > 0)
    {
        Nodo *borrar = cola->primero;
        cola->primero = cola->primero->siguiente;
        free(borrar->dato);
        free(borrar);
        cola->cantidad--;
    }

    // libero la memoria
    free(cola);
    cola = NULL;
    return 0;
}