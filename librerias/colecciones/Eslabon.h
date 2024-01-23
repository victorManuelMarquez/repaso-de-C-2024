#ifndef ESLABON_H_
#define ESLABON_H_

typedef struct Elemento
{
    int dato;
    struct Elemento *anterior, *siguiente;
} eslabon;

#endif