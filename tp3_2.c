#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 5
#define COLUMNAS 12

int main(){

    int produccion[FILAS][COLUMNAS];
    int suma = 0, promedio, x = 0;
    int maximo, minimo;
    int anio1, anio2, mes1, mes2;

    srand(time(NULL));

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            produccion[i][j] = 10000 + rand() % 40000;
            suma += produccion[i][j];
            printf("produccion[%d][%d] = %d \n", i, j, produccion[i][j]);    
        }
        
        promedio = suma / 12;
        printf("el promedio de ganancias es: %d\n", promedio);
        printf("\n");
    }

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (x == 0)
            {
                maximo = produccion[i][j];
                minimo = produccion[i][j];
                anio1 = j;
                mes1 = i;
                anio2 = j;
                mes2 = i;
                x++;
            } else
            {
                if (produccion[i][j] > maximo)
                {
                    maximo = produccion[i][j];
                    anio1 = j;
                    mes1 = i;
                }
                if (produccion[i][j] < minimo )
                {
                    minimo = produccion[i][j];
                    anio2 = j;
                    mes2 = i;
                }
                
            }
        }
    }

    printf("\nel valor maximo es: %d, del mes %d del anio %d", maximo, mes1, anio1);
    printf("\nel valor minimo es: %d, del mes %d del anio %d", minimo, mes2, anio2);
    
    return 0;
}