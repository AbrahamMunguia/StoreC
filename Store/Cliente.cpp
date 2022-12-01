#include "Cliente.h"
#include <iostream>

Cliente::Cliente()
{
	 identificador = "";
	 nombreC = "";
	 correoElectronico = "";
	 telefono = "";
	 productos = { };
	 totalCompra = 0.0;
}

Cliente::Cliente(std::string _identificador, std::string _nombreC, std::string _correoElectronico, std::string _telefono, std::vector<Producto> _productos, double _totalCompra)
{
	 identificador = _identificador;
	 nombreC = _nombreC;
	 correoElectronico = _correoElectronico;
	 telefono = _telefono;
	 std::vector<Producto> productos(_productos);
	 totalCompra =  _totalCompra;
}

Cliente::~Cliente()
{
}
// RECORDAR
// PRODUCTOS SIRVE COMO CARRITO DE COMPRAS
void Cliente::imprimirCliente()
{
	double totalCompradoPorCliente = 0;
	std::cout << "identificador: " << identificador << std::endl;
	std::cout << "nombre cliente: " << nombreC << std::endl;
	std::cout << "correo cliente: " << correoElectronico << std::endl;
	std::cout << "telefono:" << telefono << std::endl;
	if (productos.size() > 0) {
		std::cout << "Productos Seleccionados: " << std::endl;
		for (Producto producto : productos) {
			totalCompradoPorCliente += producto.getCantidad() * producto.getPrecioP();
			producto.imprimir();
		}
		std::cout << "----------" << std::endl;
	}
	else {
		std::cout << "Lo invitamos a visitar nuestra tienda! Grandes ofertas tenemos!" << std::endl;
	}
	setTotalCompra(totalCompradoPorCliente);
	std::cout << "total: " << totalCompradoPorCliente << std::endl;
}

std::string Cliente::getIdentificador()
{
	return identificador;
}

std::string Cliente::getNombreC()
{
	return nombreC;
}

std::string Cliente::getCorreoElectronico()
{
	return correoElectronico;
}

std::string Cliente::getTelefono()
{
	return telefono;
}

std::vector<Producto> Cliente::getProductos()
{
	return productos;
}

double Cliente::getTotalCompra()
{
	return totalCompra;
}

void Cliente::setIdentificador(std::string _valor)
{
	identificador = _valor;
}

void Cliente::setNombreC(std::string _valor)
{
	nombreC = _valor;
}

void Cliente::setCorreoElectronico(std::string _valor)
{
	correoElectronico = _valor;
}

void Cliente::setTelefono(std::string _valor)
{
	telefono = _valor;
}

void Cliente::setProductos(std::vector<Producto> _productos)
{
	productos = _productos;
}

void Cliente::setTotalCompra(double nuevoTotal)
{
	totalCompra = nuevoTotal;
}
