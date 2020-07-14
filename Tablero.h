#ifndef TABLERO_H
#define TABLERO_H

#include<iostream>
#include "Ficha.h"
#include <conio2.h>
class Tablero {
public:
	Tablero();
	void mostrarTablero();
	bool existeFicha(int x, int y);
	void setFicha(int x, int y, char c);
	bool tateti();
	bool estaLleno();
private:		
	bool ChequeaFilas(); //VERIFICAR QUE NO ESTAN FUNCIONANDO
	bool ChequeaDiagonales();
	bool ChequeaColumnas();
	Ficha fichas[3][3];
};

#endif

