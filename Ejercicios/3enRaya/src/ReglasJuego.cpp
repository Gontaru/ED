#include <iostream>
#include "ReglasJuego.h"



using namespace std;


	ReglasJuego::ReglasJuego(const Tablero &t, Jugador ju1, Jugador ju2){
			mitab=t;
			mitab.m1 = (ju1.GetTipo() == 1) ? ju1.GetFicha() : blanco;
			mitab.m2 = (ju2.GetTipo() == 1) ? ju2.GetFicha() : blanco;
			j1=ju1;
			j2=ju2;
	}

	bool ReglasJuego::HemosAcabado(){
		
		
		if(mitab.Busca3Raya() == circulo){
			if(j1.GetFicha() == circulo){ cout << endl << "Ha ganado " << j1.GetNombre();}
			else{ cout << "Ha ganado " << j2.GetNombre();}
		}
		else if(mitab.Busca3Raya() == cruz){
			if(j1.GetFicha() == cruz){  cout << endl << "Ha ganado " << j1.GetNombre();}
			else{  cout << "Ha ganado " << j2.GetNombre();}
		}
		else if(mitab.CuantasFichas() == 9) cout << endl << "Empate " << endl;
		else if(mitab.CuantasFichas() < 9) return false;			
		char aux;
		cout << endl <<  "¿Desea volver a jugar? S/N: ";
		cin >> aux;
		cout << endl;
		if(aux == 's' || aux == 'S'){
			NuevoJuego();
			return false;
		}
		return true;	
	}

	void ReglasJuego::NuevoJuego(){
		turno = (turno+1)%2;
		mitab = Tablero();
		mitab.ImprimirTablero();
	}

	void ReglasJuego::JugarTurno(){

	
		if(turno == 0){
			cout << endl << "Turno de: " << j1.GetNombre() << endl;
			j1.siguientemov(mitab);
		}
		else{
			cout << endl << "Turno de: " << j2.GetNombre() << endl;
			j2.siguientemov(mitab);
		}
		mitab.ImprimirTablero();
		turno = (turno+1)%2;
	}
