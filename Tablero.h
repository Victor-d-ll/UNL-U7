#ifndef TABLERO_H
#define TABLERO_H

#include<iostream>
#include "Ficha.h"
class Tablero {
public:
	Tablero();
	void mostrarTablero();
	
private:

	void cargarTablero();
	
	Ficha fichas[3][3];
};

#endif

