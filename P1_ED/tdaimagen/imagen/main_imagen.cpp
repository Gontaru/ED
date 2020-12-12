/**
  * @file main_imagen.cpp
  * @brief Fichero con definiciones para el tratamiento de imagenes
  *
  * Permite realizar operaciones obre las imagene
  *
  */


#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <utility>
#include <math.h>
#include "imagen.h"

using namespace std;

/**
  * @brief funcion que cifra un mensaje dentro de una imagen
  * @param I imagen donde cifraremos el mensaje
  * @pre f y c deben ser mayores que 0
  * @post I es modificado para alojar el mensaje
  */

void CifrarMensaje(Imagen &I){
	if(I.num_filas() >0 && I.num_columnas()>0){
		//le sacamos por pantalla al usuario el máximo de caracteres que se podrán escribir. 
		//Le restamos uno, porque el primer byte indicará si hay o no un mensaje cifrado
		int max_cadena= ((I.num_filas()*I.num_columnas())/8)-1;
		string s;
		//char s[max_cadena];
		int v, contador_cadena=0, pos_b=7, aux=0, i=0,j=0;
		unsigned char c;
		char* t;


	
		do{	
	
			
				getline(cin,s);
				if(s.length()>0 && s.length()<max_cadena)break;
				cout << "Introduzca la cadena de texto a cifrar en la imagen"<<endl;
				cout << "Máximo " << max_cadena << " caracteres: ";

		}while(s.length()==0 || s.length()>max_cadena);

		int tam = s.length();





	
		for(int u=7; u>=0; u--){
			v=I.consultar_pixel(i,j);		
			if(u!=1)v = (0xFE & v);
			else v = (v | 0x01);
			I.asigna_pixel(i,j,v);
			j++;
			if(j==I.num_columnas()){
				j=0;
				i++;
			}
		}

	

		for( i ; i<I.num_filas(); i++){
				pos_b=7;
			for( j ; j<I.num_columnas(); j++){
			
				if(pos_b==-1){
					contador_cadena++;

					pos_b=7;
				}


				aux=((c >> pos_b) & 0x01);

				v=I.consultar_pixel(i,j);

				if(aux==1){
			
					v=(v|aux);
				}
				else{
					v=(0x0FE & v);
				}
				I.asigna_pixel(i,j,v);

				c=s[contador_cadena];

				pos_b--;			
				if(contador_cadena==/*s.length()*/tam || contador_cadena==max_cadena-1)break;

			}
		
			if(contador_cadena==/*s.length()*/tam || contador_cadena==max_cadena-1)break;
		}
	
		for(int u=7; u>=0; u--){
			v=I.consultar_pixel(i,j);		
			if(u>1)v = (0xFE & v);
			else v = (v | 0x01);
			I.asigna_pixel(i,j,v);
			j++;
			if(j==I.num_columnas()){
				j=0;
				i++;
			}
		}
	}
	else{
		cout << "No se puede cifrar mensaje.Imagen vacia" << endl;
	}
}

/**
  * @brief funcion que lee un mensaje cifrado en la imagen I
  * @param I imagen donde buscaremos el mensaje
  * @param cadena string donde guardaremos el mensaje leido
  * @pre f y c deben ser mayores que 0
  * @return Devuelve true si se ha leido un mensaje oculto, false en caso contrario
  */
bool LeerMensajeCifrado(const Imagen & I , string &cadena){
	if(I.num_filas() >0 && I.num_columnas()>0){
		int v, pos_b=7, auxi;

		string s;
		unsigned char c, aux=0;
	
		bool primero=true;
		int nbits=0;

		for(int i = 0; i<I.num_filas(); i++){
			for(int j = 0; j<I.num_columnas(); j++){

				//Consultamos el caracter
				c=I.consultar_pixel(i,j);
			
				//Extraemos el ultimo bit
				auxi=((c >> 0) & 0x01);

				auxi = auxi << 7-nbits;
				aux = aux | auxi;
				aux << 1;

				nbits++;
		
				//Si hemos acumulado 1 byte, guardamos el caracter cifrado
				if(nbits==8){
					//Si es el primer caracter que leemos, comprobamos que sea un comienzo de texto
					if(primero){
						if(aux!=2){
							cout << "No hay mensaje cifrado" << endl;
							return false;
						}
				
						primero=false;
						aux=0;
						nbits=0;
					}
					//si ya hemos leido el primero, vamos leyendo los demás caracteres
					else{
						//Si es un final de texto quiere decir que el mensaje oculto ha finalizado
						if(aux==3){return true;}

						cadena.push_back(aux);

						aux=0;
						nbits=0;
					}
				}

			
			}

		}

		cout << "No se ha encontrado ningun mensaje"<<endl;
		return false;
	}
	else{
		cout << "No se ha podido leer un mensaje. Imagen vacia"<<endl;
		return false;
	}
}

/**
  * @brief funcion aumenta el contraste en la imagen I
  * @param I imagen a modificar
  * @param min minimo valor de gris para la imagen resultante
  * @param max maximo valor de gris para la imagen resultante
  * @pre f y c deben ser mayores que 0
  * @post pixeles de I modificados
  */
void AumentarContraste(Imagen &I, int min, int max){

	if(I.num_filas() >0 && I.num_columnas()>0){
		int a=255, b=0, aux;
		int cociente;
		for(int i = 0; i< I.num_filas(); i++){
			for(int j = 0; j<I.num_columnas(); j++){
				aux=I.consultar_pixel(i,j);
				a= (aux<a)? aux : a;
				b= (aux>b)? aux : b;	

			}
		}
		float c=round(((max-min)/(b-a)));

	
		cociente=round(((max-min)/(b-a)));




		int v; 

		for(int i = 0; i< I.num_filas(); i++){
			for(int j = 0; j<I.num_columnas(); j++){
				aux = I.consultar_pixel(i,j);

				v = min + (cociente * (aux -a));

				I.asigna_pixel(i,j,v);		
			}
		}
	}
	else{
		cout << "Imagen vacia. Operacion no valida" << endl;
	}
}
/**
  * @brief funcion que umbraliza la imagen I por valores dados
  * @param I imagen a modificar
  * @param t1 rango minimo del umbral
  * @param t2 rango maximo del umbral
  * @pre f y c deben ser mayores que 0
  * @post pixeles de I modificados
  */
void umbralizar_escala_grises(Imagen &I,int t1, int t2){
	if(I.num_filas() >0 && I.num_columnas()>0){
		int nf = I.num_filas();
		int nc = I.num_columnas();

		for (int f=0; f < nf; f++){
			for(int c=0 ; c< nc; c++){
			if(I.consultar_pixel(f,c)>= t1 && I.consultar_pixel(f,c) <= t2){}
			else{I.asigna_pixel(f, c, 255);}
			}	
		}

	}
	else{
		cout << "Operacion no valida. Imagen vacia" << endl;
	}	

}
/**
  * @brief funcion que umbraliza automaticamente una imagen I
  * @param I imagen a modificar
  * @param e valor pequeño que condiciona el umbral calculado  
  * @pre f y c deben ser mayores que 0
  * @post pixeles de I modificados
  */
void umbralizar_automatico(Imagen &I, int e){

	if(I.num_filas() >0 && I.num_columnas()>0){
		int T=0, Tnew=0;
		int s1=0, s2=0;
		int cnt1=0, cnt2=0;
		int u1, u2;
		bool fin=false;
	
		for(int i =0; i<I.num_filas(); i++){
			for(int j = 0; j<I.num_columnas(); j++){
				T+=I.consultar_pixel(i,j);
			}
		
		}

		T= (T/(I.num_filas()*I.num_columnas()));

		do{

				s1=0, s2=0;
				cnt1=0, cnt2=0;
				u1=0, u2=0;

		

				for(int i =0; i<I.num_filas(); i++){
					for(int j = 0; j<I.num_columnas(); j++){
						if(I.consultar_pixel(i,j)<T){
							s1+=I.consultar_pixel(i,j);				
							cnt1++;
						}
						else{
							s2+=I.consultar_pixel(i,j);				
							cnt2++;
						}
					}	
				}
				u1=round(s1/cnt1);
				u2=round(s2/cnt2);
				Tnew=(u1+u2)/2;
				fin = ((Tnew-T)<e)? true : false;
				T=Tnew;

		}while(!fin);
	
		for(int i =0; i<I.num_filas(); i++){
				for(int j = 0; j<I.num_columnas(); j++){
					if(I.consultar_pixel(i,j)<=T){
						I.asigna_pixel(i,j,255);
					}
				}
	
		}
	}
	else{
		cout << "Operacion no valida. Imagen vacia" <<endl;
	}

}


/**
  * @brief funcion que hace un zoom en una imagen I a partir de la esquina superior izquierda de la imagen y las dimensiones del zoom a hacer
  * @param I imagen a modificar
  * @param ei par de coordenadas que determinan la esquina superior izquierda de la nueva imagen en la imagen actual. 
  * @param dim dimension dimXdim del zoom a realizar
  * @pre f y c deben ser mayores que 0
  * @post pixeles de I modificados
  */
void zoom(Imagen &I, pair<int, int> ei, int dim){


	if(I.num_filas() >0 && I.num_columnas()>0){
		unsigned char aux;
	
		//Creamos imagen resultado con las dimensiones apropiadas
		Imagen result(2*dim-1,2*dim-1);

		int nf = result.num_filas();
		int nc = result.num_columnas();	

		int fila=0, columna=0;
		int v1,v2,vaux;


		for (int f=ei.second; f < ei.second+dim; f++){
			columna=0;
			for(int c=ei.first ; c< ei.first+dim; c++){
			
			
				result.asigna_pixel(fila,columna,I.consultar_pixel(f,c));	
			
			
				columna+=2;
			}
			fila+=2;
		}


		//bucle para añadir una columna entre cada dos
		for (int f=0; f < nf; f++){

			if(f%2==0){		
				for(int c=0 ; c< nc; c++){
					if(c%2!=0){
						v1=result.consultar_pixel(f,c-1);
						v2=result.consultar_pixel(f,c+1);

						aux = ((v1+v2)%2!=0)? ((v1+ v2)/2)+1 : (v1+v2)/2;

						result.asigna_pixel(f,c,aux);	
						
					}	
				}
			}
		}

		//bucle para añadir una nueva fila entre cada 2
		for (int f=0; f < nf; f++){

			if(f%2!=0){
				for(int c=0 ; c< nc; c++){
					v1=result.consultar_pixel(f-1,c);
					v2=result.consultar_pixel(f+1,c);
					aux = ((v1+v2)%2!=0)? ((v1+  v2)/2)+1 : ((v1+  v2)/2);
					result.asigna_pixel(f,c,aux);

				
				}
			}	
		}

		I=result;
	}
	else{
		cout << "Operacion no valida. Imagen vacia"<<endl;
	}

}

/**
  * @brief funcion que crea un marco negro a una imagen
  * @param I imagen a modificar
  * @pre f y c deben ser mayores que 0
  * @post marco negro creado en la Imagen I
  */
void enmarca_imagen(Imagen &I)
{
	if(I.num_filas() >0 && I.num_columnas()>0){
		int nf = I.num_filas();
		int nc = I.num_columnas();
	
		for (int f=0; f < nf-1; f++){
			I.asigna_pixel(f, 0, 0);// lado izquierdo
		}

		for (int f=0; f < nf; f++){// lado derecho
			I.asigna_pixel (f, nc-1, 0);
		}
		for (int c=0; c < nc; c++){// lado superior
			I.asigna_pixel (0, c, 0);
		}
		for (int c=0; c < nc; c++){// lado inferior
			I.asigna_pixel (nf-1, c, 0);
		}
		cerr << "ENMARCADO";
	}
	else{
		cout << "Operacion no valida. Imagen vacia"<<endl;
	}
}



/**
  * @brief funcion que crea un icono dada una Imagen I a partir del numero de veces que sea desea reducir la imagen.
  * @param I imagen a modificar
  * @pre f y c deben ser mayores que 0
  * @post La imagen I es encogida 
  */
void Icono_Imagen(Imagen &I){

	if(I.num_filas() >0 && I.num_columnas()>0){
		int nf = I.num_filas();
		int nc = I.num_columnas();

		int n_veces_red=100000;
		do{			
			cout << "Introduzca cuantas veces quiere reducir la imagen (Ej. 2 haria la mitad)" << endl;
			cin>> n_veces_red;
		}while(n_veces_red*2>=nf && n_veces_red*2>=nc && n_veces_red<1);

		int nfi = nf/n_veces_red;
		int nci = nc/n_veces_red;
		Imagen r(nfi,nci);

		double v=0;

		int auxf=0, auxc=0;
		for(int i = 0; i<nfi; i++){
			for(int j = 0; j<nci; j++){
				 auxf=0, auxc=0;
				for(int k=n_veces_red*i; auxf<n_veces_red; k++){
					for(int l=n_veces_red*j; auxc<n_veces_red; l++){

					v+=I.consultar_pixel(k,l);
					auxc++;
					}
				auxf++;
				}
				v=round(v/n_veces_red);
				r.asigna_pixel(i,j,v);
				v=0;			
			}
		}
		I=r;	
	}
	else{
		cout << "Operacion no valida. Imagen vacia" <<endl;
	}	

}

/**
  * @brief funcion que el negativo de una Imagen
  * @param I imagen a modificar
  * @pre f y c deben ser mayores que 0
  * @post La imagen I es encogida 
  */
void negativo(Imagen &I){

	if(I.num_filas() >0 && I.num_columnas()>0){
		for(int i = 0; i<I.num_filas(); i++){
			for(int j =0; j<I.num_columnas(); j++){
				I.asigna_pixel(i,j,255-I.consultar_pixel(i,j));
			}
		}
	}
	else{
		cout << "Operacion no valida. Imagen vacia" << endl;
	}
}

int main(int argc, char * argv[])
{
	 char *origen=NULL, *destino=NULL; // nombres de los ficheros
	 string auxtxt;
	 string cadena;

	 int nf, nc, npixeles; // Num. de filas y columnas de las imagenes
	 int n=0;
	 Imagen aux;
	 Imagen lectura;
	 pair<int,int> es_si;

	
	  char opcion='o';

          while(opcion!='E'){
		cout << endl << "	Menu: " << endl;
		cout << "	(C) Cargar Imagen" << endl;
		cout << "	(G) Guardar Imagen" << endl;
		cout << "	(1) Umbralizar automatico "<< endl;
		cout << "	(2) Leer mensaje cifrado" << endl;
		cout << "	(3) cifrar mensaje" << endl;
		cout << "	(4) Umbralizar Imagen con escala de grises" << endl;
		cout << "	(5) Negativo Imagen" << endl;
		cout << "	(6) Enmarcar Imagen" << endl;
		cout << "	(7) Zoom Imagen" << endl;
		cout << "	(8) Aumentar contraste" << endl;
		cout << "	(9) Icono imagen" << endl;
		cout << "	(E) Salir del programa" << endl;

		cout << endl<<"Elija una opción: ";
		cin >> opcion;

		switch(opcion){
			case 'C':


				auxtxt="";
				cout << "Introduzca nombre del fichero de la imagen: ";
				cin >> auxtxt;
				n=auxtxt.length();

				origen = new char[n];
				for(int i = 0; i<n; i++){
					origen[i] = auxtxt[i];
				}


				if (!lectura.CargarImagen(origen)){
					cerr << "Error: No pudo leerse la imagen." << endl;
					cerr << "Terminando la ejecucion del programa." << endl;
					exit (1);
				  }
			
				cout << "Imagen cargada correctamente" << endl;
				cout << "Dimensiones de " << origen << ":" << endl;
	  			cout << "   Imagen   = " << lectura.num_filas()  << " filas x " << lectura.num_columnas() << " columnas " << endl;
				origen=0;


				aux=lectura;
				break;
			case 'G':
				auxtxt="";
				cout << "Introduzca nombre del fichero de la imagen: ";
				cin >> auxtxt;

				n=auxtxt.length();				
				
				destino = new char[n];
				for(int i = 0; i<n; i++){
					destino[i] = auxtxt[i];

				}
				if(!aux.GuardarImagen(destino)){
					cerr << "Error: No pudo guardarse la imagen." << endl;
					cerr << "Terminando la ejecucion del programa." << endl;
					exit (1);
				}
				cout << "Imagen guardada correctamente en: " << destino << endl;
				destino=0;
				break;
			case '1':
				int vmin;
				cout << "Introduzca para metro e: ";
				cin >> vmin;
				if(vmin<1){
					cout << "Parametro no valido" << endl;
					break;

				}				
				umbralizar_automatico(aux, vmin);
				cout << "Umbralizado realizado" << endl;
				break;
			case '2':
				if(LeerMensajeCifrado(aux, cadena)){
					cout << endl <<"Exito en la lectura: " << cadena << endl;
				}
				break;
			case '3':


				CifrarMensaje(aux);
				
				break;
			case '4':

				int t1,t2;
				cout << "Introduzca umbral T1: ";
				cin >> t1;
				cout << "Introduzca umbral T2: ";
				cin >> t2;
				umbralizar_escala_grises(aux,t1,t2);
				break;
			case '5':
				negativo(aux);
				cout << "Negativo de la imagen creado" << endl;
				break;
			case '6':

				enmarca_imagen(aux);
				cout << "Imagen enmarcada correctamente " << endl;				
				break;
			case '7':

				int intaux;
				cout << "Introduzca la coordenada X de la esquina superior izquierda: ";
				cin >> intaux;
				es_si.first=intaux;
				cout << "Introduzca la coordenada Y de la esquina superior izquierda: ";
				cin >> intaux;
				es_si.second = intaux;
				cout << "Dimension de la subimagen:";
				cin >> intaux;

				zoom(aux, es_si, intaux);

				break;
			case '8':

				int minimo, maximo;
				cout << "Introduzca minimo de gris: ";
				cin >> minimo;
				cout << "Introduzca maximo de gris: ";
				cin >> maximo;
				AumentarContraste(aux,minimo,maximo);
				break;
			case '9':
				Icono_Imagen(aux);
				break;
			
			case 'E':
				cerr << "Saliendo del programa " <<endl;
				cerr << "bye! "<<endl;

				break;
		}		
	}
	
	
	delete[] origen;
	delete[] destino;
  	return (1);	
}
