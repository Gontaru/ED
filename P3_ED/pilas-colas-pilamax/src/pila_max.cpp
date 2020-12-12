/**
* @file pila_max.cpp
* @brief fichero que decide que contenedor se usará para representar una pila (un vector o una cola).
*/
#include "pila_max.h"
#define CUAL_COMPILA 1
#if CUAL_COMPILA==1
#include "pila_max_vd.cpp"
#elif CUAL_COMPILA==2
#include "pila_max_cola.cpp"
#endif
