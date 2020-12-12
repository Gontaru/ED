#include "pila_max_cola.h"
/**
  * @file pila_max_cola.cpp
  * @brief Fichero donde se implementa el TDA pila_max_cola
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo
  */

	const elemento Pila_max::tope() {
		Cola<elemento> aux(mipila);

		for(int i = 0; i<size()-1; i++){
			aux.quitar();
		}

		return aux.frente();

	}
	void Pila_max::quitar(){
		Cola<elemento> aux;
		int tam=mipila.num_elementos();
		for(int i = 0; i<tam-1; i++){
			aux.poner(mipila.frente());
			mipila.quitar();
		}
		mipila=aux;
	}

	void Pila_max::poner(int e){
		elemento newele;

		newele.ele=e;
		if(!vacia())newele.max_ele = (tope().max_ele < e)? e : tope().max_ele;
		else newele.max_ele =e;

		mipila.poner(newele);

	}

	bool Pila_max::vacia() const{
		return mipila.vacia();
	}


	int Pila_max::size() const{
		return mipila.num_elementos();
	}
