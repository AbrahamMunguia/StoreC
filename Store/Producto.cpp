
#include "Producto.h"
#include <iostream>

// Producto Info en general
// Triple seteador. Con params, sin params y de muerte

Producto::Producto(std::string id, std::string name, int category, float price, int ammount) {
	clave = id;
	nombreP = name;
	categoriaP = category;
	precioP = price;
	cantidad = ammount;
}
Producto::Producto() {
	clave = "";
	nombreP = "";
	categoriaP = 0;
	precioP = 0;
	cantidad = 0;
}	
Producto::~Producto() {
	std::cout << "Adios producto" << std::endl;
}

// Metodo imprimir
void Producto::imprimir()
{
	std::cout << "clave: " << clave << std::endl;
	std::cout << "nombre producto: " << nombreP << std::endl;
	std::cout << "categoriaP: " << categoriaP << std::endl;
	std::cout << "precioP: " << precioP << std::endl;
	std::cout << "cantidad: " << cantidad << std::endl;
}

std::string Producto::getClave()
{
	return clave;
}

std::string Producto::getNombreP()
{
	return nombreP;
}

int Producto::getCategoriaP()
{
	return categoriaP;
}

float Producto::getPrecioP()
{
	return precioP;
}

int Producto::getCantidad()
{
	return cantidad;
}

void Producto::setClave(std::string _valor)
{
	clave = _valor;
}

void Producto::setNombreP(std::string _valor)
{
	nombreP = _valor;
}

void Producto::setCategoriaP(int _valor)
{
	categoriaP = _valor;
}

void Producto::setPrecioP(float _valor)
{
	precioP = _valor;
}

void Producto::setCantidad(int _valor)
{
	cantidad = _valor;
}
