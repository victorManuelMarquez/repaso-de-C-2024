#include <stdio.h>

int main(void)
{
    int numeros[] = {3, 4, 0, -13, 23, 100, -1};
    char cadena[] = "Hola";

    for (int i=0; i<7; i++) {
        printf("%d | ", numeros[i]);
    }

    printf("\n");

    for (int i=0; i<4; i++) {
        printf("'%c' ", cadena[i]);
    }

    printf("\n");

    return 0;
}