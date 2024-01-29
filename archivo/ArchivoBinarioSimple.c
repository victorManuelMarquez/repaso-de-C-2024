#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Si está en un entorno Windows
#ifdef _WIN32
#include <limits.h>
// O si se está en un entorno Linux
#elif defined linux
#include <linux/limits.h>
#endif
#include <unistd.h>

struct Nodo
{
    char *dato;
    struct Nodo *siguiente;
};

struct Pila
{
    struct Nodo *tope;
    int total;
};

int main()
{
    srand(time(NULL));
    int cantidad = (rand() % 15) + 1, maxCaracteres = 50;
    // defino e inicializo la pila
    struct Pila pila;
    pila.tope = NULL;
    pila.total = 0;
    printf("Se almacenarán %d registros en la pila.\n", cantidad);
    for (int i=0; i<cantidad; i++)
    {
        struct Nodo *nuevo = malloc(sizeof(struct Nodo));
        nuevo->dato = malloc(maxCaracteres * sizeof(char));
        snprintf(nuevo->dato, maxCaracteres, "elemento: %d", i+1);
        printf("%s\n", nuevo->dato);
        nuevo->siguiente = pila.tope;
        pila.tope = nuevo;
        pila.total++;
    }
    
    // ARCHIVO BINARIO
    char *directorio = getcwd(NULL, 0);
    if (directorio)
        printf("Ruta: %s\n", directorio);
    else
    {
        printf("Falló la obtención del directorio de trabajo.\n");
        exit(1);
    }
    char *nombreArchivo = malloc(50 * sizeof(char));
    strcpy(nombreArchivo, "pila.dat");
    directorio = strcat(strcat(directorio, "/"), nombreArchivo);
    printf("%s\n", directorio);
    // escribo el archivo en binario
    FILE *archivoBin = fopen((char*) directorio,"wb");
    if (!archivoBin)
    {
        printf("No se pudo crear el archivo %s\n", nombreArchivo);
        exit(1);
    }
    struct Nodo *actual = pila.tope;
    while (actual)
    {
        printf("Almacenando: [%s]->(%p)\n", actual->dato, actual->siguiente);
        fwrite(actual, sizeof(struct Nodo), 1, archivoBin);
        actual = actual->siguiente;
    }
    fclose(archivoBin);
    
    // leo el archivo binario
    archivoBin = fopen((char*) directorio, "rb");
    if (!archivoBin)
    {
        printf("El archivo %s no se pudo abrir.\n", nombreArchivo);
        exit(1);
    }
    for (int i=0; i<cantidad; i++)
    {
        struct Nodo *recuperado = malloc(sizeof(struct Nodo));
        fread(recuperado, sizeof(struct Nodo), 1, archivoBin);
        printf("Recuperando info del archivo \"%s\"\n\t{[%s] -> (%p)}\n", nombreArchivo, recuperado->dato, recuperado->siguiente);
        free(recuperado);
    }
    fclose(archivoBin);
    
    // vacio la pila
    while (pila.total>0)
    {
        struct Nodo *temporal = pila.tope;
        pila.tope = temporal->siguiente;
        pila.total--;
        printf("free(%s);\n", temporal->dato);
        free(temporal->dato);
        free(temporal);
    }
    printf("La pila tiene %d elementos.\n", pila.total);
    printf("Fin del programa.\n");
    return 0;
}