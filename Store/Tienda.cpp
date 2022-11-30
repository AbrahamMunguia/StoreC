#include "Tienda.h"
#include <string>
#include <vector>
#include "Producto.h"
#include "Cliente.h"
#include <iostream>

/*
* CONSTRUCTORES
*/
Tienda::Tienda()
{
    identificadorT = "";
    nombre = "";
    direccion = "";
    cantidadProductosT = 0;
    cantidadClientesT = 0;
    productos = {};
    clientes = {};
    ingresoDiario = 0;

}

Tienda::Tienda(std::string _identificador, std::string _nombre, std::string _direccion, int _cantidadProductosT, int cantidadClientesT, std::vector<Producto> _productos, std::vector<Cliente> _clientes, double _ingresoDiario)
{
    identificadorT = _identificador;
    nombre = _nombre;
    direccion = _direccion;
    cantidadProductosT = _cantidadProductosT;
    cantidadClientesT = cantidadClientesT;
    productos = _productos;
    clientes = _clientes;
    ingresoDiario = _ingresoDiario;
}
// DESTRUCTOR
Tienda::~Tienda()
{
}
// GETTERS 
std::string Tienda::getIdentificadorT()
{
    return identificadorT;
}

std::string Tienda::getNombre()
{
    return nombre;
}

std::string Tienda::getDireccion()
{
    return direccion;
}

int Tienda::getCantidadProductosT()
{
    return cantidadProductosT;
}

int Tienda::getCantidadClientesT()
{
    return cantidadClientesT;
}

std::vector<Producto> Tienda::getProductos()
{
    return productos;
}

std::vector<Cliente> Tienda::getClientes()
{
    return clientes;
}

double Tienda::getIngresoDiario()
{
    return ingresoDiario;
}

// SETTERS
void Tienda::setIdentificadorT(std::string _identificador)
{
    identificadorT = _identificador;
}

void Tienda::setNombre(std::string _nombre)
{
    nombre = _nombre;
}

void Tienda::setDireccion(std::string _direccion)
{
    direccion = _direccion;
}

void Tienda::setCantidadProductosT(int _cantidadProductos)
{
    cantidadProductosT = _cantidadProductos;
}

void Tienda::setCantidadClientesT(int _cantidadClientesT)
{
    cantidadClientesT = _cantidadClientesT;
}

void Tienda::setProductos(std::vector<Producto> _productos)
{
    productos = _productos;
}

void Tienda::setIngresoDiario(std::vector<Cliente> _clientes)
{
    clientes = _clientes;
}

/*
* METODOS PERSONALIZADOS
    IMPRMIR TIENDA
    AGREGAR PRODUCTOS
    AGREGAR PRODUCTO
    AGREGAR CLIENTE
    LLENAR CARRITO
    IMPRIMIR TICKET COMPRA
    CERRAR OPERACIONES
*/
void Tienda::imprimirTienda()
{
    std::cout << "IMPRIMIR TIENDA" << std::endl;
    std::cout << "Identificador: " << getIdentificadorT() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Direccion: " << getDireccion() << std::endl;
    std::cout << "Cantidad de Productos: " << getCantidadProductosT() << std::endl;
    std::cout << "Cantidad de Clientes: " << getCantidadClientesT() << std::endl;
    std::cout << "Productos Disponibles: " << std::endl;
    for (Producto producto : productos) {
        producto.imprimir();
    }
    std::cout << "********************************************" << std::endl;
    std::cout << "Clientes Registrados: " << std::endl;
    for (Cliente cliente : clientes) {
        cliente.imprimirCliente();
    }
    std::cout << "********************************************" << std::endl;
    std::cout << "Corte de caja (Cierre de dia): " << getIngresoDiario() << std::endl;
}

void Tienda::agregarProductos()
{
}

void Tienda::agregarProducto()
{
}

void Tienda::agregarCliente()
{
}

void Tienda::llenarCarrito()
{
}

void Tienda::imprimirTicketCompra()
{
}

void Tienda::cerrarOperaciones()
{
}
