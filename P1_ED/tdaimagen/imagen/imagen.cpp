/**
  * @file imagen.cpp
  * @brief Fichero con definiciones de los metodos de la clase imagen
  *
  *
  */

#include "imagen.h"
#include <math.h>

using namespace std;
  Imagen::Imagen(){
	filas=0;
	columnas=0;	
	}

  Imagen::Imagen(int f, int c){
	if(c>0 && f>0){
		filas=f;
		columnas=c;
  		imagen= new unsigned char* [filas];
		for(int j = 0; j<filas; j++){
			imagen[j] = new unsigned char[columnas];				
		}
	}
	
  }

  Imagen::Imagen (const Imagen &c){

	if(this!=&c){
		filas=c.filas;
		columnas=c.columnas;
		imagen= new unsigned char* [filas];
		for(int j = 0; j<filas; j++){
			imagen[j] = new unsigned char[columnas];				
		}
		for(int i = 0; i<filas; i++){
			for(int j = 0; j<columnas; j++){
				imagen[i][j]=c.consultar_pixel(i,j);
			}
		}
	}
  }

 Imagen::~Imagen(){
	bool del=false;
	for(int i = 0; i<filas; i++){	del=(imagen[filas]!=0)? true: del;	}
	if (del){
		for(int i=0; i<filas; i++){ 	

			delete[] imagen[i];	
	  	}
		delete[] imagen;
		filas=0;
		columnas=0;
	}


  }

  Imagen& Imagen::operator=(const Imagen &I){
	if(this!=&I){
		//t=I.t;
		filas=I.filas;
		columnas=I.columnas;
		imagen= new unsigned char* [filas];
		for(int j = 0; j<filas; j++){
			imagen[j] = new unsigned char[columnas];				
		}

		for(int i = 0; i<filas; i++){
			for(int j = 0; j<columnas; j++){
				imagen[i][j]=I.consultar_pixel(i,j);
			}
		}
	}
 }

 




  void Imagen::asigna_pixel(int f, int c, unsigned char valor){

	if(f<0 || c<0 || f>=filas || c>=columnas){
		cerr << "Indice fuera de la matriz de la imagen";
	}	
	else{
		//cerr << "ASIGNANDO EN : " << f<< " " << c <<" :" << valor<<endl;
		imagen[f][c]=valor;	

	}
  }


  unsigned char Imagen::consultar_pixel(int f, int c)const{
	
	if(f<0 || c<0 || f>=filas || c>=columnas){
		cerr << "CONSULTA ERRONEA";
		return 'E';
	}
	else{
		return imagen[f][c];
	}

  }

  bool Imagen::CargarImagen(const char * nombre){

	TipoImagen tipo=LeerTipoImagen(nombre);
	if(tipo==IMG_PGM){

		int f, c;
		//Carga en un vector toda la matriz de la imagen
		unsigned char *buffer=LeerImagenPGM(nombre, f, c);
		if(buffer==0){
			cout << "No se ha podido leer el fichero" << endl;
			return false;		
		}
		Imagen aux(f,c);

		for(int i =0; i<f; i++){

			for(int j=0; j<c; j++){
				aux.asigna_pixel(i, j, buffer[i*c+j]);
			}
		}
		delete[] buffer;
		buffer=0;
		*this=aux;
		return true;
	}
	else if(tipo==IMG_PPM){

		int f, c;
		//Carga en un vector toda la matriz de la imagen
		unsigned char *buffer=LeerImagenPPM(nombre, f, c);
		if(buffer==0){
			cout << "No se ha podido leer el fichero" << endl;
			return false;		
		}
		//Igris(i, j) = 0,2989 × R(i, j) + 0,587 × G(i, j) + 0,114 × B(i, j)
		int pixel;
		int columna=0;
		Imagen aux(f,c);
		for(int i =0; i<f; i++){
			for(int j=0; j<c; j++){
				pixel=round((0.2989 * buffer[columna]) + (0.587 * buffer[columna+1]) + (0.114 * buffer[columna+2]));
				aux.asigna_pixel(i, j, pixel);
				columna+=3;			
			}
		}

		delete[] buffer;
		buffer=0;
		*this=aux;
		return true;
	}
	cout << "No se reconoce el formato" << endl; 
	return false;
  }


  bool Imagen::GuardarImagen(const char *nombre){


	cerr << "Guardando PGM" << endl;
	unsigned char *buffer= new unsigned char[filas*columnas];
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			buffer[i*columnas+j]=imagen[i][j];
		}
	}

	return EscribirImagenPGM(nombre, buffer, filas, columnas);
	delete[] buffer;


 
  }

  void Imagen::ImprimirImagen(){
	int v;
	cout << "Imprimiendo matriz imagen" << endl;
	for(int i = 0; i<filas; i++){
		for(int c=0; c<columnas; c++){
			v=consultar_pixel(i,c);
			cout << v << " ";
		}
		cout << endl;
	}

  }

  void Imagen::Borrar(){
	if(imagen!=0){

		for(int i=0; i<filas; i++){ 	

			delete[] imagen[i];	
	  	}
		delete[] imagen;
		filas=0;
		columnas=0;
	}

  }
