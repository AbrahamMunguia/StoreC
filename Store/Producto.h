#pragma once
#include <string>

class Producto
{
	private:
		std::string clave;
		std::string nombreP;
		int categoriaP;
		float precioP;
		int cantidad;
	public:
		Producto(std::string id, std::string name, int category, float price, int ammount);
		Producto();
		~Producto();
		void imprimir();

		//GETTERS
		std::string getClave();
		std::string getNombreP();
		int getCategoriaP();
		float getPrecioP();
		int getCantidad();

		// SETTERS
		void setClave(std::string _valor);
		void setNombreP(std::string _valor);
		void setCategoriaP(int _valor);
		void setPrecioP(float _valor);
		void setCantidad(int _valor);


};

