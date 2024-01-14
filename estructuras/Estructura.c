#include <stdio.h>
#include <string.h>

// defino la estructura
struct Dato {
    int id;
    char contenido[1024];
};

void mostrar(struct Dato dato);

int main(void)
{
    // variable
    struct Dato dato;

    // asigno los valores
    dato.id = 1003;
    strcpy(dato.contenido, "Texto de ejemplo.");

    mostrar(dato);

    return 0;
}

void mostrar(struct Dato dato) {
    printf("ID: %d\nContenido: \"%s\"\n", dato.id, dato.contenido);
}