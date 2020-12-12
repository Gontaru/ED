#include "pila_max_vd.h"

/**
  * @file pila_max_vd.cpp
  * @brief Fichero que implementa el TDA pila_max_vd
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo
  */

	elemento Pila_max::tope() const{
		elemento result;
		result.ele=-1;
		result.max_ele=-1;
		if(!vacia())return mipila.back();
		return result;
	}


	void Pila_max::quitar(){
		mipila.pop_back();
	}

	void Pila_max::poner(int e){

		elemento newele;
		newele.ele=e;

		newele.max_ele = (tope().max_ele < e)? e : tope().max_ele;

		mipila.push_back(newele);
	}

	bool Pila_max::vacia() const{

		return mipila.empty();
	}

	int Pila_max::size() const{

		return mipila.size();
	}


