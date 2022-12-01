// Store.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Producto.h"
#include "Cliente.h"
#include "Tienda.h"
#include <fstream>

using namespace std;

int menu() {
    Tienda oxxo;
    int opcionMenu = 0;
    bool lecturaArchivo = false;
    int salir = 0;
    // Producto productoSample("1manzanas", "manzanas", 8, 1500, 5);
    while (salir == 0) {
        cout << "Bienvenido al sistema administrativo!" << endl;
        cout << "Digite la opcion deseada para ir al submenu" << endl;
        cout << "1- Agregar Productos Desde Archivo" << endl;
        cout << "2- Agregar Productos Uno a Uno" << endl;
        cout << "3- Agregar Clientes" << endl;
        cout << "4- Comprar Productos" << endl;
        cout << "5- Realizar Cierre del dia" << endl;
        cout << "6- Salir" << endl;
        cin >> opcionMenu;

        switch (opcionMenu) {
        case 1:
            system("CLS");
            if(!lecturaArchivo){
                cout << "Agregando datos desde el archivo..." << endl;
                // oxxo.setProductos({productoSample});
                oxxo.agregarProductos();
                lecturaArchivo = true;
                oxxo.imprimirTienda();
            }
            else {
                cout << "Ya se agrego desde el archivo. Solo es posible una vez por instancia" << endl;
            }
            break;
        case 2:
            system("CLS");
            oxxo.agregarProducto();
            break;
        case 3:
            system("CLS");
            cout << "Agregar Clientes" << endl;
            oxxo.agregarCliente();
            break;
        case 4:
            system("CLS");
            cout << "Comprar Productos" << endl;
            oxxo.llenarCarrito();
            break;
        case 5:
            system("CLS");
            cout << "Realizar cierre del dia" << endl;
            break;
        case 6:
            system("CLS");
            cout << "salir" << endl;
            salir = 1;
            break;
        default:
            system("CLS");
            cout << "Opcion invalida, repita de nuevo" << endl;
            break;
        }

    }
    return 0;
}

int main()
{
    /*Producto productoNuevo("001", "manzana", 1, 50.20, 5);
    Producto productoNuevo2("002", "pera",1,40.20,5);
    Cliente clienteSergio("sergio01", "sergio", "sergio@gmail.com", "9856031", {}, 0);
    Tienda oxxo("oxxo5", "Oxxo Beltran Leyva", "Av.Patriotas", 15, 5, { productoNuevo,productoNuevo2 }, { clienteSergio }, 0);
    oxxo.imprimirTienda();*/
    menu();
    
    
}


