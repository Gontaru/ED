/**
  * @file cola_max.h
  * @brief Fichero cabecera del TDA cola_max
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en dos extremos
  */

#ifndef __COLA_MAX__
#define __COLA_MAX__
/**
 *  @brief T.D.A. cola_max
 *
 *
 * Una instancia @e c del tipo de dato abstracto cola_max sobre un dominio @e T es
 * una sucesión finita de elementos del mismo con un funcionamiento @e FIFO
 * (First In, First Out}). En una cola, las operaciones de inserción tienen
 * lugar en uno de los extremos, denominado @e final de la cola, mientras que
 * el borrado y consulta se lleva a cabo en el otro extremo, denominado 
 * @e frente de la cola. Una cola de longitud @e n la denotamos

 * - <elemento1,elemento2,elemento3,..,elementon<

 * En esta cola, tendremos acceso únicamente al elemento del @e Frente,
 * es decir, a @e elemento1. El borrado o consulta de un elemento será sobre @e elementon,
 * mientras que la inserción de un nuevo elemento se hará después de
 * @e elemento1.
 *
 * Si n=0 diremos que la cola está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número 
 * de elementos de la cola.
 *
 * @author Gonzalo Medina Medina
 * @date Noviembre 2020
*/

#include <iostream>
#include <stack>
#include "elemento.h"

using namespace std;
/**
* @brief clase cola_max que representa una cola que guarda el valor máximo añadido
*/
class cola_max{

	private:
	
		stack<elemento> mipila1;//pila que se gestionará para que funcione como una cola


	public:
		/**
		 * @brief Método que devuelve el primer elemento de la cola
		 * @return objeto constante de tipo elemento
		*/
		const elemento front();
		/**
		 * @brief Método que devuelve el último elemento de la cola
		 * @return objeto constante de tipo elemento
		*/
		const elemento back();
		/**
		 * @brief Método que quita el último elemento de la cola
		*/
		void quitar();
		/**
		 * @brief Método que añade un elemento con valor e al principio de la cola
		*/
		void poner(int e);
		/**
		 * @brief Método que comprueba si la cola está vacía. 
		 * @return true si está vacía, de lo contrario false
		*/
		bool vacia() const;
		/**
		 * @brief Método que devuelve el número de elementos de la cola
		 * @return número de elementos de la cola
		*/
		int size() const;


};


#endif
