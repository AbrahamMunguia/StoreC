// Store.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Producto.h"
#include "Cliente.h"
#include "Tienda.h"
#include <fstream>

using namespace std;

int menu(string id, string nombreTienda, string nombreArchivo, string direccion) {
    Tienda tiendaPersonal(id, nombreTienda, direccion, 0, 0, {}, {},0);
    int opcionMenu = 0;
    bool lecturaArchivo = false;
    int salir = 0;
    while (salir == 0) {
        cout << "Bienvenido a su sucursal: " << tiendaPersonal.getNombre() << endl;
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
                tiendaPersonal.agregarProductos(nombreArchivo);
                lecturaArchivo = true;
                tiendaPersonal.imprimirTienda();
            }
            else {
                cout << "Ya se agrego desde el archivo. Solo es posible una vez por instancia" << endl;
            }
            break;
        case 2:
            system("CLS");
            tiendaPersonal.agregarProducto();
            break;
        case 3:
            system("CLS");
            cout << "Agregar Clientes" << endl;
            tiendaPersonal.agregarCliente();
            break;
        case 4:
            system("CLS");
            cout << "Comprar Productos" << endl;
            tiendaPersonal.llenarCarrito();
            system("CLS");
            tiendaPersonal.imprimirTicketCompra();
            break;
        case 5:
            system("CLS");
            cout << "Realizar cierre del dia" << endl;
            tiendaPersonal.cerrarOperaciones();
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

inline bool fileExists(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

int main()
{
    string idTienda = "";
    string nombreDeLaTienda = "";
    string nombreDelArchivo = "";
    string direccion = "";
    int archivoExiste = 0;
    cout << "Bienvenido al sistema administrativo!" << endl;
    cout << "Identificacion de sucursal:" << endl;
    cin >> idTienda;
    cout << "Nombre de la tienda:" << endl;
    cin >> nombreDeLaTienda;
    while (archivoExiste == 0)
    {
        cout << "Nombre del archivo omitiendo la terminacion txt:" << endl;
        cin >> nombreDelArchivo;
        if(fileExists(nombreDelArchivo+".txt")) {
            archivoExiste = 1;
        }
    }
    cout << "Direccion:" << endl;
    cin >> direccion;
    menu(idTienda,nombreDeLaTienda,nombreDelArchivo+".txt", direccion);
}


