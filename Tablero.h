#ifndef TABLERO_H
#define TABLERO_H

#include<iostream>
#include "Ficha.h"
class Tablero {
public:
	Tablero();
	void mostrarTablero();
	bool existeFicha(int x, int y);
	void setFicha(int x, int y, char c);
private:		
	Ficha fichas[3][3];
};

#endif

