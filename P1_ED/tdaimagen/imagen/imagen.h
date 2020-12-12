/**
  * @file imagen.h
  * @brief Fichero cabecera del TDA Imagen
  *
  */

#ifndef __IMAGEN__
#define __IMAGEN__

#include <iostream>
#include "imagenES.h"

using namespace std;

/**
 * @brief byte tipo de dato a tratar en los pixeles
*/
typedef unsigned char byte;
/**
  *  @brief T.D.A. Imagen
  *
  * Una instancia @e c de la clase imagen representa una imagen con f filas y c columnas en una matriz de char byte imagen[filas][columnas]
  * dónde cada casilla representa un pixel con valores entre [0,255], siendo 0 negro y 255 blanco
  * 
  *
  * @author Gonzalo Medina Medina
  * @date Octubre 2020
  */

class Imagen{

private:
/**
  * @page Rep del TDA Imagen
  *
  * @section Invariante de la representación
  *
  * El invariante es filas>0 y columnas>0
  *
  *
  */

/**
  * @brief Datos privados de la clase Imagen
  * @param filas numero de filas de la imagen
  * @param columnas numero de columnas de la imagen
  * @param imagen matriz de pixeles de la imagen
  *
  */
  int filas;
  int columnas;
  unsigned char **imagen;

public:

/**
  * @brief Constructor por defecto de la clase. Crea una imagen vacía
  */
  Imagen();
/**
  * @brief Constructor de la clase
  * @param f numero de filas de la imagen
  * @param c numero de columnas de la imagen
  * @return Crea el numero racional n/d
  * @pre f y c deben ser mayores que 0
  * @post la imagen creada contiene valores basura
  */
  Imagen(int f, int c);


/**
  * @brief Constructor de copias de la clase
  * @param c Imagen a copiar
  * @post la imagen creada contiene valores basura
  */
  Imagen (const Imagen& c);

/**
  * @brief Destructor de clase. Libera los recursos ocupados
  * @post No devuelve nada. el objeto no puede volver a usarse a no ser que se vuelva a inicializar
  */
  ~Imagen();  

/**
  * @brief Filas
  * @return Devuelve el numero de filas de la imagen
  */
  int num_filas() const{return filas;};

/**
  * @brief Columnas
  * @return Devuelve el numero de columnas de la imagen
  */
  int num_columnas()const {return columnas;};


/**
  * @brief Asigna un pixel a una posicion de la imagen
  * @param f fila a la que asignar el pixel
  * @param c columna a la que asignar el pixel
  * @param valor es un valor entre[0,255] a asignar en el pixel 
  * @pre 0<f<=filas, 0<c<=columnas, 0<valor<=255
  * @post No devuelve nada. La imagen se modifica.
  */
  void asigna_pixel(int f, int c, unsigned char valor);

/**
  * @brief Devuelve el pixel en la posicion f y c
  * @param f fila en la que consultar
  * @param c columna en la que consultar
  * @pre 0<f<=filas, 0<c<=columnas, e imagen[f][c]!=null
  * @return devuelve unsigned char con el valor de la celda
  */

  unsigned char consultar_pixel(int f, int c)const;

/**
  * @brief carga la imagen con nombre n
  * @param n nombre del fichero de la imagen
  * @return devuelve true si se ha cargado bien la imagen, false en cualquier otro caso
  */
  bool CargarImagen(const char * n);

/**
  * @brief guarda la imagen con nombre n
  * @param nombre del fichero de la imagen
  * @return devuelve true si se ha guardado bien la imagen, false en cualquier otro caso
  */
  bool GuardarImagen(const char *nombre);

/**
  * @brief sobrecarga del operador de copia
  * @param I de la imagen a copiar
  * @return devuelve la dirección de memoria del objeto Imagen
  */
  Imagen & operator=(const Imagen &I);

/**
  * @brief Saca por pantalla la matriz imagen
  *
  */
void ImprimirImagen();

/**
  * @brief Borra el objeto Imagen
  *
  */
void Borrar();

#endif
};
