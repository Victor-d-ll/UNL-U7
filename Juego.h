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
	bool jugando;
	void bienvenida();
	void mostrarGanador(bool turnoJ1);
	void mostrarJugador();
	void mostrarOpciones();
	void mostrarTablero();
	
	int capturarTecla();
	bool setPosicion(int tecla);
	bool hayTateti();
};

#endif

