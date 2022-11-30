// Store.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Producto.h"
#include "Cliente.h"
#include "Tienda.h"

int main()
{
    Producto productoNuevo("001", "manzana", 1, 50.20, 5);
    Producto productoNuevo2("002", "pera",1,40.20,5);
    Cliente clienteSergio("sergio01", "sergio", "sergio@gmail.com", "9856031", {}, 0);
    Tienda oxxo("oxxo5", "Oxxo Beltran Leyva", "Av.Patriotas", 15, 5, { productoNuevo,productoNuevo2 }, { clienteSergio }, 0);
    oxxo.imprimirTienda();
}

