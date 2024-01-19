#include <stdio.h>
#include <stdlib.h>

typedef struct Enlace
{
    char * dato;
    struct Enlace *enlace;
} Nodo;

int main(void)
{
    // defino el nodo inicial
    Nodo *inicial = NULL;

    // establezco una cantidad limite arbitraria
    int total = 4;

    for (int i=0; i<total; i++)
    {
        // Creo un nodo nuevo
        Nodo *nuevo = malloc(sizeof(Nodo)); // reservo espacio
        char *valor = malloc(100 * sizeof(char)); // reservo espacio para 100 caracteres

        printf("Ingrese un dato: ");
        scanf("%[^\n]%*c", valor); // almaceno la información

        nuevo->dato = valor; // asigno la dirección de la info a mi nodo
        nuevo->enlace = NULL;

        // si es el primero de la cola
        if (inicial == NULL)
            inicial = nuevo;
        else // si existen otros nodos
        {
            Nodo *ultimo = inicial; // asigno el primer nodo
            // N iteraciones hasta encontrar al último nodo, el cual no tiene un nodo siguiente
            while (ultimo->enlace != NULL)
            {
                ultimo = ultimo->enlace; // reasigno este nodo con el que le siga
            }
            ultimo->enlace = nuevo; // asigno el enlace a este nuevo nodo
        }
    }

    // muestro los datos
    if (inicial != NULL)
    {
        printf("[");
        Nodo *actual = inicial;
        do
        {
            printf(" %s ", actual->dato);
            actual = actual->enlace;
        } while (actual != NULL);
        printf("]\n");
    }

    // vacio la cola
    while (inicial->enlace != NULL)
    {
        Nodo *temporal = inicial;
        inicial = inicial->enlace;
        free(temporal->dato);
        free(temporal);
    }
    // libero el último dato y la cola de la memoria
    free(inicial->dato);
    free(inicial);
    inicial = NULL;
    return 0;
}