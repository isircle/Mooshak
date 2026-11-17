#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <list>
#include "Producto.h"
using namespace std;

struct Par { //😀
    string palabra;
    list<Producto*> productos;
};

class Hash {
private:
    list<Par> T[10007]; //10007 es un número primo que servirá como tamaño de la lista
    unsigned int hash(string s);

public:
    Hash();
    list<Producto*> consultar(string palabra);
    void insertar(Producto *p, string palabra);
};

#endif