#pragma once
#include <string>
#include "Producto.h"
#include <vector>

class Cliente
{
	private:
		std::string identificador;
		std::string nombreC;
		std::string correoElectronico;
		std::string telefono;
		std::vector<Producto> productos;
		double totalCompra;
	public:
		Cliente();
		Cliente(
			std::string _identificador,
			std::string _nombreC,
			std::string _correoElectronico,
			std::string _telefono,
			std::vector<Producto> _productos,
			double _totalCompra
		);
		~Cliente();
		// Imprimir todo
		void imprimirCliente();
		// GETTERS
		std::string getIdentificador();
		std::string getNombreC();
		std::string getCorreoElectronico();
		std::string getTelefono();
		std::vector<Producto> getProductos();
		double getTotalCompra();
		// SETTERS
		void setIdentificador(std::string _valor);
		void setNombreC(std::string _valor);
		void setCorreoElectronico(std::string _valor);
		void setTelefono(std::string _valor);
		void setProductos(std::vector<Producto> _productos);
		void setTotalCompra(double nuevoTotal);
};

