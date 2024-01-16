#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Persona {
    char *dni;
    char *nombreCompleto;
    int edad;
} Alumno;

void mostrarInfo(Alumno alumno);

void liberar(Alumno alumno);

int main(void)
{
    int cantidad = 3;
    Alumno alumnos[cantidad];
    for (int i=0; i<cantidad; i++)
    {
        char *dni = malloc(50 * sizeof(char));
        char *nombreCompleto = malloc(150 * sizeof(char));

        alumnos[i].dni = dni;
        alumnos[i].nombreCompleto = nombreCompleto;

        printf("Ingrese el dni del alumno: ");
        scanf("%s", dni);
        strcpy(alumnos[i].dni, dni);

        while ((getchar()) != '\n');

        printf("Ingrese el nombre del alumno: ");
        scanf("%[^\n]%*c", nombreCompleto);
        strcpy(alumnos[i].nombreCompleto, nombreCompleto);

        printf("Ingrese la edad del alumno %s: ", nombreCompleto);
        scanf("%d", &alumnos[i].edad);
        while ((getchar()) != '\n');
    }

    for (int i=0; i<cantidad; i++)
    {
        mostrarInfo(alumnos[i]);
        liberar(alumnos[i]);
    }
    return 0;
}

void mostrarInfo(Alumno alumno) {
    printf("DNI: %s, Nombre Completo: %s, Edad: %d.\n", alumno.dni, alumno.nombreCompleto, alumno.edad);
}

void liberar(Alumno alumno) {
    free(alumno.dni);
    free(alumno.nombreCompleto);
    alumno.dni = NULL;
    alumno.nombreCompleto = NULL;
}