#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string> 
#include <sstream>

using namespace std;

class Producto {

	private:
		string ident;
		string nombre;
		string desc;
		double precio;

	public:
		Producto(){};
		void leer();
		void mostrar();
		
		string getIdentidad();
		double getPrecio();
        string getNombre();
        string getDescripcion();
};

#endif
