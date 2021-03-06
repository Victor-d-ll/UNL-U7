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
	bool opciones[9];
	
	bool hayTateti();
	bool setPosicion(int tecla);
	char getValorPorTurno();
	void bienvenida();
	void mensajeEmpate();
	void mostrarGanador(bool turnoJ1);
	void mostrarJugador();
	void mostrarOpciones();
	void mostrarTablero();
	void verificarFin();	
	int capturarTecla();
};

#endif

