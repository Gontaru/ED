/**
* @file cola_max.cpp
* @brief fichero que implementa el TDA cola_max
*/
#include "cola_max.h"



		const elemento cola_max::front(){
			return mipila1.top();

		}

		const elemento cola_max::back(){
			
			stack<elemento> aux=mipila1;
			int tam=aux.size();
			for(int i=0; i<tam-1; i++)aux.pop();
			return aux.top();
		}

		void cola_max::quitar(){
			
			stack<elemento> aux;
			int tam=mipila1.size();
			for(int i = 0; i<tam-1;i++){
				aux.push(mipila1.top());
				mipila1.pop();
			}

			while(!mipila1.empty())mipila1.pop();
			tam=aux.size();
			
			for(int i = 0; i<tam;i++){
				mipila1.push(aux.top());
				aux.pop();
			}
		}

		void cola_max::poner(int e){
			elemento aux;
			aux.ele=e;

			if(!vacia())aux.max_ele = (mipila1.top().max_ele<e)? e : mipila1.top().max_ele;
			else aux.max_ele=e;

			mipila1.push(aux);

			
		}


		bool cola_max::vacia() const{
			return mipila1.empty();

		}
		int cola_max::size() const{
			return mipila1.size();
		}

