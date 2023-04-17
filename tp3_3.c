#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CANTIDAD 5

void mostrar(char *aux, char *nombres);

int main(){

    char *nombre;
    char *buff;

    for (int i = 0; i < CANTIDAD; i++)
    {
        buff = malloc(sizeof(char));
        printf("\ningrese su nombre: ");
        gets(buff);

        nombre = malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(nombre, buff);
    }

    mostrar(buff, nombre);
    

    return 0;
}

void mostrar(char *aux, char *nombres)
{
    for (int i = 0; i < CANTIDAD; i++)
    {
        printf("\nbuff: %s", *aux);
        printf("\nnombre: %s", *nombres);
    }
    
}