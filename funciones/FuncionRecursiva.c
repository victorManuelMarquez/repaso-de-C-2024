#include <stdio.h>
#include <time.h>

float dividir(int dividendo, int divisor, int contador);

int main(void)
{
    srand(time(NULL));
    int dividendo = rand() % 100, divisor = (rand() % 10) + 1, cociente = 0, resto = 0;
    printf("Se espera que la división entera entre %d y %d dé %d\n", dividendo, divisor, (dividendo / divisor));
    resto = dividendo;
    while (resto >= divisor)
    {
        cociente++;
        resto -= divisor;
    }
    printf("%d dividido %d es igual a %d con resto %d.\n", dividendo, divisor, cociente, resto);
    printf("Se invocará a la función recursiva.\n");
    printf("%d / %d = %.1f\n", dividendo, divisor, dividir(dividendo, divisor, 0));
    printf("Fin del programa.\n");
    return 0;
}

float dividir(int dividendo, int divisor, int contador)
{
    if (dividendo>=divisor)
    {
        contador++;
        return dividir(dividendo-=divisor, divisor, contador);
    }
    else return contador + dividendo * 0.1;
}