#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CANTIDAD 5

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

        puts(nombre);
        puts(buff);

        free(buff);
        free(nombre);
    }

    return 0;
}
