#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int promedio(int matriz[][]);

int main(){

    int produccion[5][12];

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            produccion[i][j] = 10000 + rand() % 40000;
            printf("\nproduccion[%d][%d] = %d", i, j, produccion[i][j]);    
        printf("\n");
        }
       
    }
    
    printf("\nel promedio de ganancias es: %d", promedio(produccion));

    return 0;
}

int promedio(int matriz[][])
{
    int suma = 0, promedio;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            suma += matriz[i][j];
        }
        
    }

    promedio = suma / (5*12);
    return promedio;
    
}