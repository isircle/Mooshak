#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"

using namespace std;

void Producto::leer() {
	getline(cin>>ws, ident);
	getline(cin, nombre);
	getline(cin, desc);
	cin>>precio;
}

void Producto::mostrar(){
	cout<<nombre<<" ("<<ident<<")\n";
	cout<<"  "<<desc<<"\n";
	cout<<"  "<<precio<<" euros\n";
}

string Producto::getIdentidad(){
	
	return ident;
}

string Producto::getNombre(){
	
	return nombre;
}

string Producto::getDescripcion(){
	
	return desc;
}

double Producto::getPrecio(){
	
	return precio;
}