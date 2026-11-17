#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "Producto.h"
#include "Hash.h"

using namespace std;

class Diccionario {
	
	private:
		list<Producto> lista;
		Hash tabla;
	public:
		Diccionario();
        void palabras(string palabra);
		void insertar(Producto &p);
		//void eliminar(string &ident);
		//void producto(string &ident);
		//void precios(double &min, double &max);
};

#endif