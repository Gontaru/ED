#include <iostream>
#include "Tablero.h"


using namespace std;

class Jugador{


	private:
		string nombre;
		Ficha f; //circulo o cruz
		int tipo; //maquina o humano (0 o 1)
		void piensa_mov_humano(Tablero &t);
		void piensa_mov_maquina(Tablero &t);

	public:
		Jugador();
		Jugador(string n, int t, Ficha fj);
		string GetNombre() const;
		Ficha GetFicha() const;
		int GetTipo() const;
		void siguientemov(Tablero &t);

};
