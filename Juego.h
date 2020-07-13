#ifndef JUEGO_H
#define JUEGO_H

#include <conio2.h>
#include<iostream>
#include "Tablero.h"

class Juego {
public:
	Juego();
	void start();
private:	
	Tablero tablero;
	bool turnoJ1;
	void bienvenida();
	void mostrarJugador();
	void mostrarOpciones();
};

#endif

