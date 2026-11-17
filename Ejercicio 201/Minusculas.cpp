#include "Minusculas.h"
using namespace std;
#include <string>
#include <sstream>

string minusculas(string palabra) {
	
    string fin = "";
	int longitud = palabra.length();

			for(int j=0; j < longitud;j++) {
				
				if ((int(palabra[j]) >= 'A') && (int(palabra[j]) <= 'Z')){
					fin=fin+char(palabra[j]+32);
				}
				else if ((int(palabra[j]) == -61) && (j+1 < longitud)) {
					int sig = int(palabra[j+1]);
					if (sig == -127 || sig == -119 || sig == -115 || sig == -109 || sig == -102 || sig == -100 || sig == -111) {	
							palabra[j+1] = palabra[j+1]+32; 
					}
                    fin=fin+char(palabra[j]);
					fin=fin+char(palabra[j+1]);
					j++;
				}	
				else {
					fin = fin+palabra[j];
				}
			}
			return fin;
}