#include <iostream>

#include <string>
#include <sstream>
#include "Producto.h"
#include "Diccionario.h"
#include "Minusculas.h"

using namespace std;

Diccionario::Diccionario(){
	
}

void Diccionario::palabras(string palabra) {

    cout << "palabras " << palabra << endl;

    string min=minusculas(palabra);
    list<Producto*> lista = tabla.consultar(min); //Añade a Hash

    int PeterGriffin=1;
    for (Producto*p: lista) {

        cout << PeterGriffin << ". "; 
        p->mostrar();
        PeterGriffin++;
    }

    cout << "Total: " << lista.size() << " productos" << endl;
}

void Diccionario::insertar(Producto &p) {
	

	string palabra = "";
	lista.push_back(p);
	Producto* pt = &lista.back();
	string nombre=p.getNombre();

	for (int i=0; i<nombre.length(); i++) {
		
		if (i < nombre.length() && nombre[i] != ' ' && nombre[i] != '\r' && nombre[i] != '\t') {
			palabra = palabra + nombre[i];
		}
		else {
			if (palabra != "") {
				tabla.insertar(pt, minusculas(palabra));
				palabra = "";
			}	
		}
	}

	if (palabra != "") {
		tabla.insertar(pt, minusculas(palabra));
		palabra = "";
	}	

	string descripcion=p.getDescripcion();
	palabra = "";

	for (int i=0; i<descripcion.length(); i++) {
		
		if (i < descripcion.length() && descripcion[i] != ' ' && descripcion[i] != '\r' && descripcion[i] != '\t') {
			palabra = palabra + descripcion[i];
		}
		else {
			if (palabra != "") {
				tabla.insertar(pt, minusculas(palabra));
				palabra = "";
			}	
		}
	}

	if (palabra != "") {
		tabla.insertar(pt, minusculas(palabra));
	}

	cout << lista.size() << " productos" << endl;
	
}
/*
void Diccionario::eliminar(string &ident) {
	
	for(list<Producto>::iterator it = lista.begin(); it != lista.end(); it++) {
		if (it->getIdentidad() == ident) {
			lista.erase(it);
			break;
		}
	}
	cout<<lista.size()<< " productos"<<endl;
}

void Diccionario::producto(string &ident) {
	
	cout << "producto " << ident << endl;
	int cond=0;
	
	for (list<Producto>::iterator it = lista.begin(); it != lista.end(); it++) {
		if (it->getIdentidad() == ident) {
			cond++;
			cout << cond << ". ";
			it->mostrar();
			break;
		}
	}
	cout<<"Total: "<<cond<< " productos"<<endl;
}

void Diccionario::precios(double &min, double &max) {
	
	cout << "precios " <<min<<" "<<max<<endl;
	int cond=0;
	for (list<Producto>::iterator it = lista.begin(); it != lista.end(); it++) {
		
		if ((it->getPrecio() >= min) && (it->getPrecio() <= max)) {
			cond++;
			cout << cond << ". ";
			it->mostrar();
		}
	}
	cout<<"Total: "<<cond<< " productos"<<endl;
}
*/