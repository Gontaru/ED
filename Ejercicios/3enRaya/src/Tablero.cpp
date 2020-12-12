#include<iostream>
#include "Tablero.h"

using namespace std;
			//[0][0][0][1]		[1][0][1][1]   [2][0][2][1]    [3][0][3][1]
	int const dir[4][2] = { {0,1}, 		{1,1}, 		{1,0}, 		{1,-1} };

	ostream& operator<<(ostream &os, const Ficha &f){

		if(f == circulo){
			os << 'O';
		}
		else if(f == cruz){
			os << 'X';	
		}
		else{
			os << " ";
		}
	}


	Tablero::Tablero(){
		numfichas=0;
		PonerEnBlanco();
	}

	bool Tablero::hay3raya(const Ficha &f){
	
		for(int i = 0; i<3; i++){
			for(int j = 0; j<3; j++){
				if(tab[i][j] == f){
					for(int d=0; d<4; d++){

						int fx=i;
						int cx=j;
						fx+=dir[d][0];
						cx+=dir[d][1];
						int nfichas=1;
						while(tab[fx][cx] == f && fx >=0 && cx >=0 && fx<3 && cx<3){
							nfichas++;
							fx+=dir[d][0];
							cx+=dir[d][1];
						}
						if(nfichas==3)return true;		
					}				
				}
			}
		}
		return false;	
	}


	bool Tablero::PonerFicha(int i, int j, const Ficha &f){
		bool imprimir = (f == m1) ?  true : false;
		imprimir = (f == m2) ?  true : imprimir;

		if(i<3 && i>=0 && j<3 && j>=0){
			if(tab[i][j] == blanco){
				tab[i][j] = f;
				numfichas++;
				return true;
			}
			else{
				if(imprimir)cout <<  "Casilla ocupada" << endl;
				return false;
			}
		}
		else{
			if(imprimir)cout <<  "Rango no permitido" << endl;
			return false;
		}
	}
	Ficha Tablero::QueFicha(int i, int j) const{
		return tab[i][j];
	}

	Ficha Tablero::Busca3Raya(){
		if(hay3raya(circulo)) return circulo;
		if(hay3raya(cruz)) return cruz;
		return blanco;
	}

	int Tablero::CuantasFichas(){
		return numfichas;
	}

	void Tablero::PonerEnBlanco(){
		for(int i = 0; i<3; i++){
			for(int j = 0; j<3; j++){
			tab[i][j]=blanco;
			}		
		}
	}


	void Tablero::ImprimirTablero(){
		cout << "	------"<<endl;
		for(int i = 0; i <3; i++){
			cout << "	|";
			for(int j = 0; j<3; j++){
				cout << tab[i][j]<<"|";
			}
			cout << endl;
		}
		cout << "	------";
	}


