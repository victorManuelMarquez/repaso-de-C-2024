#include <stdio.h>
#include <stdlib.h>

// Programa que solicita números ingresados por teclado.
int main(void)
{
    // variable
    int num;

    printf("Ingrese un número: ");
    scanf("%d", &num);

    printf("Se almacenó el número %d en %p.\n", num, &num);

    // puntero
    int *p;

    p = malloc(sizeof(int)); // consulto memoria disponible para un entero.

    printf("Ahora ingrese otro número: ");
    scanf("%d", p);

    printf("Se almacenó el número %d en %p.\n", *p, p);

    // libero la memoria
    free(p);

    // se elimina el valor residual
    p = NULL;

    return 0;
}