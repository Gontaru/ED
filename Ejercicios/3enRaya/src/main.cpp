#include<iostream>
#include"ReglasJuego.h"

using namespace std;


int main(){
	string n1,n2;
	char aux;
	Ficha f1,f2;
	int t1,t2;


	Tablero tablero = Tablero();
	
	cout << "Introduzca el nombre del jugador 1: ";
	cin >> n1;
	cout << endl << "¿El jugador 1 es humano o maquina?: (0 : 1)";
	cin >> t1;
	cout << endl << "¿Que ficha desea?: (X : O)";
	cin >> aux;
	f1 = (aux == 'o' || aux == 'O') ? circulo : cruz;
	Jugador j1 = Jugador(n1,t1,f1);
	aux=NULL;

	cout << "Introduzca el nombre del jugador 2: ";
	cin >> n2;
	cout << endl << "¿El jugador 2 es humano o maquina?: (0 : 1)";
	cin >> t2;
	f2 = (f1 == cruz) ? circulo : cruz;
	Jugador j2 = Jugador(n2,t2,f2);

	ReglasJuego juego = ReglasJuego(tablero, j1, j2);
	juego.NuevoJuego();

	do{
		
		juego.JugarTurno();
	}while(!juego.HemosAcabado());

	return 0;
};
