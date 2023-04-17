#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char *nombre;
    char *buff;
    int cantidad;

    printf("\ningrese la cantidad de nombres que desea ingresar: ");
    scanf("%d",&cantidad);

    for (int i = 0; i < cantidad; i++)
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
