#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Si está en un entorno Windows
#if defined(_MSC_VER)
#include <limits.h>
// O si se está en un entorno Linux/Mac
#elif defined(__GNUC__)
#include <linux/limits.h>
#include <unistd.h>
#endif

int main(void)
{
    char *directorio = getcwd(NULL, 0);
    if (directorio)
    {
        printf("Ruta: %s\n", directorio);
    } else {
        printf("Falló.\n");
        exit(1);
    }
    char *nombreArchivo = malloc(50 * sizeof(char));
    strcpy(nombreArchivo, "archivo.txt");
    printf("Se creará el archivo %s en el directorio: %s\n", nombreArchivo, directorio);
    directorio = strcat(strcat(directorio, "/"), nombreArchivo);
    FILE *archivo = fopen((char*) directorio, "w");
    if (archivo)
    {
        printf("%s\n", directorio);
        char *contenido = malloc(1024 * sizeof(char));
        strcpy(contenido, "Escribiendo...\nHola Mundo!!!\nHecho!\n");
        printf("%s", contenido);
        fprintf(archivo, "%s", contenido);
        free(contenido);
        printf("Cerrando el archivo %s...\n", nombreArchivo);
        fclose(archivo);
    }
    else
    {
        printf("Falló, no se pudo crear el archivo.\n");
    }
    printf("Fin del programa.\n");
    free(nombreArchivo);
    free(directorio);
    return 0;
}