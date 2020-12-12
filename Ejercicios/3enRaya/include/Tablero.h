#include<iostream>
#include "Ficha.h"

using namespace std;

class Tablero{

	private:
		Ficha tab[3][3];
		int numfichas;
		bool hay3raya(const Ficha &f);


	public:
		Ficha m1,m2;
		Tablero();
		bool PonerFicha(int i, int j, const Ficha &f);
		Ficha QueFicha(int i, int j) const;
		Ficha Busca3Raya();
		int CuantasFichas();
		void PonerEnBlanco();
		void ImprimirTablero();

};
