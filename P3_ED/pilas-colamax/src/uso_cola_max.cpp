/**
* @file uso_cola_max.cpp
* @brief fichero que hace uso del TDA cola_max. crea una cola, le inserta 10 elementos, los saca e imprime por pantalla.
*/


#include <iostream>
#include "cola_max.h"
using namespace std;

/**
* @brief sobrecarga del operador de salida <<
* @param o ostream donde almacenaremos los caracteres
* @param e elemento donde consultar valores
*/
ostream& operator<<(ostream &o, const elemento &e){

	o << "elemento: " << e.ele << ", maximo de la pila: " << e.max_ele << endl;
	return o;
}


int main(){

	cola_max c;
	int i;


	for ( i=10; i>=0 ; i--)	c.poner(i);	



	while (!c.vacia() ){
		elemento x = c.back();
		cerr << x<<endl;
		c.quitar();
	}
return 0;
}
