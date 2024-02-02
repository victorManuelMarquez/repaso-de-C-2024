#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ListaDoblementeEnlazada.h"

int main(void)
{
    printf("Iniciando programa...\n");
    srand(time(NULL));
    eslabon *principal = generarNodos((rand() % 6) + 5);
    ordenNatural(principal);
    mostrar(principal);
    ordenInverso(principal);
    mostrar(principal);
    insertarAlInicio(&principal, crearNodo(rand() % 100));
    mostrar(principal);
    insertarDespuesDe(principal, crearNodo(-100));
    principal = vaciar(principal);
    mostrar(principal);
    printf("Fin del programa.\n");
    return 0;
}