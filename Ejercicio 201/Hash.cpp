#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "Hash.h"
#include "Producto.h"
using namespace std;

Hash::Hash() {

}

unsigned int Hash::hash(string w) { //Aplicamos el algoritmo djb2 de Bernstein
    unsigned int h = 5381; //Con unsigned se evita que el numero acabe siendo negativo debido a que sea un numero excesivamente largo
    for (char c : w) {
        h=h*33+c;
    }
    return h % 10007;
}

list<Producto*> Hash::consultar(string palabra){
    unsigned int h=hash(palabra);

    for(const Par &par : T[h]){ //Recorremos todas las palabras que hay dentro de la casilla
        if(par.palabra==palabra){
            return par.productos;
        }
    }
    return list<Producto*>();
}

void Hash::insertar(Producto *p, string palabra) {
    unsigned int h=hash(palabra);
    for(Par &par : T[h]){ //Recorremos todas las palabras que hay dentro de la casilla
        if(par.palabra==palabra){


            
            for(Producto* prod : par.productos){ //Recorremos todos los productos asociados a la palabra
                if(prod->getIdentidad()==p->getIdentidad()){ //Si encontramos un producto con la misma identidad, no lo añadimos
                    return;
                }
            }

            for (list<Producto*>::iterator it = par.productos.begin(); it != par.productos.end(); it++) {
		        if ((*it)->getIdentidad() > p->getIdentidad()) { //se pone parentesis entre *it para que tenga prioridad sobre "->"
                    par.productos.insert(it, p); // Inserta 'p' justo antes del elemento mayor
                    return;
                }
            }
            par.productos.push_back(p);
            return;
        }
    }
    
    Par Npar; //Si no encontramos la palabra, creamos un nuevo par y lo añadimos a la lista de la casilla correspondiente
    Npar.palabra=palabra;
    Npar.productos.push_back(p);
    T[h].push_back(Npar);
}
