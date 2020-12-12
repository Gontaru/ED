/**
  * @file pila_max_cola.h
  * @brief Fichero cabecera del TDA pila_max_cola
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo
  */

#ifndef __PILA_MAX_COLA__
#define __PILA_MAX_COLA__


#include "cola.h"
#include <iostream>
#include "elemento.h"


class Pila_max{

	private:
	
		Cola<elemento> mipila;

	public:
               /**
    		 * @brief Método que devuelve el tope de la pila
		 * @return elemento objeto elemento tope de la pila
    	       */
		const elemento tope();
		/**
		  * @brief Método que quita el elemento del tope de la pila (igual que pop())
		 */
		void quitar();
		/**
		  * @brief Método que añade un elemento con valor e por el tope de la pila
		  * @param e valor que tendrá el elemento a añadir
		*/
		void poner(int e);
		/*
		 * @brief Método que comprueba si la pila está vacia
		 * @return true en caso afirmativo, de lo contrario false	
		*/
		bool vacia() const;
	        /**
		 * @brief Método que devuelve el tamaño de la pila
		 * @return número de elementos de la pila
		*/
		int size() const;


};


#endif
