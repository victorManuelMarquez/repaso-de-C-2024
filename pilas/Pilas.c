#include <stdio.h>
#include <stdlib.h>

// prototipo para crear un nodo
typedef struct Elemento
{
    char* dato;
    struct Elemento* siguiente;
} Nodo;

// prototipo para crear una pila
typedef struct Torre
{
    int cantidad;
    Nodo* tope;
} Pila;

int main(void)
{
    // defino la pila
    Pila *pila = malloc(sizeof(Pila));

    // inicializo
    pila->cantidad = 0;
    pila->tope = NULL;

    // agrego datos
    for (int i=0; i<3; i++)
    {
        // defino un nuevo nodo como puntero
        Nodo *nuevo = malloc(sizeof(Nodo));
        // defino y asigno memoria a un puntero temporal
        char* valor = malloc(50 * sizeof(char));
        nuevo->dato = valor; // asigno la referencia al puntero del nodo
        nuevo->siguiente = pila->tope;
        pila->tope = nuevo;
        pila->cantidad++;
        // solicito el dato
        printf("Ingrese un valor para la pila (%d/3): ", i+1);
        scanf("%[^\n]%*c", valor); // el valor se asigna a la memoria reservada
    }

    // muestro los datos de la pila
    int i=0;
    Nodo *nodo = pila->tope;
    while (i<pila->cantidad)
    {
        printf("Pila -> elemento -> valor: %s\n", nodo->dato);
        nodo = nodo->siguiente;
        i++;
    }

    // Tope de la pila
    printf("Tope de la pila -> valor: %s\n", pila->tope->dato);

    // remuevo todos los elementos de la pila
    for (int i=0; i<3; i++)
    {
        Nodo *borrado = pila->tope;
        pila->tope = pila->tope->siguiente;
        pila->cantidad--;
        free(borrado->dato); // elimino el contenido
        free(borrado); // elimino el nodo
    }

    // libero la pila de la memoria
    free(pila);
    pila = NULL;

    return 0;
}