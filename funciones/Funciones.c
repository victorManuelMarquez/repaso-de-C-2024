#include <stdio.h>

// prototipos de las funciones
void pedirNumero(int *n); // paso por referencia

void espejo(int n); // paso por valor

// Función principal
int main(void)
{
    int num1, num2;

    pedirNumero(&num1);
    pedirNumero(&num2);

    printf("a=%d, b=%d\n", num1, num2);

    espejo(num1);
    espejo(num2);

    return 0;
}

void pedirNumero(int *n)
{
    do
    {
        printf("Ingrese un número: ");
        scanf("%d", n);
    } while (*n <= 0);
}

void espejo(int n)
{
    int c = 0, r = 0, e = 0, aux = n;
    while (n > 0)
    {
        r = n % 10;
        e = e * 10 + r;
        n /= 10;
    }
    printf("el número %d invertido es %d.\n", aux, e);
}