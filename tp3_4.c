#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//5 clientes
//hasta 10 productos c/u

struct Producto{
    int productoID; //numerado en ciclo iterativo
    int cantidad; //entre 1 y 10
    char *tipoProducto; 
    float precioUnitario; //entre 10 - 100
}typedef producto;

struct Cliente{
    int clienteID; //numerado en ciclo iterativo
    char *nombreCliente; //ingresado por usuario
    int cantidadProductosAPedir; //aleatorio entre 1 y 5
    producto *productos;  //tamaño de este arreglo depende de la variable cantidadproductosapedir
}typedef cliente;

float costoTotal(producto *producto);

int main(){

    char *tiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    cliente *clientes;
    int cantidadc;
    float costototalproducto, sumatodoslosproductos = 0;

    printf("\ningrese la cantidad de clientes: ");
    scanf("%d",&cantidadc);

    clientes = (cliente *)malloc(sizeof(cliente) * cantidadc);

    srand(time(NULL));

    for (int i = 0; i < cantidadc; i++)
    {
        //srand(time(NULL));
        clientes[i].clienteID = i;
        fflush(stdin);
        char buff[20];
        printf("\ningrese el nombre del cliente: ");
        gets(buff);
        clientes[i].nombreCliente = malloc(sizeof(char) * (strlen(buff) + 1));
        fflush(stdin);
        clientes[i].cantidadProductosAPedir = 2; //1 + rand() % 4;
        clientes[i].productos = (struct Producto *) malloc(sizeof(producto) * clientes[i].cantidadProductosAPedir);
        
        for (int j = 0; j < clientes[i].cantidadProductosAPedir; j++)
        {
            clientes[i].productos->productoID = j;
            clientes[i].productos->cantidad = 1 + rand() % 10;
            //fflush(stdin);
            clientes[i].productos->tipoProducto = &tiposProductos[rand() % 3][0];
            clientes[i].productos->precioUnitario = 10 + rand() % 101;
        }

    }

    for (int i = 0; i < cantidadc; i++)
    {
        printf("\n-------CLIENTE-------");
        printf("\nNombre del cliente: ");
        puts(clientes[i].nombreCliente);
        printf("\nID: %d", clientes[i].clienteID);
        printf("\nCantidad de productos a pedir: %d", clientes[i].cantidadProductosAPedir);
        
        for (int j = 0; j < clientes[i].cantidadProductosAPedir; j++)
        {
            printf("\n-------PRODUCTOS-------");
            printf("\nID: %d", clientes[i].productos->productoID);
            printf("\nTipo de producto: %s", clientes[i].productos->tipoProducto);
            printf("\nCantidad: %d", clientes[i].productos->cantidad);
            printf("\nPrecio Unitario: %.2f", clientes[i].productos->precioUnitario);
            costototalproducto = costoTotal(clientes[i].productos);
            printf("\nCosto Total: %.2f", costototalproducto);
            sumatodoslosproductos += costototalproducto;
        }

        printf("\nsuma de todos los productos: %.2f", sumatodoslosproductos);
        
    }
    
    return 0;
}

float costoTotal(producto *producto)
{
    float costo;
    costo = producto->precioUnitario * producto->cantidad;

    return costo;
}