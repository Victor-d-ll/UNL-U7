#ifndef TABLERO_H
#define TABLERO_H

#include<iostream>
#include "Ficha.h"
#include <conio2.h>
class Tablero {
public:
	Tablero();
	
	bool estaLleno();
	bool existeFicha(int x, int y);
	bool tateti();
	void mostrarTablero();	
	void setFicha(int x, int y, char c);	
	
private:	
	
	Ficha fichas[3][3];
	
	bool ChequeaColumnas();
	bool ChequeaDiagonales();
	bool ChequeaFilas(); 	
};

#endif

