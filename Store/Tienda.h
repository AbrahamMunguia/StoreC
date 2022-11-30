#pragma once
#include <string>
#include <vector>
#include "Producto.h"
#include "Cliente.h"
class Tienda
{
	private: 
		std::string identificadorT;
		std::string nombre;
		std::string direccion;
		int cantidadProductosT;
		int cantidadClientesT;
		std::vector<Producto> productos;
		std::vector<Cliente> clientes;
		double ingresoDiario;
	public:
		// CONSTRUCTORS
		Tienda();
		Tienda(std::string _identificador, std::string _nombre, std::string _direccion, int _cantidadProductosT, int cantidadClientesT, std::vector<Producto> _productos, std::vector<Cliente> _clientes, double _ingresoDiario);
		// DESTRUCTOR
		~Tienda();
		// GETTERS
		std::string getIdentificadorT();
		std::string getNombre();
		std::string getDireccion();
		int getCantidadProductosT();
		int getCantidadClientesT();
		std::vector<Producto> getProductos();
		std::vector<Cliente> getClientes();
		double getIngresoDiario();
		// SETTERS
		void setIdentificadorT(std::string _identificador);
		void setNombre(std::string _nombre);
		void setDireccion(std::string _direccion);
		void setCantidadProductosT(int _cantidadProductos);
		void setCantidadClientesT(int _cantidadClientesT);
		void setProductos(std::vector<Producto> _productos);
		void setIngresoDiario(std::vector<Cliente> _clientes);

		// CUSTOMS
		void imprimirTienda();
		// AGREGA PRODUCTOS DESDE ARCHIVO
		void agregarProductos();
		// AGREGA PRODUCTO MANUALMENTE
		void agregarProducto();
		// AGREGA CLIENTE
		void agregarCliente();
		// LLENAR CARRITO
		void llenarCarrito();
		// TICKET DE COMPRA
		void imprimirTicketCompra();
		// CERRAR OPERACION
		void cerrarOperaciones();

};

