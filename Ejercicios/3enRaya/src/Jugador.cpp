#include <iostream>
#include "Jugador.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

			  //[0][0][0][1]	[1][0][1][1]   [2][0][2][1]    [3][0][3][1]		[4][0][4][1]
	int const dir[7][2] = { {0,1}, 		{1,1}, 		{1,0}, 		{1,-1}, 	{0,-1},    {-1,-1},   {-1,0}};

	Jugador::Jugador(){}

	Jugador::Jugador(string n, int t, Ficha fj){
		nombre=n;
		f=fj;
		tipo = t;
	}

	void Jugador::piensa_mov_humano(Tablero &t){
		int fila,columna;
		do{
			cout << endl << "Introduzca fila:";
			cin >> fila;
			cout << endl << "Introduzca columna:";
			cin >> columna;
			}while(!t.PonerFicha(fila-1,columna-1,f));

	}

	bool EnRango(int i, int j){
		if(i<3 && i>=0 && j<3 && j>=0) return true;
		else return false;
	}


	void Jugador::piensa_mov_maquina(Tablero &t){

		bool ficha_colocada=false;
		for(int i = 0; i<3 && !ficha_colocada; i++){
			for(int j=0; j<3 && !ficha_colocada; j++){
				if(t.QueFicha(i,j) == blanco && !ficha_colocada){
					for(int d=0; d<7 && !ficha_colocada; d++){

						int fx=i;
						int cx=j;
						fx+=dir[d][0];
						cx+=dir[d][1];
						int numfichas=1;

						while(t.QueFicha(fx,cx) == f && EnRango(fx,cx)){
							numfichas++;

							fx+=dir[d][0];
							cx+=dir[d][1];
						}
						if(numfichas==3){

							if(t.PonerFicha(i,j,f))ficha_colocada=true;
						}
					}

				}
			}
		}
		Ficha f_contrincante = (f == circulo) ? cruz : circulo;

		for(int i = 0; i<3 && !ficha_colocada; i++){
			for(int j=0; j<3 && !ficha_colocada; j++){
				if(t.QueFicha(i,j) == blanco && !ficha_colocada){

					for(int d=0; d<7 && !ficha_colocada; d++){
				
						
						int fx=i;
						int cx=j;
						fx+=dir[d][0];
						cx+=dir[d][1];
						int numfichas=1;

						while(t.QueFicha(fx,cx) == f_contrincante && EnRango(fx,cx)){
							numfichas++;
							fx+=dir[d][0];
							cx+=dir[d][1];
						}
						if(numfichas==3){
							if(t.PonerFicha(i,j,f))ficha_colocada=true;
						}					
					}
				}
			}
		}
		

		for(int i = 0; i<3 && !ficha_colocada; i++){
			for(int j=0; j<3 && !ficha_colocada; j++){
				bool una_blanca=false;
				int auxi;
				int auxj;
				if((t.QueFicha(i,j) == f_contrincante) && !ficha_colocada){

					for(int d=0; d<7 && !ficha_colocada; d++){
				
						int fx=i;
						int cx=j;
						fx+=dir[d][0];
						cx+=dir[d][1];
						int numfichas=0;
						

						while((t.QueFicha(fx,cx) == f_contrincante || (t.QueFicha(fx,cx) == blanco && !una_blanca)) && EnRango(fx,cx)){

							if(t.QueFicha(fx,cx) == blanco && EnRango(fx,cx) && !una_blanca){
								una_blanca=true;
								auxi=fx;
								auxj=cx;

								numfichas++;
								fx+=dir[d][0];
								cx+=dir[d][1];
							}
							else{						
								numfichas++;
								fx+=dir[d][0];
								cx+=dir[d][1];
							}
						}
						if(numfichas==2){
							if(una_blanca){
								if(t.PonerFicha(auxi,auxj,f))ficha_colocada=true;
							}
							if(t.QueFicha(fx,cx) == blanco){
								if(t.PonerFicha(fx,cx,f)){
									ficha_colocada=true;
								}
							}
						}
					una_blanca=false;					
					}
					
				}
			}
		}

	



		if(!ficha_colocada){
			if(t.QueFicha(1,1) == blanco)t.PonerFicha(1,1,f);
			else{
				srand(time(NULL));						
				int ri=  rand() % 3;
				int rj=	 rand() % 3;
				do{
					ri=  rand() % 3;
					rj=  rand() % 3;
					}while(!t.PonerFicha(ri,rj,f));					
			}		
		}
	}

	string Jugador::GetNombre() const{
		return nombre;
	}
	Ficha Jugador::GetFicha() const{
		return f;
	}
	int Jugador::GetTipo() const{
		return tipo;
	}
	void Jugador::siguientemov(Tablero &t){
		
		if(GetTipo()==0){
			piensa_mov_humano(t);
		}
		else{
			piensa_mov_maquina(t);
		}		
	}

