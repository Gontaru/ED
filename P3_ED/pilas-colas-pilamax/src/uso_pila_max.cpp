/**
* @file uso_pila_max.cpp
* @brief fichero que testea el TDA pila_max
*/

#include <iostream>
#include "pila_max.h"
using namespace std;


ostream& operator<<(ostream &o, const elemento &e){

	o << "elemento: " << e.ele << ", maximo de la pila: " << e.max_ele << endl;
	return o;
}


int main(){

	Pila_max p;
	int i;


	for ( i=10; i>=0 ; i--)	p.poner(i);	
		 	


	while (!p.vacia() ){
		elemento x = p.tope();
		cerr << x<<endl;
		p.quitar();
	}
return 0;
}
