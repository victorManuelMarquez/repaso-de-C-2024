#include <stdio.h>

int main(void)
{
    // variable
    char cadena[1000];
    
    printf("Ingrese algo de texto: ");
    scanf("%[^\n]%*c", &cadena);

    printf("Ingresó: \"%s\"\n", &cadena);

    // puntero a la variable "cadena"
    char *p = cadena;

    printf("El puntero \"p\" se asignó a %p y cuyo contenido es: %s.\n", p, p);

    printf("Ingrese otra cadena de texto: ");
    scanf("%[^\n]%*c", p); // piso el valor original de "cadena" con el puntero

    printf("Ingresó: \"%s\"\n", &cadena);

    return 0;
}