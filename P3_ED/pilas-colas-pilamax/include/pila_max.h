/**
* @file pila_max.h
* @brief fichero que define que contenedor se usará para representar una pila (un vector o una cola).
*/

#define CUAL_COMPILA 1
#if CUAL_COMPILA==1
#include "pila_max_vd.h"
#elif CUAL_COMPILA==2
#include "pila_max_cola.h"
#endif
