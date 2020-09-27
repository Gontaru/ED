#include <iostream>
#include "Jugador.h"

using namespace std;

class ReglasJuego{

	private:
		int turno;
		Jugador j1, j2;
		Tablero mitab;

	public:
		ReglasJuego(const Tablero &t, Jugador ju1, Jugador ju2);
		bool HemosAcabado();
		void NuevoJuego();
		void JugarTurno();
};
