#include <iostream>
#include <string>
using namespace std;
#include "Producto.h"
#include "Diccionario.h"
#include "Hash.h"

int main () {

    Diccionario dicc;
    string palabra;

    while (cin >> palabra) {
        if (palabra == "insertar") {
            Producto p;
            p.leer();
            dicc.insertar(p);
        }
        else if (palabra == "palabras") {
            string palabra2;
            cin >> palabra2;
            dicc.palabras(palabra2);
        }
    }


    return 0;
}